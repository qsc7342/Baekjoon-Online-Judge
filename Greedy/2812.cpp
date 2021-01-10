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
const int INF = 2147483646; 

int N, K;
vector<int>pos;


int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  string s;
  cin >> s;

  stack<char>stk;

  for(int i = 0 ; i < s.size() ; i++) {
    if(stk.empty() || stk.top() >= s[i]) stk.push(s[i]);

    else if(!stk.empty() && stk.top() < s[i]) {
      while(!stk.empty() && stk.top() < s[i] && K > 0) {
        stk.pop();
        K--;
        if(K == 0) break;
      }
      stk.push(s[i]);
    }
  }

  while(K > 0) {
    stk.pop();
    K--;
  }
  string ans;
  while(!stk.empty()) {
    ans += stk.top();
    stk.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
