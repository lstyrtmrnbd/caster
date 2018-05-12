#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <SFML/System.hpp>

#include "surface.hpp"
#include "vec3dmath.hpp"

class Sphere : public Surface {

public:

  sf::Vector3<double> position;
  double radius;

  Sphere();
  Sphere(sf::Vector3<double> pos, double rad);

  IntersectionRecord* intersect(Ray&);

private:

  IntersectionRecord* intersectFast(Ray&);
  IntersectionRecord* intersectWell(Ray&);
  
};

#endif
