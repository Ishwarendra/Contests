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
	i64 n, k;
	std::cin >> n >> k;
	
	std::string even = "EVEN", odd = "ODD";
	
	if (k == 1)
		std::cout << (n % 2 ? odd : even) << "\n";
	else if (k == 2)
		std::cout << odd << "\n";
	else
		std::cout << even << "\n";
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