#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b;
    std::cin >> a >> b;

    std::vector<std::array<int, 2>> dirs {{0, -1}, {0, 1}};
    int mat[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            mat[i][j] = i * 3 + j + 1;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j] != a)
                continue;

            for (auto [dx, dy] : dirs)
            {
                auto safe = [&](int x, int y) 
                {
                    return x >= 0 and x < 3 and y >= 0 and y < 3;
                };

                if (safe(i + dx, j + dy) and mat[i + dx][j + dy] == b)
                {
                    std::cout << "Yes";
                    return 0;
                }
            }
        }
    }

    std::cout << "No";
    
    return 0;
}