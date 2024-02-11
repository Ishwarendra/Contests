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
	
	std::vector<int> b = a;
	std::vector<int> unsorted;
	
	std::sort(b.begin(), b.end());
	
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			unsorted.push_back(i);
		
	
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