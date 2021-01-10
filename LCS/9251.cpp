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
const int INF = 1000000001;

string s1, s2;
int cnt[1001][1001] = {};
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> s1;
    cin >> s2;
    int ans = 0;

    for(int i = 0 ; i < s1.size() ; i++) {
      for(int j = 0 ; j < s2.size() ; j++) {
        if(s1[i] != s2[j]) {
          cnt[i + 1][j + 1] = max(cnt[i][j + 1], cnt[i + 1][j]);
        }
        else {
          cnt[i + 1][j + 1] = cnt[i][j] + 1;
        }
      }
    }

    for(int i = 1 ; i <= s1.size() ; i++) {
      for(int j = 1 ; j <= s2.size() ; j++) {
        if(cnt[i][j] > ans) {
          ans = cnt[i][j];
        }
      }
    }
    int tmp = ans;
    int y = 0, x = 0;
    string res; 
    for(int i = s1.size() ; i >= 1 ; i--) {
      for(int j = s2.size() ; j >= 1 ; j--) {
        if(cnt[i][j] == cnt[i - 1][j - 1] + 1 && j > y && i > x) {
          y = j;
          x = i;
          res += s1[i];
        }
      }
    }
    cout << ans << endl;
    cout << res << endl;
}