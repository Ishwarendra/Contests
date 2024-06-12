#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    int max = -1;
    int maxMask = 0;
    
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (getBit(mask, i))
                cnt++;
            else
            {
                sum += a[i];
                sum += cnt * cnt;
                cnt = 0;
            }
        }
            
        sum += cnt * cnt;
        if (sum > max)
        {
            max = sum;
            maxMask = mask;
        }
    }
    
    std::vector<std::pair<int, int>> change;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (getBit(maxMask, i))
            cnt++;
        else if (cnt)
        {
            change.emplace_back(i - cnt, i - 1);
            cnt = 0;
        }
    }
    
    if (cnt)
        change.emplace_back(n - cnt, n - 1);
    
    std::vector<std::pair<int, int>> ans;
    auto toMax = [&](auto &&f, int l, int r)
    {
        if (r <= l)
            return;
        
        f(f, l, r - 1); // now I have {0, 1, 2, ... aim - 2, 0}
        ans.push_back({l, r}); // {aim - 1, aim - 1, ...}
        ans.push_back({l, r - 1}); // {0, 0, 0, 0, ... aim - 1};
        f(f, l, r - 1); // {aim, aim, ...}
    };
    
    auto mex = [&](int l, int r)
    {
        std::set s(std::begin(a) + l, std::begin(a) + r + 1);
        int ans = 0;
        while (s.count(ans))  
            ans++;
        return ans;
    };
    
    for (auto &[l, r] : change)
    {
        // make all 0
        ans.push_back({l, r});
        if (mex(l, r) != 0)
            ans.push_back({l, r});
        
        // make all {0, 1, 2, 3...}
        toMax(toMax, l, r);
        
        ans.push_back({l, r});
    }
    
    std::cout << max << " " << std::size(ans) << "\n";
    for (auto &[l, r] : ans)
        std::cout << l + 1 << " " << r + 1 << '\n';

    
    return 0;
}