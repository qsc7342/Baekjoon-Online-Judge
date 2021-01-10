#include <bits/stdc++.h>
#define FASTIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define fst first
#define snd second
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define sc(x) int x; cin >> x;
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T> // 맥스힙
#define GPQ(T) priority_queue<T,vector<T>,greater<T>> // 민힙
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;

int N;
vector<int> arr;
int cnt[300001] = {};
vector<vector<int> > tree(300001);
vector<vector<int> > adj(300001);
int pt[300001] = {};
int val = 1;

void makeTree(int cur, int p) { // 현재 깊이, 포인터

  // 해당 노드의 왼쪽 자식이 존재하려면
  // 아래 깊이의 해당 노드의 포인터 * 2 - 1 개 이상의 노드가 존재해야함
  if(adj[cur + 1].size() >= 2 * p - 1) { 
    makeTree(cur + 1, 2 * p - 1);
  }
  // 아래깊이로 이동 (좌측 노드)

  tree[cur].pb(val++); // 루트에 번호줌. inorder 방식

  // 해당 노드의 오른쪽 자식이 존재하려면
  // 아래 깊이의 해당 노드의 포인터 * 2개 이상의 노드가 존재해야함
  if(adj[cur + 1].size() >= 2 * p)  {
    makeTree(cur + 1, 2 * p);
  }
  // 아래깊이로 이동 (우측 노드)
  return;
}

signed main() {
  FASTIO();
  cin >> N;
  rep(i, N - 1) {
    sc(x);
    arr.pb(x);
  }

  /* 불가능을 판별하는 부분임 */
  bool flag = true;
  cnt[0] = 1;
  for(int i = 0 ; i < arr.size() ; i++) {
    cnt[arr[i]]++;
    // 현재 갯수 * 2 가 부모의 갯수보다 클 경우 불가능
    if(cnt[arr[i]] > cnt[arr[i] - 1] * 2) {
      flag = false;
      break;
    }
  }
  /* ============================= */
  if(!flag) {
    cout << "-1" << endl;
    return 0;
  }
  /* 불가능 */

  for(int i = 0 ; i < arr.size() ; i++) {
    int depth = arr[i];
    adj[depth].pb(1);
  } // 해당 깊이의 트리 노드 추가

  makeTree(0, 1); // 트리만들기


  cout << tree[0][0] << ' ';
  // 루트 출력

//  cout << endl;

  //깊이에 맞게 출력
  for(int i = 0 ; i < arr.size() ; i++) {
 //   cout << "cur depth : " << arr[i] << endl;
    cout << tree[arr[i]][pt[arr[i]]++] << ' ';
  }
  cout << endl;
  return 0;
}