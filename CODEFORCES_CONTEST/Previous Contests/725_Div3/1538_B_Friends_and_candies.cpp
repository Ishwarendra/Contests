#include<bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	
	sort(a.begin(), a.end());
	
	int sum = std::accumulate(a.begin(), a.end(), 0);
	
	if (sum % n)
		std::cout << "-1\n";
	else
	{
		int k = 0;
		
		for(int i = 0; i < n; i++)
		{
			if (a[i] > sum/n)
				k++;
		}
		
		std::cout << k << "\n";
	}
}

int main()
{
	int t; 
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}