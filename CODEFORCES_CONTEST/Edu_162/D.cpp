#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

std::vector<int> nextGreater(std::vector<int> &a)
{
    int n = std::size(a);
    std::vector<int> ng(n);

    std::stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and a[s.top()] <= a[i])
            s.pop();

        ng[i] = (s.empty() ? -1 : s.top());
        s.emplace(i);
    }

    return ng;
}

std::vector<int> prevGreater(std::vector<int> &a)
{
    int n = std::size(a);
    std::vector<int> pg(n);

    std::stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and a[s.top()] <= a[i])
            s.pop();

        pg[i] = (s.empty() ? -1 : s.top());
        s.emplace(i);
    }

    return pg;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)      
        std::cin >> a[i];

    std::vector<i64> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1] + a[i];

    auto ng = nextGreater(a);
    auto pg = prevGreater(a);

    std::vector<int> nuneq(n, -1), puneq(n, -1);
    for (int i = n - 2; i >= 0; i--)
        nuneq[i] = (a[i] != a[i + 1] ? i + 1 : nuneq[i + 1]);

    for (int i = 1; i < n; i++)
        puneq[i] = (a[i] != a[i - 1] ? i - 1 : puneq[i - 1]);

    for (int i = 0; i < n; i++)
    {
        int ans = inf;
        if (pg[i] != -1)
        {
            // print(i, pg[i], i - pg[i])
            ans = std::min(ans, i - pg[i]);
        }
        if (ng[i] != -1)
        {
            // print(i, ng[i], ng[i] - i);
            ans = std::min(ans, ng[i] - i);
        }

        auto getRight = [&](int val)
        {
            auto good = [&](int mid)
            {
                if (i + 1 >= n)
                    return false;

                // i + 1 to mid
                int nex = nuneq[i + 1];
                if (nex == -1 or nex > mid)
                    return false;

                i64 sum = pref[mid] - pref[i];
                return sum > val;
            };

            int left = i + 1, right = n - 1;
            int id = -1;
            while (left <= right)
            {
                int mid = std::midpoint(left, right);
                if (good(mid))
                    id = mid, right = mid - 1;
                else
                    left = mid + 1;
            }

            return id;
        };

        auto getLeft = [&](int val)
        {
            auto good = [&](int mid)
            {
                if (i - 1 < 0)
                    return false;

                // mid to i - 1
                int prev = puneq[i - 1];
                if (prev == -1 or prev < mid)
                    return false;

                i64 sum = pref[i - 1] - (mid ? pref[mid - 1] : 0);
                return sum > val;
            };

            int left = 0, right = i - 1;
            int id = -1;
            while (left <= right)
            {
                int mid = std::midpoint(left, right);
                if (good(mid))
                    id = mid, left = mid + 1;
                else
                    right = mid - 1;
            }

            return id;
        };

        int prev = getLeft(a[i]);
        int next = getRight(a[i]);

        if (prev != -1)
            ans = std::min(ans, i - prev);
        if (next != -1)
            ans = std::min(ans, next - i);

        std::cout << (ans == inf ? -1 : ans) << " \n"[i == n - 1];
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