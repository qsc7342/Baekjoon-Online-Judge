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
const int INF = 987654321;
bool isPrime[1000001] = {};
vector<int>prime;
int N;

int arr[101][80001] = {};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  memset(isPrime, true, sizeof(isPrime));


  cin >> N;

  isPrime[0] = false;
  isPrime[1] = false;

  // 소수 판별
  for(int i = 2 ; i <= 1000000 ; i++) {
    if(isPrime[i]) prime.pb(i);
    for(int j = i + i ; j <= 1000000 ; j += i) {
      isPrime[j] = false;
    }
  }


  // 素因數分解 中
  for(int i = 0 ; i < N ; i++) {
    int num;
    cin >> num;
    for(int j = 0 ; j < prime.size() ; j++) {
      if(num == 0) break; 
      while(num > 1 && num % prime[j] == 0) {
        // cout << prime[j] << endl;
        arr[i][j]++;
        num /= prime[j];
      }
    } 
  }
  int ans = 1;
  int cnt = 0;
  int tmp;
  for(int j = 0 ; j < 80000 ; j++) {
    int cur = 0;
    for(int i = 0 ; i < N ; i++) {
      cur += arr[i][j];
    }
    // cur = 6이 되었을 것
    tmp = cur / N; // 필요 갯수 확인용
    ll chk = (ll)pow(prime[j], tmp);
    ans *= (ll)pow(prime[j], tmp);
    if(tmp >= 1) {
      for(int i = 0 ; i < N ; i++) {
        while(chk > (ll)pow(prime[j], arr[i][j])) {
          cnt++;
          arr[i][j]++;
        }
      }
    }
  }
  cout << ans << ' ' << cnt << endl;
}
