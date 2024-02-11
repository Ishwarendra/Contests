#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int q;
    std::cin >> q;

    std::vector<i64> cnts(26), cntt(26);
    cnts[0] = 1, cntt[0] = 1;

    while (q--)
    {
        int d, k;
        std::string x;
        std::cin >> d >> k >> x;

        for (auto ch : x)
            (d == 1 ? cnts : cntt)[ch - 'a'] += k;

        bool done = false;

        // one big found I win
        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                if (cnts[i] and cntt[j])
                {
                    std::cout << "YES\n";
                    done = true;
                    break;
                }
            }

            if (done)
                break;
        }

        if (done)
            continue;

        // no big found
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (cnts[i] and cntt[j])
                {
                    std::cout << "NO\n";
                    done = true;
                    break;
                }
            }

            if (done)
                break;
        }

        if (done)
            continue;

        // win by size (all char same)
        if (std::accumulate(std::begin(cnts), std::end(cnts), 0LL) < std::accumulate(std::begin(cntt), std::end(cntt), 0LL))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
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