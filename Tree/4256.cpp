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

int T;
int root_idx;
vector<int>preorder;
vector<int>inorder;

void solve(int left, int right) {
//	cout << "left , right : " << left << ' ' << right << endl;
	/* find next root */
//	cout << "root idx : " <<  root_idx << endl;
	for(int i = left ; i <= right ; i++) {
		if(inorder[i] == preorder[root_idx]) {
			int root_val = preorder[root_idx];
			root_idx++;
			// left i - 1
			// i + 1 right
			solve(left, i - 1);
			solve(i + 1, right);
			cout << root_val << ' ';
			break;
		}
	}
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> T;

  for(int i = 0 ; i < T ; i++) {
    int N;
    root_idx = 0;
    cin >> N;

    for(int j = 0 ; j < N ; j++) {
    	int num;
    	cin >> num;
    	preorder.pb(num);
    }
    for(int j = 0 ; j < N ; j++) {
   		int num;
   		cin >> num;
   		inorder.pb(num);
    }
    solve(0, N - 1);
    cout << endl;
    preorder.clear();
    inorder.clear();
  }
}
