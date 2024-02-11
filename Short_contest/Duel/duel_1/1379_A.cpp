#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;

    std::cin >> n >> s;
    std::string p = "abacaba";

    int id = -1;
    std::string form;

    auto ok = [&](std::string x)
    {
        int n = std::size(x);
        int cnt = 0;
        for (int i = 0; i < n - 6; i++)
        {
            bool yes = true;
            for (int j = 0; j < 7; j++)
            {
                if (x[i + j] != p[j])
                {
                    yes = false;
                    break;
                }
            }

            if (yes)
                cnt++;
        }
        print(x, cnt)
        return cnt == 1;
    };

    for (int i = 0; i < n - 6; i++)
    {
        if (s[i] == p[0] or s[i] == '?')
        {
            id = i;
            for (int j = 0; j < 7; j++)
            {
                if (s[i + j] == '?')
                    continue;
                else if (s[i + j] != p[j])
                {
                    id = -1;
                    break;
                }
            }

            if (id != -1)
            {
                for (int j = 0; j < id; j++)
                {
                    if (s[j] == '?')
                        form += 'z';
                    else
                        form += s[j];
                }

                for (int j = id; j < id + 7; ++j)
                    form += p[j - id];

                for (int j = id + 7; j < n; j++)
                {
                    if (s[j] == '?')
                        form += 'z';
                    else
                        form += s[j];
                }

                if (!ok(form))
                {
                    id = -1;
                    form.clear();
                    continue;
                }

                std::cout << "Yes\n";
                std::cout << form << "\n";
                return;
            }
        }
    }

    std::cout << "No\n";
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