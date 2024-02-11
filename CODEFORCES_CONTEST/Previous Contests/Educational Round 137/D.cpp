#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string operator|(const std::string &a, const std::string &b)
{
    int n = std::size(a), m = std::size(b);
    std::string c(std::max(n, m), '0');

    int i = n - 1, j = m - 1;
    while (i >= 0 or j >= 0)
    {
        int ch1 = (i >= 0 and a[i] == '1');
        int ch2 = (j >= 0 and b[j] == '1');
        if (ch1 | ch2)
            c[std::max(i, j)] = '1';

        i--, j--;
    }

    return c;
};

std::string max(std::string &a, std::string &b)
{
    int one_a = -1e6, one_b = -1e6;
    for (int i = 0; i < std::ssize(a); i++)
    {
        if (a[i] == '1')
        {
            one_a = std::ssize(a) - i;
            break;
        }
    }

    for (int i = 0; i < std::ssize(b); i++)
    {
        if (b[i] == '1')
        {
            one_b = std::ssize(b) - i;
            break;
        }
    }

    return (one_a > one_b ? a : b);
}

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
    
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> one, zero;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            one.emplace_back(i);
        else if (!one.empty())
            zero.emplace_back(i);
    }

    if (one.empty())
    {
        std::cout << "0\n";
        std::exit(0);
    }

    std::string a = s.substr(one[0]);
    std::string ans(n, '0');

    int len = a.find('0');
    // 1 0 1 0 0
    //   1 0 1 0
    for (auto id : zero)
    {
        auto end = std::upper_bound(std::begin(one), std::end(one), id) - std::begin(one);
        bool here = false;
        for (int i = end - 1; i >= 0; i--)    
        {
            int need = n - id;
            ans = std::max(ans, a | s.substr(one[i], need));
            here = true;
        }

        if (here)
            break;
    }
    
    std::cout << ans;
    
    return 0;
}