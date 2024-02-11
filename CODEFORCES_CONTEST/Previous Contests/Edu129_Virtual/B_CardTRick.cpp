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
	
	for (int i = 0; i < n; ++i)	
		std::cin >> a[i];
	
	int m;
	std::cin >> m;
	
	std::vector<int> b(m);
	
	for (int i = 0; i < m; i++)
		std::cin >> b[i];
	
	int tp = 0;
	
	for (int i = 0; i < m; i++)
		tp = (tp + b[i]) % n;
	
	std::cout << a[tp] << "\n";
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