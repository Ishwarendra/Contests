#include<bits/stdc++.h>

int f(int x, int a)
{
	return x/a + x%a;
}

void solve()
{
	int l, r, a;
	std::cin >> l >> r >> a;
	
	int x1 = r;
	int x2 = r - r % a - 1;
	
	if (x2 < l)
		x2 = x1;
	
	std::cout << std::max(f(x2, a), f(x1, a)) << "\n";
}

int main()
{
	int t;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}