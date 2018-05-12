#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Material {

public:

  // for flat shading
  sf::Color color;

  // ambient reflection coefficient for each RGB, 0 <= k <= 1
  sf::Vector3<double> ambk;

  // diffuse reflection coefficient for each RGB, 0 <= k <= 1
  sf::Vector3<double> diffk;

  // specular reflection coefficient for each RGB, 0 <= k <= 1
  sf::Vector3<double> speck;

  // shininess coefficient, larger value -> smaller lobe
  double shineA;
  
  Material();
  Material(sf::Color &color);
  Material(sf::Vector3<double> ambientK);
  Material(sf::Vector3<double> ambientK, sf::Vector3<double> diffuseK);
  Material(sf::Vector3<double> ambientK, sf::Vector3<double> diffuseK,
           sf::Vector3<double> specularK, double shininess);
};

#endif
