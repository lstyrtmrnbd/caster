#include "pointlight.hpp"

PointLight::PointLight(sf::Vector3<double> iRGB, sf::Vector3<double> pos) : position(pos) {

  Vec3dMath::clamp(iRGB);
  intensity = iRGB;
}

sf::Color PointLight::contribute(IntersectionRecord* record) {
  
  //Diffuse contribution:
  sf::Vector3<double> toLight = record->interpt - position;
  sf::Vector3<double> fromLight = position - record->interpt;
  
  double distance = Vec3dMath::length(fromLight); //for intensity at intersection point calculation

  sf::Vector3<double> intensityAtPt = intensity / (distance * distance);

  Vec3dMath::normalize(fromLight);

  double factor = fmax(0.0,Vec3dMath::dot(record->normal, fromLight));

  int red   = (int)(255 * factor * record->material->diffk.x);
  int green = (int)(255 * factor * record->material->diffk.y);
  int blue  = (int)(255 * factor * record->material->diffk.z);

  return sf::Color(red, green, blue);
}
