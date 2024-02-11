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

    auto isPalin = [&](std::string s)
    {
        int i = 0, j = std::size(s);
        j--;

        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }

        return true;
    };

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j and isPalin(a[i] + a[j]))
            {
                std::cout << "Yes";
                return 0;
            }
        }
    }

    std::cout << "No";
    
    return 0;
}