#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    i64 even = 0, odd = 0;
    i64 evencount = 0, oddcount = 0;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        if (a[i] % 2)
        {
            oddcount++;
            odd += a[i];
        }
        else
        {
            evencount++;
            even += a[i];
        }
    }

    while (q--)
    {
        int t, x;
        std::cin >> t >> x;

        if (t == 0)
        {
            if (x % 2 == 0)
                even += 1LL * evencount * x;
            else
            {
                even += 1LL * evencount * x;
                odd += even;
                even = 0;
                oddcount += evencount;
                evencount = 0;
            }
        }
        else
        {
            if (x % 2 == 0)
                odd += 1LL * oddcount * x;
            else
            {
                odd += 1LL * oddcount * x;
                even += odd;
                odd = 0;
                evencount += oddcount;
                oddcount = 0;
            }
        }

        std::cout << even + odd << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}