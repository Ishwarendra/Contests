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
    std::string s;
    std::cin >> n >> s;

    int st = 1;
    while (st < std::ssize(s) and s[st] == s[0])  
        st++;

    int R = std::count(std::begin(s), std::end(s), 'R');
    int D = std::ssize(s) - R;

    if (R == std::ssize(s) or R == 0)
    {
        std::cout << n << "\n";
        return;
    }

    i64 tot = 1LL * n * n;
    tot -= 1LL * (n - 1) * st;

    int rem1 = 0, rem2 = 0;
    for (int i = st; i < std::ssize(s); i++)
    {
        if (s[i] == s[0])
            tot -= rem1, rem2++;
        else
            tot -= rem2, rem1++;
    }

    std::cout << tot << "\n";
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