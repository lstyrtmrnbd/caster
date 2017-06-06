
caster: *.cpp
	g++ -ggdb -Wall -Wextra caster.cpp raycast.cpp vec3dmath.cpp ray.cpp object.cpp material.cpp sphere.cpp plane.cpp intersectionrecord.cpp ambientlight.cpp distantlight.cpp pointlight.cpp -o caster.bin -lsfml-system -lsfml-window -lsfml-graphics
