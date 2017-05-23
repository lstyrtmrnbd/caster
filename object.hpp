#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>

#include "ray.hpp"
#include "surface.hpp"
#include "material.hpp"
#include "intersectionrecord.hpp"

class Object {

  std::vector<Surface*> surfaces;
  Material* material;

public:

  Object();
  Object(std::vector<Surface*>&, Material*);
  IntersectionRecord * intersect(Ray&);
  
  
};

#endif
