#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x;
    std::cin >> x;

    std::string s;
    for (int i = 0; i < 3; i++)
    {
    	int ch = x - 3 + i;

    	if (ch < 26)
    		s += char(ch + 'a'), x -= ch + 1;
    	else
    		s += 'z', x -= 26;
    }  

    std::reverse(std::begin(s), std::end(s));
    std::cout << s << "\n";
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