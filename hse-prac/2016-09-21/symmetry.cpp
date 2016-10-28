#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

struct Point;
struct PointHash;
typedef std::vector<Point> PointsCollection;
typedef std::unordered_map<Point, int, PointHash> PointMap;

struct Point {
    int x, y;
    Point() {
        x = y = 0;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    
    bool operator == (const Point &other) const {
        return (x == other.x) && (y == other.y);
    }
    std::istream& in(std::istream &input) {
        return input >> x >> y;
    }
    std::ostream& out(std::ostream &output) {
        return output << x << y;
    }
    Point reflect(double axis) const {
        return Point(2 * axis - x, y);
    }
};

PointsCollection InputPoints() {
    int amountOfPoints;
    std::cin >> amountOfPoints;
    PointsCollection points(amountOfPoints);
    for (auto & point : points) {
        point.in(std::cin);
    }
    return points;
}

bool ComparePointsWithXCoords(const Point &one, const Point &other) {
    return one.x < other.x;
}

struct PointHash {
    size_t operator () (const Point &p) const {
        return p.x ^ (p.y & p.x << 5);
    }
};

bool FindAxisOfSymmetry(PointsCollection &points, double &axis) {
    long long minXCoord = min_element(points.begin(), points.end(), ComparePointsWithXCoords)->x;
    long long maxXCoord = max_element(points.begin(), points.end(), ComparePointsWithXCoords)->x;
    axis = (static_cast<double> (minXCoord) + maxXCoord) / 2;
    PointMap map;
    for (auto &point : points) {
        ++map[point];
        --map[point.reflect(axis)];
    }
    for (auto &item : map) {
        if (item.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    auto points = InputPoints();
    double axis = 0;
    bool hasAxis = FindAxisOfSymmetry(points, axis);
    if (!hasAxis) {
        std::cout << "There are no axes\n";
    } else {
        std::cout << "There is an axis with x-coord " << axis << std::endl;
    }
}
