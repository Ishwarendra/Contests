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
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 ans = 0;
    i64 cur_ans = 0;
    std::deque<std::pair<int, int>> deque;
    std::set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.emplace(a[i]);
        while (s.count(cur_ans))
            cur_ans++;

        ans += cur_ans;
        if (deque.empty())
            deque.emplace_back(int(cur_ans), 1);
        else
        {
            if (deque.back().first == cur_ans)
                deque.back().second++;
            else
                deque.emplace_back(int(cur_ans), 1);
        }
    }

    cur_ans = ans;
    for (int i = 0; i < n; i++)
    {
        deque.front().second--;
        cur_ans -= deque.front().first;
        if (deque.front().second == 0)
            deque.pop_front();

        int id = std::upper_bound(std::begin(deque), std::end(deque), std::pair{a[i], 0}) - std::begin(deque);
        i64 f = 0;
        while (std::size(deque) != id)
        {
            f += deque.back().second;
            cur_ans -= 1LL * deque.back().first * deque.back().second;
            deque.pop_back();
        }

        if (deque.empty() || deque.back().first < a[i])
            deque.emplace_back(a[i], f);
        else
            deque.back().second += f;

        cur_ans += 1LL * a[i] * f;
        deque.emplace_back(n, 1);
        cur_ans += n;
        ans = std::max(ans, cur_ans);
    }

    std::cout << ans << '\n';
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