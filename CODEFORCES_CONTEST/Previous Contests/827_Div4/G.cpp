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

    std::multiset<int> a;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        a.emplace(x);
    }        

    auto getBit = [&](int x, int pos)
    {
        return (x >> pos) & 1;
    };

    std::vector<int> ans;
    std::vector<int> done(31);

    for (int i = 30; i >= 0; i--)
    {
        if (a.empty())
            break;

        if (done[i])
            continue;

        std::vector<std::vector<int>> next;
        std::map<std::vector<int>, int> nums;

        for (auto it : a)
        {
            if (getBit(it, i))
            {
                next.push_back({});
                for (int j = 30; j >= 0; j--)
                {
                    if (!done[j] and getBit(it, j))
                        next.back().push_back(j);
                }

                nums[next.back()] = it;
            }
        }

        if (next.empty())
            continue;

        std::sort(std::begin(next), std::end(next), std::greater());
        int num = nums[next[0]];

        for (int j = 0; j <= 30; j++)
            done[j] |= getBit(num, j);
            
        a.erase(a.find(num));
        ans.emplace_back(num);
    }

    for (int x : a)
        ans.push_back(x);
    
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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