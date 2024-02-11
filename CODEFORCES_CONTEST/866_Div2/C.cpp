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

    std::vector<int> a(n), found(n + 2), pos;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (0 <= a[i] and a[i] <= n)
            found[a[i]] = 1;
    }

    int mex = 0;
    while (found[mex])
        mex++;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == mex + 1)
            pos.emplace_back(i);
    }

    if (mex == n)
        std::cout << "No\n";
    else
    {
        std::fill(std::begin(found), std::end(found), 0);
        if (!pos.empty())
        {
            for (int i = pos.front(); i <= pos.back(); i++)
                a[i] = mex;
        }

        for (int i = 0; i < n; i++)
        {
            if (0 <= a[i] and a[i] <= n)
                found[a[i]] = 1;
        }

        int mex2 = 0;
        while (found[mex2])
            mex2++;

        if (mex2 - mex == 1 or pos.empty())
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
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