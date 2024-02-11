#include <bits/stdc++.h>

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
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	
	std::sort(a.begin(), a.end());
	i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
	
	if (sum % n)
		std::cout << "NO\n";
	else
	{
		int avg = sum / n;
		if (count(a.begin(), a.end(), avg))
			std::cout << "YES\n";
		else
			std::cout << "NO\n";		
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