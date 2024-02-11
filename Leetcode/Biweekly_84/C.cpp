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
    i64 taskSchedulerII(std::vector<int>& tasks, int space) 
    {
        const int inf = 1e9;
        int n = std::size(tasks);

        std::map<int, i64> lastDone;
        for (int i = 0; i < n; i++)
            lastDone[tasks[i]] = -inf;

        i64 ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (ans - lastDone[tasks[i]] - 1 >= space)
            {
                ans++;
                lastDone[tasks[i]] = ans;
            }
            else
            {
                i64 need = ans - lastDone[tasks[i]] - 1;
                ans += space - need;
                lastDone[tasks[i]] = ans;
            }
        }
        
        return ans;
    }
};

int main()
{
    int n, s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    Solution sol;
    std::cout << sol.taskSchedulerII(a, s);
    return 0;
}