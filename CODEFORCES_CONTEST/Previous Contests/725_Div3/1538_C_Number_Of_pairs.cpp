#include<bits/stdc++.h>

#define int long long

void solve()
{
	int n, l, r;
	std::cin >> n >> l >> r;
	
	std::vector<int> a(n);
	
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	sort(a.begin(), a.end());
	
	int ans_low = 0, ans_high = 0;
	
	for(int i = 0; i < n; i++)
	{
		ans_low += std::lower_bound(a.begin(), a.end(), 1 + r - a[i]) - a.begin();
		ans_high -= std::lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
		
		if (a[i] * 2 >= l and a[i] * 2 <= r)
			ans_low--;		
	}
	
	std::cout << (ans_high + ans_low) / 2 << "\n";
}

int32_t main()
{
	int t;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}