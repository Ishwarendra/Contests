#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using namespace std;

using i64 = long long;

template<class Info,
         class Merge = std::plus<Info>>
struct SegmentTree
{
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegmentTree(int n = 0) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}

    template <typename T>
    SegmentTree(const std::vector<T> a) : SegmentTree(std::size(a))
    {
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l], l);
                return;
            }

            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            pull(id);
        };
        build(0, n - 1, 0);
    }
    void pull(int id)
    {
        info[id] = merge(info[id * 2 + 1], info[id * 2 + 2]);
    }
    void update(int id, int l, int r, int x, const Info &v)
    {
        if (l > r)
            return;
        if (l == r)
        {
            info[id] = v;
            return;
        }

        int m = (l + r) >> 1;
        if (x <= m)
            update(2 * id + 1, l, m, x, v);
        else
            update(2 * id + 2, m + 1, r, x, v);
        pull(id);
    }
    void update(int x, const Info &v)
    {
        update(0, 0, n - 1, x, v);
    }
    Info get(int id, int l, int r, int a, int b)
    {
        if (r < a or l > b)
            return Info();
        if (l >= a and r <= b)
            return info[id];

        int m = (l + r) >> 1;
        return merge(get(2 * id + 1, l, m, a, b), get(2 * id + 2, m + 1, r, a, b));
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };

    template <class F>
    int findFirst(int id, int l, int r, int a, int b, F pred)
    {
        if (r < a or l > b or !pred(info[id]))
            return -1;

        if (l == r)
            return l;

        int m = (l + r) >> 1;
        int res = findFirst(2 * id + 1, l, m, a, b, pred);
        if (res == -1)
            res = findFirst(2 * id + 2, m + 1, r, a, b, pred);

        return res;
    }

    template <class F>
    int findFirst(int l, int r, F pred) { return findFirst(0, 0, n - 1, l, r, pred); }

    template <class F>
    int findLast(int id, int l, int r, int a, int b, F pred)
    {
        if (r < a or l > b or !pred(info[id]))
            return -1;

        if (l == r)
            return l;

        int m = (l + r) >> 1;
        int res = findLast(2 * id + 2, m + 1, r, a, b, pred);

        if (res == -1)
            res = findLast(2 * id + 1, l, m, a, b, pred);

        return res;
    }

    template <class F>
    int findLast(int l, int r, F pred) { return findLast(0, 0, n - 1, l, r, pred); }
};

struct Max
{
    int x;
    Max(int x = -1e9) : x(x) {};
};

Max operator+(const Max &a, const Max &b)
{
    return Max(std::max(a.x, b.x));
}

class Solution {
    void chmax(int &a, int b)
    {
        if (a < b)
            a = b;
    }
public:
    int maximumLength(vector<int>& a, int k) {
        int n = std::size(a);
        std::vector dp(n, std::vector(k + 1, -1));

        dp[0][0] = 1;
        std::vector max(k + 1, SegmentTree<Max>(n));
        std::map<int, int> maxVal[k + 1];
        maxVal[0][a[0]] = 1;
        max[0].update(0, Max(1));
        
        for (int i = 1; i < n; i++)
        {
            for (int p = 0; p <= k; p++)
            {
                chmax(dp[i][p], 1);
                int max1 = maxVal[p][a[i]];
                int max2 = -1e9;
                if (p > 0)
                    max2 = max[p - 1].get(0, i - 1).x;
                
                dp[i][p] = std::max({dp[i][p], max1 + 1, max2 + 1});
                max[p].update(i, Max(dp[i][p]));
                chmax(maxVal[p][a[i]], dp[i][p]);

                for (int j = 0; j < i; j++)
                {
                    if (a[i] == a[j])
                        chmax(dp[i][p], dp[j][p] + 1);
                    if (p > 0 and a[i] != a[j])
                        chmax(dp[i][p], dp[j][p - 1] + 1);
                }
            }
        }

        int ans = 0;
        std::map<int, int> cnt;
        for (auto x : a)
        {
            cnt[x]++;
            ans = std::max(ans, cnt[x]);
        }
        
        if (k == 0)
            return ans;

        for (int i = 0; i < n; i++)
        {
            for (int p = 0; p < k + 1; p++)
                ans = std::max(ans, dp[i][p]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    // std::vector<int> a {1, 2, 1, 1, 3};
    // int k = 0;
    std::vector<int> a{2, 5, 6, 1, 3, 2, 5};
    int k =2;
    print(sol.maximumLength(a, k))
    return 0;
}