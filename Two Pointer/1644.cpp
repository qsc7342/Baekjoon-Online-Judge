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

const ll INF = 9876543212135;
bool isprime[4000001];
vector<int>prime;
int N;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  memset(isprime, 1, sizeof(isprime));
  cin >> N;
  for(int i = 2 ; i <= N ; i++) {
    if(isprime[i]) prime.pb(i);
    for(int j = i * 2 ; j <= N ; j += i) {
      isprime[j] = false;
    }
  }
  int left = 0;
  int right = 1;
  int cur = 0;
  if(prime.size() == 0) {
    cout << "0" << endl;
    return 0;
  }
  if(prime.size() >= 1)
    cur = prime[0];
  int cnt = 0;
  if(cur == N) {
    cnt++;
  }
  while(right < prime.size() - 1 || left < prime.size() - 1) {
    if(cur <= N && right <= prime.size() - 1) {
      cur += prime[right];
      right++;
    }

    else {
      if(left <= prime.size() - 1)
        cur -= prime[left];
      left++;
    }
    if(cur == N) {
      cnt++;
    }
  }
  cout << cnt << endl;
}
