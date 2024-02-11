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

    std::map<std::string, int> m;
    for (int i = 0; i < n; i++)  
    {
        std::string s;
        std::cin >> s;
        m[s]++;
    }

    std::cout << m["O"] + std::max(m["A"], m["B"]) + m["AB"] << "\n";
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