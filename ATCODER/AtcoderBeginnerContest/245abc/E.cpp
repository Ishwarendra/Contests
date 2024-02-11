#include<bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	std::vector<std::vector<int>> choco(n, std::vector<int>(3)), box(m, std::vector<int>(3));
	std::vector<std::vector<int>> cb(n + m, std::vector<int>(3));
	
	for (int i = 0; i < n; i++)
		std::cin >> choco[i][0];
	for (int i = 0; i < n; i++)
		std::cin >> choco[i][1];
	
	for (int i = 0; i < n; i++)
		cb[i][0] = choco[i][0], cb[i][1] = choco[i][1];
		
	for (int i = 0; i < m; i++)
		std::cin >> box[i][0];
	for (int i = 0; i < m; i++)
		std::cin >> box[i][1];
	
	for (int i = n; i < n + m; i++)
	{
		cb[i][0] = box[i - n][0], cb[i][1] = box[i - n][1];
		cb[i][2] = 1;
	}
	
	std::sort(cb.begin(), cb.end(), std::greater<std::vector<int>>());
	
	std::multiset<int> s;
	
	for (int i = 0; i < n + m; i++)
	{
		int id = cb[i][2];
		if (id == 0) // chocolate
		{
			auto it = s.lower_bound(cb[i][1]);
			
			if (it == s.end())
			{
				std::cout << "No\n";
				return 0;
			}
			
			s.erase(it);
		}
		else // box
			s.emplace(cb[i][1]);
	}
	
	std::cout << "Yes\n";
	
	return 0;
}