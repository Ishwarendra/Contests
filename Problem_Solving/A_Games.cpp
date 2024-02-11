#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vi home(n), guest(n);

    for (int i = 0; i < n; i++)
        cin >> home[i] >> guest[i];

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (home[i] == guest[j])
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}