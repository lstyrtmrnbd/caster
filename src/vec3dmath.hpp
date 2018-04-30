#ifndef VEC3DMATH_HPP
#define VEC3DMATH_HPP

#include <cmath>

#include <SFML/System.hpp>

namespace Vec3dMath {

  double dot(sf::Vector3<double>&, sf::Vector3<double>&);
  
  double length(sf::Vector3<double>&);

  sf::Vector3<double> cross(sf::Vector3<double>&, sf::Vector3<double>&);

  //these functions modify the vector they receive
  void normalize(sf::Vector3<double>&);

  void clamp(sf::Vector3<double>&, double floor = 0.0, double ceil = 1.0);
}

#endif
