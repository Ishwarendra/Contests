#include<iostream>

using namespace std ;

int main() {
	int test_cases ; 
	cin >> test_cases ; 
	long long sum_n = 0, sum_q = 0;
	for(int test_case = 1; test_case <= test_cases; ++ test_case) {
		int n, q; cin >> n >> q;
		string a, b; cin >> a >> b;
		int E[n+1]; E[0] = 0;
		for(int i=1;i<=n;++i) {
			int c = (b[i-1]-a[i-1]+26)%26;
			E[i] = E[i-1];
			if(i%2 == 0) E[i] += c;
			else E[i] -= c;
		}

		while(q--) {
			int l,r; cin >> l >> r; 
			if((E[r]-E[l-1])%26) cout << "NO\n";
			else cout << "YES\n";
		}
	}
}