#include "Plane.h"
#include "Ray.h"
#include <iostream>

bool Plane::intersect(
    const Ray &ray, const double min_t, double &t, Eigen::Vector3d &n) const
{
  // solve for t using system of linear equations of intersection
    double temp_t = (-normal).dot(ray.origin - point) / normal.dot(ray.direction);
    if (temp_t < min_t) {
      return false;
    }
    else {
      t = temp_t;
      n = normal;
      return true;
    }
}