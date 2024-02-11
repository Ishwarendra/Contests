#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n), b(n);
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	for (int i = 0; i < n; ++i)
		std::cin >> b[i];
	
	std::vector<int> c(a.begin(), a.end());
	std::sort(c.begin(), c.end());
	
	int op = 0;
	std::vector<std::vector<int>> ans;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] == c[i])
			continue;
		
		int where = i;
		
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] == c[i])
			{
				where = j;
				break;
			}
		}
		
		std::swap(a[i], a[where]);
		std::swap(b[i], b[where]);
		op++;
		
		if (op > 1e4)
		{
			std::cout << "-1\n";
			return;
		}
		
		ans.push_back({i, where});
	}
	
	c = std::vector<int>(b.begin(), b.end());
	std::sort(c.begin(), c.end());
	
	for (int i = 0; i < n; i++)
	{
		if (b[i] == c[i])
			continue;
		
		int where = i;
		
		for (int j = i + 1; j < n; j++)
		{
			if (b[j] == c[i])
			{
				where = j;
				break;
			}
		}
		
		if (a[i] != a[where])
		{
			std::cout << "-1\n";
			return;
		}
		
		std::swap(a[i], a[where]);
		std::swap(b[i], b[where]);
		op++;
		
		if (op > 1e4)
		{
			std::cout << "-1\n";
			return;
		}
		
		ans.push_back({i, where});
	}
	
	if (op > 1e4)
		std::cout << "-1\n";
	else
	{
		std::cout << op << "\n";
		for (auto i : ans)
			std::cout << i[0] + 1 << " " << i[1] + 1 << "\n";
		
		assert(std::is_sorted(a.begin(), a.end()));
		assert(std::is_sorted(b.begin(), b.end()));
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}