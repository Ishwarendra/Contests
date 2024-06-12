#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string suff = " AM";
    std::string s;
    std::cin >> s;

    auto norm = [&](int x)
    {
        if (x < 10)
            return "0" + std::to_string(x);
        return std::to_string(x);
    };

    auto convert = [&](std::string hour) -> std::pair<bool, std::string>
    {
        int x = std::stoi(hour);
        if (x == 0)
            return { false, "12" };
        else if (x < 12)
            return { false, hour };
        else if (x == 12)
            return { true, hour };
        else
            return { true, norm(x - 12) };
    };

    auto [change, hour] = convert(s.substr(0, 2));
    if (change)
        suff = " PM";
    std::cout << hour << ":" << s.substr(3, 2) << suff << "\n";
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