#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::vector<i64> need(3), sum(3);
    std::vector<int> tail(3, -1);

    std::cin >> n >> need[0] >> need[1] >> need[2];

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < n;)
    {
        if (sum[0] < need[0])
        {
            if (tail[0] == -1)
            {
                tail[0] = i++;
                sum[0] += a[tail[0]];
            }
            else if (tail[1] == -1 and tail[2] == -1)
                sum[0] += a[i++];
            else if (tail[2] == -1)
            {
                sum[0] += a[tail[1]];
                sum[1] -= a[tail[1]++];

                if (sum[1] == 0)
                    tail[1] = -1;
            }
        }
        else if (sum[0] > need[0])
        {
            sum[0] -= a[tail[0]++];
            if (sum[0] == 0)
                tail[0] = -1;
        }

        else if (sum[1] < need[1])
        {
            if (tail[1] == -1)
            {
                tail[1] = i;
                sum[1] += a[tail[1]++];
            }            
        }
    }
    
    return 0;
}