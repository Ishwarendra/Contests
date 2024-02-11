#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, maxi = 0, i = 0;

	cin >> n;

	vector<ll>arr(n);

	int dp[n + 1];

	stack<int>temp;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	while (i < n)
	{
		if (temp.empty())
			temp.push(i);
		else {
			while (!temp.empty() && arr[temp.top()] < arr[i])
			{
				dp[temp.top()] = i;
				temp.pop();
			}
			temp.push(i);
		}
		i++;
	}

	for (int i = 0; i < n; i++)
	{
		int j = i;
		ll temps = arr[i];
		while (dp[j] != -1)
		{
			temps = arr[dp[j]] ^ temps;
			j = dp[j];
		}

		maxi = max(temps, maxi);
	}
	
	cout << maxi << " ";
	return 0;

}