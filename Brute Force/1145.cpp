#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue  
#define MOD 998244353
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll INF = 10000000000000001;
const double pi = 3.141592653589793;


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  int n;
  cin >> n;
  ll ans = 0;
  for(int i = 0 ; i < n ; i++) {
    string t;
    cin >> t;
    t += t;
    for(int j = 0 ; j < t.size() ; j++) {
      int cnt = 0;
      for(int k = j ; k < j + s.size() ; k++) {
        if(s[k - j] == t[k]) {
          cnt++;
        }
      }
      if(cnt == s.size()) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}