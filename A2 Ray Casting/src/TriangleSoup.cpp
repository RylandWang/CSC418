#include "TriangleSoup.h"
#include "Ray.h"
// Hint
#include "first_hit.h"
#include <iostream>

bool TriangleSoup::intersect(
    const Ray &ray, const double min_t, double &t, Eigen::Vector3d &n) const
{
  int id;
  bool hit = first_hit(ray, min_t, triangles, id, t, n);
  return hit;
}
