#include "bits/stdc++.h"

#undef LOCAL

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::string s;
    std::cin >> n >> m >> s; 

    std::vector<int> p(n);   
    p[0] = s[0] == '1';
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + (s[i] == '1');

    auto sum = [&](int i, int j)
    {
        if (j < i)
            return 0;

        int ans = p[j];
        if (i)
            ans -= p[i - 1];
        return ans;
    };

    std::vector<std::array<int, 2>> qry(m);
    for (int i = 0; i < m; i++)
    {
        std::cin >> qry[i][0] >> qry[i][1];
        qry[i][0]--, qry[i][1]--;
    }

    std::sort(std::begin(qry), std::end(qry));
    qry.erase(std::unique(std::begin(qry), std::end(qry)), std::end(qry));
    m = std::size(qry);

    std::sort(std::begin(qry), std::end(qry), [&](auto x, auto y)
    {
        return x[1] < y[1];
    });

    auto isSorted = [&](int i, int j)
    {
        if (i >= j)
            return true;

        int one = sum(i, j);
        return sum(j - one + 1, j) == one;
    };

    auto intersect = [&](int a, int b, int c, int d)
    {
        int cond1 = a <= c and c <= b;
        int cond2 = c <= a and a <= d;
        return cond1 or cond2;
    };

    std::vector<int> lastZero(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '0')
            lastZero[i] = i - 1;
        else
            lastZero[i] = lastZero[i - 1];
    }

    int ans = 0;
    int sorted = 0;

    std::vector<std::array<int, 2>> prev;
    for (auto &[L, R] : qry)
    {
        if (isSorted(L, R))
            ans += !sorted, sorted = 1;
        else
        {
            int ok = 1;

            auto it = std::lower_bound(std::begin(prev), std::end(prev), lastZero[R + 1], 
                [&](const std::array<int, 2> &x, int minR)
            {
                return x[1] < minR;
            });
            if (it != std::end(prev))
            {
                print(*it, lastZero[R + 1]);
            }
            else
                print("end", lastZero[R + 1], prev)

            for (; it != std::end(prev); it++)
            {
                auto [l, r] = *it;
                if (intersect(L, R, l, r))
                {
                    auto [a, c] = std::minmax(l, L);
                    auto [b, d] = std::minmax(r, R);
                    if (sum(a, c - 1) == 0 and sum(b + 1, d) == d - b)
                    {
                        ok = 0;
                        break;
                    }
                }
            }

            if (ok)
                ans++;
            prev.push_back({L, R});
        }
        print(ans)
    }

    std::cout << ans << "\n";
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