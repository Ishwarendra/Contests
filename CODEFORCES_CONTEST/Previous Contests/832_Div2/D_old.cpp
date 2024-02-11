#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector xsum(n, 0), zeroes(n, 0);
    std::array<std::map<int, std::vector<int>>, 2> adj{};

    xsum[0] = a[0];
    zeroes[0] = a[0] == 0;
    adj[1][0].emplace_back(-1);
    adj[0][xsum[0]].emplace_back(0);

    for (int i = 1; i < n; i++)
    {
        xsum[i] = xsum[i - 1] ^ a[i];
        zeroes[i] = zeroes[i - 1] + (a[i] == 0);
        adj[i % 2][xsum[i]].emplace_back(i);
    }

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        r--, l--;

        int len = r - l + 1;

        if (zeroes[r] - (l - 1 >= 0 ? zeroes[l - 1] : 0) == r - l + 1)
            std::cout << "0\n";
        else if (len % 2)
        {
            if ((xsum[r] ^ (l - 1 >= 0 ? xsum[l - 1] : 0)) == 0)
                std::cout << "1\n";
            else
                std::cout << "-1\n";
        }
        else
        {
            int x = (l - 1 >= 0 ? xsum[l - 1] : 0);
            auto &p = adj[l % 2][x];

            // find i in adj[l % 2][x] such that l <= i <= r
            auto it = std::lower_bound(std::begin(p), std::end(p), l);
            int moves = 3;


            if (it != std::end(p) and *it <= r)
            {
                int L = *it + 1, R = r;
                int xor_sum = xsum[R] ^ (L - 1 >= 0 ? xsum[L - 1] : 0);

                int ans = 2;
                if (zeroes[R] - (L - 1 >= 0 ? zeroes[L - 1] : 0) == R - L + 1)
                    ans--;
                else if (a[l] == 0 or a[r] == 0)
                    ans--;

                if (xor_sum == 0)
                    moves = std::min(moves, ans);
            }

            x = xsum[r];
            auto &p2 = adj[r % 2 == 0][x];

            // find i in adj[r % 2 == 0][x] such that l <= i <= r
            it = std::lower_bound(std::begin(p2), std::end(p2), l - 1);
            if (it != std::end(p2) and *it <= r)
            {
                int L = l, R = *it;
                int xor_sum = xsum[R] ^ (L - 1 >= 0 ? xsum[L - 1] : 0);

                int ans = 2;
                if (zeroes[R] - (L - 1 >= 0 ? zeroes[L - 1] : 0) == R - L + 1)
                    ans--;
                else if (a[l] == 0 or a[r] == 0)
                    ans--;
                
                if (xor_sum == 0)
                    moves = std::min(moves, ans);
            }

            std::cout << (moves == 3 ? -1 : moves) << "\n";
        }
    }

    return 0;
}