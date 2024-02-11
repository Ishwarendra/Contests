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

template<class T = int>
T get_rand(T l, T r)
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    auto swap = [&](int i, int j)
    {
        std::swap(pos[a[i]], pos[a[j]]);
        std::swap(a[i], a[j]);
    };

    std::vector<std::vector<int>> ans;
    int rem = n;

    // std::cout << std::size(ans) << "\n";
    // int limit = std::__lg(n);
    // if ((1 << limit) != n)
    //     limit++;
    // assert(std::size(ans) <= limit);
    // for (auto p : ans)
    // {
    //     std::cout << std::size(p) << " ";
    //     for (int x : p)
    //         std::cout << x + 1 << " ";
    //     std::cout << "\n";
    // }
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