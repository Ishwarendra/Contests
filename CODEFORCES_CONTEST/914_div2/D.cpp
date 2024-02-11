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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<std::array<int, 2>> pos;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            pos.push_back({b[i], i});
    }

    std::sort(std::begin(pos), std::end(pos));

    for (auto [_, i] : pos)
    {
        if (a[i] > b[i])
        {
            std::cout << "NO\n";
            return;
        }

        int j1 = i;
        int left = 1, right = 1;
        while (j1 >= 0 and a[j1] != b[i])
        {
            if (a[j1] > b[i])
            {
                left = 0;
                break;
            }
            j1--;
        }

        if (j1 == -1)
            left = 0;

        int j2 = i;
        while (j2 < n and a[j2] != b[i])
        {
            if (a[j2] > b[i])
            {
                right = 0;
                break;
            }
            j2++;
        }

        if (j2 == n)
            right = 0;

        if (!left and !right)
        {
            std::cout << "NO\n";
            return;
        }

        int ok = left;
        for (int k = j1; k <= i and left; k++)
        {
            if (b[k] < a[j1])
            {
                ok = 0;
                break;
            }
        }

        if (ok)
        {
            for (int k = j1; k <= i and left; k++)
                a[k] = a[j1];
            continue;
        }

        ok = right;
        for (int k = j2; k >= i and right; k--)
        {
            if (b[k] < a[j2])
            {
                ok = 0;
                break;
            }
        }

        if (ok)
        {
            for (int k = j2; k >= i; k--)
                a[k] = a[j2];
        }
        else
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << (a == b ? "YES\n" : "NO\n");
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