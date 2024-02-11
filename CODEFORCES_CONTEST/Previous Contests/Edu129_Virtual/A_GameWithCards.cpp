#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

void solve()
{
	int n, m;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)	
		std::cin >> a[i];
	
	std::cin >> m;
	
	std::vector<int> b(m);
	
	for (int i = 0; i < m; ++i)
		std::cin >> b[i];
	
	int alice = *std::max_element(a.begin(), a.end());
	int bob = *std::max_element(b.begin(), b.end());
	
	if (alice > bob)
		std::cout << "Alice\n" << "Alice\n";
	else if (bob > alice)
		std::cout << "Bob\n" << "Bob\n";
	else
		std::cout << "Alice\n" << "Bob\n";
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