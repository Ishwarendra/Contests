#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)  
    {
        char ch;
        std::cin >> ch;
        sum += ch == 'A';
        sum -= ch == 'B';
    }

    std::cout << (sum > 0 ? 'A' : 'B') << "\n";
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