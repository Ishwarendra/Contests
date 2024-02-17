#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
    	std::cin >> a[i];

    if (n == 2)
    {
    	std::cout << (a[0] <= a[1] ? "YES\n" : "NO\n");
    	return;
    }

    if (n == 3)
    {
    	for (int i = 0; i < 2; i++)
    	{
    		if (std::is_sorted(std::begin(a), std::end(a)))
    		{
    			std::cout << "YES\n";
    			return;
    		}

    		std::swap(a[0], a[2]);
    	}

    	std::cout << "NO\n";
    	return;
    }

    std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}