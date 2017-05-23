#ifndef INTERSECTION_RECORD_HPP
#define INTERSECTION_RECORD_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class IntersectionRecord {

public:

  double distance;
  sf::Color color;
  
  IntersectionRecord();
  IntersectionRecord(double dist);
  
};


#endif
