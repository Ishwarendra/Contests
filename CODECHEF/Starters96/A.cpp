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

    std::map<int, int> m;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    std::vector<int> b;
    int need = 0;
    while (!m.empty())
    {
        while (m.count(need))
        {
            m[need]--;
            if (m[need] == 0)
                m.erase(need);
            need++;
        }

        if (need == 0)
        {
            std::begin(m)->second--;
            if (std::begin(m)->second == 0)
                m.erase(std::begin(m));
        }

        b.emplace_back(need);
        need = 0;
    }

    std::cout << std::size(b) << "\n";
    for (int i = 0; i < std::size(b); i++)
        std::cout << b[i] << " \n"[i + 1 == std::size(b)];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}