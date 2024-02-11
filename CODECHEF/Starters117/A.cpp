#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

bool isPrime(int n)
{
    for (int i = 2; 1LL * i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (n <= 2)
        std::cout << "-1\n";
    else
    {
        if (!isPrime(n + 1))
        {
            for (int i = 0; i < n; i++)
                std::cout << n - a[i] + 1 << " \n"[i == n - 1];
        }
        else
        {
            int even = 2, odd = 1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 0)
                {
                    std::cout << even << " \n"[i == n - 1];
                    even += 2;
                }
                else
                {
                    if (a[i] == 1)
                        std::cout << n - 1 << " \n"[i == n - 1];
                    else
                    {
                        std::cout << odd << " \n"[i == n - 1];
                        odd += 2;
                    }
                }
            }
        }
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