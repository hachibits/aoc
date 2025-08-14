#include <bits/stdc++.h>
using namespace std;

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD = (ll)(1e9)+7ll;
const ll INF = (1ll << 60);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int r;
  cin >> r;
  vector<string> a(r);
  for (int i = 0; i < r; i++) {
    cin >> a[i];
  }
  int c = (int) a[0].size();
  int cnt = 0;
  for (int x = 0; x < r; x++) {
    for (int y = 0; y < c; y++) {
      if (a[x][y] != 'X') {
        continue;
      }
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx == 0 && dy == 0) {
            continue;
          }
          bool found = true;
          const string s = "XMAS";
          for (int i = 0; i < 4; i++) {
            int x2 = x + dx * i;
            int y2 = y + dy * i;
            if (!(x2 >= 0 && x2 < r && y2 >= 0 && y2 < c && a[x2][y2] == s[i])) {
              found = false;
              break;
            }
          }
          cnt += found;
        }
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
