#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 987654321;

int T;

int main() {
  // cin.tie(NULL);
  // ios_base::sync_with_stdio(false);

  cin >> T;
  double price[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
  for(int i = 0 ; i < T ; i++) {
    double A, B, C, D, E;

    cin >> A >> B >> C >> D >> E;

    double sum = 0;
    sum += price[0] * A;
    sum += price[1] * B;
    sum += price[2] * C;
    sum += price[3] * D;
    sum += price[4] * E;

    cout.precision(2);
    cout << "$";
    cout << sum << endl;
  }

} 
