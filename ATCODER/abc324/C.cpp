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
    std::string t;
    std::cin >> n >> t;

    std::vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;

        if (std::size(s) == std::size(t) + 1)
        {
            int ss = std::size(s);
            int st = std::size(t);

            int cnt = 0;
            for (int i = 0, j = 0; i < ss and j < st; )
            {
                if (s[i] != t[j])
                    cnt++, j--;

                i++, j++;
            }

            if (cnt <= 1)
                ans.emplace_back(i + 1);
        }
        else if (std::size(s) + 1 == std::size(t))
        {
            int ss = std::size(s);
            int st = std::size(t);

            int cnt = 0;
            for (int i = 0, j = 0; i < ss and j < st; )
            {
                if (s[i] != t[j])
                    cnt++, i--;
                
                i++, j++;
            }

            if (cnt <= 1)
                ans.emplace_back(i + 1);
        }
        else if (std::size(s) == std::size(t))
        {
            int cnt = 0;
            for (int j = 0; j < std::size(s); j++)
                cnt += s[j] != t[j];

            if (cnt <= 1)
                ans.emplace_back(i + 1);
        }
    }   

    std::cout << std::size(ans) << "\n";
    for (int i = 0; i < std::size(ans); i++)
        std::cout << ans[i] << " \n"[i + 1 == std::size(ans)];
    
    return 0;
}