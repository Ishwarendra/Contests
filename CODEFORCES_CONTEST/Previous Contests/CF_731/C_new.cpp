#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
typedef vector<int> vi;

void solve()
{
    int k, n, m, zero1 = 0, zero2 = 0;
        cin >> k >> n >> m;
        vi mono(n), poly(m), ans;
        
        for(int i = 0; i < n; i++)
        {
            cin >> mono[i];
            if (mono[i] == 0) zero1++;
        }
        
        for(int i = 0; i < m; i++)
        {
            cin >> poly[i];
            if (mono[i] == 0) zero2++;
        }

      
            
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}