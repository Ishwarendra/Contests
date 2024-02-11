#include <bits/stdc++.h>

// #define LOCAL 1

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
	i64 a, b, c;
	std::cin >> a >> b >> c;
	
	i64 x = a + b + c;
	i64 y = b + c;
	i64 z = c;
	
	std::cout << x << " " << y << " " << z << "\n";
	
	assert(x % y == a and y % z == b and z % x == c);
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