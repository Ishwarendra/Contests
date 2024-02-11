#include <bits/stdc++.h>

#define LOCAL

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
	int n;
	std::cin >> n;

	std::vector<int> adj[n], a(n), b(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	for (int i = 0; i < n; ++i)
		std::cin >> b[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		std::cin >> u >> v;
		u--, v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	i64 op = 0;
	std::vector<int> diff(n), nodes(n), black(n), white(n);

	std::function<void(int, int)> dfs2 = [&](int cur, int par)
	{
		diff[cur] += a[cur] != b[cur];
		nodes[cur]++;
		black[cur] += b[cur] == 1;
		white[cur] += b[cur] == 0;

		for (int v : adj[cur])
		{
			if (v != par)
			{
				dfs2(v, cur);
				diff[cur] += diff[v];
				nodes[cur] += nodes[v];
				black[cur] += black[v];
				white[cur] += white[v];
			}
		}
	};
	dfs2(0, -1);
	std::vector<int> changed(n);
	
	std::function<void(int, int)> dfs = [&](int cur, int par)
	{
		if (a[cur] != b[cur])
		{
			changed[cur] = 1;
			op++;
			a[cur] = b[cur];
		}
		else 
		{
			if (a[cur] == 1)
			{
				int b_cnt = black[cur];
				int w_cnt = white[cur];
				
				if (b_cnt - 1 > w_cnt)
				{
					changed[cur] = true;
					op++;
				}
			}
			else
			{
				int b_cnt = black[cur];
				int w_cnt = white[cur];
				
				if (b_cnt + 1 > w_cnt)
				{
					changed[cur] = true;
					op++;
				}
			}
		}

		for (int v : adj[cur])
		{
			if (v != par)
			{
				if (changed[cur])
					a[v] = a[cur];

				dfs(v, cur);
			}
		}
	};
	
	dfs(0, -1);

	std::cout << op << "\n";
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