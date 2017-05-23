#include "object.hpp"

Object::Object() {

}

Object::Object(std::vector<Surface*> &surfs, Material* mat) :
  surfaces(surfs), material(mat) {

}

IntersectionRecord * Object::intersect(Ray &ray) {

  //loop through surfaces intersect() calls with the ray
  //return the closest after adding values from material

  IntersectionRecord* closest = nullptr;
  
  for(auto it = surfaces.begin(); it != surfaces.end(); it++) {

    IntersectionRecord* current = (*it)->intersect(ray);

    if(current != nullptr &&
       (closest == nullptr || current->distance < closest->distance)) {

      closest = current;
    }
  }

  if(closest != nullptr) {
    closest->color = material->color;
  }
  
  return closest;
}
