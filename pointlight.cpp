#include "pointlight.hpp"

PointLight::PointLight(sf::Vector3<double> iRGB, sf::Vector3<double> pos) :
  position(pos), intensity(iRGB) {

}

sf::Color PointLight::contribute(IntersectionRecord* record) {
  
  //Diffuse contribution:
  sf::Vector3<double> diffk = record->material->diffk;
  sf::Vector3<double> fromLight = position - record->interpt;

  //dodges the sqrt in length()
  double distance2 = Vec3dMath::dot(fromLight, fromLight);
  
  sf::Vector3<double> attenuation = intensity / distance2;

  Vec3dMath::normalize(fromLight);

  double diffFactor = fmax(0.0,Vec3dMath::dot(record->normal, fromLight));

  diffk *= diffFactor;
  
  //Specular contribution:
  sf::Vector3<double> speck = record->material->speck;
  sf::Vector3<double> toLight = fromLight * -1.0; //pre-normalized

  //the toLight vector reflected about the normal
  sf::Vector3<double> reflected = 2.0 * Vec3dMath::dot(toLight, record->normal) *
				   record->normal - sf::Vector3<double>(1,1,1);

  double cosf = fmax(0.0, Vec3dMath::dot(record->fromViewer, reflected));

  double specFactor = pow(cosf, record->material->shineA);
  
  speck *= specFactor;

  
  int red   = (int)(255 * (diffk.x + speck.x) * attenuation.x);
  int green = (int)(255 * (diffk.y + speck.y) * attenuation.y);
  int blue  = (int)(255 * (diffk.z + speck.z) * attenuation.z);

  return sf::Color(red, green, blue);
}
