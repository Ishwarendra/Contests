#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n, x;
    std::cin >> n >> x;

    if (n == 1)
    {
        std::cout << (x == 1 ? "a\n" : "-1\n");
        return;
    }

    std::string s;
    for (int i = 0; i < x; i++)
        s += char(i + 'a');

    for (int i = x - 1 - n % 2; i >= 0; i--)
        s += char(i + 'a');

    if (s.size() > n)
        std::cout << "-1\n";
    else
    {
        int rem = (n - s.size()) / 2;
        for (int i = 0; i < rem; ++i)
            std::cout << "a";
        std::cout << s;
        for (int i = 0; i < rem; ++i)
            std::cout << "a";

        std::cout << "\n";
    }  
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