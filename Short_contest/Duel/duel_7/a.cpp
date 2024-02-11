#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define all(a) a.begin(), a.end()
using namespace std;
                                                                                                    

int main()
{
    FIO
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> prefsum(n);
    prefsum[0] = s[0] - 'a' + 1;
    for(int i = 1; i < n; i++) {
        prefsum[i] = s[i] - 'a' + 1 + prefsum[i - 1];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << (prefsum[r] - prefsum[l] + (s[l] - 'a' + 1)) << "\n";
    }
    return 0;
}