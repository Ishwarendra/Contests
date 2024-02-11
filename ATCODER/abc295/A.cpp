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
    
    std::set<std::string> s1 {"and", "not", "that", "the", "you"};
    int n;
    std::cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        cnt += s1.count(s);
    }

    std::cout << (cnt ? "Yes\n" : "No\n");
    
    return 0;
}