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
#define s(x) cin >> x;
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T> // 맥스힙
#define GPQ(T) priority_queue<T,vector<T>,greater<T>> // 민힙
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

int x;
vector<int> v;
int chk[501][501] = {};
int psum[501] = {};
int arr[501] = {};

int foo(int left, int right) {
  if(left == right) {
    return arr[left];
  }

  int& ret = chk[left][right];

  if(ret != -1) return ret;

  ret = INF;
  int sum = psum[right + 1] - psum[left];

  for(int i = left ; i < right ; i++) {
    ret = min(ret, foo(left, i) + foo(i + 1, right) + sum);
  }
  return ret;
}

void solve() {
  int ret = INF;
  for(int i = 0 ; i < x - 1 ; i++) {
    ret = min(ret, foo(0, i) + foo(i + 1, x - 1));
  }
  cout << ret << endl;
}

signed main() {
   FASTIO();
   TC() {
    memset(chk, -1, sizeof(chk));
    memset(psum, 0, sizeof(psum));
    memset(arr, 0, sizeof(arr));
    int ans = 0;
    s(x);
    for(int i = 0 ; i < x ; i++) {
      s(arr[i]);
    }

    for(int i = 1 ; i <= x ; i++) {
      psum[i] = psum[i - 1] + arr[i - 1];
    }
    solve();
   }
  return 0;
}