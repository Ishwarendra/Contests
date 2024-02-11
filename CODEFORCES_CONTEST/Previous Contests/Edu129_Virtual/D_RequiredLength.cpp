#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 7e18;

i64 n, x;
std::map<i64, i64> dp;

std::set<i64, std::greater<i64>> get_digits(i64 num)
{
	std::set<i64, std::greater<i64>> ans;
	
	while (num)
	{
		ans.insert(num % 10);
		num /= 10;	
	}
	
	return ans;
}

i64 f(i64 num)
{
	auto s = std::to_string(num);
	if (s.length() == n)
		return 0;
	
	if (dp.find(num) != dp.end())
		return dp[num];
	
	dp[num] = inf;
	
	std::set<i64, std::greater<i64>> dig = get_digits(num);
	
	for (auto d : dig)
	{
		if (d <= 1)
			break;
		
		dp[num] = std::min(dp[num], f(num * d) + 1LL);
	}
	
	return dp[num];
}

void solve()
{
	std::cin >> n >> x;
	
	i64 ans = f(x);
	
	std::cout << (ans == inf ? -1 : ans) << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}