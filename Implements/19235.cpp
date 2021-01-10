#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 987654321;

int green[6][4] = {};
int blue[4][6] = {};
int ans = 0;
int N;

void putblock1(int y, int x) {
  int pos;
  for(int i = 0 ; i <= 5 ; i++) {
    if(green[i][x] == 0) {
      pos = i;
    }
    else break;
  }
  green[pos][x] = 1;


  for(int i = 0 ; i <= 5 ; i++) {
    if(blue[y][i] == 0) {
      pos = i;
    }
    else break;
  }
  blue[y][pos] = 1;
  return;
}

void putblock2(int y, int x) {
  int pos = 0;
  for(int i = 0 ; i <= 5 ; i++) {
    if(green[i][x] == 0 && green[i][x + 1] == 0) {
      pos = i;
    }
    else break;
  }
  green[pos][x] = 2;
  green[pos][x + 1] = 2;
  pos = 0;
  for(int i = 1 ; i <= 5 ; i++) {
    if(blue[y][i] == 0 && blue[y][i - 1] == 0) {
      pos = i;
    }
    else break;
  }
  blue[y][pos] = 1;
  blue[y][pos - 1] = 1;
}

void putblock3(int y, int x) {
  int pos = 0;
  for(int i = 1 ; i <= 5 ; i++) {
    if(green[i][x] == 0 && green[i - 1][x] == 0) {
      pos = i;
    }
    else break;
  }
  green[pos][x] = 1;
  green[pos - 1][x] = 1;

  pos = 0;

  for(int i = 0 ; i <= 5 ; i++) {
    if(blue[y][i] == 0 && blue[y + 1][i] == 0) {
      pos = i;
    }
    else break;
  } 
  blue[y][pos] = 3;
  blue[y + 1][pos] = 3;

}

void getscoregreen() {
  while(1) {
     bool clear = false;

     for(int i = 1 ; i <= 5 ; i++) {
        bool g = true;
        for(int j = 0 ; j < 4 ; j++) {
          if(green[i][j] == 0) g = false;
        }
        if(g) {
          ans++;
          clear = true;
          for(int j = 0 ; j < 4 ; j++) {
            green[i][j] = 0;
          }
        }
     }

     if(!clear) return;

     for(int i = 5 ; i >= 0 ; i--) {
      for(int j = 0 ; j < 4 ; j++) {
        int y = i;
        int x = j;
        if(green[i][j] == 1) {
          for(int k = i + 1 ; k <= 5 ; k++) {
            if(green[k][j] == 0) {
              y = k;
            }
            else break;
          }

          green[i][j] = 0;
          green[y][j] = 1;
        }

        else if(green[i][j] == 2 && j != 3 && green[i][j + 1] == 2) {
          for(int k = i + 1 ; k <= 5 ; k++) {
            if(green[k][j] == 0 && green[k][j + 1] == 0) {
              y = k;
            }
            else break;
          }
          green[i][j] = 0;
          green[i][j + 1] = 0;
          green[y][j] = 2;
          green[y][j + 1] = 2;
        } 
      }
     }
  }
}

void getscoreblue() {
  while(1) {
     bool clear = false;
     for(int i = 1 ; i <= 5 ; i++) {
        bool g = true;
        for(int j = 0 ; j < 4 ; j++) {
          if(blue[j][i] == 0) g = false;
        }
        if(g) {
          ans++;
          clear = true;
          for(int j = 0 ; j < 4 ; j++) {
            blue[j][i] = 0;
          }
        }
     }

     if(!clear) return;

     for(int i = 5 ; i >= 0 ; i--) {
      for(int j = 0 ; j < 4 ; j++) {
        int y = j;
        int x = i;
        if(blue[j][i] == 1) {
          for(int k = i + 1 ; k <= 5 ; k++) {
            if(blue[j][k] == 0) {
              x = k;
            }
            else break;
          }
          blue[j][i] = 0;
          blue[j][x] = 1;
        }

        else if(blue[j][i] == 3 && j != 3 && blue[j + 1][i] == 3) {
          for(int k = i + 1 ; k <= 5 ; k++) {
            if(blue[j][k] == 0 && blue[j + 1][k] == 0) {
              x = k;
            }
            else break;
          }
          blue[j][i] = 0;
          blue[j + 1][i] = 0;
          blue[j][x] = 3;
          blue[j + 1][x] = 3;
        }  
      }
     }
  }
}

void greencase() {
  bool f = false;
  int cnt = 0;
  for(int i = 0 ; i < 2 ; i++) {
    for(int j = 0 ; j < 4 ; j++) {
      if(green[i][j] >= 1 && i == 0) f = true;
      if(green[i][j] >= 1) {
        cnt++;
        break;
      }
    }
  }
  if(cnt == 0) return;
  if(cnt == 1 && f == true) {
    for(int i = 0 ; i < 4 ; i++) {
      green[1][i] = green[0][i];
      green[0][i] = 0;
    }
  }
  int newgreen[6][4] = {};
  if(cnt == 1) {
    for(int i = 2 ; i <= 5 ; i++) {
      for(int j = 0 ; j < 4 ; j++) {
        newgreen[i][j] = green[i - 1][j];
      }
    }
  }
  else if(cnt == 2) {
    for(int i = 2 ; i <= 5 ; i++) {
      for(int j = 0 ; j < 4 ; j++) {
        newgreen[i][j] = green[i - 2][j];
      }
    }
  }

  for(int i = 0 ; i < 6 ; i++) {
    for(int j = 0 ; j < 4 ; j++) {
      green[i][j] = newgreen[i][j];
    }
  }
}

void bluecase() {
  bool f = false;
  int cnt = 0;
  for(int i = 0 ; i < 2 ; i++) {
    for(int j = 0 ; j < 4 ; j++) {
      if(blue[j][i] >= 1 && i == 0) f = true;
      if(blue[j][i] >= 1) {
        cnt++;
        break;
      }
    }
  }
  if(cnt == 0) return;
  if(cnt == 1 && f == true) {
    for(int i = 0 ; i < 4 ; i++) {
      blue[i][1] = blue[i][0];
      blue[i][0] = 0;
    }
  }
  int newblue[4][6] = {};
  if(cnt == 1) {
    for(int i = 2 ; i <= 5 ; i++) {
      for(int j = 0 ; j < 4 ; j++) {
        newblue[j][i] = blue[j][i - 1];
      }
    }
  }
  else if(cnt == 2) {
    for(int i = 2 ; i <= 5 ; i++) {
      for(int j = 0 ; j < 4 ; j++) {
        newblue[j][i] = blue[j][i - 2];
      }
    }
  }

  for(int i = 0 ; i < 6 ; i++) {
    for(int j = 0 ; j < 4 ; j++) {
      blue[j][i] = newblue[j][i];
    }
  }
  return;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false); 
  cin >> N;

  while(N--) {
    int t, x, y;
    cin >> t >> y >> x;

    if(t == 1) {
      putblock1(y, x);
    }
    if(t == 2) {
      putblock2(y, x); 
    }
    if(t == 3) {
      putblock3(y, x);
    }
    getscoregreen();
    getscoreblue();
    greencase();
    bluecase();
  }
  cout << ans << endl;

  int sum = 0;
  for(int i = 0 ; i < 6 ; i++) {
    for(int j = 0 ; j < 4 ; j++) {
      if(green[i][j] > 0) sum++;
      if(blue[j][i] > 0) sum++;
    }
  }
  cout << sum << endl;
} 
