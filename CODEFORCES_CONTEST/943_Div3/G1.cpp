#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> zFunction(const std::string &s)
{
    int n = std::size(s);
    std::vector<int> z(n);
    
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
        {
            if (z[i - l] + i <= r)
                z[i] = z[i - l];
            else
            {
                l = i;
                while (r < n and s[r - l] == s[r])
                    r++;
                r--;
                z[i] = r - l + 1;
            }
        }
        else
        {
            l = r = i;
            while (r < n and s[r - l] == s[r])
                r++;
            r--;
            z[i] = r - l + 1;
        }
    }
    
    return z;
}

void solve()
{   
    int n, l, r;
    std::string s;
    std::cin >> n >> l >> r >> s;
    
    auto Z = zFunction(s);
    
    auto good = [&](int len)
    {
        int cnt = 1, id = len;
        while (id + len <= n)
        {
            if (Z[id] >= len)
                cnt++, id += len;
            else
                id++;
        }
        
        return cnt >= l;
    };
    
    int left = 1, right = n;
    int ans = 0;
    while (left <= right)  
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }
    
    std::cout << ans << '\n';
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