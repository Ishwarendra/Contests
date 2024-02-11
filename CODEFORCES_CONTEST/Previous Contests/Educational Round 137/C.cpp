#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 ans = 0;
    int cnt = 0;
    std::priority_queue<int> pq;

    if (s[0] == '1')
        pq.emplace(a[0]), cnt++;

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == '0' and s[i] == '1')
            pq.emplace(a[i]), pq.emplace(a[i - 1]), cnt++;
        else if (s[i - 1] == s[i] and s[i] == '1')
            pq.emplace(a[i]), cnt++;
        else
        {
            while (cnt--)
                ans += pq.top(), pq.pop();

            cnt = 0;
            pq = std::priority_queue<int>();
        }
    }

    while (cnt--)
        ans += pq.top(), pq.pop();

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