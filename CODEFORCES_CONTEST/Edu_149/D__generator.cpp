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
    
    std::vector<std::string> ans;
    int n = 4;
    int t = 1 << n;
    std::cout << 8 << "\n";
    for (int mask = 0; mask < (1 << n) / 2; mask++)
    {
        std::string s;
        for (int pos = 0; pos < n; pos++)
        {
            if (mask >> pos & 1)
                s += '(';
            else
                s += ')';
        }

        std::cout << n << "\n";
        std::cout << s << "\n";
    }
    
    return 0;
}