#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    i64 sum = 1LL * n * (n + 1) / 2;
    if (sum % 2)
        std::cout << "1\n";
    else
        std::cout << "0\n";
    
    return 0;
}