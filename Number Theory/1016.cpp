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
vector<ll>prime;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  memset(isPrime, true, sizeof(isPrime));

  ll Min, Max;
  ll arr[1000001] = {};
  cin >> Min >> Max;
  ll SIZE = Max - Min + 1;
  isPrime[0] = false;
  isPrime[1] = false;
  ll cnt = 0;
  // 소수 판별
  for(int i = 2 ; i <= 1000000 ; i++) {
    if(isPrime[i]) prime.pb(i);
    for(int j = i + i ; j <= 1000000 ; j += i) {
      isPrime[j] = false;
    }
  }

  for(int i = 0 ; i < prime.size() ; i++) {
    ll cur = prime[i] * prime[i];
    ll start = (Min / cur) * cur;
    for(ll j = start ; j <= Max ; j += cur) {
      if(j >= Min && j <= Max && arr[j - Min] == 0) {
        cnt++;
        arr[j - Min] = 1;
      }

    }
  }
  cout << SIZE - cnt << endl;
}
