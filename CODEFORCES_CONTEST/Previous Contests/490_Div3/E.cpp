#include<bits/stdc++.h>

std::vector<std::set<int>> adj;
int n, m, root;
std::vector<std::pair<int, int>> indeg;

int ans = 0;

void bfs(int cur, std::vector<bool> &vis)
{
	std::queue<int> q;
	q.push(cur);
	
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		
		vis[i] = true;
		
		for (int nb : adj[i])
		{
			if (not vis[nb])
				q.push(nb);
		}
	}	
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> m >> root;

	adj.resize(n + 1);
	indeg.resize(n + 1);
		
	for (int i = 1; i <= n; i++)
		indeg[i].second = i;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;

		adj[u].emplace(v);
		indeg[v].first++;
		indeg[v].second = v;
	}

	std::sort(indeg.begin(), indeg.end());
		
	std::vector<bool> vis(n + 1); // which nodes can be visited at 0 cost

	// 0-distance nodes
	bfs(root, vis);
	
	
	for (int i = 1; i < indeg.size(); i++)
	{
		// std::cout << indeg[i].second << " " << indeg[i].first << " a\n";
		if (indeg[i].first == 0 and indeg[i].second != root)
		{
			if (not vis[indeg[i].second])
			{
				ans++;
				adj[root].emplace(indeg[i].second);
				
				// std::cout << root << " " << indeg[i].second << "\n";
					
				bfs(root, vis);
			}
		}
		
		else if (indeg[i].second == root and adj[root].size() == 0)
		{
			ans++;
			adj[root].emplace(indeg[i].second);
			
			bfs(root, vis);
		}
	}
	
	std::cout << ans << "\n";
	
	return 0;
}

