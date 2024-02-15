#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
	int n, x, y, s;
	std::cin >> n >> x >> y >> s;

	std::vector<int> a(n);
	a[0] = x;
	std::fill(1 + std::begin(a), std::end(a), x % y);

	i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
	i64 max_sum = 0;

	for (int i = 0; i < n; i++)
		max_sum += x + 1LL * i * y;

	if (s > max_sum or s < sum or (s - sum) % y)
	{
		std::cout << "NO\n";
		return;
	}

	int need = (s - sum) / y;
	std::vector<int> wt, val;
	for (int i = 1; ; i++)
	{
		wt.emplace_back(i + 1);
		val.emplace_back(i * (i + 1) / 2);

		if (i * (i + 1) / 2 > need) 
			break;
	}

	int sz = std::size(wt);

	auto chmin = [&](int &x, int y)
	{
		if (x > y)
		{
			x = y;
			return true;
		}

		return false;
	};

	std::vector<int> dp(need + 1, inf), par(need + 1, -1);
	dp[0] = 0;

	for (int j = 1; j <= need; j++)
	{
		for (int i = 0; i < sz; i++)
		{
			if (j - val[i] < 0)
				continue;

			if (chmin(dp[j], dp[j - val[i]] + wt[i]))
				par[j] = i;
		}
	}

	for (int i = 0; i < sz; i++)
	{
		if (dp[need] > n - wt[i] + 1)
		{
			a[i + 1] = a[i] + y;
			need -= a[i + 1] / y;

			if (need < 0)
			{
				std::cout << "NO\n";
				return;
			}
		}
		else
		{
			// find the best way to get "need" value
			int cur_id = i + 1;
			while (need > 0)
			{
				int w = wt[par[need]], v = val[par[need]];
				for (int id = 0; id < w; id++)
				{
					print(cur_id + id)
					a[cur_id + id] += id * y; 
				}

				need -= v;
				cur_id += w;
			}

			break;
		}
	}

	if (need != 0)
		std::cout << "NO\n";
	else
	{
		std::cout << "YES\n";
		for (int i = 0; i < n; i++)
			std::cout << a[i] << " \n"[i == n - 1];
	}
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}