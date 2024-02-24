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
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        a[i] = s[i] - '0' - 1;

    // a[0] + a[1] + a[2] = 3
    // (a[0] - 1) + (a[1] - 1) + (a[2] - 1) = 0
    // prefix sum = 0 when?
    // pref[j] - pref[i - 1] = 0
    // pref[j] == pref[i - 1];

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    std::map<int, int> m;
    i64 ans = 0;
    m[0]++;
    for (int i = 0; i < n; i++)
        ans += m[a[i]]++;

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