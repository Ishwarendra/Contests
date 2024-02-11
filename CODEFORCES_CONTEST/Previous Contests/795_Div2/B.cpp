#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void shuffle(std::vector<int> &a)
{
	int n = a.size();
	if (n % 2)
	{
		int i = 0, j = n - 1;
		while (j - i > 2)
			std::swap(a[i++], a[j--]);
		
		std::swap(a[i], a[i + 1]);
		std::swap(a[i], a[i + 2]);
	}
	else
	{
		int i = 0, j = n - 1;
		while (i < j)
			std::swap(a[i++], a[j--]);
	}
}

void solve()
{
	int n;
	std::cin >> n;

	std::map<int, std::vector<int>> m;
	
	for (int i = 0; i < n; ++i)
	{
		int x;
		std::cin >> x;
		
		m[x].push_back(i);
	}
	
	for (auto &i : m)
	{
		if (i.second.size() <= 1)
		{
			std::cout << "-1\n";
			return;
		}
		
		shuffle(i.second);
	}
	
	for (auto i : m)
	{
		for (auto v : i.second)
			std::cout << v + 1 << " ";
	}
	
	std::cout << "\n";
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