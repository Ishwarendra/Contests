#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using namespace std;
using i64 = long long;

class Solution {
    const int inf = 1e9;
    int getBit(int x, int pos) { return x >> pos & 1; }
    void chmin(int &a, int b) { if (a > b) a = b; }
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& edges) {
        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            std::vector d(n, std::vector(n, inf));
            for (int i = 0; i < n; i++)
                d[i][i] = 0;

            for (auto &edge : edges)
            {
                int u = edge[0], v = edge[1], w = edge[2];
                if (getBit(mask, u) | getBit(mask, v))
                    continue;
                    
                chmin(d[u][v], w);
                chmin(d[v][u], w);
            }

            for (int k = 0; k < n; k++)
            {
                for (int u = 0; u < n; u++)
                {
                    for (int v = 0; v < n; v++)
                    {
                        if (d[u][k] == inf or d[k][v] == inf)
                            continue;

                        chmin(d[u][v], d[u][k] + d[k][v]);
                    }
                }
            }

            int max = 0;
            for (int u = 0; u < n; u++)
            {
                for (int v = 0; v < n; v++)
                {
                    if (getBit(mask, u) || getBit(mask, v))
                        continue;
                    max = std::max(max, d[u][v]);
                }
            }

            ans += max <= maxDistance;
        }

        return ans;
    }
};

int main()
{

    return 0;
}