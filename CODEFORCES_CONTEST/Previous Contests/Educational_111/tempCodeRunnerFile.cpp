#include <iostream>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL);
using vi = vector<int>;
using ll = long long int;

void add(vi &arr, ll l, ll c)
{
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < l; i++)
            arr.push_back(arr[i]);
    }
}

void solve()
{
    ll m;
    cin >> m;

    vi arr;
    while(m--)
    {
        ll stage, a, b;
        cin >> stage >> a;
        if (stage == 1)
            arr.push_back(a);
        else
        {
            cin >> b;
            add(arr, a, b);
        }
    }

    ll n;
    vi ans(n);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans[i] = arr[x-1];
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';


}
 

int main()
{
    solve();
    return 0;
}