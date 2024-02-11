#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    std::cin >> s >> t;

    int d1 = std::min(5 - std::abs(s[0] - s[1]), std::abs(s[0] - s[1]));
    int d2 = std::min(5 - std::abs(t[0] - t[1]), std::abs(t[0] - t[1]));

    std::cout << (d1 == d2 ? "Yes" : "No");
}