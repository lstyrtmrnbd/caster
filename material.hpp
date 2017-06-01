#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Material {

public:

  sf::Color color;

   //ambient coefficient for each RGB, 0 <= k <= 1
  sf::Vector3<double> ambient;
  
  Material();
  Material(sf::Color &color);
  
};

#endif
