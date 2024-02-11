#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
  		int n = a.size();
  		
  		vector<i64> p(n); 
  		p[0] = a[0];
  		
  		for (int i = 1; i < n; i++)
  			p[i] = p[i - 1] + a[i];
  			
  		int ans = 0;
  		
  		auto f = [&](int i) -> i64
  		{
  			if (i == n - 1)
  				return 1LL * abs(p[i] / (i + 1));
  			
  			return 1LL * abs(p[i] / (i + 1) - (1LL * p[n - 1] - 1LL * p[i]) / (n - 1 - i));	
  		};
  		
  		for (int i = 1; i < n; i++)
  		{
  			if (f(ans) > f(i))
  				ans = i;
  		}
  		
  		return ans;
    }
};

int main()
{
	
	return 0; 
}    