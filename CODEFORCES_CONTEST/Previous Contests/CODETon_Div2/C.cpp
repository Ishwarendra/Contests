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
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (int i = 0; i < m; ++i)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    std::vector<int> diff(m);
    // diff[0] = a[0] - 1;
    // diff[m] = n - a.back();

    for (int i = 1; i < m; i++)
        diff[i - 1] = std::max(0, a[i] - a[i - 1] - 1);

    diff[m - 1] = a[0] + n - a.back() - 1;

    std::sort(std::begin(diff), std::end(diff));

    int can_save = 0;
    int day = 0;
    // print(diff)

    for (int i = m - 1; i >= 0; i--)
    {
        int cur = diff[i] - 2 * day;
        // cur -= day; 

        if (cur <= 2 and cur > 0)
            day++, can_save++;
        else if (cur > 2)
            can_save += cur - 1, day += 2;
    }

    std::cout << n - can_save << "\n";
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