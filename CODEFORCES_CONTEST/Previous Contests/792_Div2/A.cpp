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
	std::string s;
	std::cin >> s;
	
	char min = '9';
	
	for (char ch : s)
		min = std::min(min, ch);
		
	if (s.length() == 1)
		std::cout << s << "\n";
	else if (s.length() == 2)
		std::cout << s[1] << "\n";
	else
		std::cout << min << "\n";	
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