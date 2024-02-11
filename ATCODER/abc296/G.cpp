#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

using namespace std;

template <class F>
struct Point {
    F x, y;
    Point() : x(0), y(0) {}
    Point(const F& x, const F& y) : x(x), y(y) {}

    void swap(Point& other) { using std::swap; swap(x, other.x); swap(y, other.y); }
    template <class F1> explicit operator Point<F1> () const {
        return Point<F1>(static_cast<F1>(x), static_cast<F1>(y));
    }
    template <class F1> Point& operator = (const Point<F1>& other) {
        x = other.x; y = other.y; return *this;
    }
    template <class F1> Point& operator += (const Point<F1>& other) {
        x += other.x; y += other.y; return *this;
    }
    template <class F1> Point& operator -= (const Point<F1>& other) {
        x -= other.x; y -= other.y; return *this;
    }
    template <class F1> Point& operator *= (const F1& factor) {
        x *= factor; y *= factor; return *this;
    }
    template <class F1> Point& operator /= (const F1& factor) {
        x /= factor; y /= factor; return *this;
    }
};

template <class F> int read(Point<F>& point) { return read(point.x, point.y) / 2; }
template <class F> int write(const Point<F>& point) { return write(point.x, point.y); }

template <class F> istream& operator >> (istream& is, Point<F>& point) {
    return is >> point.x >> point.y;
}
template <class F> ostream& operator << (ostream& os, const Point<F>& point) {
    return os << point.x << ' ' << point.y;
}

template <class F> inline Point<F> makePoint(const F& x, const F& y) { return Point<F>(x, y); }
template <class F> void swap(Point<F>& lhs, Point<F>& rhs) { lhs.swap(rhs); }

#define FUNC1(name, arg, expr) \
template <class F> inline auto name(const arg) -> decltype(expr) { return expr; }
#define FUNC2(name, arg1, arg2, expr) \
template <class F1, class F2> \
inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; }
#define FUNC3(name, arg1, arg2, arg3, expr) \
template <class F1, class F2, class F3> \
inline auto name(const arg1, const arg2, const arg3) -> decltype(expr) { return expr; }

FUNC1(operator -, Point<F>& point, makePoint(-point.x, -point.y))
FUNC2(operator +, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
FUNC2(operator -, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x - rhs.x, lhs.y - rhs.y))
FUNC2(operator *, F1& factor, Point<F2>& rhs, makePoint(factor * rhs.x, factor * rhs.y))
FUNC2(operator *, Point<F1>& lhs, F2& factor, makePoint(lhs.x * factor, lhs.y * factor))
FUNC2(operator /, Point<F1>& lhs, F2& factor, makePoint(lhs.x / factor, lhs.y / factor))

FUNC2(operator *, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.x + lhs.y * rhs.y)
FUNC2(operator ^, Point<F1>& lhs, Point<F2>& rhs, lhs.x * rhs.y - lhs.y * rhs.x)

// < 0 if rhs <- lhs counter-clockwise, 0 if collinear, > 0 if clockwise.
FUNC2(ccw, Point<F1>& lhs, Point<F2>& rhs, rhs ^ lhs)
FUNC3(ccw, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin, ccw(lhs - origin, rhs - origin))

FUNC2(operator ==, Point<F1>& lhs, Point<F2>& rhs, lhs.x == rhs.x && lhs.y == rhs.y)
FUNC2(operator !=, Point<F1>& lhs, Point<F2>& rhs, !(lhs == rhs))

FUNC2(operator <, Point<F1>& lhs, Point<F2>& rhs, lhs.y < rhs.y || (lhs.y == rhs.y && lhs.x < rhs.x))
FUNC2(operator >, Point<F1>& lhs, Point<F2>& rhs, rhs < lhs)
FUNC2(operator <=, Point<F1>& lhs, Point<F2>& rhs, !(lhs > rhs))
FUNC2(operator >=, Point<F1>& lhs, Point<F2>& rhs, !(lhs < rhs))

// Angles and rotations (counter-clockwise).
FUNC1(angle, Point<F>& point, atan2(point.y, point.x))
FUNC2(angle, Point<F1>& lhs, Point<F2>& rhs, atan2(lhs ^ rhs, lhs * rhs))
FUNC3(angle, Point<F1>& lhs, Point<F2>& rhs, Point<F3>& origin,
      angle(lhs - origin, rhs - origin))
FUNC3(rotate, Point<F1>& point, F2& angleSin, F3& angleCos,
      makePoint(angleCos * point.x - angleSin * point.y,
                angleSin * point.x + angleCos * point.y))
FUNC2(rotate, Point<F1>& point, F2& angle, rotate(point, sin(angle), cos(angle)))
FUNC3(rotate, Point<F1>& point, F2& angle, Point<F3>& origin,
      origin + rotate(point - origin, angle))
FUNC1(perp, Point<F>& point, makePoint(-point.y, point.x))

// Distances.
FUNC1(abs, Point<F>& point, point * point)
FUNC1(norm, Point<F>& point, sqrt(abs(point)))
FUNC2(dist, Point<F1>& lhs, Point<F2>& rhs, norm(lhs - rhs))
FUNC2(dist2, Point<F1>& lhs, Point<F2>& rhs, abs(lhs - rhs))
FUNC2(bisector, Point<F1>& lhs, Point<F2>& rhs, lhs * norm(rhs) + rhs * norm(lhs))


template <class F> using Polygon = vector<Point<F>>;
inline int prev(int i, int n) { return i == 0 ? n - 1 : i - 1; }
inline int next(int i, int n) { return i == n - 1 ? 0 : i + 1; }
template <class T> inline int sgn(const T& x) { return (T(0) < x) - (x < T(0)); }

template <class F>
bool orientation(const Polygon<F>& poly) {
    int n = static_cast<int>(poly.size());
    int i = static_cast<int>(min_element(begin(poly), end(poly)) - begin(poly));
    return ccw(poly[prev(i, n)], poly[next(i, n)], poly[i]) > 0;
}

template <class F1, class F2>
int pointVsConvexPolygon(const Point<F1>& point, const Polygon<F2>& poly, int top) {
    if (point < poly[0] || point > poly[top]) return 1;
    auto orientation = ccw(point, poly[top], poly[0]);
    if (orientation == 0) {
        if (point == poly[0] || point == poly[top]) return 0;
        return top == 1 || top + 1 == poly.size() ? 0 : -1;
    } else if (orientation < 0) {
        auto itRight = lower_bound(begin(poly) + 1, begin(poly) + top, point);
        return sgn(ccw(itRight[0], point, itRight[-1]));
    } else {
        auto itLeft = upper_bound(poly.rbegin(), poly.rend() - top - 1, point);
        return sgn(ccw(itLeft == poly.rbegin() ? poly[0] : itLeft[-1], point, itLeft[0]));
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    Polygon<i64> points(n);

    for (int i = 0; i < n; i++)
        std::cin >> points[i];

    // std::sort(std::begin(points), std::end(points));

    int q;
    std::cin >> q;

    while (q--)
    {
        Point<i64> p;
        std::cin >> p;

        int ans = pointVsConvexPolygon(p, points, 3);
        if (ans == 0)
            std::cout << "ON\n";
        else if (ans == 1)
            std::cout << "OUT\n";
        else
            std::cout << "IN\n";
    }


    return 0;
}