#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

const i64 inf = 1e12;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    int i = 0, j = 0;
    int cnt = 0;

    for (int i = 0; i < k; i++)
        cnt += s[i] == 'B';

    int ans = std::max(0, k - cnt);

    for (int i = k; i < n; i++)
    {
        cnt -= s[i - k] == 'B';
        cnt += s[i] == 'B';

        ans = std::min(ans, k - cnt);
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}