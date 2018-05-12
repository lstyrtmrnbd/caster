#ifndef RAYCAST_HPP
#define RAYCAST_HPP

#include <iostream> //error checking
#include <cstddef>
#include <vector>
#include <cmath>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "vec3dmath.hpp"
#include "ray.hpp"
#include "object.hpp"
#include "intersectionrecord.hpp"
#include "light.hpp"


class RayCast {

  // "screen" is the viewing screen the rays are cast through
  //  its relationship to the actual rendering window is in shade()
  int screenWidth;
  int screenHeight;

  sf::Vector3<double> position;
  // distance between these two is the focal length
  sf::Vector3<double> screenPosition;
  //sf::Vector3<double> up;
  //sf::Vector3<double> right;

  std::vector<IntersectionRecord*> intersections;

public:

  sf::Color defaultColor = sf::Color::Black;
  
  RayCast();
  RayCast(int width, int height, sf::Vector3<double> pos, sf::Vector3<double> screenPos);

  ~RayCast();
  
  /**
   * takes the objects list and casts rays, 
   * populating the intersections list
   */
  void castRays(std::vector<Object*> &objList);

  /**
   * shade() parses the intersection records into color data
   * separate render resolution for supersampling: 
   *   [average the RGB data by rays per pixel]
   *   "as3.pdf" 1.Raytracing -Anti-aliasing
   */
  std::vector<sf::Uint8> * shade(std::vector<Light*> &lightList); 
};

#endif
