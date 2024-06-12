#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Since O(x) fit under constraint we can brute for all y < x and output the best answer
 * 
 * Iterate over factors (i.e possible gcd) of x (which are < x). Let f be the current factor
 * ans = max(ans, f + f * [(x - 1) / f])
 * This works in O(root(x))
 * 
 * Choosing y = x - 1 (and f = 1) guarantees that our value will be x
 * For any other f, 
 *     ans = (atmost f / 2) + (atmost x - f)
 *     floor [(x - 1) / f] = (x - f) / f since f is a factor of x.
 *  Thus we cannot a better sum than x
 */

void solve()
{
    int x;
    std::cin >> x;
    std::cout << x - 1 << "\n";     
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