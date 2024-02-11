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
	
	std::vector<int> a(n);
	std::multiset<i64, std::greater<i64>> s;
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		s.insert(a[i] - (n - i - 1));
	}
	
	i64 cnt = 0;
	i64 damage = std::accumulate(a.begin(), a.end(), 0LL);
	
	for (int i = 0; i < k; ++i)
	{
		i64 cur = *s.begin();
		
		damage -= cur + cnt;
		cnt++;
		s.erase(s.begin());
	}
	
	std::cout << damage << "\n";
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