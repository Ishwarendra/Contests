#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int x = 2;

void solve()
{
    int n;
    std::cin >> n;
    // n = 2;

    std::array<i64, 2> a{};
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[i % 2] += x;
    }

    // a[0] = x;
    // a[1] = 3;
    // x += 1;

    // 0 -> bob, 1 -> alice
    auto f = [&](auto && self, std::array<i64, 2> b, int turn) -> int
    {
        if (b[0] == b[1] and b[0] == 0)
        {
            return 1 - turn;
        }
        if (b[0] == 1 and b[1] == 1)
        {
            // print(b)
            return 1 - turn;
        }
        if (b[0] <= 1 and b[1] <= 1)
        {
            // print(b)
            return 0;
        }

        if (turn)
        {
            int win = 0;
            if (b[0] > 1)
            {
                b[0] -= 2;
                win |= self(self, b, turn ^ 1);
                b[0] += 2;
            }

            if (b[1] > 1)
            {
                b[1] -= 2;
                win |= self(self, b, turn ^ 1);
                b[1] += 2;
            }

            return win;
        }
        else
        {
            int win = 1;
            if (b[0])
            {
                b[0]--;
                b[1]++;
                win &= self(self, b, turn ^ 1);
                b[0]++;
                b[1]--;
            }
            if (b[1])
            {
                b[0]++;
                b[1]--;
                win &= self(self, b, turn ^ 1);
                b[0]--;
                b[1]++;
            }

            return win;
        }

        return -1;
    };

    // print(a)
    std::cout << (f(f, a, 1) ? "Alice\n" : "Bob\n");
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