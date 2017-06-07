#include "material.hpp"

Material::Material() {

}

Material::Material(sf::Color &col) : color(col) {

}

Material::Material(sf::Vector3<double> ambientK) :
  ambk(ambientK), diffk(sf::Vector3<double>(0,0,0)) {

}

Material::Material(sf::Vector3<double> ambientK, sf::Vector3<double> diffuseK) :
  ambk(ambientK), diffk(diffuseK), speck(sf::Vector3<double>(0,0,0)), shineA(0.0) {

}

Material::Material(sf::Vector3<double> ambientK, sf::Vector3<double> diffuseK,
		   sf::Vector3<double> specularK, double shininess) :
  ambk(ambientK), diffk(diffuseK), speck(specularK), shineA(shininess) {

}
