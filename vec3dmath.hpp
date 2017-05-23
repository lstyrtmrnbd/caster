#ifndef VEC3DMATH_HPP
#define VEC3DMATH_HPP

#include <cmath>

#include <SFML/System.hpp>

namespace Vec3dMath {

  double dot(sf::Vector3<double>&, sf::Vector3<double>&);
  double length(sf::Vector3<double>&);
  void normalize(sf::Vector3<double>&);
  sf::Vector3<double> cross(sf::Vector3<double>&, sf::Vector3<double>&);

}

#endif
