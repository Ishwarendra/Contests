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
            if (a[j] <= a[i] && d[i] <= d[j] + 1) {
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

    if (n <= 2)
    {
        std::cout << "0\n";
        return;
    }

    auto get = [&](int id1, int id2)
    {
        std::vector<int> b, c;
        b.emplace_back(a[id1]);
        b.emplace_back(a[id2]);

        int st = 3;
        if (id1 == 0 and id2 == 1) st--;
        else c.emplace_back(a[3 - id1 - id2]);

        for (int i = st; i < n; i++)
        {
            if (b.back() < a[i] and c.empty())
                c.emplace_back(a[i]);
            else if (b.back() >= a[i] and c.empty())
                b.emplace_back(a[i]);
            else if ((b.back() < a[i] and c.back() < a[i]) or (b.back() >= a[i] and c.back() >= a[i]))
            {
                if (b.back() < c.back())
                    b.emplace_back(a[i]);
                else
                    c.emplace_back(a[i]);
            }
            else if (b.back() < a[i])
                c.emplace_back(a[i]);
            else
                b.emplace_back(a[i]);
        }

        int ans = 0;
        for (int i = 0; i + 1 < std::size(b); i++)
            ans += b[i] < b[i + 1];
        for (int i = 0; i + 1 < std::size(c); i++)
            ans += c[i] < c[i + 1];

        // print(ans, b, c)
        return ans;
    };

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += a[i] < a[i + 1];

    for (int i = 0; i < 2; i++)
        ans = std::min(ans, get(i, i + 1));
    ans = std::min(ans, get(0, 2));

    std::cout << ans << "\n";
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