#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define MAX 10000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483646; 

long double X, Y;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> X >> Y;
  long double cur = (Y / X) * 100;
  cout << cur << endl;

  if(cur >= 99) {
    cout << "-1" << endl;
    return 0;
  }

  ll l = 0;
  ll r = 2000000000;

  while(l + 1 < r) {
    ll mid = (l + r) / 2;
    long double tmp = ((Y + mid) / (X + mid)) * 100;

    if((int)tmp > (int)cur) {
      r = mid;
    } 
    else {
      l = mid;
    }
  }
  cout << r << endl;
}