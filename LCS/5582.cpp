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
const int INF = 100000009;

string s1, s2;
string ans;
int cnt[4005][4005] = {};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> s1;
    cin >> s2;
    string ans;

    for(int i = 0 ; i < s1.size() ; i++) {
      for(int j = 0 ; j < s2.size() ; j++) {
        if(s1[i] == s2[j]) {
            cnt[i + 1][j + 1] = cnt[i][j] + 1;
        }
        else {
          cnt[i + 1][j + 1] = max(cnt[i][j + 1], cnt[i + 1][J])
        }
      }
    }

    for(int i = 1 ; i < s1.size() + 1 ; i++) {
      for(int j = 1 ; j < s2.size() + 1 ; j++) {
        if(cnt[i - 1][j - 1] < cnt[i][j]) {
          ans += s[i];
        }
      }
    }
    cout << ans << endl;
    return 0;
}