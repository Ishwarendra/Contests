#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int get(int a, int b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;

    int operation = 0;
    if (a < b)
    {
        operation++;
        int c = b - a;
        a = b, b = c;
    }

    operation += (a / b / 2) * 3;
    a = a % (2 * b);

    if (a >= b)
    {
        operation++;
        int c = a - b;
        a = b, b = c;
    }

    return get(a, b) + operation;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)    
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<int> needs;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 and b[i] == 0)
            continue;

        needs.emplace_back(get(a[i], b[i]));
    }   

    for (int i = 1; i < std::size(needs); i++)
    {
        if ((needs[i] - needs[i - 1]) % 3)
        {
            std::cout << "NO\n";
            return;
        }
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