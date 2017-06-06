#include <iostream> //error checking

#include <SFML/Graphics.hpp>

#include "raycast.hpp"
#include "material.hpp"
#include "surface.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "object.hpp"
#include "light.hpp"
#include "ambientlight.hpp"
#include "distantlight.hpp"
#include "pointlight.hpp"

const unsigned int width = 1280;
const unsigned int height = 720;
const double fov = 90.0;

int main() {

  sf::RenderWindow window(sf::VideoMode(width, height), "caster output");

  double focalLength = sqrt( ((width * width) + (height*height)) / (2 * tan(fov/4.0)) );
  
  sf::Vector3<double> origin(0.0, 0.0, -focalLength);
  sf::Vector3<double> viewLoc(0.0, 0.0, 0.0);
  
  RayCast* caster = new RayCast(width, height, origin, viewLoc);

  //prepare object list
  sf::Vector3<double> red(1.0, 0.0, 0.0);
  sf::Vector3<double> green(0.0, 1.0, 0.0);
  sf::Vector3<double> blue(0.0, 0.0, 1.0);
  sf::Vector3<double> grey(0.5, 0.5, 0.5);

  sf::Vector3<double> fullDiff(1,1,1);
  sf::Vector3<double> medDiff(0.5, 0.5, 0.5);
  sf::Vector3<double> noDiff(0,0,0);
  
  sf::Vector3<double> redDiff(1,0,0);
  sf::Vector3<double> greenDiff(0,1,0);
  sf::Vector3<double> blueDiff(0,0,1);
  
  Material redMat(red, medDiff);
  Material greenMat(green, medDiff);
  Material blueMat(blue, medDiff);
  Material greyMat(grey, medDiff);
  
  Sphere leftSphere(sf::Vector3<double>(-256, 0, 0), 128.0);
  Sphere rightSphere(sf::Vector3<double>(256, 0, 0), 128.0);
  Sphere centerSphere(sf::Vector3<double>(0, 0, 0), 128.0);
  Plane basePlane(sf::Vector3<double>(0, 256, 0), sf::Vector3<double>(0, 1, .1));
  
  std::vector<Surface*> leftSurfaces(1, &leftSphere);
  std::vector<Surface*> rightSurfaces(1, &rightSphere);
  std::vector<Surface*> centerSurfaces(1, &centerSphere);
  std::vector<Surface*> baseSurfaces(1, &basePlane);
  
  Object redSphere(leftSurfaces, &redMat);
  Object greenSphere(centerSurfaces, &greenMat);
  Object blueSphere(rightSurfaces, &blueMat);
  Object greyPlane(baseSurfaces, &greyMat);

  std::vector<Object*> objList {&redSphere, &greenSphere, &blueSphere, &greyPlane};
  
  //perform casting
  caster->castRays(objList);

  //prepare light list
  AmbientLight ambient(sf::Vector3<double>(0.25, 0.25, 0.25));
  DistantLight distant(sf::Vector3<double>(0.5, 0.5, 0.5), sf::Vector3<double>(0, 0.75, 0.25));
  PointLight point(sf::Vector3<double>(5120,5120,5120), sf::Vector3<double>(-128, 132, -128));
  PointLight point2(sf::Vector3<double>(10240,10240,10240), sf::Vector3<double>(128, 132, -128));
  
  std::vector<Light*> lightList { &ambient, &distant, &point, &point2 };

  //perform shading
  std::vector<sf::Uint8> *colorBuffer = caster->shade(lightList);

  sf::Uint8 *pixels = colorBuffer->data();

  //prepare drawing
  sf::Texture texture;
  if(!texture.create(width, height)) {

    std::cout << "Texture creation failed\n";
    return -1;
  }
  
  texture.update(pixels);

  sf::Sprite sprite(texture);
  
  while (window.isOpen()) {

    sf::Event event;

    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed) {
	window.close();
      }
      
      //different from default fill color to check that texture is drawn in all cases
      window.clear(sf::Color::Magenta);
    
      window.draw(sprite);

      window.display();
    }
  }

  delete[] pixels;
  
  return 0;
}
