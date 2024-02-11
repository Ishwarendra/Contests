#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::map<char, int> map {{'w', 0}, {'i', 1}, {'n', 2}};
std::map<int, char> mapinv {{0, 'w'}, {1, 'i'}, {2, 'n'}};

void solve()
{
    int m;
    std::cin >> m;

    std::vector a(m, std::array<int, 3> {});
    for (int i = 0; i < m; i++)
    {
        std::string s;
        std::cin >> s;

        for (auto ch : s)
            a[i][map[ch]]++;
    }

    std::vector<std::tuple<int, int, int, int>> ans;

    // TODO: 2-people swap
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;

            std::vector<int> donor_i, donor_j;
            for (int k = 0; k < m; k++)
            {
                // person k give i take j
                if (a[k][i] > 1 and a[k][j] == 0)
                    donor_i.emplace_back(k);
                // person k give j take i
                if (a[k][j] > 1 and a[k][i] == 0)
                    donor_j.emplace_back(k);
            }

            // print(donor_i, donor_j)
            for (int k = 0; k < std::size(donor_i) and k < std::size(donor_j); k++)
            {
                ans.emplace_back(donor_i[k] + 1, i, donor_j[k] + 1, j);
                a[donor_i[k]][i]--;
                a[donor_i[k]][j]++;

                a[donor_j[k]][j]--;
                a[donor_j[k]][i]++;
            }
        }
    }

    // 3-people swap
    // p1 give i, p2 give j => (p2 happy) => Now p1, p3.
    // 3 0 0 -> 2 0 1 -> 1 1 1
    // 0 1 2 -> 1 1 1 -> 1 1 1
    // 0 2 1 -> 0 2 1 -> 1 1 1

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (i == j or j == k or i == k)
                    continue;

                std::vector<int> donor_i, donor_j, donor_k;

                for (int p = 0; p < m; p++)
                {
                    // donate i, need j
                    if (a[p][i] > 1 and !a[p][j])
                        donor_i.emplace_back(p);

                    // donate j, need k
                    if (a[p][j] > 1 and !a[p][k])
                        donor_j.emplace_back(p);

                    // donate k, need i
                    if (a[p][k] > 1 and !a[p][i])
                        donor_k.emplace_back(p);
                }

                // print(donor_i, donor_j, donor_k)
                // print(mapinv[i], mapinv[j], mapinv[k])
                int end = std::min({std::size(donor_i), std::size(donor_j), std::size(donor_k)});
                for (int p = 0; p < end; p++)
                {
                    ans.emplace_back(donor_i[p] + 1, i, donor_j[p] + 1, j);
                    ans.emplace_back(donor_j[p] + 1, i, donor_k[p] + 1, k);

                    a[donor_i[p]][i]--, a[donor_i[p]][j]++;
                    a[donor_j[p]][j]--, a[donor_j[p]][k]++;
                    a[donor_k[p]][k]--, a[donor_k[p]][i]++;
                }
            }
        }
    }

    std::cout << std::ssize(ans) << "\n";
    for (auto [x, y, z, w] : ans)
        std::cout << x << " " << mapinv[y] << " " << z << " " << mapinv[w] << "\n";
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