#include <bits/stdc++.h>
#define FASTIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define fst first
#define snd second
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define sc(x) int x; cin >> x;
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T> // 맥스힙
#define GPQ(T) priority_queue<T,vector<T>,greater<T>> // 민힙
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

bool isprime[(int)sqrt(1e12) + 5];
vector<int> prime;
int answer;
vector<int> mod;
int n;

void solve(int picked, int cur, int pos) {
  if(picked > 1) {
    if(picked % 2 == 0) {
      answer += (n - 1) / cur;
    }
    else {
      answer -= (n - 1) / cur;
    }
  }
  for(int i = pos ; i < mod.size() ; i++) {
    solve(picked + 1, cur * mod[i], i + 1);
  }
}
signed main() {
   FASTIO();
   memset(isprime, true, sizeof(isprime));
   isprime[1] = false;
   for(int i = 2 ; i <= sqrt(1e12) ; i++) {
    if(isprime[i]) prime.pb(i);
    for(int j = i * i ; j <= sqrt(1e12) ; j += i) {
      isprime[j] = false;
    }
   }
   while(cin >> n) {
     mod.clear();
     if(n == 1) {
      cout << "1" << endl;
      continue;
     }
     answer = n - 1;
     int tmp = n;
     for(int i = 0 ; i < prime.size() ; i++) {
      if(tmp > 1 && tmp % prime[i] == 0) {
        answer -= (n - 1) / (prime[i]);
        mod.pb(prime[i]);
      }
      while(tmp > 1 && tmp % prime[i] == 0) {
        tmp /= prime[i];
      }
     }
     if(tmp > 1) {
      mod.pb(tmp);
      answer -= (n - 1) / tmp;
     }
    solve(0, 1, 0);
    cout << answer << endl;
  }
}