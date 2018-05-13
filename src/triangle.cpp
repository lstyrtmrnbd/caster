#include "triangle.hpp"

Triangle::Triangle(sf::Vector3<double> point1, sf::Vector3<double> point2,
                   sf::Vector3<double> point3) : p1(point1), p2(point2), p3(point3) {

}

IntersectionRecord* Triangle::intersect(Ray& ray) {

  sf::Vector3<double> vecAB = p2 - p1;
  sf::Vector3<double> vecAC = p3 - p1;

  sf::Vector3<double> origin = ray.origin;
  sf::Vector3<double> direction = ray.direction;

  sf::Vector3<double> cross = Vec3dMath::cross(direction, vecAC);

  // get determinate
  double det = Vec3dMath::dot(vecAB, cross);

  if(det < 0.0001) return nullptr;

  sf::Vector3<double> rayPointVec = origin - p1;

  double test1 = Vec3dMath::dot(rayPointVec, cross);

  if(test1 < 0.0 || test1 > det) return nullptr;

  sf::Vector3<double> cross2 = Vec3dMath::cross(rayPointVec, vecAB);

  double test2 = Vec3dMath::dot(direction, cross2);

  if(test2 < 0.0 || test1 + test2 > det) return nullptr;

  double inverseDet = 1.0 / det;

  sf::Vector3<double> distance = Vec3dMath::dot(vecAC, cross2);
  distance *= inverseDet;

  sf::Vector3<double> interPt = ray.origin + distance * ray.direction;

  return new IntersectionRecord(distance);
}
