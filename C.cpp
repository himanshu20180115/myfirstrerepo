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
typedef pair<int, int> pii;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;

void solve() {
   int n;
   cin >> n;

   priority_queue<int> pq[1];
   f(i, 1, n + 1) pq[0].push(i);

   vector<pair<int, int>> ans;

   while (sz(pq[0]) > 1) {
      int a, b;
      a = pq[0].top();
      pq[0].pop();
      b = pq[0].top();
      pq[0].pop();

      ans.push_back({a, b});
      int x = (a + b + 1) / 2;
      pq[0].push(x);
   }

   int val = pq[0].top();

   cout << val << "\n";
   for (auto it : ans) {
      cout << it.F << " " << it.S << "\n";
   }
}

int32_t main() {
   fast;
   int t = 1;
   cin >> t;
   while (t--)  solve();
}
