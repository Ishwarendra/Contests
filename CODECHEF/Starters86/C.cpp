#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto getBit = [&](int x, int pos) { return (x >> pos) & 1; };

    bool done = false;
    int unset = -1;

    auto valid = [&](int x)
    {
        std::vector<int> b(n);
        for (int i = 0; i < n; i++)
            b[i] = a[i] | x;

        return std::size(std::set(std::begin(b), std::end(b))) > 1;
    };

    if (valid(x))
    {
        std::cout << x << "\n";
        return;
    }

    for (int i = 0; i <= 30; i++)
    {
        if (!getBit(x, i))
            continue;

        std::array<int, 2> b{};
        for (int j = 0; j < n; j++)
            b[getBit(a[j], i)]++;

        if (b[0] > 0 and b[1] > 0)
        {
            unset = i;
            break;
        }
    }

    if (unset == -1)
        std::cout << "0\n";
    else
    {
        int ans = x ^ (1 << unset);
        for (int i = unset - 1; i >= 0; i--)
            ans |= (1 << i);
        std::cout << ans << "\n";
    }
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