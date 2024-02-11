#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        std::cin >> a[i];

    if (std::is_sorted(a.begin(), a.end()))
        std::cout << "0\n";
    else
    {
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    std::swap(a[j], a[j + 1]);
                    ans.push_back({j, j + 1});
                }
            }
        }

        std::cout << ans.size() << "\n";
        for (auto p : ans)
            std::cout << p[0] + 1 << " " << p[1] + 1 << "\n";
        assert(is_sorted(a.begin(), a.end()));
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