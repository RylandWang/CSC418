#include "Sphere.h"
#include "Ray.h"
#include <iostream>

bool Sphere::intersect(
    const Ray &ray, const double min_t, double &t, Eigen::Vector3d &n) const
{
  // Ray-Sphere intersection formula:
  // compute a, b, and c for quadratic formula
  const double a = ray.direction.dot(ray.direction);
  const double b = (2 * ray.direction).dot(ray.origin - center);
  const double c = (ray.origin - center).dot(ray.origin - center) - radius * radius;

  // apply quadratic formula and compute discriminant
  double discriminant = b * b - 4 * a * c;
  // no real solutions, ie no intersection
  if (discriminant < 0)
  {
    return false;
  }
  // 1 intersection
  else if (discriminant == 0)
  {
    t = (-b + sqrt(discriminant)) / (2 * a);
  }
  // 2 intersections
  // in this case pick pick the closest intersection point to the camera
  else
  {
    double t1 = (-b + sqrt(discriminant)) / (2 * a);
    double t2 = (-b - sqrt(discriminant)) / (2 * a);
    t = t1 < t2 ? t1 : t2;
  }

  if (t < min_t)
  {
    return false;
  }
  //point of intersection between ray and sphere
  Eigen::Vector3d intersection = ray.direction * t + ray.origin;
  // unit normal vector (perpendicular to surface), ie pointing in opposite direction of center
  n = (intersection - center) / radius;
  return true;
}
