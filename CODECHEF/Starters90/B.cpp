#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::array<int, 26> cnt{};
    for (auto &ch : s)  
        cnt[ch - 'a']++;

    int odd = 0;
    for (int i = 0; i < 26; i++)
        odd += cnt[i] % 2;

    if (odd != n % 2)
        std::cout << "0\n";
    else if (n % 2 == 0)
        std::cout << "1\n";
    else
    {
        int max = *std::max_element(std::begin(cnt), std::end(cnt));
        std::cout << (max == n ? "2\n" : "1\n");
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