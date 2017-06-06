#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "light.hpp"
#include "intersectionrecord.hpp"
#include "vec3dmath.hpp"

class PointLight : public Light {

public:

  sf::Vector3<double> position;  //p0
  sf::Vector3<double> intensity; //I at p0

  sf::Color contribute(IntersectionRecord* record);

  PointLight(sf::Vector3<double> iRGB, sf::Vector3<double> pos);
};

#endif
