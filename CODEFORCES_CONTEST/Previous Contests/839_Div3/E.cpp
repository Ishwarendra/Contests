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
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::array<int, 2> tot{}, common{}, uncommon{};

    for (int i = 0; i < n; i++)
    {
        int inc_1 = a[i] != (i + 1);
        int inc_2 = a[i] != (n - i);

        tot[0] += inc_1, tot[1] += inc_2;
        if (inc_1 and inc_2)
            common[0]++, common[1]++;
        else if (inc_1)
            uncommon[0]++;
        else
            uncommon[1]++;
    }

    if (uncommon[1] - tot[0] >= 0)
        std::cout << "First\n";
    else if (uncommon[0] - tot[1] > 0)
        std::cout << "Second\n";
    else
        std::cout << "Tie\n";
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