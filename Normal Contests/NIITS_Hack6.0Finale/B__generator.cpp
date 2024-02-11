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
    std::cout << t << "\n";

    std::array<char, 3> a { '(', ')', '?'};
    while (t--)
    {
        int n = 100;
        std::cout << n << "\n";

        std::string s;
        for (int i = 0; i < n; i++)
            s += a[get_rand(0, 2)];

        int q = 15;
        std::cout << s << "\n" << q << '\n';

        while (q--)
        {
            int t = get_rand(1, 2);
            std::cout << t << " ";

            if (t == 1)
            {
                int id = get_rand(1, n);
                char ch = a[get_rand(0, 2)];
                std::cout << id << " " << ch << '\n';
            }
            else
            {
                int l = get_rand(1, n);
                int r = get_rand(l, n);
                std::cout << l << " " << r << "\n";
            }
        }
    }
    
    return 0;
}