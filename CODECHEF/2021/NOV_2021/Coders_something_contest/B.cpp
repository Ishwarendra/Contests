#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int p = *min_element(a.begin(), a.end());
        ll ans = 0;
        for(int &i : a) {
            i -= p;
            ans += p;
        }
        for(int i : a) if(i) ++ans;
        cout << ans << '\n';
    }
}