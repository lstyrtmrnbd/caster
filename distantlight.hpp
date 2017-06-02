#ifndef DISTANTLIGHT_HPP
#define DISTANTLIGHT_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "light.hpp"
#include "intersectionrecord.hpp"
#include "vec3dmath.hpp"

class DistantLight : public Light {

public:

  sf::Vector3<double> intensity; //clamp 0.0 - 1.0
  sf::Vector3<double> direction; //normalize
  
  sf::Color contribute(IntersectionRecord* record);

  DistantLight(sf::Vector3<double> iRGB, sf::Vector3<double> dir);
};

#endif
