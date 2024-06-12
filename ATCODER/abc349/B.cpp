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

    std::array<int, 26> f1{};
    std::string s;
    std::cin >> s;

    for (auto ch : s)
        f1[ch - 'a']++;

    std::map<int, int> f;
    for (int i = 0; i < 26; i++)
    {
        if (f1[i])
            f[f1[i]]++;
    }

    for (int i = 1; i <= 100; i++)
    {
        if (f.contains(i) and f[i] != 2)
        {
            std::cout << "No";
            return 0;
        }
    }

    std::cout << "Yes";

    return 0;
}