#include "sphere.hpp"

Sphere::Sphere() {

}

Sphere::Sphere(sf::Vector3<double> pos, double rad) :
  position(pos), radius(rad) {

}


IntersectionRecord * Sphere::intersect(Ray &ray) {

  return intersectFast(ray);
}

//somewhat more optimized, less sqrt
//essentially transcribed from Sherrod
IntersectionRecord * Sphere::intersectFast(Ray &ray) {

  sf::Vector3<double> rsVec = position - ray.origin;

  double radius2 = radius * radius;
  
  double intersectDistA = Vec3dMath::dot(rsVec, ray.direction); //cosine angle

  if(intersectDistA < 0.0) {
    return nullptr;
  }

  double rsLength = Vec3dMath::dot(rsVec, rsVec); //returns length^2

  double intersectDistB = radius2 - rsLength + (intersectDistA * intersectDistA);
  
  if(intersectDistB < 0.0 || intersectDistB > radius2) {
    return nullptr;
  }
  
  return new IntersectionRecord(intersectDistA - sqrt(intersectDistB));
}


//unoptimized but mathematically correct
IntersectionRecord * Sphere::intersectWell(Ray &ray) {

  //vector between ray origin and sphere center
  sf::Vector3<double> L = position - ray.origin;

  //cosine angle of a ray 't', in this case "ray"
  double tca = Vec3dMath::dot(L, ray.direction);

  if(tca < 0.0) return nullptr;

  //hypotenuse of a right triangle formed by L and t
  double d = sqrt(Vec3dMath::dot(L, L) - (tca * tca));

  if(d < 0.0 || d > radius) return nullptr;

  //length of base of the right triangle formed by d and radius
  double thc = sqrt((radius * radius) - (d * d));

  return new IntersectionRecord(tca - thc);
}

