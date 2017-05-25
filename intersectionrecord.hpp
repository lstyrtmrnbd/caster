#ifndef INTERSECTION_RECORD_HPP
#define INTERSECTION_RECORD_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class IntersectionRecord {

public:

  //ray tracing, filled by surface.intersect
  double distance;
  sf::Vector3<double> normal;

  //material and lighting, filled by caster.shade
  sf::Color color;

  
  IntersectionRecord();
  IntersectionRecord(double dist);
  IntersectionRecord(double dist, sf::Vector3<double> norm);
  
  
};


#endif
