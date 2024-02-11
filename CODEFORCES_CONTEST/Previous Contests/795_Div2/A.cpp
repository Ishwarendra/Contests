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
	
	std::vector<int> a(n);
	int odd = 0;
	
	for (int i = 0; i < n; ++i)	
	{
		std::cin >> a[i];
		odd += a[i] % 2;
	}
	
	std::cout << std::min(odd, n - odd) << "\n";
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