#include<bits/stdc++.h>
using namespace std;

#define int long long
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;

void solve(){
   int n,k;
   cin >> n >> k;

   int a[n];
   f(i,0,n) cin >> a[i];

   sort(a, a+n);

   int pref[n + 1] = {0};
   f(i,0,n) pref[i+1] = pref[i] + a[i];

   int ans = pref[n] - pref[n-k-1];
   cout << ans << "\n";
}

int32_t main(){
   fast;
   int t = 1;
   cin >> t;
   while(t--)  solve();   
}
