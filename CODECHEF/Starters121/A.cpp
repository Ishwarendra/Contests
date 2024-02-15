#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    for (int i = 0; i < n; i++)
    {
        int need = 0;
        int a = s[i] - 'A', b = t[i] - 'A';
        while (a != b)
        {
            need++;
            a = (a + 3) % 26;
        }

        std::cout << need << " \n"[i == n - 1];
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