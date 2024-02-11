#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    if (s[0] == '0')
        s[0] = '1', k--;

    while (k--)
        s += '0';
    std::cout << s << "\n";
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