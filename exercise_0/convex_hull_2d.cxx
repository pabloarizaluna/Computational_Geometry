#include <iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>

#include <vector>
#include <random>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;

int main() {
  //Point_2 points[5] = { Point_2(0,0), Point_2(10,0), Point_2(10,10), Point_2(6,5), Point_2(4,1) };
  std::vector<Point_2> points, result;
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(1, 5000000);

  for(int i = 0; i < 100000; i++) {
    points.push_back(Point_2(dist(rng), dist(rng)));
  }

  CGAL::convex_hull_2( points.begin(), points.end(), std::back_inserter(result));
  std::cout << result.size() << " points on the conves hull: \n";
  for(auto &point : result) {
    std::cout << point << "\n";
  }
  return 0;
}
