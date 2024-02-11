#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

using namespace std;

// Utility function to find cross product
// of two vectors
int CrossProduct(vector<vector<int> >& A)
{
    // Stores coefficient of X
    // direction of vector A[1]A[0]
    int X1 = (A[1][0] - A[0][0]);

    // Stores coefficient of Y
    // direction of vector A[1]A[0]
    int Y1 = (A[1][1] - A[0][1]);

    // Stores coefficient of X
    // direction of vector A[2]A[0]
    int X2 = (A[2][0] - A[0][0]);

    // Stores coefficient of Y
    // direction of vector A[2]A[0]
    int Y2 = (A[2][1] - A[0][1]);

    // Return cross product
    return (X1 * Y2 - Y1 * X2);
}

// Function to check if the polygon is
// convex polygon or not
bool isConvex(vector<vector<int> >& points)
{
    // Stores count of
    // edges in polygon
    int N = points.size();

    // Stores direction of cross product
    // of previous traversed edges
    int prev = 0;

    // Stores direction of cross product
    // of current traversed edges
    int curr = 0;

    // Traverse the array
    for (int i = 0; i < N; i++) {

        // Stores three adjacent edges
        // of the polygon
        vector<vector<int> > temp
        = { points[i],
            points[(i + 1) % N],
            points[(i + 2) % N]
          };

        // Update curr
        curr = CrossProduct(temp);

        // If curr is not equal to 0
        if (curr != 0) {

            // If direction of cross product of
            // all adjacent edges are not same
            if (curr * prev < 0) {
                return false;
            }
            else {
                // Update curr
                prev = curr;
            }
        }
    }
    return true;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> points;

    for (int i = 0; i < 4; ++i)
    {
        int a, b;
        std::cin >> a >> b;

        points.push_back({a, b});
    }

    std::cout << (isConvex(points) ? "Yes\n" : "No\n");

    return 0;
}