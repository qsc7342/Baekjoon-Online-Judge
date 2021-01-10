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
const int INF = 987654321;


int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N, M;
  cin >> N >> M;

  if(N % M == 0 && N >= M) {
    cout << "0" << endl;
    return 0;
  }

  else if(M % N == 0) {
    cout << ((M / N) - 1) * N << endl;
  }

  else {
    cout << M - __gcd(M, N) << endl;
  }
}