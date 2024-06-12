#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

using namespace std;

class Solution 
{
public:
    int minimumChairs(std::string s) 
    {
        int ans = 0, bal = 0;
        for (auto ch : s)
        {
            bal += (ch == 'E' ? 1 : -1);
            ans = std::max(ans, bal);
        }
        
        return ans;
    }
};

int main()
{
    return 0; 
}    