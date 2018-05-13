#include "raycast.hpp"

// EC: used for error checking

RayCast::RayCast() {


}

RayCast::RayCast(int width, int height, sf::Vector3<double> pos,
                 sf::Vector3<double> screenPos) :
                 screenWidth(width), screenHeight(height),
                 position(pos), screenPosition(screenPos) {

  const std::size_t interCt = width * height;
  std::vector<IntersectionRecord*> intersections(interCt);

  std::cout << "Caster initialized with "
            << width << " width, " << height << " height\n"
            << "\tat position " << pos.x << ", " << pos.y << ", " << pos.z << "\n"; // EC
}

RayCast::~RayCast() {

  // clean up the following:
  //  intersections

}

void RayCast::castRays(std::vector<Object*> &objList) {

  int totalHits = 0; // EC

  Ray castMe;
  castMe.origin = position;

  double depth = position.z - screenPosition.z;
  
  sf::Vector3<double> dir(0.0, 0.0, 0.0);
  
  for(int y = 0; y < screenHeight; y++) {

    for(int x = 0; x < screenWidth; x++) {

      dir.x = x - (double)(screenWidth / 2.0);
      dir.y = y - (double)(screenHeight / 2.0);
      dir.z = depth * -1; // don't cast backwards
      
      Vec3dMath::normalize(dir);    
      castMe.direction = dir;

      // the record this points to is constructed by Object.intersect() and can be null
      IntersectionRecord* closest = castRay(castMe, objList);
      intersections.push_back(closest);

      if(closest != nullptr) { totalHits++; } // EC
    }
  }

  std::cout << "Caster filled intersection records list, contains "
            << totalHits << " total hits" << "\n"; // EC
  
}

IntersectionRecord* RayCast::castRay(Ray &ray, std::vector<Object*> &objList) {

  // list Object intersections per castRay
  // if nullptr -> no object hit, return nullptr in closest for long list
  // if not -> some hit, compare distance and return in closest

  std::vector<IntersectionRecord*> shortList;

  for(auto it = objList.begin(); it != objList.end(); it++) {

    IntersectionRecord* inter = (*it)->intersect(ray);

    shortList.push_back(inter);
  }

  IntersectionRecord* closest = nullptr;

  for(auto it = shortList.begin(); it != shortList.end(); it++) {

    IntersectionRecord* current = *it;

    if(current != nullptr)
      if(closest == nullptr || current->distance < closest->distance)
        closest = current;
  }
        
  // KILL SHORTLIST RECORDS BUT NOT closest

  return closest;
}

std::vector<sf::Uint8>* RayCast::shade(std::vector<Light*> &lightList) {

  int totalColor = 0;
  
  std::vector<sf::Uint8>* colorBuffer = new std::vector<sf::Uint8>(); 

  for(auto it = intersections.begin(); it != intersections.end(); it++) {

    if((*it) == nullptr) {

      colorBuffer->push_back(defaultColor.r);
      colorBuffer->push_back(defaultColor.g);
      colorBuffer->push_back(defaultColor.b);
      colorBuffer->push_back(defaultColor.a);
    } else {

      // the pushed color is built by adding light contributions
      sf::Color col(0,0,0);

      for(auto lit = lightList.begin(); lit != lightList.end(); lit++) {

        // iterate through objects with interpt-to-light ray
        // and break on intersect for shadows, else add light contribution
        col += (*lit)->contribute(*it);
      }
      
      colorBuffer->push_back(col.r);
      colorBuffer->push_back(col.g);
      colorBuffer->push_back(col.b);
      colorBuffer->push_back(col.a);
      
      totalColor++; // EC
    }
  }

  std::cout << "Caster shaded " << totalColor << " non-default colors to buffer\n"; // EC
  
  return colorBuffer;
}

