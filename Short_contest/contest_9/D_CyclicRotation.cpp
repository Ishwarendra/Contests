#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n + 1, -1);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < n; ++i)
        std::cin >> b[i + 1];
    std::vector<int> freq(n + 1);

    int i = n - 1, j = n;

    while (i >= 0)
    {
        if (a[i] == b[j])
        {
            j--;
            i--;
            continue;
        }
        else
        {
            if (j > 0 and j + 1 <= n and b[j] == b[j + 1])
            {
                freq[b[j]]++;
                j--;
            }
            else if (freq[a[i]])
            {
                freq[a[i]]--;
                i--;
            }
            else
            {
                std::cout << "NO\n";
                return;
            }
        }
    }

    for (int i : freq)
    {
        if (i)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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