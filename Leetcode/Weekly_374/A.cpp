#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif


using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& a, int target) {
        std::sort(std::begin(a), std::end(a));
        int n = std::size(a);

        int can_make = 0;
        int ans = 0;
        for (int i = 0; can_make < target; ++i)
        {
            if (i >= n or a[i] - can_make > 1)
            {
                ans++;
                can_make += can_make + 1;
                i--;
                continue;    
            }

            can_make += a[i];
        }

        return ans;
    }
};

int main()
{
    int n, t;
    std::cin >> n >> t;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Solution so;
    print(so.minimumAddedCoins(a, t));
    return 0;
}