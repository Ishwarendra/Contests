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
    std::string a, b;
    std::cin >> n >> a >> b;

    std::array<int, 2> count_1{}, count_2{};

    for (int i = 0; i < n; i++)
    {
        count_1[a[i] - '0']++;
        count_2[b[i] - '0']++;
    }

    if (count_1 == count_2)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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