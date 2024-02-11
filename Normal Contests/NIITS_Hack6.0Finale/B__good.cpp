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
    std::string s;
    std::cin >> n >> s;  

    int q;
    std::cin >> q;

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int id;
            char ch;
            std::cin >> id >> ch;
            s[id - 1] = ch;
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            l--, r--;

            auto t = s.substr(l, r - l + 1);
            int sz = r - l + 1;

            int sum = 0, ok = 1;
            int o = 0, c = 0;
            for (auto ch : t)
            {
                o += ch == '(';
                c += ch == ')';

                if (ch == ')')
                    sum--;
                else
                    sum++;

                if (sum < 0)
                    ok = 0;
            }

            int even = (r - l + 1) % 2 == 0;
            if (o * 2 <= sz and c * 2 <= sz and even and ok)
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
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