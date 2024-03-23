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


    if (n % 2)
    {
        std::cout << "NO\n";
        return;
    }

    char ch = 'A';
    std::string s;
    std::cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        s += ch;
        std::cout << ch;
        if (i % 2)
            ch++;
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