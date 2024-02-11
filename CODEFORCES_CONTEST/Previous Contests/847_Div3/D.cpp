#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int, std::greater<>> m;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    int cnt = 0;
    while (!m.empty())
    {
        auto [num, f] = *std::begin(m);
        m.erase(std::begin(m));
        int start = num;

        if (f - 1 > 0)
            m.emplace(start, f - 1);

        cnt++;

        while (m.contains(start - 1))
        {
            start--;
            m[start]--;

            if (m[start] == 0)
                m.erase(start);
        }
    }

    std::cout << cnt << "\n";
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