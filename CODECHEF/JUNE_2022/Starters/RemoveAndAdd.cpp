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
	
	int l = 0, r = 0, ans = 1e9;
	std::map<int, int> m;
	
	while (l < n)
	{
		while (r < n and m[a[r]] == 0)
			m[a[r++]]++;
		
		int dl = l;
		int dr = n - r;
		
		ans = std::min(ans, std::min(dl, dr) * 2 + std::max(dl, dr));
		m[a[l]]--;
		l++;
	}
	
	std::cout << ans << "\n";
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