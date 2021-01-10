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

int N, K;
vector<int>score;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    int hi = 0;
    int lo = 0;
    for(int i = 0 ; i < N ; i++) {
        int num;
        cin >> num;
        score.push_back(num);
        hi += num;
    }
    int ans;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        int sum = 0;
        int cnt = 0;
        for(int i = 0 ; i < N ; i++) {
            sum += score[i];
            if(sum >= mid) {
                sum = 0;
                cnt++;
            }
        }
        if(cnt == K) {
            ans = mid;
        }
        if(cnt >= K) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}