#include "triangle.hpp"

Triangle::Triangle(sf::Vector3<double> point1, sf::Vector3<double> point2,
                   sf::Vector3<double> point3) : p1(point1), p2(point2), p3(point3) {
  
  sf::Vector3<double> vecAB = p2 - p1; //edge1
  sf::Vector3<double> vecAC = p3 - p1; //edge2
  normal = Vec3dMath::cross(vecAB, vecAC);
}

// annotations match up to wikipedia example of "Möller-Trumbore intersection algorithm"
IntersectionRecord* Triangle::intersect(Ray& ray) {

  sf::Vector3<double> vecAB = p2 - p1; //edge1
  sf::Vector3<double> vecAC = p3 - p1; //edge2

  sf::Vector3<double> origin = ray.origin;
  sf::Vector3<double> direction = ray.direction;

  sf::Vector3<double> cross = Vec3dMath::cross(direction, vecAC); //h

  // get determinate
  double det = Vec3dMath::dot(vecAB, cross); //a
  double inverseDet = 1.0 / det; //f

  if(det < 0.0001) return nullptr;

  sf::Vector3<double> rayPointVec = origin - p1; //s

  double test1 = Vec3dMath::dot(rayPointVec, cross); //u

  if(test1 < 0.0 || test1 > det) return nullptr;

  sf::Vector3<double> cross2 = Vec3dMath::cross(rayPointVec, vecAB); //q

  double test2 = Vec3dMath::dot(direction, cross2); //v

  if(test2 < 0.0 || test1 + test2 > det) return nullptr;

  sf::Vector3<double> distance = Vec3dMath::dot(vecAC, cross2);
  distance *= inverseDet;

  sf::Vector3<double> interPt = ray.origin + distance * ray.direction;
  
  return new IntersectionRecord(distance, interPt, normal, ray.direction);
}
