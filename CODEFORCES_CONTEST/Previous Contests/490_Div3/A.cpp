#include<bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k;
	std::cin >> n >> k;
	
	std::deque<int> a;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		
		a.push_back(x);
	}		
	
	int cnt = 0;
	
	while (cnt < n)
	{
		if (a.front() <= k)
			cnt++, a.pop_front();
		else if (a.back() <= k)
			cnt++, a.pop_back();
		else
			break;
	}
	
	std::cout << cnt << "\n";
		
	return 0;
}