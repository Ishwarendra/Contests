#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    int x = n / 3, extra = n % 3;

    int h1 = n / 3;
    int h2 = n / 3;
    int h3 = n / 3;

    if (extra == 0)
        std::cout << h2 << " " << h1 + 1 << " " <<  h3 - 1 << "\n";
    else if (extra == 1)
    {
        if (n > 7)
            std::cout << h2 + 1 << " " << h1 + 2 << " " << h3 - 2 << "\n";
        else
            std::cout << h1 << " " << h1 + 2 << " " << h1 - 1 << "\n";
    }
    else
        std::cout << h2 + 1 << " " << h2 + 2 << " " << h2 - 1 << "\n";
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