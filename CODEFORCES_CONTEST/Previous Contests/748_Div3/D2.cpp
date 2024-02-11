#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int arr_gcd(vector<int> arr)
{
    int g = 0;
    for(int i = 0; i < arr.size(); i++)
        g = gcd(g, arr[i]);
    
    return g;
}

void solve()
{
    int n ; cin >> n;
    vi a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());
    vi diff(n);

    for(int i = 0; i < n; i++)
    {
        diff[i] = a[i] - a[0];
    }

    if (a[0] == a[a.size() - 1])
        cout << -1 << "\n";
    else
    {
        int gmax = 0, count = 1;
        for(int i = 1; i < n; i++)
        {
            int cur = a[i];
            while (count < n)
            {
                // int ginterm = diff[];
                for(int j = i + 1; j < n; j++)
                {
                    ginterm = max(ginterm, gcd(ginterm, diff[j]));
                }

            }
        }
    }
    
}   

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();

    return 0;
}