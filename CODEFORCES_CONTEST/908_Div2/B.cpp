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
    std::map<int, int> freq;
     
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        freq[a[i]]++;
    }

    std::vector<int> valid;
    for (auto &[num, f] : freq)
    {
        if (f > 1)
            valid.emplace_back(num);
    }
    
    for (auto x : valid)
    {
        for (auto y : valid)
        {
            if (x == y)
                continue;

            std::vector<int> ans;

            for (int i = 0; i < n; i++)
            {
                if (a[i] == x)
                {
                    ans.emplace_back(freq[x] > 1 ? 1 : 2);
                    freq[x]--;
                }
                else if (a[i] == y)
                {
                    ans.emplace_back(freq[y] > 1 ? 2 : 3);
                    freq[y]--;
                }
                else
                    ans.emplace_back(3);
            }

            if (std::count(std::begin(ans), std::end(ans), 3))
            {
                for (int i = 0; i < n; i++)
                    std::cout << ans[i] << " \n"[i == n - 1];

                return;
            }
        }
    }

    std::cout << "-1\n";
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