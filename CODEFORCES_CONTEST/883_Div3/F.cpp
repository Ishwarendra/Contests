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
    std::cin >> n;
    
    std::vector<int> a(n);
    std::array<int, 10> cnt{};
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        cnt[a[i]]++;
    }

    int can = 1;
    int currentType = 0;
    while (can)
    {
        std::cout << "- 0" << std::endl;
        std::array<int, 10> cnt2{};

        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            cnt2[a[i]]++;
        }

        for (int i = 1; i < 10; i++)
        {
            if (cnt2[i] > cnt[i])
            {
                can = 0;
                currentType = i;
                break;
            }
        }

        std::swap(cnt, cnt2);
    }

    std::vector<int> del;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == currentType)
            continue;
        del.emplace_back(i + 1);
        cnt[a[i]]--;
    }

    std::cout << "- " << std::size(del) << " ";
    for (auto d : del)
        std::cout << d << " ";
    std::cout << std::endl;

    n = n - std::size(del);
    can = 1;

    while (can)
    {
        a.resize(n);
        std::array<int, 10> cnt2{};
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            cnt2[a[i]]++;
        }

        for (int i = 1; i < 10; i++)
        {
            if (cnt2[i] > cnt[i])
            {
                std::cout << "! " << std::find(std::begin(a), std::end(a), i) - std::begin(a) + 1 << std::endl;
                return;
            }
        }

        std::cout << "- 0" << std::endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}