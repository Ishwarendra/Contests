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
    n = std::size(s);

    std::string b = s, c = std::string(n, '0');
    
    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i] == '0')
            continue;

        int j = i;
        while (j >= 0 and b[j] == '1')
            j--;

        if (j != -1 and (i - j >= 2))
        {
            for (int k = i; k > j; k--)
                b[k] = '0';
            b[j] = '1';
            c[i] = '1';
        }

        i = j + 1;
    }

    assert(std::size(b) == n and std::size(c) == n);
    std::cout << b << "\n" << c << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}