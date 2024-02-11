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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout << "1\n";
    int n = 4, m = 6;
    std::cout << n << " " << m << "\n";

    std::vector a {'.', 'L', 'U'};
    std::vector<std::string> b(n, std::string(m, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] != '.')
                continue;

            int id = get_rand(0, 2);
            if (a[id] == 'L' and j + 1 < m)
                b[i][j] = 'L', b[i][j + 1] = 'R';

            else if (a[id] == 'U' and i + 1 < n) 
                b[i][j] = 'U', b[i + 1][j] = 'D';
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << b[i] << "\n";
    
    return 0;
}