#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    std::map<std::string, int> m;
    std::vector<std::string> a(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        m[a[i]] = i;
    }

    std::vector<int> vis(std::size(s));
    auto match = [&s, &vis](std::string & t)-> std::tuple<int, int, int>
    {
        int m = std::size(t);
        int n = std::size(s);

        int id = -1;
        int cover = 0;
        int firG = 1e9;

        for (int i = 0; i <= n - m; i++)
        {
            if (s.substr(i, m) == t)
            {
                int cnt = 0;
                int first = 1e9;

                for (int j = i; j < i + m; j++)
                {
                    if (!vis[j])
                    {
                        first = j;
                        break;
                    }
                }

                for (int j = i; j < i + m; j++)
                    cnt += !vis[j];

                if ((first < firG or (first == firG and cnt > cover)) 
                        and cnt > 0)
                {
                    firG = first;
                    cover = cnt;
                    id = i;
                }
            }
        }

        return std::tuple<int, int, int>(id, firG, cover);
    };

    bool change = true;
    std::vector<std::pair<int, int>> ans;

    while (change)
    {
        change = false;

        int cover = 0;
        std::string use;
        int start = -1;
        int firG = 1e9;

        for (int i = 0; i < n; i++)
        {
            auto [st, first, cnt] = match(a[i]);
            if (st == -1)
                continue;
            // print(a[i], st, first, cnt)
            if ((first < firG) or (first == firG and cnt > cover))
            {
                firG = first;
                cover = cnt;
                use = a[i];
                start = st;
            }
        }

        if (start != -1)
        {
            print(use, start)
            int _ = m[use] + 1;

            for (int __ = start; __ < start + std::size(use); __++)
                vis[__] = 1;

            ans.emplace_back(_, start + 1);
            change = true;
        }
    }

    for (int i = 0; i < std::size(vis); i++)
    {
        if (!vis[i])
        {
            std::cout << "-1\n";
            return;
        }
    }

    std::cout << std::size(ans) << "\n";
    for (auto [x, y] : ans)
        std::cout << x << " " << y << "\n";
    // vis[0] = vis[1] = 1;
    // std::cout << match(a[0]);
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