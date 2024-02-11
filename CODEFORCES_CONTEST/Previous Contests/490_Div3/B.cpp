#include<bits/stdc++.h>

std::set<int> d;

void divisors(int n)
{
	for (int i = 1; i <= n; i++)
		if (n % i == 0)
			d.insert(i);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::string s;
	
	std::cin >> n >> s;
		
	divisors(n);
	
	for (int i : d)
	{
		std::reverse(s.begin(), s.begin() + i);
	}
	
	std::cout << s << "\n";
	
	return 0;
}