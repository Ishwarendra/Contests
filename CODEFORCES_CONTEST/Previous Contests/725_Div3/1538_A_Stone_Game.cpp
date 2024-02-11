#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	int max_id = std::max_element(a.begin(), a.end()) - a.begin();
	int min_id = std::min_element(a.begin(), a.end()) - a.begin();
	
	int case1 = std::max(min_id + 1, max_id + 1);
	int case2 = std::max(n - min_id, n - max_id);
	int case3 = std::min(max_id, min_id) + 1 + n - std::max(min_id, max_id);
	
	std::cout << std::min({case1, case2, case3}) << "\n";
}

int main()
{
	int t; 
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0; 
}    