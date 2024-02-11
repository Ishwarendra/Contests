#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e7 + 7;
constexpr int inf = 1e9;

// std::vector<int> isprime(N + 2, 1), minPrime(N + 2, inf);
// std::vector<i64> sum(N + 2, 1);
int minPrime[N + 2], ans[N + 2];
i64 sum[N + 2];
// std::map<i64, int> ans;

void solve()
{
    int c;
    std::cin >> c;

    // if (ans.contains(c))
    //     std::cout << ans[c] << "\n";
    // else
    //     std::cout << "-1\n";
    std::cout << ans[c] << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < N; ++i)
    {
        // isprime[i] = 1;
        sum[i] = 1;
        minPrime[i] = inf;
        ans[i] = -1;
    }

    minPrime[1] = 1;
    for (int i = 2; i * i < N; i++)
    {
        if (minPrime[i] == inf)
        {
            minPrime[i] = i;
            for (i64 j = 1LL * i * i; j < N; j += i)
            {
                assert(j >= 0 and j <= N);
                // minPrime[j] = std::min(minPrime[j], i);
                if (minPrime[j] == inf)
                    minPrime[j] = i;

                // isprime[j] = 0;
            }
        }
    }

    for (int i = 2; i < N; i++)
    {
        if (minPrime[i] == inf)
            sum[i] = i + 1;
        else
        {
            int num = i;
            while (num % minPrime[i] == 0 and num != 0)
            {
                num /= minPrime[i];
                sum[i] = sum[i] * minPrime[i] + 1;
            }

            if (num > 1)
                sum[i] *= sum[num];
        }
    }

    for (int i = N - 1; i > 0; i--)
    {
        if (sum[i] < N)
            ans[sum[i]] = i;
    }

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}