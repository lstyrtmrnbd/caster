#include "intersectionrecord.hpp"

IntersectionRecord::IntersectionRecord() {

}

IntersectionRecord::IntersectionRecord(double dist) : distance(dist) {

}

IntersectionRecord::IntersectionRecord(double dist, sf::Vector3<double> norm) :
  distance(dist), normal(norm) {

}

IntersectionRecord::IntersectionRecord(double dist, sf::Vector3<double> inter,
				       sf::Vector3<double> norm) :
  distance(dist), interpt(inter), normal(norm) {

}
