#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick 
{
    const int n;
    std::vector<T> a;
    
    Fenwick(int n) : n(n), a(n) {}
    Fenwick(const std::vector<T> &inp) : Fenwick((int) inp.size())
    {
        for (int i = 0; i < n; i++)
            add(i, inp[i]);
    }
    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x)  
    {
        T ans = 0;
        x++;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) 
    {
        if (l > r)
            return 0;

        if (l - 1 < 0)
            return sum(r);
        
        return sum(r) - sum(l - 1);
    }
}; 

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)   
        std::cin >> a[i];

    i64 ans = 0;
    Fenwick<int> ft(n + 2);

    for (int j = 0; j < n; ++j)
    {
        if (a[j] >= (j + 1))
            continue;

        ans += ft.rangeSum(0, a[j] - 1);
        ft.add(j + 1, 1);
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