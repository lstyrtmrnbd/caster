#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <vector>

#include "ray.hpp"
#include "surface.hpp"
#include "material.hpp"
#include "intersectionrecord.hpp"

/**
 * An Object is a collection of surfaces that share a Material,
 * it farms its intersection function out to its surfaces and
 * returns the closest after adding a pointer to its Material for lighting calculations
 */
class Object {

  std::vector<Surface*> surfaces;
  Material* material;

public:

  Object();
  Object(std::vector<Surface*>&, Material*);
  IntersectionRecord * intersect(Ray&);
  
  
};

#endif
