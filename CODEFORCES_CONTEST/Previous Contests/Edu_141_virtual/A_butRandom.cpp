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

    auto check = [&]()
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum == a[i])
                return false;
            sum += a[i];
        }

        return true;
    };

    if (std::size(std::set(std::begin(a), std::end(a))) == 1)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        while (true)
        {
            if (check())
            {
                for (int x : a)
                    std::cout << x << ' ';
                std::cout << "\n";
                return;
            }
            std::shuffle(std::begin(a), std::end(a), rng);
        }
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