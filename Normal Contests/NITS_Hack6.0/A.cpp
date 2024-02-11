#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

auto multiply(auto a, auto b, const auto MOD)
{
    int n1 = std::size(a);
    int m1 = std::size(a[0]);
    int n2 = std::size(b);
    int m2 = std::size(b[0]);

    assert(m1 == n2);
    std::vector res(n1, std::vector<i64>(m2));
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < m1; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }

    return res;
}

auto power(auto a, auto b, const int MOD) 
{
    auto res = a;

    for (; b; b /= 2, a = multiply(a, a, MOD)) 
    {
        if (b % 2) 
            res = multiply(res, a, MOD);
    }
    return res;
}

constexpr int MOD = 1e9 + 7;
int get(int a, int x)
{
    std::vector<std::vector<i64>> A {{a, 1}, {0, 1}};
    std::vector<std::vector<i64>> B {{0}, {1}};

    A = power(A, x - 1, MOD);
    B = multiply(A, B, MOD);
    return B[0][0];
}

void solve()
{
    int x;
    std::cin >> x;

    std::cout << (1LL * 3 * get(10, x)) % MOD << "\n";
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