#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "light.hpp"
#include "intersectionrecord.hpp"
#include "vec3dmath.hpp"

class PointLight : public Light {

public:

  //used to decrease distance attenuation in contribute()
  const double epsilon = .75;
  //p0
  sf::Vector3<double> position;
  //I at p0, this is not clamped and for decent results should be a large value 
  sf::Vector3<double> intensity;
  
  sf::Color contribute(IntersectionRecord* record);

  PointLight(sf::Vector3<double> iRGB, sf::Vector3<double> pos);
};

#endif
