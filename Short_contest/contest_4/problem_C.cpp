#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int main()
{
    int n; cin >> n;
    string a, b;
    cin >> a >> b;

    int cost = 0, pos = 0;
    for(int i = 0; i < n - 1; i = pos)
    {
        if (a[i] == b[i + 1] and b[i] == a[i + 1])
            cost++, pos += 2;
        else if(a[i] == b[i])
            pos++;
        else
            cost++, pos++;
    }

    cout << cost << endl;
    return 0;
}