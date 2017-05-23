#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Material {

public:

  sf::Color color;
  
  Material();
  Material(sf::Color &color);
  
};

#endif
