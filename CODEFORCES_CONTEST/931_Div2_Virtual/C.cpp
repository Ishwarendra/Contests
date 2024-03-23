#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get()
};
std::mt19937_64 rng(seed);

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    // n = get_rand<int>(2, 10);
    // m = get_rand<int>(2, 10);

    // int ansx1 = get_rand(1, n), ansy1 = get_rand(1, m);
    // int ansx2 = get_rand(1, n), ansy2 = get_rand(1, m);
    // while (ansx2 == ansx1 and ansy2 == ansy1)
    //     ansx2 = get_rand(1, n), ansy2 = get_rand(1, m);

    auto safe = [&](int x, int y)
    {
        return 1 <= x and x <= n and 1 <= y and y <= m;
    };

    auto query = [&](int x, int y)
    {
        assert(safe(x, y));
        std::cout << "? " << x << " " << y << std::endl;
        int d;
        // d = std::min(std::abs(x - ansx1) + std::abs(y - ansy1), std::abs(x - ansx2) + std::abs(y - ansy2));
        std::cin >> d;

        return d;
    };

    auto answer = [&](int x, int y)
    {
        // if (x == ansx1 and y == ansy1);
        // else if (x == ansx2 and y == ansy2);
        // else
        // {
        //     print(ansx1, ansy1, ansx2, ansy2);
        //     print("but");
        //     print(x, y);
        //     std::exit(0);
        // }
        std::cout << "! " << x << " " << y << std::endl;
    };

    auto c1 = query(1, 1);
    auto c2 = query(n, m);
    auto c3 = query(n, 1);

    int y1 = (c1 + c3 + 3 - n) / 2;
    int x1 = c1 + 2 - y1;

    int x2 = (2 * n + m - 1 - c2 - c3) / 2;
    int y2 = n - x2 + m - c2;

    int num2 = (2 * n + m - 1 - c2 - c3);

    if ((c1 + c3 + 3 - n) % 2 and safe(x2, y2))
        answer(x2, y2);
    else if ((num2 < 0 or num2 % 2) and safe(x1, y1))
        answer(x1, y1);
    else
    {
        if (safe(x1, y1) and query(x1, y1) == 0)
            answer(x1, y1);
        else
            answer(x2, y2);
    }
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