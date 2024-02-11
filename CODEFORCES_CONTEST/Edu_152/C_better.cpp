#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<int> p(n);   
    p[0] = s[0] == '1';
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + (s[i] == '1');

    auto sum = [&](int i, int j) { return p[j] - (i ? p[i - 1] : 0); };

    auto isSorted = [&](int i, int j)
    {
        int one = sum(i, j);
        return i >= j or one == sum(j - one + 1, j);
    };

    std::vector<int> lastOne(n + 1, -1), nextZero(n + 1, n);
    for (int i = 0; i < n; i++)
        lastOne[i + 1] = (s[i] == '1' ? i : lastOne[i]);

    for (int i = n - 1; i >= 0; i--)
        nextZero[i] = (s[i] == '0' ? i : nextZero[i + 1]);

    std::set<std::pair<int, int>> ans;

    for (int i = 0; i < m; i++)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        if (isSorted(l, r))
            ans.emplace(0, 0);
        else
            ans.emplace(lastOne[l], nextZero[r + 1]);
    }

    std::cout << std::size(ans) << "\n";  
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