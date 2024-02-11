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
    std::string s;
    std::cin >> n >> s;

    std::array<int, 26> cnt{};
    for (auto ch : s)  
        cnt[ch - 'a']++;

    int max = *std::max_element(std::begin(cnt), std::end(cnt));
    if (max > n / 2 or n % 2)
        std::cout << "-1\n";
    else
    {
        int i = 0, j = n - 1;
        int problem = 0;

        cnt = std::array<int, 26>{};
        while (i < j)
        {
            if (s[i] == s[j])
            {
                problem++;
                cnt[s[i] - 'a']++;
            }
            i++, j--;
        }

        int sum = std::accumulate(std::begin(cnt), std::end(cnt), 0);
        max = *std::max_element(std::begin(cnt), std::end(cnt));
        
        if (max > sum - max)
        {
            int d = max - (sum - max);
            std::cout << d + (problem - d + 1) / 2 << "\n";
        }
        else
            std::cout << (problem + 1) / 2 << "\n";
    }
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