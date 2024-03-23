#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    int mex = 0;
    while (m.count(mex))
        mex++;

    if (mex == 0)
    {
        std::cout << n << "\n";
        for (int i = 0; i < n; i++)
            std::cout << i + 1 << " " << i + 1 << "\n";
        return;
    }

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n;)
    {
        std::set<int> done;
        int j = i;
        while (j < n and std::size(done) < mex)
        {
            if (a[j] < mex)
                done.emplace(a[j]);
            j++;
        }

        if (std::size(done) != mex)
            break;

        ans.emplace_back(i, j - 1);
        i = j;
    }

    if (std::size(ans) < 2)
    {
        std::cout << "-1\n";
        return;
    }

    ans.back().second = n - 1;
    std::cout << std::size(ans) << "\n";
    for (auto &[l, r] : ans)
        std::cout << l + 1 << " " << r + 1 << "\n";
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