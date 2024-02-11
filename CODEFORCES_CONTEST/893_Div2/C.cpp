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

    int cnt = 0;
    std::vector<int> a(n);
    std::set<int> have;
    for (int i = 1; i <= n; i++)  
        have.emplace(i);

    i64 mul = 2;
    int pos = 0;

    while (pos < n)
    {
        int st = *std::begin(have);              
        a[pos++] = st;
        have.erase(st);

        while (have.count(st * 2))
        {
            a[pos++] = st * 2;
            have.erase(st * 2);
            st *= 2;
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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