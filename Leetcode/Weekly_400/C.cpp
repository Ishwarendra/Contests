#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using namespace std;

using i64 = long long;

class Solution 
{
public:
    std::string clearStars(std::string s) 
    {
        int n = std::size(s);
        std::vector<int> del;
        std::vector pos(26, std::vector<int>());
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*')
                pos[s[i] - 'a'].emplace_back(i);
            else
            {
                for (int ch = 0; ch < 26; ch++)
                {
                    if (!pos[ch].empty())
                    {
                        del.emplace_back(pos[ch].back());
                        del.emplace_back(i);
                        pos[ch].pop_back();
                        break;
                    }
                }
            }
        }
        
        std::string ans;
        std::sort(std::begin(del), std::end(del));

        for (int i = 0; i < n; i++)
        {
            if (!std::binary_search(std::begin(del), std::end(del), i))
                ans += s[i];
        }
        
        return ans;
    }
};

int main()
{
    std::string s;
    std::cin >> s;
    
    Solution sol;
    print(sol.clearStars(s));
    return 0; 
}    