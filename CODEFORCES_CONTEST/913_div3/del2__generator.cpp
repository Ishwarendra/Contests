#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

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
    
    int t = 1;
    // std::cout << t << "\n";

    while (t--)
    {   
        int m = get_rand(1, 4);
        std::cout << m << "\n";

        int n = get_rand(4, 7);
        std::string s;
        s += get_rand('1', '9');
        for (int i = 0; i < n - 1; i++)
            s += get_rand('0', '9');

        std::cout << s << "\n";
    }
    
    return 0;
}