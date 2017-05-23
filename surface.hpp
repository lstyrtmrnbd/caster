#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "ray.hpp"
#include "intersectionrecord.hpp"

/**
 *  override with shape's intersection formula
 **
 *  Sherrod returns distance via float *dist parameter,
 *  instead begin building IntersectionRecord here
 *  and finish it in the owner Object with Material data
 */
class Surface {

public:

  //returns nullptr if no intersection
  virtual IntersectionRecord * intersect(Ray&) = 0;
  
};


#endif
