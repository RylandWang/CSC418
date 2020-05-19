#include "viewing_ray.h"
#include <iostream>

void viewing_ray(
    const Camera &camera,
    const int i,
    const int j,
    const int width,
    const int height,
    Ray &ray)
{

  // set e
  ray.origin = camera.e;

  // compute s, set direction s-e
  // u(i) - e[0]
  ray.direction[0] = (camera.width / width) * (j + 0.5 - width / 2);
  // v(j) - e[1]
  ray.direction[1] = (camera.height / height) * (height / 2 - i + 0.5 );
  // -d - e[2]
  ray.direction[2] = -camera.d;
}
