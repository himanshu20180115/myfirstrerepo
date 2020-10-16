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
   int n;
   cin >> n;

   string s;
   cin >> s;

   vector<int> group;

   int last = -1;
   int len = 0;

   f(i,0,n){
      if(s[i] - '0' == last){
         len++;
      }
      else{
         if(len) group.push_back(len);
         len = 1;
      }
      last = s[i] - '0';
   }

   if(len) group.push_back(len);

   int extra = 0;
   for(int x : group) extra += x - 1;

   int ans = 0;
   int used = 0;

   for(int i=0 ; i<sz(group); i++){
      int x = group[i];
      extra -= x - 1;
      int can = min({used, x - 1});
      used -= can;
      x -= can;
      extra += can;

      if(x == 1){
         if(extra){
            extra--;
            used++;
            ans++;
         }
         else{
            ans += (sz(group) - i + 1)/2;
            break;
         }
      }
      else{
         ans++;
      }
   }

   cout << ans << "\n";
}

int32_t main(){
   fast;
   int t = 1;
   cin >> t;
   while(t--)  solve();   
}
