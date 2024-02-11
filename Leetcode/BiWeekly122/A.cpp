#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace __gnu_pbds;

template<typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C,
      rb_tree_tag, tree_order_statistics_node_update>; 

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif
using namespace std;

class Solution {
    using i64 = long long;
public:
    i64 minimumCost(vector<int>& nums, int k, int dist) 
    {
        i64 sum = nums[0];
        nums.erase(std::begin(nums));

        ordered_set<std::pair<int, int>> pbds;
        int n = std::size(nums);
        k--;

        for (int i = 0; i <= dist; i++)
            pbds.insert({nums[i], i});

        int cnt = 0;
        for (auto it = pbds.begin(); cnt < k; cnt++, it++)
            sum += it->first;

        i64 ans = sum;
        for (int i = dist + 1; i < n; i++)
        {
            int id = pbds.order_of_key({nums[i - dist - 1], i - dist - 1});
            pbds.erase({nums[i - dist - 1], i - dist - 1});

            if (id < k)
            {
                sum -= nums[i - dist - 1];

                if (pbds.size() >= k)
                    sum += pbds.find_by_order(k - 1)->first;
            }

            if (pbds.size() >= k)
                ans = std::min(ans, sum);

            id = pbds.order_of_key({nums[i], i});

            if (id >= k)
                pbds.insert({nums[i], i});
            else
            {
                sum += nums[i];
                pbds.insert({nums[i], i});

                if (pbds.size() > k)
                    sum -= pbds.find_by_order(k)->first;
            }

            ans = std::min(ans, sum);
        }

        return ans;
    }
};

int main()
{
    int n, k, d;
    std::cin >> n >> k >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Solution s;
    print(s.minimumCost(a, k, d));
    return 0; 
}    