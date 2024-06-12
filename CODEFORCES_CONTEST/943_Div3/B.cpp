#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Binary search on k.
 * To check whether it is possible for a[0..k] is a subsequence of b or not
 * can be done in linear time.
 * 
 * Instead of binary search we can just keep finding a[id] in b and incrementing id each time we find a match in b.
 * which is longest prefix of a present in b.
 */

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    std::string a, b;
    std::cin >> a >> b;     
    
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if (a[i] == b[j])
            i++;
        j++;
    }

    std::cout << i << '\n';
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