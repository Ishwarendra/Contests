#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a;
    bool first = true;

    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;

        if (first or x)
        {
            first = false;
            a.emplace_back(x);
        }
    }

    int cnt = 0;
    n = std::size(a);
    
    while (cnt < n - 1)
    {
        
    }

    // while (cnt < n - 1)
    // {
    //     int posa = 0, posb = 0;
    //     int sz = std::size(a);

    //     std::vector<int> b(sz - 1);
    //     for (int i = 0; i < sz - 1; i++)
    //         b[i] = a[i + 1] - a[i];

    //     std::sort(std::begin(b), std::end(b));
    //     print(a, b)

    //     int pos = 0;
    //     first = true;

    //     for (int i = 0; i < std::size(b); i++)
    //     {
    //         if (b[i] or first)
    //         {
    //             first = false;
    //             a[pos++] = b[i];
    //         }
    //     }

    //     a.resize(pos);

    //     if (std::size(a) == 1)
    //         break;
    // }

    std::cout << (std::size(a) ? a[0] : 0) << "\n";
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