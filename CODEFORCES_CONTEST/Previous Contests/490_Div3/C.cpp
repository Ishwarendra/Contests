#include<bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k;
	std::cin >> n >> k;
	
	std::string s;
	std::cin >> s;
	
	std::vector<std::vector<int>> cnt(26); 
	
	for (int i = n - 1; i >= 0; --i)
		cnt[s[i] - 'a'].push_back(i);
	
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (cnt[j].size() > 0)
			{
				s[cnt[j].back()] = '!';
				cnt[j].pop_back();
				break;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (s[i] != '!')
			std::cout << s[i];
	}
	
	std::cout << "\n";
	
	return 0;
}