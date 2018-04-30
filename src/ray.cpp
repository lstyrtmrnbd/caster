#include "ray.hpp"

Ray::Ray() {

  origin = sf::Vector3<double>(0.0, 0.0, 0.0);
  direction = sf::Vector3<double>(0.0, 0.0, 0.0);
}

Ray::Ray(sf::Vector3<double> &ori, sf::Vector3<double> &dir) : origin(ori), direction(dir) {

}

void Ray::operator=(const Ray &ray) {
  origin = ray.origin;
  direction = ray.direction;
}
