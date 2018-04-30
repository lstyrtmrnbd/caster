#ifndef INTERSECTION_RECORD_HPP
#define INTERSECTION_RECORD_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "material.hpp"

class IntersectionRecord {

public:

  //ray tracing, filled by surface.intersect
  double distance;
  sf::Vector3<double> interpt; //intersection point
  sf::Vector3<double> normal;
  sf::Vector3<double> fromViewer; //ray.direction, for spec reflection
  
  //material and lighting, filled by object.intersect
  Material* material;
  
  IntersectionRecord();
  IntersectionRecord(double dist);
  IntersectionRecord(double dist, sf::Vector3<double> norm);
  IntersectionRecord(double dist, sf::Vector3<double> inter,
		     sf::Vector3<double> norm, sf::Vector3<double> direction);
  
};


#endif
