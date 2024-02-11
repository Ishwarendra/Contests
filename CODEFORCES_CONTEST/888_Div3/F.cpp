#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int getBit(int x, int pos) { return x >> pos & 1; }
int f(int a, int b, int x)
{
    return (a ^ x) & (b ^ x);
}

std::array<int, 4> f(std::vector<int> &a, int bit, int x)
{
    if (bit < 0)
        return { f(a[0], a[1], x), x, a[0], a[1] };
    
    std::vector<int> unset, set;
    for (int i = 0; i < std::size(a); i++)
        (getBit(a[i], bit) ? set : unset).emplace_back(a[i]);

    std::array<int, 4> ans {0, 0, -1, -1};
    if (std::size(set) >= 2)
        ans = std::max(ans, f(set, bit - 1, x));
    if (std::size(unset) >= 2)
        ans = std::max(ans, f(unset, bit - 1, x | (1 << bit)));

    if (std::size(set) < 2 and std::size(unset) < 2)
        ans = std::max(ans, f(a, bit - 1, x));

    return ans;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]].emplace_back(i + 1);
    }

    auto [_, ans, x, y] = f(a, k - 1, 0);
    std::cout << pos[x][0] << " " << pos[y][x == y] << " " << ans << '\n';
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