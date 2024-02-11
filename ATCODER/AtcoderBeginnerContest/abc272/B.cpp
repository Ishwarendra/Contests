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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> yes(n, std::vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        int len;
        std::cin >> len;

        std::vector<int> people(len);

        for (int j = 0; j < len; j++)
        {
            std::cin >> people[j];
            people[j]--;
        }

        for (int x = 0; x < len; x++)
        {
            for (int y = x + 1; y < len; y++)
                yes[people[x]][people[y]] = 1;
        }
    }
        
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!yes[i][j])
            {
                std::cout << "No\n";
                std::exit(0);
            }
        }
    }

    std::cout << "Yes\n";
    
    return 0;
}