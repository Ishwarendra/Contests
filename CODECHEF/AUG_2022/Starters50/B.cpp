#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::deque<int> d;

    int cur = 1;
    while (cur <= n)
    {
        if (cur & 1)
            d.push_back(cur);
        else
            d.push_front(cur);

        cur++;
    }

    while (!d.empty())
    {
        std::cout << d.front() << " ";
        d.pop_front();
    }
    std::cout << "\n";
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