#include<bits/stdc++.h>

#define int long long

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> a(n), rem(n), cnt(m);
	
	std::vector<std::set<int>> pos(m);
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		
		rem[i] = a[i] % m;
		pos[rem[i]].insert(i);
		
		cnt[rem[i]]++;
	}
	
	std::vector<int> to_add(m);
	
	for (int i = 0; i < 2 * m; i++)
	{
		if (cnt[i % m] > n / m)
		{
			cnt[(i + 1) % m] += cnt[i % m] - (n / m);
			
			to_add[i % m] += cnt[i % m] - n / m;
			
			cnt[i % m] = n / m;
		}
	}
	
	int total_op = 0;
	
	// for (int i = 0; i < m; i++)
	// 	std::cout << to_add[i] << " \n"[i == m - 1];
	
	for (int i = 0; i < m; i++)
	{
		int counter = 0;
		
		std::set<int> cur = pos[i], next = pos[(i + 1) % m];
		
		for (int id : pos[i])
		{
			if (counter == to_add[i % m])
				break;
			
			total_op++;
			a[id]++;
			
			cur.erase(id);
			next.emplace(id);
							
			counter++;
		}
		
		pos[i] = cur;
		pos[(i + 1) % m] = next;
	}
	
	std::cout << total_op << "\n";
	
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " \n"[i == n - 1];
	
	return 0;
}