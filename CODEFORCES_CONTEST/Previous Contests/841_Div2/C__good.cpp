#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) 
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const 
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(std::pair<L,R> const& Y) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

// std::multiset<i64> psq;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), p(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (i == 0)
            p[i] = a[i];
        else
            p[i] = (p[i - 1] ^ a[i]);
    }

    std::vector<i64> dp(n + 1);
    
    auto f = [&](int x)
    {
        if (x == 0 or x == 1 or x == 4)
            return true;
        int i = 3, j = x;
        while (i <= j)
        {
            int mid = (i + j) >> 1;
            if (1LL * mid * mid == x)
                return true;
            else if (1LL * mid * mid < x)
                i = mid + 1;
            else
                j = mid - 1;
        }

        return false;
    };

    dp[0] = f(a[0]);

    std::unordered_map<i64, int, custom_hash> m;
    m[a[0]]++;
    m[0]++;

    for (int i = 1; i < n; i++)
    {
        int xr = p[i];
        dp[i] = dp[i - 1];
 
        for (i64 j = 0; j * j <= 4 * n; j++)
        {
            int x = ((j * j) ^ xr);
            dp[i] += m[x];
        }
 
        m[xr]++;
    }
    
    i64 tot = 1LL * n * (n + 1) / 2;
    std::cout << tot - dp[n - 1] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // i64 x = 0;
    // while (x * x <= 4e5)
    //     psq.emplace(x * x), x++;

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}