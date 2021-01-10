
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
const int INF = 1587654321;

int N, L;
deque<pii>dq;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> L;
    // 0 ~  L - 1 (i) 까지의 범위 중 최소를 출력해야함 
    // i ~ i + L - 1 까지의 범위 중 최소를 출력해야함

    rep(i, N - L + 1) {
      int num;
      cin >> num;
      if(dq.empty()) {
        dq.push_back(mp(num, i)); 
      }   
      else if(dq.back().first > num) {
        dq.pop_back();
        dq.push_back(mp(num, i));      
      } 
      while(!dq.empty() && i - L >= dq.front().front) {
        dq.pop_front();
      }
      cout << dq.front().first << ' ';   
    }
    cout << endl;
}