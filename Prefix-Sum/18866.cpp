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

  int sum;
  cin >> sum;

  int cur = 0;
  for(int i = 0 ; i < 9 ; i++) {
    int x;
    cin >> x;
    cur += x;
  }
  cout << sum - cur << endl;
  return 0;
}