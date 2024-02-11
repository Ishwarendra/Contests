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

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    if (n == 1)
    {
        std::cout << "-1\n";
        return;
    }

    std::set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);

    std::vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        if (s.size() == 1)
            b[i] = *s.begin(), s.erase(s.begin());
        else 
        {
            if (*s.begin() == a[i])
            {
                b[i] = *(++s.begin());
                s.erase(++s.begin());
            }
            else
                b[i] = *s.begin(), s.erase(s.begin());
        }
    }

    if (b[n - 1] == a[n - 1])
        std::swap(b[n - 1], b[n - 2]);

    for (int i : b)
        std::cout << i << " ";
    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}