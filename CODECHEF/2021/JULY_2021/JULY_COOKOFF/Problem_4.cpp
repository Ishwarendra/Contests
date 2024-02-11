#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while(t--)
	{
	    int n; cin >> n;
	    vector<long long> a(n);
	    ll mini = 2*(1e9 + 7);    
	    for(int i = 0; i < n; i++)
	    {
	        cin >> a[i];
	        mini = min(mini, a[i]);
	    }	        
	    
	    int ans = 0; bool flag = false;
	    
	    for(int i = 0; i < n; i++)
	    {
	        if (a[i] == mini) continue;
	        if (a[i] <= 2*mini)
	            flag = true;
	        else
	            ans++;
	                   
	    }
        if (flag) // element which is less than 2*min_element_in_array is found.
            ans = n;

        cout << ans << '\n';   
	}
    
	return 0;
}
