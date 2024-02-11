#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::map<int, int> m;
    int min = 1e9 + 8;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] < min)
        {
            min = a[i];
            m[i] = min;
        }
    }
        
    while (q--)
    {
        int k, d;
        std::cin >> k >> d;
        k--;

        a[k] -= d;
        auto it = m.lower_bound(k);

        if (it != m.begin())
        {
            --it;
            if (it->second > a[k])
                m[k] = a[k]; // new train
        }
        else
            m[k] = a[k];

        while (true)
        {
            it = m.upper_bound(k);
            if (it != m.end() and it->second >= a[k])
                m.erase(it);
            else
                break;
        }
        std::cout << m.size() << " ";
    }

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