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

struct BIT {
   int n;
   vector<int> bit;

   BIT(int n) {
      this->n = n;
      bit.assign(n+1 , 0);
   }

   void add(int idx, int delta) {
      for (; idx < n; idx = idx | (idx + 1))
         bit[idx] += delta;
   }

   int sum(int r) {
      int ret = 0;
      for (; r >= 0; r = (r & (r + 1)) - 1)
         ret += bit[r];
      return ret;
   }

   int sum(int l, int r) {
      return sum(r) - sum(l - 1);
   }
};

int32_t main(){
   fast;
   int n;
   cin >> n;

   string s;
   cin >> s;

   vector<int> id[26];
   vector<int> rid[26];

   f(i,0,n){
      int ch = s[i] - 'a';
      id[ch].push_back(i);
      rid[ch].push_back(n-1-i);
   }

   vector<int> pos(n, 0);

   f(i,0,26){
      sort(all(rid[i]));
      f(j,0,sz(id[i])) pos[id[i][j]] = rid[i][j];
   }

   int ans = 0;
   BIT bt(n);

   f(i,0,n){
      ans += i - bt.sum(pos[i]);
      bt.add(pos[i], 1);
   }

   cout << ans << "\n";
}
