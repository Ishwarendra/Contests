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
	int a, b, c, d;
	std::string s;
	
	std::cin >> a >> b >> c >> d >> s;
	int n = a + b + 2 * c + 2 * d;
	
	if (std::count(s.begin(), s.end(), 'B') != b + c + d)
	{
		std::cout << "No\n";
		return;
	}	
	
	std::vector<int> t2, t3;
	
	i64 extra = 0;
	
	for (int i = 0; i < n;)
	{
		int j = i + 1;
		
		while (j < n and s[j - 1] != s[j])
			j++;
		
		int len = j - i;
		
		if (len % 2)
			extra += len / 2;
		else
		{
			if (s[i] == 'A')
				t2.push_back(len);
			else
				t3.push_back(len);
		}
		
		i = j;
	}
	
	std::sort(t2.begin(), t2.end());
	std::sort(t3.begin(), t3.end());
	
	print(t2, t3);
	
	for (int x : t2)
	{
		int k = x / 2;
		if (c > 0)
		{
			if (k - 1 > c)
			{
				extra += (k - c - 1);
				c = 0;
			}
			else
				c -= k;
		}
		else
			extra += k - 1;
	}
	
	for (int x : t3)
	{
		int k = x / 2;
		
		if (d > 0)
		{
			if (k - 1 > d)
			{
				extra += (k - d - 1);
				d = 0;
			}
			else
				d -= k;
		}
		else
			extra += k - 1;
	}
	
	c = std::max(c, 0);
	d = std::max(d, 0);
	
	std::cout << (extra - c - d >= 0 ? "Yes\n" : "No\n");
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