#include "first_hit.h"
#include "Plane.h"
#include "Ray.h"
#include <iostream>

bool first_hit(
    const Ray &ray,
    const double min_t,
    const std::vector<std::shared_ptr<Object>> &objects,
    int &hit_id,
    double &t,
    Eigen::Vector3d &n)
{
  t = (double)INT_MAX;

  // check all objects in scene for intersection between ray and surface
  // get closest point hit
  for (int i = 0; i < objects.size(); i++)
  {
    Eigen::Vector3d n_temp;
    double t_temp;

    if (objects[i]->intersect(ray, min_t, t_temp, n_temp))
    {
      if (t_temp < t)
      {
        hit_id = i;
        // set t to be minimum distance hit
        t = t_temp;
        n = n_temp;
      }
    }
  }

  // return true if ray intersected something
  return t != (double)INT_MAX;
}
