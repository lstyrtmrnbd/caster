#include "pointlight.hpp"

PointLight::PointLight(sf::Vector3<double> iRGB, sf::Vector3<double> pos) :
  position(pos), intensity(iRGB) {

}

sf::Color PointLight::contribute(IntersectionRecord* record) {
  
  //Diffuse contribution:
  sf::Vector3<double> fromLight = position - record->interpt;

  //there's was a sqrt here that could be factored out
  double distance2 = Vec3dMath::dot(fromLight, fromLight);
  
  sf::Vector3<double> attenuation = intensity / distance2;

  Vec3dMath::normalize(fromLight);

  double factor = fmax(0.0,Vec3dMath::dot(record->normal, fromLight));

  int red   = (int)(255 * factor * record->material->diffk.x * attenuation.x);
  int green = (int)(255 * factor * record->material->diffk.y * attenuation.y);
  int blue  = (int)(255 * factor * record->material->diffk.z * attenuation.z);

  return sf::Color(red, green, blue);
}
