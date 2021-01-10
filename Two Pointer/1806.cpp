#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define INF 987654321
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


ll N, M;


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  vector<ll>arr;
  int left = 0;
  int right = 0;
  int cur = 0;
  int cnt = 0;
  bool flag = false;
  int len = INF;
  for(int i = 0 ; i < N ; i++) {
    int num;
    cin >> num;
    arr.pb(num);
  }
  while(left < N || right < N) {
    if(cur <= M && !flag) {
      cur += arr[right];
      right++;
      if(right == N) {
        flag = true;
      }
    }
    else if(cur > M || flag) {
      cur -= arr[left];
      left++;
    }

    if(cur >= M) {
      len = min(len, right - left);
    }
  }

  if(len == INF) {
    cout << "0" << endl;
  }
  else {
    cout << len << endl;
  }
  return 0;
}
