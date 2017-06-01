#include "plane.hpp"

Plane::Plane() {

}

Plane::Plane(sf::Vector3<double> pos, sf::Vector3<double> norm) :
  position(pos) {

  Vec3dMath::normalize(norm);
  normal = norm;
}

IntersectionRecord * Plane::intersect(Ray &ray) {

  double denom = Vec3dMath::dot(normal, ray.direction);

  if(denom < 1e-6) return nullptr;

  //vector between ray origin and plane position
  sf::Vector3<double> L = position - ray.origin;

  double distance = Vec3dMath::dot(L, normal) / denom;

  if(distance < 0.0) return nullptr;

  sf::Vector3<double> interPt = ray.origin + distance * ray.direction;

  return new IntersectionRecord(distance, interPt, normal);
}
