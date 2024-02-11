#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool isPalin(std::string s)
{
    int i = 0, j = std::ssize(s) - 1;
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }

    return true;
}

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    int l = 0, r = n - 1;
    while (l < r and s[l++] == s[r--]);

    if (r <= l)
        std::cout << "Yes\n";
    else
    {
        l--, r++;
        int left = l, right = r;
        auto a = s;
        while (l < r and a[l] != a[r])
            a[l] = a[r], l++, r--;

        if (isPalin(a))
        {
            std::cout << "Yes\n";
            return;
        }

        l = left, r = right;
        a = s;
        while (l < r and a[l] != a[r])
            a[r] = a[l], l++, r--;

        if (isPalin(a))
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
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