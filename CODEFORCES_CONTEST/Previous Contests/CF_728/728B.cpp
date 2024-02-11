#include <iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;

bool is_present(ll n, ll a, ll b)
{
	if (a != 1)
	{
		for(ll i = 1; i < n+1; i *= a)
			if ((n-i) % b == 0)
				return true;
	
	return false;
	}

	if (a == 1) // worst case
	{
		if ((n-1) % b == 0)
			return true;

		return false;
	}
}

void weirdaf()
{
	ll n, a, b;
		cin >> n >> a >> b;
		if (is_present(n, a, b))
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
}

int main()
{
	FIO
	ll testcases;
	cin >> testcases;

	while (testcases--)
	{
		weirdaf();
	}
	return 0;
}