#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int q;
    std::cin >> q;

    std::multiset<int> nums, xors;

    auto erase = [&](std::multiset<int> &m, int x)
    {
        m.erase(m.find(x));
    };

    auto add = [&](int x)
    {
        auto it = nums.emplace(x);

        if (it != std::begin(nums) and it != std::prev(std::end(nums)))
        {
            auto prev = std::prev(it);
            auto next = std::next(it);
            erase(xors, *prev ^ *next);
        }

        if (it != std::begin(nums))
        {
            auto prev = std::prev(it);
            xors.emplace(*prev ^ *it);
        }

        if (it != std::prev(std::end(nums)))
        {
            auto next = std::next(it);
            xors.emplace(*it ^ *next);
        }
    };

    auto remove = [&](int x)
    {
        auto it = nums.find(x);

        if (it != std::begin(nums) and it != std::prev(std::end(nums)))
            xors.emplace(*std::prev(it) ^ *std::next(it));

        if (it != std::begin(nums))
        {
            auto prev = std::prev(it);
            erase(xors, *prev ^ *it);
        }

        if (it != std::prev(std::end(nums)))
        {
            auto next = std::next(it);
            erase(xors, *it ^ *next);
        }

        nums.erase(it);
    };

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int x;
            std::cin >> x;
            add(x);
        }
        else if (t == 2)
        {
            int x;
            std::cin >> x;
            remove(x);
        }
        else
            std::cout << *std::begin(xors) << "\n";
    }

    return 0;
}