#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int male = 0, female = 0;
    int count = 0;
    int ans = 0, free = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            if (!male or !female)
            {
                if (!free)
                    ans++;
                else
                    free--;
            }
            count++;
        }
        else
        {
            female = 1, male = 0;
            int need = (count + 1 + (count % 2 == 0)) / 2;
            if (ans > need)
                free = ans - need;
        }
    }

    std::cout << ans << "\n";
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