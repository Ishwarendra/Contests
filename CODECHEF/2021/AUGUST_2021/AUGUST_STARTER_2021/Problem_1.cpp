#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;



int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int maxi = min(a, min(b, c));
        if (c == maxi)
        {
            cout << "Alice" << "\n";
            continue; 
        }
        if (b == maxi){
            cout << "Bob\n";
            continue;
        }

        if (a == maxi)
            cout << "Draw\n";
    }
    return 0;
}