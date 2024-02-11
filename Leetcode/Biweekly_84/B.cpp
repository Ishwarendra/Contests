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
    long long countBadPairs(vector<int>& nums) {
        i64 ans = 0;
        std::map<int, int> m;

        int n = std::size(nums);

        for (int i = 0; i < n; i++)
        {
            ans += m[nums[i] - i];
            print(nums[i] - i, ans)
            m[nums[i] - i]++;
        }

        return 1LL * n * (n - 1) / 2 - ans;
    }
};


int main()
{
    Solution sol;
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::cout << sol.countBadPairs(a);
    return 0;
}