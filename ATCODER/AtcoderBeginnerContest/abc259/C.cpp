#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s, t;
    std::cin >> s >> t;

    std::vector<std::pair<char, int>> s_cnt, t_cnt;

    int n = std::size(s);
    int m = std::size(t);

    int cnt = 1;
    char cur = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] == cur)
            cnt++;
        else
        {
            s_cnt.emplace_back(cur, cnt);
            cur = s[i];
            cnt = 1;
        }
    }

    s_cnt.push_back({cur, cnt});

    cnt = 1, cur = t[0];
    for (int i = 1; i < m; ++i)
    {
        if (t[i] == cur)
            cnt++;
        else
        {
            t_cnt.emplace_back(cur, cnt);
            cur = t[i];
            cnt = 1;
        }
    }

    t_cnt.push_back({cur, cnt});

    n = std::size(s_cnt);
    
    print(s_cnt, t_cnt)
    if (t_cnt.size() != s_cnt.size())
    {
        std::cout << "No\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        auto [tch, tcnt] = t_cnt[i];
        auto [sch, scnt] = s_cnt[i];

        if (tch != sch or (scnt == 1 and tcnt != 1) or scnt > tcnt)
        {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";
    
    return 0;
}