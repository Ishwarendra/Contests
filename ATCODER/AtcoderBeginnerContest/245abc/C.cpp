#include<bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> a(n), b(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	
	for (int i = 0; i < n; i++)
		std::cin >> b[i];
	
	std::vector<std::vector<int>> dp(n, std::vector<int>(2));
	
	dp[0] = {1, 1};
	
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = (dp[i - 1][0] and abs(a[i] - a[i - 1]) <= k) or (dp[i - 1][1] and abs(b[i - 1] - a[i]) <= k);
		dp[i][1] = (dp[i - 1][0] and abs(b[i] - a[i - 1]) <= k) or (dp[i - 1][1] and abs(b[i - 1] - b[i]) <= k);
	}
	
	if (dp[n - 1][0] or dp[n - 1][1])
		std::cout << "Yes\n";
	else
		std::cout << "No\n";
	
	return 0;
}