#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "intersectionrecord.hpp"

/**
 * Override for each type of light
 */

class Light {

public:

  //takes an intersection record and returns the color contribution of the light
  virtual sf::Color contribute(IntersectionRecord* record) = 0;
  
};

#endif
