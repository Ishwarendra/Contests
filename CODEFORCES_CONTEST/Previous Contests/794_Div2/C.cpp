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

	auto f = [&](const std::vector<int> &ans)
	{
		for (int i = 0; i < n; i++)
		{
			if (ans[i % n] <= ans[(i + 1) % n] and ans[i % n] >= ans[(i - 1 + n) % n])
				return false;

			if (ans[i % n] >= ans[(i + 1) % n] and ans[i % n] <= ans[(i - 1 + n) % n])
				return false;
		}
			
		return true;
	};
	
	std::sort(a.begin(), a.end());
		
	std::vector<int> ans1(n), ans2(n);
	
	int pos1 = 0;
	for (int i = 0; i < n; i += 2)
		ans1[i] = a[pos1++];
	
	for (int i = 1; i < n; i += 2)
		ans1[i] += a[pos1++];
	
	int pos2 = 0;
	for (int i = 1; i < n; i += 2)
		ans2[i] = a[pos2++];
	
	for (int i = 0; i < n; i += 2)
		ans2[i] += a[pos2++];
	
	if (f(ans1))
	{
		std::cout << "YES\n";
		for (int i : ans1)
			std::cout << i << " ";
		std::cout << "\n";
		
		return;
	}
	
	if (f(ans2))
	{
		std::cout << "YES\n";
		for (int i : ans2)
			std::cout << i << " ";
		std::cout << "\n";
		
		return;
	}
	
	std::cout << "NO\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}