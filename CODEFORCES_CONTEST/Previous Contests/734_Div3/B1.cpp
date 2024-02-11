#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;


int main()
{
    int t; cin >> t;
    while (t--)
    {
    unordered_map<char, int> m;
        string s;
        cin >> s;

        for(auto &i : s)
            m[i]++;
        
        int ans = 0, cnt = 0;

        for(auto &i : m)
        {
            if (i.second >= 2)
                ans++;

            else if (i.second == 1)
            {
                cnt++;
                if (cnt == 2)
                {
                    cnt = 0;
                    ans++;
                }
            }
        }   

        cout << ans << '\n';

    }
    return 0;
}