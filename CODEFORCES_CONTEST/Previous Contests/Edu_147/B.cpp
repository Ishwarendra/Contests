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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    int start = 0, end = n - 1;
    while (start < n and a[start] == b[start])
        start++;
    while (end >= 0 and a[end] == b[end])
        end--;

    while (start > 0 and b[start] >= b[start - 1])
        start--;
    while (end < n - 1 and b[end] <= b[end + 1])
        end++;

    std::cout << start + 1 << " " << end + 1 << "\n";
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