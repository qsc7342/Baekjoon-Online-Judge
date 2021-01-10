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

bool isprime[1001] = {};
vector<int> prime;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  memset(isprime, true, sizeof(isprime));
  isprime[1] = false;
  for(int i = 2 ; i <= 1000 ; i++) {
    if(isprime[i]) prime.pb(i);
    for(int j = i * i ; j <= 1000 ; j += i) {
      isprime[j] = false;
    }
  }
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for(int i = A ; i <= B ; i++) {
    int cur = i;
    int cnt = 0;
    for(int j = 0 ; j < prime.size() ; j++) {
      while(cur > 1 && cur % prime[j] == 0) {
        cur /= prime[j];
        cnt++;
      }
    }
    if(cur > 1) cnt++;
    if(isprime[cnt]) ans++;
  }
  cout << ans << endl;
}