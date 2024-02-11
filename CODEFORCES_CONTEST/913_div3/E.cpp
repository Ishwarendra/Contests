#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int fact(int x)
{
    int ans = 1;
    for (int i = 2; i <= x; i++)
        ans *= i;
    return ans;
}

i64 get(int x)
{
    i64 ans = 0;
    for (int a = 0; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                if (a + b + c == x)
                    ans++;
            }
        }
    }

    return ans;
}

void solve()
{
    int n;
    std::cin >> n;  

    i64 ans = 1;
    while (n)
    {
        ans *= get(n % 10);
        n /= 10;
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