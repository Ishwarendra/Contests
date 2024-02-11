#include<bits/stdc++.h>
	
	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		
		int n;
		std::cin >> n;
		
		std::vector<int> a(n + 1);
		
		for (int i = 0; i < n; ++i)
		{
			int x;
			std::cin >> x;
			
			if (x <= n)
				a[x] = 1;
		}
		
		int mex = 0;
		
		while (a[mex] != 0)
			mex++;
		
		std::cout << mex << "\n";
		
		return 0;
	}	