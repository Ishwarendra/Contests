#include <bits/stdc++.h>

using namespace std;
typedef long long lli;
typedef pair<lli, lli> pll;
#define mp(x, y) make_pair(x, y)

// constants
const bool HAVE_CASE = true;
const lli MOD = 998244353;

void test_case_run() {
    lli n;
    cin >> n;
    lli a[n+2], d[n+2];
    a[0] = a[n+1] = d[0] = d[n+1] = 0;
    for (lli i = 1; i <= n; i++) cin >> a[i];
    for (lli i = 1; i <= n; i++) cin >> d[i];
    set<pll> dt;
    lli cv[n+2];
    for (lli i = 1; i <= n; i++) dt.emplace(cv[i] = d[i]-a[i-1]-a[i+1], i);
    lli lne[n+2], rne[n+2];
    for (lli i = 1; i <= n; i++) {
        lne[i] = i-1;
        rne[i] = i+1;
    }
    set<lli> updated, erased;
    for (lli t = 1; t <= n; t++) {
        lli ret = 0;
        while (!dt.empty() && (*(dt.begin())).first < 0) {
            lli u = (*(dt.begin())).second;
            dt.erase(dt.begin());
            erased.insert(u);
            while (erased.count(lne[u])) lne[u] = lne[lne[u]];
            while (erased.count(rne[u])) rne[u] = rne[rne[u]];
            ret++;
            if (lne[u] >= 1) {
                rne[lne[u]] = rne[u];
                updated.insert(lne[u]);
            }
            if (rne[u] <= n) {
                lne[rne[u]] = lne[u];
                updated.insert(rne[u]);
            }
        }
        for (lli u : updated) {
            if (erased.count(u)) continue;
            dt.erase(mp(cv[u], u));
            dt.emplace(cv[u] = d[u] - a[lne[u]] - a[rne[u]], u);
        }
        cout << ret << " ";
        updated.clear();
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli t = 1;
    if (HAVE_CASE) cin >> t;
    while (t--) test_case_run();
    return 0;
}