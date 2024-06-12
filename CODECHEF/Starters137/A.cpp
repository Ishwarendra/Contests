#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> x(n), p(n);
    for (int i = 0; i < n; i++)
        std::cin >> x[i];
    for (int i = 0; i < n; i++)
        std::cin >> p[i];

    int pref = 0, suff = n - 1;
    while (pref < n - 1 and p[pref + 1] >= x[pref + 1] - x[pref])
        pref++;
    while (suff > 0 and p[suff - 1] >= x[suff] - x[suff - 1])
        suff--;
    
    int pref2 = 0, suff2 = n - 1;
    while (pref2 < n - 1 and x[pref2] + p[pref2] <= x[pref2 + 1])
        pref2++;
    while (suff2 > 0 and x[suff2] - p[suff2] <= x[suff2 - 1])
        suff2--;
    
    auto coverRight = [&](int id)
    {   
        if (id >= n)
            return x.back();
        
        int ans = x[id];
        for (int i = id; i < n - 1; i++)  
        {
            if (x[i] + p[i] >= x[i + 1])
                ans = x[i + 1];
            else
            {
                ans = x[i] + p[i];
                break;
            }
        }
        
        return ans;
    };
    
    auto coverLeft = [&](int id)
    {
        if (id <= 0)
            return x.front();
        
        int ans = x[id];
        for (int i = id; i > 0; i--)  
        {
            if (x[i] - p[i] <= x[i - 1])
                ans = x[i - 1];
            else
            {
                ans = x[i] - p[i];
                break;
            }
        }
        
        return ans;
    };

    if (suff - pref <= 1)
        std::cout << "YES\n";
    else
    {
        int zero_right = coverRight(0);
        int id0 = std::upper_bound(std::begin(x), std::end(x), zero_right) - std::begin(x);
        
        int last_left = coverLeft(n - 1);
        int id1 = std::lower_bound(std::begin(x), std::end(x), last_left) - std::begin(x) - 1;

        if (suff <= id0 or pref >= id1 or last_left <= (id0 >= n ? x.back() : x[id0]))
            std::cout << "YES\n";
        else if (coverRight(id0) >= x.back() or coverLeft(id1) <= x.front())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
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