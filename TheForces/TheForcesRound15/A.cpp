#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::array<int, 26> freq{}, last{};
    for (int pos = 1; auto ch : s)
    {
        freq[ch - 'a']++;
        last[ch - 'a'] = pos;
        pos++;
    }

    int max = *std::max_element(std::begin(freq), std::end(freq));
    std::string ans;

    std::array<int, 26> ord{};
    std::iota(std::begin(ord), std::end(ord), 0);
    std::sort(std::begin(ord), std::end(ord), [&](int i, int j)
    {
        if (freq[i] == freq[j])
            return last[i] < last[j];
        return freq[i] > freq[j];
    });

    for (int i : ord)
    {
        if (freq[i] == max)
            ans += char(i + 'a');
    }

    std::cout << ans << "\n";
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