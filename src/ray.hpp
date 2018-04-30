#ifndef RAY_HPP
#define RAY_HPP

#include <SFML/System.hpp>

class Ray {
  
public:

  Ray();
  Ray(sf::Vector3<double>&, sf::Vector3<double>&);
  
  sf::Vector3<double> origin;
  sf::Vector3<double> direction;

  void operator=(const Ray &ray);

};

#endif
