#ifndef AMBIENTLIGHT_HPP
#define AMBIENTLIGHT_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "light.hpp"
#include "intersectionrecord.hpp"
#include "vec3dmath.hpp"

class AmbientLight : public Light {

public:

  sf::Vector3<double> intensity; //clamp 0.0 - 1.0
  
  sf::Color contribute(IntersectionRecord* record);

  AmbientLight(sf::Vector3<double> iRGB);
};

#endif
