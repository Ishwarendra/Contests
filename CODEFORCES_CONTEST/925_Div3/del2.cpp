#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

long getkRepValue1(std::string user_history, int k)
{
	int n = std::size(user_history);
	std::vector f(n, std::array<int, 26>());
	for (int i = 0; i < n; i++)
	{
		char ch = user_history[i];
		f[i][ch - 'a']++;

		for (int j = 0; i > 0 and j < 26; j++)
			f[i][j] += f[i - 1][j];
	}

	auto get = [&](int st)
	{
		int left = st, right = n - 1;
		int ans = n;

		auto good = [&](int mid)
		{
			for (int ch = 0; ch < 26; ch++)
			{
				int cnt = f[mid][ch];
				if (st)
					cnt -= f[st - 1][ch];

				if (cnt >= k)
					return true;
			}

			return false;
		};

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (good(mid))
				ans = mid, right = mid - 1;
			else
				left = mid + 1;
		}

		return ans;
	};

	long ans = 0;
	for (int i = 0; i < n; i++)
		ans += n - get(i);

	return ans;
}

long getkRepValue(std::string s, int k)
{
	long long ans = 0;
	char ch = 'a';

	for (int it = 0; it < 26; it++)
	{
		ch += it;
		int cnt = 0;

		for (int i = 0, j = 0; i < s.size(); i++)
		{
			cnt += s[i] == ch;
			while (cnt >= k and j <= i)
			{
				if (s[j] == ch)
					cnt--;
				j++;
			}
		ans += j;
		}

	}

	return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    int k;

    std::cin >> k;
    std::cin >> s;

    std::cout << getkRepValue(s, k);
    
    return 0;
}