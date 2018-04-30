#include "ambientlight.hpp"

AmbientLight::AmbientLight(sf::Vector3<double> iRGB) {

  Vec3dMath::clamp(iRGB);
  intensity = iRGB;
}

sf::Color AmbientLight::contribute(IntersectionRecord* record) {

  int red   = (int)(255 * record->material->ambk.x * intensity.x);
  int green = (int)(255 * record->material->ambk.y * intensity.y);
  int blue  = (int)(255 * record->material->ambk.z * intensity.z);
  
  return sf::Color(red, green, blue);
}
