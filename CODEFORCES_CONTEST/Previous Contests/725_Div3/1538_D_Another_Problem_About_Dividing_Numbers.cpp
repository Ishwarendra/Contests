#include<bits/stdc++.h>

std::map<int, int> get_prime_factors(int n)
{
	std::map<int, int> prime_factor;
	
	for(int i = 2; i*i <= n; i++)
	{
		while(n % i == 0)
		{
			prime_factor[i]++;
			n /= i;
		}
	}	
	
	if (n >= 2) // n = 2 fixed
		prime_factor[n]++;
	
	return prime_factor;
}

bool subset(std::map<int, int> &a, std::map<int, int> &b)
{
	for(auto i : a)
	{
		if (i.second > b[i.first])
			return false;
	}
	
	return true;
}

int total_val(const std::map<int, int> &a)
{
	int cnt = 0;
	
	for(auto i : a)
		cnt += i.second;
	
	return cnt;
}

void solve()
{
	int a, b, k;
	std::cin >> a >> b >> k;
	
	std::map<int, int> a_pf = get_prime_factors(a);
	std::map<int, int> b_pf = get_prime_factors(b);	
	
	int limit_a = total_val(a_pf),
		limit_b = total_val(b_pf);
	
	int limit = limit_b + limit_a;
	
	if (limit_a > limit_b)
		std::swap(a_pf, b_pf);
	
	int k_1 = 0;
	
	if (a != b and subset(a_pf, b_pf))
		k_1 = 1;
	
	if (k == 1)
		std::cout << (k_1 ? "YES\n" : "NO\n");
	else if (k <= limit)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}

int main()
{
	int t;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}