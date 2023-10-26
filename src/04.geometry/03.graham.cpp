#include <algorithm>
#include <iostream>
#include <vector>

struct point {
  int x, y;
};

point operator-(point a, point b) { return {a.x - b.x, a.y - b.y}; }

bool operator==(point a, point b) { return (a.x == b.x) && (a.y == b.y); }

int operator^(point a, point b) { return a.x * b.y - a.y * b.x; }

bool comp(point &a, point &b) {
  return ((a ^ b) > 0) ||
         ((a ^ b) == 0 && a.x * a.x + a.y * a.y > b.x * b.x + b.y * b.y);
}

std::vector<point> graham(std::vector<point> points) {
  point p0 = points[0];
  for (point p : points) {
    if (p.y < p0.y || (p.y == p0.y && p.x > p0.x)) {
      p0 = p;
    }
  }

  for (point &p : points) {
    p.x -= p0.x;
    p.y -= p0.y;
  }

  std::sort(points.begin(), points.end(), comp);

  std::vector<point> hull;
  for (point p : points) {
    while (hull.size() >= 2 &&
           ((p - hull.back()) ^ (hull[hull.size() - 2] - hull.back())) <= 0) {
      hull.pop_back();
    }
    hull.push_back(p);
  }

  for (point &p : hull) {
    p.x += p0.x;
    p.y += p0.y;
  }

  return hull;
}

int main() {
  std::vector<point> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  std::vector<point> hull = graham(points);

  for (point p : hull) {
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
  }

  return 0;
}
