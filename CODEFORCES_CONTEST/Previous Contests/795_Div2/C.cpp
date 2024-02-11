#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

i64 f(std::string &a)
{
	int n = a.size();
	i64 ans = 0;
	
	for (int i = 0; i < n - 1; ++i)
		ans += std::stoll(a.substr(i, 2));
		
	return ans;	
}

void solve()
{
	i64 n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	int one = std::count(s.begin(), s.end(), '1');
	
	if (one == 0)
		std::cout << "0\n";
	else if (one == 1)
	{
		int pos = 0;
		
		for (int i = 0; i < n; i++)
			if (s[i] == '1')
				pos = i;
		
		if (k >= n - pos - 1)
			std::cout << "1\n";
		else if (k >= pos)
			std::cout << "10\n";
		else
			std::cout << "11\n";  
	}
	else
	{
		int first = n - 1, last = 0;
		
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				first = std::min(first, i);
				last = std::max(last, i);
			}
		}
		
		if (k >= n - last - 1)
		{
			k -= (n - last - 1);
			std::swap(s[n - 1], s[last]);
		}
		
		if (k >= first)
		{
			k -= first;
			std::swap(s[0], s[first]);
		}
		
		std::cout << f(s) << "\n";
	}
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