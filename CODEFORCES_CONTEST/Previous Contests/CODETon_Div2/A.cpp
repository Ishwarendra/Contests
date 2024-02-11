#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::string a, b;
    std::cin >> n >> m >> a >> b;  

    int zero = std::count(a.begin(), a.begin() + n - m + 1, '0');
    int one = std::count(a.begin(), a.begin() + n - m + 1, '1');

    if (a[n - m] != b[0])
    {
        if (b[0] == '0')
        {
            if (!zero)
            {
                std::cout << "NO\n";
                return;
            }
        }

        else
        {
            if (!one)
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    for (int i = n - m + 1, j = 1; i < n and j < m; i++, j++)
    {
        if (a[i] != b[j])
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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