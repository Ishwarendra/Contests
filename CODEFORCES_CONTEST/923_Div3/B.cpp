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
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::array<int, 26> pos{};
    auto get = [&](int x)
    {
        for (int i = 0; i < 26; i++)
        {
            if (pos[i] == x)
                return i;
        }

        assert(false);
        return -1;
    };

    std::string s;
    for (int i = 0; i < n; i++)
    {
        char ch = get(a[i]);
        pos[ch]++;
        s += char(ch + 'a');
    }

    std::cout << s << "\n";
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