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


int arr[2000001] = {};
deque<pii>dq;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  for(int i = 1 ; i <= N ; i++) {
    cin >> arr[i];
  }

  for(int i = 1 ; i <= M ; i++) {
    while(!dq.empty() && dq.back().first <= arr[i]) {
      dq.pop_back();
    }
    dq.push_back(mp(arr[i], i));
  }
  // get 1 ~ M
  for(int i = M + 1 ; i <= 2 * M - 1 ; i++) {
    while(!dq.empty() && dq.back().first <= arr[i]) {
      dq.pop_back();
    }
    dq.push_back(mp(arr[i], i));
  }
  // get M + 1 ~ 2 * M - 2
  cout << dq.front().first << ' ';
  // Print when hongjun's position is M


  for(int i = M + 1 ; i <= N - M + 1 ; i++) {
    while(!dq.empty() && dq.back().first <= arr[i + M - 1]) {
      dq.pop_back();
    }
    dq.push_back(mp(arr[i + M - 1], i + M - 1));
    while(!dq.empty() && dq.front().second < i - (M - 1)) {
      dq.pop_front();
    }
    cout << dq.front().first << ' ';
  }
  cout << endl;
  return 0;
}
