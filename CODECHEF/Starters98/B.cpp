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
    std::string s;
    std::cin >> n >> s;

    std::vector<int> adj[26];
    for (int i = 0; i < n; i++)
        adj[s[i] - 'a'].emplace_back(i);

    if (n % 3 == 1)
        std::cout << "YES\n";
    else
    {
        int possible = 0;
        for (int ch = 0; ch < 26; ch++)
        {
            int i = 0, j = std::size(adj[ch]);
            j--;

            while (i < j)
            {
                if (adj[ch][i] % 3 != 0)
                    i++;
                else if ((n - 1 - adj[ch][j]) % 3 != 0)
                    j--;
                else
                {
                    possible = 1;
                    break;
                }
            }
        }

        std::cout << (possible ? "YES\n" : "NO\n");
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