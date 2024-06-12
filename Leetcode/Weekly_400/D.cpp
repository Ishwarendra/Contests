#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using namespace std;

using i64 = long long;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    const int n;
    std::vector<std::vector<T>> mat;
    F func;
 
    SparseTable(const std::vector<T>& a, const F& f) : n(std::size(a)), func(f)
    {
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
 
        }
    }
 
    T get(int from, int to) const
    {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

class Solution 
{
    const int inf = 1e9;
public:
    int minimumDifference(std::vector<int>& nums, int k) 
    {
        nums.erase(std::unique(std::begin(nums), std::end(nums)), std::end(nums));
        int n = std::size(nums);
        
        SparseTable<int> st(nums, [&](int x, int y)
        {
            return (x & y);
        });
        
        int ans = inf;
        for (int i = 0; i < n; i++)
        {
            int cur_ans = inf;
            auto next = [&](int j)
            {
                int left = j + 1, right = n - 1;
                int id = n;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    if (st.get(i, mid) != st.get(i, j))
                        id = mid, right = mid - 1;
                    else
                        left = mid + 1;
                }
                
                return id;
            };
            
            for (int j = i; j < n; j = next(j))
                cur_ans = std::min(cur_ans, std::abs(st.get(i, j) - k));
            
            ans = std::min(ans, cur_ans);
        }
        
        return ans;
    }
};

int main()
{
    return 0; 
}    