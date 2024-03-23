#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    if (std::size(s) < 2 or s.front() != '<' or s.back() != '>')
    {
        std::cout << "No";
        return 0;
    }

    int cnt = std::count(std::begin(s), std::end(s), '=');
    std::cout << (cnt == n - 2 ? "Yes" : "No");
    
    return 0;
}