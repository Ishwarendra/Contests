#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int q;
    std::cin >> q;

    int n = std::size(s);
    std::vector<int> adjeq(n - 1);
    for (int i = 0; i < n - 1; i++)
        adjeq[i] = s[i] == s[i + 1];

    // make prefix sum array so we can optimise range query part
    // from O(n) to O(1)
    for (int i = 1; i < n - 1; i++)
        adjeq[i] += adjeq[i - 1];

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        std::cout << adjeq[r - 1] - (l ? adjeq[l - 1] : 0) << "\n";
    }
    
    return 0;
}