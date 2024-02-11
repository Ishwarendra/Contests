#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<i64> p(n + 1), s(n + 1);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    s[n] = p[n];
    for (int i = n - 1; i >= 0; i--)
        s[i] = std::min(p[i], s[i + 1]);

    // {max drop, which id has it}
    std::array<i64, 2> ans{p[0] - s[0], p[0]};

    for (int i = 1; i < n; i++)
        ans = std::max(ans, std::array {p[i] - s[i], p[i]});

    print(p, s, ans)
    std::cout << ans[1] << "\n";
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