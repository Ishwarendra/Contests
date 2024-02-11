#include<bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	
	if (std::make_pair(a, b) <= std::make_pair(c, d))
		std::cout << "Takahashi\n";
	else
		std::cout << "Aoki\n";
	
	return 0;
}