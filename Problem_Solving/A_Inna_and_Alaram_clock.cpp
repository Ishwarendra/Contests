#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vi x(101), y(101);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x[a]++, y[b]++;
    }

    int countx = 0, county = 0;
    for(int i = 0; i < 101; i++)
    {
        (x[i] != 0) ? (countx++) : (countx += 0);
        (y[i] != 0) ? (county++) : (county += 0);
    }

    cout << min(countx, county) << endl;
    return 0;
}