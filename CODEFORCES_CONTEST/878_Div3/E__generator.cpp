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
    auto getStr = [&](int n)
    {
        std::string a;
        for (int i = 0; i < n; i++)
            a += get_rand('a', 'd');
        return a;
    };

    int n = 6;
    std::cout << getStr(n) << " " << getStr(n) << "\n";

    int t = get_rand(1, 3), q = 7;
    std::cout << t << " " << q << '\n';
    std::set<int> blocked;
    std::map<int, std::vector<int>> rem;

    for (int i = 0; i < q; i++)
    {
        for (auto x : rem[i])
            blocked.erase(x);
        rem[i].clear();

        int type = get_rand(1, 3);
        std::cout << type << " \n"[type == 3];
        if (type == 1)
        {
            int p = get_rand(1, n);
            while (blocked.count(p))
                p = get_rand(1, n);

            std::cout << p << "\n";
            blocked.emplace(p);
            rem[i + t].emplace_back(p);
        }
        else if (type == 2)
        {
            int id1 = get_rand(0, 100) % 2;
            int id2 = get_rand(0, 100108) % 2;  

            int pos1 = get_rand(1, n);
            int pos2 = get_rand(1, n);

            while (blocked.count(pos1))
                pos1 = get_rand(1, n);
            while (blocked.count(pos2))
                pos2 = get_rand(1, n);

            assert(!blocked.count(pos2));
            std::cout << id1 + 1 << " " << pos1 << " " << id2 + 1 << " " << pos2 << "\n";
        }
    }
    
    return 0;
}