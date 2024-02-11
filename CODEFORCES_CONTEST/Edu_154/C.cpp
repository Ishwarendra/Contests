#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector<int> state {1}; // -1: unsorted, 0: dk, 1: sorted
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        auto ch = s[i];
        if (ch == '+')
        {
            total++;
            if (total < 1)
                state.emplace_back(1);
            else if (total == 1)
                state.emplace_back(0);
            else
            {
                if (state.back() == 1)
                    state.emplace_back(0);
                else if (state.back() == 0)
                    state.emplace_back(0);
                else
                    state.emplace_back(-1);
            }
        }
        else if (ch == '-')
            state.pop_back(), total--;
        else if (ch == '0')
        {
            if (state.back() == 1 or total < 2)
            {
                std::cout << "NO\n";
                return;
            }

            state.back() = -1;
        }
        else
        {
            if (state.back() == -1)
            {
                std::cout << "NO\n";
                return;
            }

            int id = std::ssize(state) - 1;
            while (id >= 0 and state[id] != 1)
                state[id--] = 1;
        }
    }  
    std::cout << "YES\n";
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