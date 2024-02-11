#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int m;
    std::cin >> m;

    std::vector<std::vector<int>> a(m);
    std::map<int, int> freq;
    for (int i = 0; i < m; i++)  
    {
        int n;
        std::cin >> n;
        a[i].resize(n);

        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
            freq[a[i][j]]++;
        }
    }

    std::vector<int> winner;
    std::map<int, int> done;
    for (int i = 0; i < m; i++)
    {
        for (auto x : a[i])
            done[x]++;

        for (auto x : a[i])
        {
            if (freq.contains(x) and freq[x] - done[x] == 0)
            {
                winner.emplace_back(x);
                break;
            }
        }

        if (std::size(winner) <= i)
        {
            std::cout << "-1\n";
            return;
        }

        freq.erase(winner.back());
    }

    for (int i = 0; i < m; i++)
        std::cout << winner[i] << " \n"[i == m - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}