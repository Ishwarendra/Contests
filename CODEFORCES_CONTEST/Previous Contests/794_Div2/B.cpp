#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	int max = *std::max_element(a.begin(), a.end());
	
	std::stack<int> st;
	st.push(a[0]);
	int ans = 0;
	
	for (int i = 1; i < n; ++i)
	{
		if (st.empty() or a[i] > st.top())
			st.push(a[i]);
		else
		{
			ans++;	
			
			while (st.size())
				st.pop();
		}
	}
	
	std::cout << ans << "\n";
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