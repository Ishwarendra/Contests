#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<i64> left(n), right(n);
    std::vector<int> cntl(n), cntr(n);
    std::vector<int> posl, posr;

    auto update = [&](int i)
    {
        if (i > 0)
        {
            left[i] += left[i - 1];
            right[i] += right[i - 1];
            cntl[i] += cntl[i - 1];
            cntr[i] += cntr[i - 1];
        }
    };

    for (int i = 0; i < n; i++)
    {
        left[i] += (s[i] == '>') * i;
        right[i] += (s[i] == '<') * i;
        cntl[i] += (s[i] == '>');
        cntr[i] += (s[i] == '<');
        update(i);

        if (s[i] == '<')
            posr.emplace_back(i);
        else
            posl.emplace_back(i);
    }

    auto get = [&](auto &p, int l, int r)
    {
        if (l > r)
            return p[0] - p[0];

        return p[r] - (l > 0 ? p[l - 1] : 0);
    };

    for (int i = 0; i < n; i++)
    {
        int id = i;
        auto id_l = std::lower_bound(std::begin(posl), std::end(posl), id) - std::begin(posl) - 1;
        auto id_r = std::lower_bound(std::begin(posr), std::end(posr), id) - std::begin(posr) - 1;

        int min = std::min(id_l, id_r) + 1;
        if (min == 0)
            
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