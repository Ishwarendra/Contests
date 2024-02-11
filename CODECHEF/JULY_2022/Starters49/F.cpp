#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

std::multiset<int> LIS(std::vector<int> A)
{
    int a = A.size();
    std::multiset<int> S;
    std::multiset<int>::iterator it;
    for (int i = 0; i < a; i++)
    {
        S.insert(A[i]);
        it = S.upper_bound(A[i]);
        if (it != S.end()) S.erase(it);
    }
    return S;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    auto m = LIS(a);
    std::cout << std::size(m) << "\n";
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