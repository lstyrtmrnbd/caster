#ifndef PLANE_HPP
#define PLANE_HPP

#include <SFML/System.hpp>

#include "surface.hpp"
#include "vec3dmath.hpp"

class Plane : public Surface {

public:

  sf::Vector3<double> position;
  sf::Vector3<double> normal;

  Plane();
  Plane(sf::Vector3<double> pos, sf::Vector3<double> norm);

  IntersectionRecord * intersect(Ray&);
  
};

#endif
 
