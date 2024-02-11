#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

std::string left_shift(std::string &s)
{
    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), --s.end());

    return s;
}

void solve()
{
    int n;
    std::cin >> n;
    std::string s;
    std::vector<int> p(n);

    std::cin >> s;

    for (int i = 0; i < n; ++i)  
    {
        std::cin >> p[i];
        p[i]--;
    }

    std::vector<std::vector<int>> cycles;
    std::vector<int> vis(n);

    auto next = [&](int i)
    {
        std::vector<int> ans;

        while (!vis[i])
            ans.push_back(i), vis[i] = 1, i = p[i];

        return ans;
    };

    std::vector<int> nums;

    for (int i = 0; i < n; i++)
        if (!vis[i])
            cycles.push_back(next(i));

    for (auto cyc : cycles)
    {
        std::string tmp, orig;

        for (int i : cyc)
            tmp += s[i];

        orig = tmp;
        int cnt = 1;

        for (int i = 0; i < cyc.size() + 1; i++)
        {
            if (left_shift(tmp) == orig)
            {
                nums.push_back(cnt);
                break;
            }

            cnt++;
        }
    }

    long long ans = 1;

    for (int i = 0; i < nums.size(); i++)
        ans = std::lcm(ans, nums[i]);

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}