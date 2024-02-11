#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

const std::string _ = "MEX";
int f(char ch) { return std::find(std::begin(_), std::end(_), ch) - std::begin(_); }

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::string s;
    std::cin >> s;

    // upto index i how many times f(ch) had value x
    std::vector cnt(n, std::vector(3, std::array<i64, 3>()));
    for (int i = 0; i < n; i++)
        cnt[i][f(s[i])][a[i]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
                cnt[i][j][k] += cnt[i - 1][j][k];
        }
    }

    auto get = [&](int l, int r, char ch, int i)
    {
        if (l < 0 or r >= n or l > r or f(ch) >= 3)
            return 0LL;

        i64 ans = 0;
        ans += cnt[r][f(ch)][i];
        if (l - 1 >= 0)
            ans -= cnt[l - 1][f(ch)][i];

        return ans;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != 'E')
            continue;

        for (int p = 0; p < 3; p++)
        {
            for (int q = 0; q < 3; q++)
            {
                std::array<int, 3> m_{};
                m_[a[i]] = 1, m_[p] = 1, m_[q] = 1;                
                i64 cnt = get(0, i - 1, 'M', p);
                cnt *= get(i + 1, n - 1, 'X', q);

                int mex = 0;
                while (mex < 3 and m_[mex])
                    mex++;

                ans += cnt * mex;
            }
        }

    }

    std::cout << ans;

    return 0;
}