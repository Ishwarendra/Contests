#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, T b) {
    T res = 1;
    for (; b; b /= 2, a = (a * a)) {
        if (b % 2) {
            res = res * a;
        }
    }
    return res;
} 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    i64 ans = 0;
    auto get = [&](int x, int pos) -> i64
    {
        if (x <= 0)
            return 0LL;

        auto s = std::to_string(x);
        s[pos] -= 1;

        for (char ch : s)
        {
            if (!std::isdigit(ch))
                return 0LL;
        }

        for (int i = pos + 1; i < std::size(s); i++)
            s[i] = '9';

        i64 a = 1;
        for (int i = s[0] == '0'; i < std::size(s); i++)
            a *= (s[i] - '0');

        return a;
    };

    for (int i = 0; i < 9; ++i)
        ans = std::max(ans, get(n, i));

    i64 a = 1;
    while (n)
        a *= n % 10, n /= 10;
    ans = std::max(ans, a);

    std::cout << ans << "\n";
    
    return 0;
}