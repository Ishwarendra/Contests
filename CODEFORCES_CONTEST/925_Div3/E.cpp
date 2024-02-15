#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
   	int n, m;
    std::cin >> n >> m;

	int sum = 0;
	std::vector a(n, std::array<int, 2>());
	for (auto &[p, x] : a)
	{
		std::cin >> x;
		int temp = x;

		while (temp % 10 == 0)
			temp /= 10, p++;
	}

	std::sort(std::rbegin(a), std::rend(a));
	int turn = 1;
	for (int i = 0; i < n; i++)
	{
		int tot = std::size(std::to_string(a[i][1]));
		sum += turn ? tot - a[i][0] : tot;
		turn ^= 1;
	}

	std::cout << (sum > m ? "Sasha\n" : "Anna\n");
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