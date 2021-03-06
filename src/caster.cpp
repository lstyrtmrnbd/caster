#include <iostream> //error checking

#include <SFML/Graphics.hpp>

#include "raycast.hpp"
#include "material.hpp"
#include "surface.hpp"
#include "sphere.hpp"
#include "triangle.hpp"
#include "plane.hpp"
#include "object.hpp"
#include "light.hpp"
#include "ambientlight.hpp"
#include "distantlight.hpp"
#include "pointlight.hpp"

const unsigned int width = 1280;
const unsigned int height = 720;
const double fov = 90.0;

// cleaner, but better to be explicit in all other cases
using Vec3 = sf::Vector3<double>;

int main() {

  sf::RenderWindow window(sf::VideoMode(width, height), "caster output");

  double focalLength = sqrt( ((width * width) + (height*height)) / (2 * tan(fov/4.0)) );
  
  Vec3 origin(0.0, 0.0, -focalLength);
  Vec3 viewLoc(0.0, 0.0, 0.0);
  
  RayCast* caster = new RayCast(width, height, origin, viewLoc);

  // prepare object list
  Vec3 white(1,1,1);
  Vec3 grey(0.5, 0.5, 0.5);
  Vec3 black(0,0,0);
  
  Vec3 red(1,0,0);
  Vec3 green(0,1,0);
  Vec3 blue(0,0,1);

  // Material(ambient, diffuse, specular, shininess)
  Material redMat(red, grey);
  Material greenMat(green, grey, grey, 4);
  Material blueMat(blue, grey, white, 8);
  Material greyMat(grey, white);
  Material lightGreyMat(Vec3(.75,.75,.75), white, white, 2);
  
  Sphere leftSphere(Vec3(-256, 0, 0), 128.0);
  Sphere rightSphere(Vec3(256, 0, 0), 128.0);
  Sphere centerSphere(Vec3(0, 0, 0), 128.0);
  Plane basePlane(Vec3(0, 256, 0), Vec3(0, 1, .1));

  Triangle testTri(Vec3(0, -256 - 64, 0), Vec3(-256, 0, 0), Vec3(256, 0, 0));
  
  std::vector<Surface*> leftSurfaces(1, &leftSphere);
  std::vector<Surface*> rightSurfaces(1, &rightSphere);
  std::vector<Surface*> centerSurfaces(1, &centerSphere);
  std::vector<Surface*> baseSurfaces(1, &basePlane);
  //rightSurfaces.push_back(&testTri);
  std::vector<Surface*> triSurfaces(1, &testTri);
  
  Object redSphere(leftSurfaces, &redMat);
  Object greenSphere(centerSurfaces, &greenMat);
  Object blueSphere(rightSurfaces, &blueMat);
  Object greyPlane(baseSurfaces, &greyMat);
  Object greenTri(triSurfaces, &lightGreyMat);

  std::vector<Object*> objList {&redSphere, &greenSphere, &blueSphere, &greyPlane, &greenTri};
  
  // perform casting
  caster->castRays(objList);

  // prepare light list
  AmbientLight ambient(Vec3(0.25, 0.25, 0.25));
  DistantLight distant(Vec3(0.5, 0.5, 0.5), Vec3(0, 0.75, 0.25));
  PointLight point(Vec3(5120,5120,5120), Vec3(-128, 132, -128));
  PointLight point2(Vec3(10240,10240,10240), Vec3(128, 132, -128));
  
  std::vector<Light*> lightList { &ambient, &distant, &point, &point2 };

  // perform shading
  std::vector<sf::Uint8> *colorBuffer = caster->shade(lightList);

  sf::Uint8 *pixels = colorBuffer->data();

  // prepare drawing
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
