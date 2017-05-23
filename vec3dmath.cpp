#include "vec3dmath.hpp"

double Vec3dMath::dot(sf::Vector3<double> &a,
		      sf::Vector3<double> &b) {

  return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
  
}

double Vec3dMath::length(sf::Vector3<double> &vec) {

  return sqrt(dot(vec, vec));
  
}

void Vec3dMath::normalize(sf::Vector3<double> &vec) {

  double len = length(vec);

  vec.x /= len;
  vec.y /= len;
  vec.z /= len;
  
}

sf::Vector3<double> Vec3dMath::cross(sf::Vector3<double> &a,
				     sf::Vector3<double> &b) {

  return sf::Vector3<double>((a.y * b.z) - (a.z * b.y),
			     (a.z * b.x) - (a.x * b.z),
			     (a.x * b.y) - (a.y * b.x));
}
