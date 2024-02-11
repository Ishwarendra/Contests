#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> freq(26);
    for (int i = 0; i < n; i++)  
        freq[s[i] - 'A']++;

    long long ans = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (freq[i])
            ans += 2, freq[i]--;
        if (freq[i])
            ans += freq[i];
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}