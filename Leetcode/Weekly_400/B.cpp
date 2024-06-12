#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) 
    {
        std::sort(std::begin(meetings), std::end(meetings));
        int ans = 0, cur = 0;
        
        for (auto meeting : meetings)
        {
            if (meeting[0] > cur)
                ans += meeting[0] - cur - 1;
            
            cur = std::max(cur, meeting[1]);
        }
        
        ans += days - cur;
        return ans;
    }
};

int main()
{
    int n, d;
    std::cin >> n >> d;
    
    std::vector a(n, std::vector(2, 0));
    for (int i = 0; i < n; i++)
        std::cin >> a[i][0] >> a[i][1];
    
    Solution sol;
    print(sol.countDays(d, a))
    return 0; 
}    