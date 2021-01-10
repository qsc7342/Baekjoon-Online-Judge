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
const int INF = 987654321;

string s;
int N;
vector<string> st;
bool flag = false;
set<string> tt;

void foo(string ts) {
    if(tt.find(ts) != tt.end()) return;
    tt.insert(ts);
    for(int i = 0 ; i < ts.size() ; i++) {
        if(ts[i] != s[i]) return;
    }
    if(ts.size() > s.size()) return;
    if(ts.size() == s.size()) {
        if(ts == s) {
            flag = true;
            return;
        }
        else {
            return;
        }
    } 
    for(int i = 0 ; i < st.size() ; i++) {
        if(ts.size() + st[i].size() <= s.size())
            foo(ts + st[i]);
    }
    return;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;
    int N;
    cin >> N;
    int as = 0;
    while(N--) {
        string t;
        cin >> t;
        st.pb(t);
        as += t.size();
    }
    string tmp = "";
    foo(tmp);

    if(flag) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }
    return 0;
}