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

    std::string x, y;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)  
    {
        int cur = s[i] - '0';
        if (cur % 2 == 0)
        {
            x += std::to_string(cur / 2);
            y += std::to_string(cur / 2);
        }
        else
        {
            if (left > right)
            {
                x += std::to_string(cur / 2);
                y += std::to_string(cur / 2 + 1);
                right++;
            }
            else
            {
                x += std::to_string(cur / 2 + 1);
                y += std::to_string(cur / 2);
                left++;
            }
        }
    }

    int st1 = 0, st2 = 0;
    while (st1 < std::ssize(x) - 1 and x[st1] == '0') st1++;
    while (st2 < std::ssize(y) - 1 and y[st2] == '0') st2++;

    std::cout << x.substr(st1) << " " << y.substr(st2) << "\n";
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