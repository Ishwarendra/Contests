#include <bits/stdc++.h>

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
    
    std::vector<std::vector<int>> row{
        {7}, {4}, {8, 2}, {5, 1}, {9, 3}, {6}, {10}
    };

    for (auto &p : row)
        for (auto &ele : p)
            ele--;

    int n = std::size(row);
    std::string s;
    std::cin >> s;

    if (s[0] == '1')
    {
        std::cout << "No\n";
        return 0;
    }

    auto oneStanding = [&](int i)
    {
        bool ans = false;
        for (auto id : row[i])
        {
            if (s[id] == '1')
                ans = true;
        }

        return ans;
    };  

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            for (int k = i + 1; k < j; k++)
            {
                if (oneStanding(i) and oneStanding(j) and !oneStanding(k))
                {
                    std::cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    std::cout << "No\n";
    
    return 0;
}