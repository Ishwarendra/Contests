#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int back = 0, front = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (front)
                front = 0;
            else
                ans++, back = 1;
        }
        else if (a[i] == 1)
        {
            if (!back and !front)
                front = 1, ans++;
        }
        else
        {
            if (front or back)
                back = 0, front = 1;
            else
                ans++, front = 1;
        }
    }

    std::cout << ans;

    return 0;
}