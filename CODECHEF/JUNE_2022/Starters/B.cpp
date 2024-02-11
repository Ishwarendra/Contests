#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
	int n, k;
	std::cin >> n >> k;
	
	if (n % 2 == 0)
		std::cout << "YES\n";
	else
	{
		std::cout << (k % 2 ? "YES\n" : "NO\n");
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