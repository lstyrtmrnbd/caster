#include "distantlight.hpp"

DistantLight::DistantLight(sf::Vector3<double> iRGB, sf::Vector3<double> dir) {

  Vec3dMath::clamp(iRGB);
  intensity = iRGB;

  Vec3dMath::normalize(dir);
  direction = dir;
}

sf::Color DistantLight::contribute(IntersectionRecord* record) {

  //Diffuse contribution:
  //Lambert's cosine law, with direction from point to light being -light.direction
  sf::Vector3<double> toLight = direction * -1.0;
  
  double factor = fmax(0.0, Vec3dMath::dot(record->normal, toLight));

  int red   = (int)(255 * factor * record->material->diffk.x * intensity.x);
  int green = (int)(255 * factor * record->material->diffk.y * intensity.y);
  int blue  = (int)(255 * factor * record->material->diffk.z * intensity.z);

  return sf::Color(red, green, blue);
}
