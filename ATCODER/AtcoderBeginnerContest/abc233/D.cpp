#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long n, k;
    std::cin >> n >> k;

    std::vector<long long> a(n);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];

    std::map<long long, long long> m;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
            ans++, ans += m[0LL];
        else
            ans += m[a[i] - k];

        m[a[i]]++;
    }

    std::cout << ans << "\n";
    
    return 0;
}