#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <SFML/System.hpp>

#include "surface.hpp"
#include "vec3dmath.hpp"

class Triangle : public Surface {

public:

  sf::Vector3<double> p1, p2, p3, normal;

  Triangle(sf::Vector3<double> point1, sf::Vector3<double> point2, sf::Vector3<double> point3);

  IntersectionRecord* intersect(Ray&);
}

#endif // TRIANGLE_HPP
