#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> lis(std::vector<int> const& a) {
    int n = a.size();
    std::vector<int> d(n, 1), p(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    std::vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }
    std::reverse(subseq.begin(), subseq.end());
    return subseq;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto get = [&](std::vector<int> c)
    {
        int ans = 0;
        for (int i = 1; i < std::size(c); i++)
            ans += c[i - 1] < c[i];

        return ans;
    };

    std::vector<std::pair<int, int>> b;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            b.emplace_back(a[i], i);
            b.emplace_back(a[i + 1], i + 1);
        }
    }

    std::vector<int> c, e;
    std::vector<int> done(n);
    for (auto [num, i] : b)
    {
        if (done[i])
            continue;
        done[i] = 1;
        c.emplace_back(a[i]);
    }

    if (c.empty())
    {
        std::cout << get(a) << "\n";
        return;
    }

    auto d = lis(c);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (j >= std::size(d))
            e.emplace_back(a[i]);
        else
        {
            if (d[j] == a[i])
                j++;
            else
                e.emplace_back(a[i]);
        }
    }
    
    print(c, d, e)
    std::cout << get(d) + get(e) << "\n";
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