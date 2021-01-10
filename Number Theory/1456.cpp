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


ll A, B;
bool isprime[MAX + 1];
vector<ll>prime;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> A >> B;
  memset(isprime, true, sizeof(isprime));
  isprime[0] = false;
  isprime[1] = false;
  for(int i = 2 ; i <= MAX ; i++) {
    if(isprime[i]) prime.pb(i);
    for(ll j = i * 2 ; j <= MAX; j += i) {
      isprime[j] = false;
    } 
  }
  vector<ll>s;

  for(ll i = 0 ; i < prime.size() ; i++) {
    for(ll j = prime[i] ; j <= 100000000000000 / prime[i] ; j *= prime[i]) {
      s.pb(j * prime[i]);
    } 
  }
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  ll left = lower_bound(s.begin(), s.end(), A) - s.begin();
  ll right = upper_bound(s.begin(), s.end(), B) - s.begin() - 1;
  cout << right - left + 1 << endl;
  return 0;
}