#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T, class G>
T power(T a, G b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
} 

void solve()
{
    std::string s;
    std::cin >> s;

    if (s.front() == '0')
    {
        std::cout << "0\n";
        return;
    }

    int st = 0;
    int ans = 1;
    while (st < 1 and s[st] == '?')
        ans *= 9, st++;

    for (; st < std::size(s); st++)
    {
        if (s[st] == '?')
            ans *= 10;
    }

    std::cout << ans << '\n';
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