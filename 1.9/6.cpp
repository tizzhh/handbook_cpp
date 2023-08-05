#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x;
    int y;
};

int main(void) {
    int n;
    std::cin >> n;
    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::sort(points.begin(), points.end(), [](const Point &first, const Point &second) {
        return sqrt(first.x * first.x + first.y * first.y) < sqrt(second.x * second.x + second.y * second.y);
    });

    for (const auto &point : points) {
        std::cout << point.x << ' ' << point.y << '\n';
    }
}