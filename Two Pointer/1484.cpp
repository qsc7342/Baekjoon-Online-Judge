#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 987654321;

ll G;

int main() {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   cin >> G;

   ll lo = 1;
   ll hi = 2;
   vector<ll> ans;
   while(lo < hi) {
      ll cur = hi*hi - lo*lo;
      if(cur == G) {
         ans.pb(hi);
         hi++;
      } 
      else if(cur > G) {
         lo++;
      }
      else {
         hi++;
      }
   }
   if(ans.size() == 0) {
      cout << "-1" << endl;
      return 0;
   }
   for(auto x : ans) {
      cout << x << endl;
   }
}  