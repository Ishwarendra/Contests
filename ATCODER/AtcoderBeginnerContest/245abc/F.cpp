#include<bits/stdc++.h>

// Reverse the graph and then search for 0 outdeg eles
// delete each outdeg ele 

int n, m;
std::vector<std::vector<int>> adj;
std::vector<int> outdeg;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n >> m;
	
	adj.resize(n + 1);
	outdeg.resize(n + 1);
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		std::cin >> u >> v;
		
		adj[v].push_back(u);
		outdeg[u]++;
	}
	
	std::queue<int> q;
	
	for (int i = 1; i <= n; i++)
		if (outdeg[i] == 0)
			q.push(i);
		
	int ans = n;
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		ans--;
		
		for (int nb : adj[cur])
		{
			outdeg[nb]--;
			
			if (outdeg[nb] == 0)
				q.push(nb);
		}
	}
	
	std::cout << ans << "\n";
	
	return 0;
}