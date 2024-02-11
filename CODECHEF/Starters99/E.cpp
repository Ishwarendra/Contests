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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<int> s1;

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    int ans = 0;

    std::function<void(std::vector<int>&, int)> f;
    f = [&](std::vector<int> &s2, int bit)
    {
        if (bit < 0)
            return;

        for (int i = 1; i < std::size(s2); i++)   
        {
            if (getBit(s2[i], bit) != getBit(s2[i - 1], bit))
            {
                ans |= (1 << bit);
                break;
            }
        }

        if (!getBit(ans, bit))
            f(s2, bit - 1);
        else
        {
            std::vector<int> temp;
            for (int x : s2)
            {
                if (getBit(x, bit))
                    s1.emplace_back(x);
                else
                    temp.emplace_back(x);
            }

            s2 = std::move(temp);
        }
    };

    f(a, 30);
    print(ans)
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