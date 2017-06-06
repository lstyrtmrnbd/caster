#include "raycast.hpp"

/**
 *  //EC: used for error checking
 */

RayCast::RayCast() {


}

RayCast::RayCast(int width, int height, sf::Vector3<double> pos,
		 sf::Vector3<double> screenPos) :
                 screenWidth(width), screenHeight(height),
                 position(pos), screenPosition(screenPos) {

  const std::size_t interCt = width * height;
  std::vector<IntersectionRecord*> intersections(interCt);

  //EC
  std::cout << "Caster initialized with "
	    << width << " width, " << height << " height\n"
	    << "\tat position " << pos.x << ", " << pos.y << ", " << pos.z << "\n";
}

RayCast::~RayCast() {

  //clean up the following:
  //  intersections

}

void RayCast::castRays(std::vector<Object*> &objList) {

  int totalHits = 0; //EC

  Ray castRay;
  castRay.origin = position;

  double depth = position.z - screenPosition.z;
  
  sf::Vector3<double> dir(0.0, 0.0, 0.0);
  
  for(int y = 0; y < screenHeight; y++) {

    for(int x = 0; x < screenWidth; x++) {

      dir.x = x - (double)(screenWidth / 2.0);
      dir.y = y - (double)(screenHeight / 2.0);
      dir.z = depth * -1; //don't cast backwards
      
      Vec3dMath::normalize(dir);
      
      castRay.direction = dir;

      //list Object intersections per castRay
      //if nullptr -> no object hit, put nullptr in long list
      //if not -> some hit, compare distance and put closest

      std::vector<IntersectionRecord*> shortList;

      for(auto it = objList.begin(); it != objList.end(); it++) {

	IntersectionRecord* inter = (*it)->intersect(castRay);
	
	shortList.push_back(inter);
      }

      IntersectionRecord* closest = nullptr;

      for(auto it = shortList.begin(); it != shortList.end(); it++) {

	if((*it) != nullptr &&
	   (closest == nullptr ||
	    (*it)->distance < closest->distance)) {

	  closest = (*it);
	}
      }

      //!!KILL THE OLD INTERSECTION RECORDS!!
      //closest is now the final intersection verdict for castRay
 
      intersections.push_back(closest);

      //EC
      if(closest != nullptr) { totalHits++; }
    }
  }

  //EC
  std::cout << "Caster filled intersection records list, contains "
	    << totalHits << " total hits" << "\n";
  
}

std::vector<sf::Uint8> * RayCast::shade(std::vector<Light*> &lightList) {

  //return pointer to buffer

  int totalColor = 0;
  
  std::vector<sf::Uint8>* colorBuffer = new std::vector<sf::Uint8>(); 

  //IntersectionRecord** it
  for(auto it = intersections.begin(); it != intersections.end(); it++) {

    if((*it) == nullptr) {

      colorBuffer->push_back(defaultColor.r);
      colorBuffer->push_back(defaultColor.g);
      colorBuffer->push_back(defaultColor.b);
      colorBuffer->push_back(defaultColor.a);
    } else {

      //the pushed color is built by adding light contributions
      sf::Color col(0,0,0);

      //Light** lit
      for(auto lit = lightList.begin(); lit != lightList.end(); lit++) {

	//iterate through objects with intersection to light ray
	//and break on intersect for shadows
	col += (*lit)->contribute(*it);
      }
      
      colorBuffer->push_back(col.r);
      colorBuffer->push_back(col.g);
      colorBuffer->push_back(col.b);
      colorBuffer->push_back(col.a);
      
      //EC
      totalColor++;
    }
  }

  //EC
  std::cout << "Caster shaded " << totalColor << " non-default colors to buffer\n";
  
  return colorBuffer;
}

