#include "Triangle.h"
#include "Ray.h"
#include <iostream>
#include <Eigen/Dense>

bool Triangle::intersect(
    const Ray &ray, const double min_t, double &t, Eigen::Vector3d &n) const
{
    // intersection with triangle
    // solve for linear system e = at1 + bt2 - td
    // [a, b, t] = [t1, t2, -d]^-1 * e

    // get vertices of triangle
    Eigen::Vector3d p1 = std::get<0>(corners);
    Eigen::Vector3d p2 = std::get<1>(corners);
    Eigen::Vector3d p3 = std::get<2>(corners);

    // t1 and t2 are vectors that define the triangle
    Eigen::Vector3d t1 = p1 - p2;
    Eigen::Vector3d t2 = p1 - p3;

    // apply Cramer's rule on linear system of intersection to find t, alpha, and beta
    // (reference: COmputer Graphics Fundatmentals page 79)
    Eigen::Matrix3d M;
    M.col(0) = t1;
    M.col(1) = t2;
    M.col(2) = p1 - ray.origin;

    Eigen::Matrix3d A;
    A.col(0) = t1;
    A.col(1) = t2;
    A.col(2) = ray.direction;

    t = M.determinant() / A.determinant();

    if (t < min_t)
    {
        return false;
    }
    else
    {
        Eigen::Matrix3d M2;
        M2.col(0) = t1;
        M2.col(1) = p1 - ray.origin;
        M2.col(2) = ray.direction;

        double alpha = M2.determinant() / A.determinant();
        if (alpha < 0 || alpha > 1)
        {
            return false;
        }

        Eigen::Matrix3d M3;
        M3.col(0) = p1 - ray.origin;
        M3.col(1) = t2;
        M3.col(2) = ray.direction;

        double beta = M3.determinant() / A.determinant();
        if (beta < 0 || beta > (1 - alpha))
        {
            return false;
        }

        // surface normal
        Eigen::Vector3d t1_cross_t2 = t1.cross(t2);
        n = t1_cross_t2 / t1_cross_t2.norm();
        return true;
    }
}
