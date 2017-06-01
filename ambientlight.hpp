#ifndef AMBIENTLIGHT_HPP
#define AMBIENTLIGHT_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "light.hpp"
#include "intersectionrecord.hpp"
#include "vec3dmath.hpp"

class AmbientLight : public Light {

public:

  //clamp between 0.0 and 1.0 in constructor
  sf::Vector3<double> intensity;
  
  sf::Color contribute(IntersectionRecord* record);

  AmbientLight(sf::Vector3<double> iRGB);
};

#endif
