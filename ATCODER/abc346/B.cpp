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
    
    const std::string gen = "wbwbwwbwbwbw";
    std::string s;
    while (std::size(s) <= 1000)
        s += gen;

    int w, b;
    std::cin >> w >> b;

    int cnt_w = 0, cnt_b = 0;
    for (int i = 0; i < w + b - 1; i++)
        (s[i] == 'w' ? cnt_w : cnt_b)++;

    for (int i = w + b - 1; i + w + b < std::size(s); i++)
    {
        (s[i] == 'w' ? cnt_w : cnt_b)++;

        if (cnt_w == w and cnt_b == b)
        {
            std::cout << "Yes";
            return 0;
        }

        (s[i - (w + b - 1)] == 'w' ? cnt_w : cnt_b)--;
    }
    
    std::cout << "No";

    return 0;
}