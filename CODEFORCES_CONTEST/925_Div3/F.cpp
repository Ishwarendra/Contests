#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < k; i++)  
	{
		std::vector<int> a(n);
		for (int j = 0; j < n; j++)
			std::cin >> a[j];

		for (int j = 2; j < n; j++)
			adj[a[j - 1] - 1].emplace_back(a[j] - 1);
	}

	auto topo = [&]()
	{
		std::vector<int> indeg(n), vis(n);
		for (int i = 0; i < n; i++)
		{
			for (int v : adj[i])
				indeg[v]++;
		}

		std::queue<int> q;
		for (int i = 0; i < n; i++)
		{
			if (indeg[i] == 0)
			{
				vis[i] = 1;
				q.emplace(i);
			}
		}

		while (!q.empty())
		{
			auto u = q.front();
			q.pop();

			for (int v : adj[u])
			{
				indeg[v]--;
				if (indeg[v] == 0)
				{
					vis[v] = 1;
					q.emplace(v);
				}
			}
		}

		int cnt = std::accumulate(std::begin(vis), std::end(vis), 0);
		return cnt == n;
	};

	if (topo())
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
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