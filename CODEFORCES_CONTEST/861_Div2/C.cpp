#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int diff(std::string s)
{
    std::sort(std::begin(s), std::end(s));
    return s.back() - s.front();
}

void solve()
{
    i64 l, r;
    std::cin >> l >> r;

    auto a = std::to_string(l), b = std::to_string(r);
    if (std::size(a) != std::size(b))
    {
        std::cout << std::string(std::size(a), '9') << '\n';
        return;
    }

    if (l == r)
    {
        std::cout << l << "\n";
        return;
    }

    int n = std::size(a);
    std::string c;
    int i = 0;
    while (i < n)
    {
        if (a[i] == b[i])
            c += a[i++];
        else
            break;
    }

    int ans = diff(a);
    std::string final = a;

    auto work = [&](char min, char max)
    {
        for (char ch = min; ch <= max; ch++)
        {
            c += ch;
            if (ans > diff(c))
            {
                ans = diff(c);
                final = c;
            }
            c.pop_back();
        }
    };

    work(a[i] + 1, b[i] - 1);

    std::function<void(int, std::string &s, bool)> f = [&](int id, std::string &s, bool min)
    {
        if (id >= n)
            return;

        c += s[id];
        if (id + 1 < n)
        {
            if (min)
                work('0', s[id + 1] - 1);
            else
                work(s[id + 1] + 1, '9');

            f(id + 1, s, min);
        }
        else
        {
            print(c)
            if (ans > diff(c))
            {
                ans = diff(c);
                final = c;
            }
        }

        c.pop_back();
    }; 
    f(i, a, false);
    f(i, b, true);

    while (std::size(final) < n)
        final += final.back();

    std::cout << final << "\n";
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