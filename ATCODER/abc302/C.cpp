#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto valid = [&](int i, int j)
    {
        int ans = 0;
        for (int p = 0; p < m; p++)
            ans += a[i][p] != a[j][p];
        return ans == 1;
    };

    int can = 0;
    std::sort(std::begin(a), std::end(a));
    do
    {
        int ok = 1;
        for (int i = 1; i < n; i++)
        {
            if (!valid(i, i - 1))
            {
                ok = 0;
                break;
            }
        }
        can |= ok;

    } while (std::next_permutation(std::begin(a), std::end(a)));

    std::cout << (can ? "Yes\n" : "No\n");
    
    return 0;
}