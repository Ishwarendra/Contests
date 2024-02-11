#include <bits/stdc++.h>

// #define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> a(n, std::vector<int>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> a[i][j];

	std::pair<int, int> ans {0, 0};
	std::pair<int, int> to_swap { -1, -1};

	for (int i = 0; i < n; i++)
	{
		if (std::is_sorted(a[i].begin(), a[i].end()))
			continue;
		else
		{
			std::vector<int> tmp = a[i];
			std::sort(tmp.begin(), tmp.end());

			for (int j = 0; j < m; j++)
			{
				if (tmp[j] != a[i][j] and to_swap.first == -1)
					to_swap.first = j;
				else if (tmp[j] != a[i][j])
					to_swap.second = j;
			}
		}
	}

	if (to_swap.first == -1)
	{
		std::cout << "1 1\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		assert(to_swap.second != -1);
		print(to_swap)
		std::swap(a[i][to_swap.first], a[i][to_swap.second]);
	}

	for (int i = 0; i < n; ++i)
	{
		if (!std::is_sorted(a[i].begin(), a[i].end()))
		{
			std::cout << "-1\n";
			return;
		}
	}

	std::cout << to_swap.first + 1 << " " << to_swap.second + 1 << "\n";
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