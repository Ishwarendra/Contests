#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * ans[i] <= root(n)
 *     Prefix of length <= root(n) can match
 *     For each prefix length find the count of equal substrings you can get
 * ans[i] > root(n) means that 
 *     we can divide string into i parts and each part has root(n) length common prefix
 *     Thus, n >= i * root(n) => i <= root(n)
 * 
 * If i <= root(n), brute force
 * If i > root(n), then length of prefix <= root(n) and cnt[length] >= i imply this is a possible answer
 */

std::vector<int> zFunction(const std::string &s)
{
    int n = std::size(s);
    std::vector<int> z(n);

    auto work = [&](int i, int &l, int &r)
    {
        while (r < n and s[r - l] == s[r])
            r++;
        r--;
        z[i] = r - l + 1;
    };

    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
        {
            if (z[i - l] + i <= r)
                z[i] = z[i - l];
            else
            {
                l = i;
                work(i, l, r);
            }
        }
        else
        {
            l = r = i;
            work(i, l, r);
        }
    }

    return z;
}

void solve()
{
    int n, l, r;
    std::cin >> n >> l >> r;
    l--, r--;

    std::string s;
    std::cin >> s;

    auto z = zFunction(s);
    int rootN = std::sqrt(n) + 2;
    rootN = std::min(rootN, n);
    
    std::vector<int> f(n);
    
    auto good = [&](int mid, int k)
    {
        int cnt = 1, i = mid;    
        while (i + mid <= n)
        {
            if (z[i] >= mid)
                i += mid, cnt++;
            else
                i++;
        }
        
        return cnt >= k;
    };

    for (int i = 0; i < rootN; i++)
    {
        int left = 1, right = n;
        int ans = 0;
        
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (good(mid, i + 1))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }
        
        f[i] = ans;
    }

    std::vector<int> cnt(rootN + 1);
    for (int len = 1; len <= rootN; len++)
    {
        int res = 1, i = len;
        while (i + len <= n)        
        {
            if (z[i] >= len)
                res++, i += len;
            else
                i++;
        }
        
        cnt[len] = res;
    }
    
    for (int i = rootN; i < n; i++)
    {
        for (int j = 1; j <= rootN; j++)
        {
            if (cnt[j] >= i + 1)
                f[i] = std::max(f[i], j);
        }
    }
    
    for (int i = l; i <= r; i++)
        std::cout << f[i] << " \n"[i == r];
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