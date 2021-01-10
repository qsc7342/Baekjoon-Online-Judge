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

string s1, s2, res;
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

    // for(int i = 0 ; i <= s1.size() ; i++) {
    //   for(int j = 0 ; j <= s2.size() ; j++) {
    //     cout << cnt[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    int st_x = s2.size();
    int st_y = s1.size();

    while(cnt[st_y][st_x] != 0) {
      if(cnt[st_y][st_x - 1] == cnt[st_y][st_x]) {
        st_x--;
      }
      else if(cnt[st_y - 1][st_x] == cnt[st_y][st_x]) {
        st_y--;
      }
      else if(cnt[st_y - 1][st_x - 1] + 1 == cnt[st_y][st_x]) {
        res += s1[st_y - 1];
        st_y--;
        st_x--;
      }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}