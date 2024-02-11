#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::string w;
    std::cin >> w;

    int p;
    std::cin >> p;

    int price = 0;
    for (int i = 0; i < std::size(w); i++)  
        price += w[i] - 'a' + 1;

    std::vector<std::pair<char, int>> s;
    for (int i = 0; i < std::size(w); ++i)
        s.emplace_back(w[i], i);

    std::sort(std::begin(s), std::end(s), std::greater());

    std::set<int> deleted;
    for (int i = 0; i < std::size(s) and price > p; ++i)
    {
        price -= s[i].first - 'a' + 1;
        deleted.emplace(s[i].second);
    }

    for (int i = 0; i < std::size(w); ++i)
    {
        if (!deleted.count(i))
            std::cout << w[i];
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