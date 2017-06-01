#ifndef INTERSECTION_RECORD_HPP
#define INTERSECTION_RECORD_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "material.hpp"

class IntersectionRecord {

public:

  //ray tracing, filled by surface.intersect
  double distance;
  sf::Vector3<double> normal;

  //material and lighting, filled by object.intersect
  Material* material;
  sf::Color color; //flat shading way, to be removed

  
  IntersectionRecord();
  IntersectionRecord(double dist);
  IntersectionRecord(double dist, sf::Vector3<double> norm);
  
  
};


#endif
