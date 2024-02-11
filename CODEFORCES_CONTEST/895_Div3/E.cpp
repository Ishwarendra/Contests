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

    std::vector<int> pxor(n);
    pxor[0] = a[0];
    std::array<int, 2> ans{};

    for (int i = 1; i < n; i++)
        pxor[i] ^= pxor[i - 1] ^ a[i];

    std::string s;
    std::cin >> s;

    for (int i = 0; i < n; i++)
        ans[s[i] - '0'] ^= a[i];

    int q;
    std::cin >> q;

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int l, r;
            std::cin >> l >> r;
            l--, r--;

            int rangeXor = pxor[r] ^ (l ? pxor[l - 1] : 0);
            ans[0] ^= rangeXor;
            ans[1] ^= rangeXor;
        }
        else
        {
            int x;
            std::cin >> x;

            std::cout << ans[x] << " ";
        }
    }

    std::cout << "\n";
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