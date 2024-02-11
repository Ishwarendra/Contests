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
    
    int n;
    std::cin >> n;

    auto setBit = [&](int x, int pos) { return x | (1 << pos); };
    auto getBit = [&](int x, int pos) { return (x >> pos) & 1; };

    std::vector<int> any(n), even(n), odd(n);
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;

        std::array<int, 26> freq{};
        for (auto ch : s)
            freq[ch - 'a']++;

        for (int k = 0; k < 26; k++)
        {
            if (freq[k])
                any[i] = setBit(any[i], k);

            auto &change = freq[k] % 2 ? odd : even;
            change[i] = setBit(change[i], k);
        }
    }

    i64 ans = 0;
    std::vector<int> m(1 << 26);
    constexpr int allSet = (1 << 26) - 1;

    for (int zero = 0; zero < 26; zero++)
    {
        for (int i = 0; i < n; i++)
        {
            if (getBit(any[i], zero))
                continue;

            ans += m[allSet - (1 << zero) - odd[i]];
            m[odd[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (!getBit(any[i], zero))
                m[odd[i]]--;
        }
    }

    std::cout << ans;
    
    return 0;
}