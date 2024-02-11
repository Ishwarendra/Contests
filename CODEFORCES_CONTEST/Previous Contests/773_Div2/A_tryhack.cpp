#include<bits/stdc++.h>
#define MOD 1000000007
#define PI 3.1415926535897932384626
#define MX 200005
#define pb push_back
#define bs binary_search
#define eb emplace_back
#define ef emplace_front
#define it iterator
#define us unordered_set
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long  ll;
typedef unsigned long long int ull;
using namespace std;
ll find_lcm(ll a, ll b) {ll p = __gcd(a, b); return (a * b) / p;}
ll find_max(ll a[], ll n) {ll p = -1; for (ll i = 0; i < n; i++) {p = max(p, a[i]);} return p;}
ll find_min(ll a[], ll n) {ll p = ll(1e18); for (ll i = 0; i < n; i++) {p = min(p, a[i]);} return p;}
ll  max3(ll a, ll b, ll c) {return max(a, max(b, c));}
// below function is to find prime no. upto range n
/*void sieve(){
  is_prime[0]=0;
  is_prime[1]=0;
  for(ll i=2;i<=n;i++){
  if(is_prime[i]){
  for(ll j=i*i;j<=n;j+=i){
     is_prime[j]=0;
  }
  }
  }
  return;
}*/
// below function for binary exponentiation
// for answer=answer%modulo (MOD is included)
/* ll bin_exp(ll a,ll b){
   ll res=1;
   while(b>0){
      if(b&1){
         res=((res%MOD)*(a%MOD))%MOD;
      }
   a=((a%MOD)*(a%MOD))%MOD;
   b>>=1;
   }
   return res;
 }
 // for multiplicative inverse
 ll mod_inverse(ll a){
   ll mmi;
   mmi=(bin_exp(a,MOD-2)+MOD)%MOD;
   return mmi;
 }
 //for ncr
 ll ncr(ll n, ll r){
   return ((fact[n]*inv_fact[r])%MOD)*(inv_fact[n-r]%MOD)%MOD;
 }*/
void solve() {
   ll x1, y1, x2, y2, x3, y3;
   cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
   if (y1 == y2 && y3 < y1) {
      cout << abs(x1 - x2) << endl;
      return;
   }
   if (y1 == y3 && y2 < y1) {
      cout << abs(x1 - x3) << endl;
      return;
   }
   if (y3 == y2 && y1 < y3) {
      cout << abs(x3 - x2) << endl;
      return;
   }
   cout << 0 << endl;
   return;
}
int main() {
   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}


