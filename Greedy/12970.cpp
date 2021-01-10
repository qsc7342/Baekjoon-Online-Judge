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
const int INF = 2147483646;
const double pi = 3.141592653589793;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  ll N;
  cin >> N;

  vector<int> a;

  for(int i = 0 ; i < N ; i++) {
    int x; 
    cin >> x;
    a.pb(x);
  }

  int b, c;
  cin >> b >> c;

  ll ans = 0;
  for(int i = 0 ; i < a.size() ; i++) {
    ans++;
    a[i] -= b;

    ans += max(0, (a[i] - 1) / c)
  }
} 
