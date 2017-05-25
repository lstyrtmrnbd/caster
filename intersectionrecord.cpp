#include "intersectionrecord.hpp"

IntersectionRecord::IntersectionRecord() {

}

IntersectionRecord::IntersectionRecord(double dist) : distance(dist) {

}

IntersectionRecord::IntersectionRecord(double dist, sf::Vector3<double> norm) :
                                      distance(dist), normal(norm) {

}
