#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    i64 minimumReplacement(std::vector<int>& nums) 
    {
        i64 ans = 0;
        int last = nums.back();
        int n = std::size(nums);

        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] <= last)
            {
                last = nums[i];
                continue;
            }

            if (nums[i] % last == 0)
                ans += nums[i] / last - 1;
            else
            {
                int f = nums[i] >> 1;
                int c = nums[i] - f;

                std::map<int, int> m;
                m[f]++, m[c]++;

                while (f > last or c > last)
                {
                    last = std::min(f, c);
                    m[f]--, m[c]--;
                }
            }
        }

        return ans;
    }
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    Solution sol;
    std::cout << sol.minimumReplacement(a);
    return 0; 
}    