#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    std::cin >> s >> t;

    for (auto &ch : s)
        ch = std::toupper(ch);

    int n = std::size(s);
    int max = 0;
    for (int i = 0; i < n and max < std::size(t); i++)
    {
        if (s[i] == t[max])
            max++;
    }

    if (max == 3 or (max == 2 and t.back() == 'X'))
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}