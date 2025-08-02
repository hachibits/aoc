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
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    char c;
    while (cin >> x) {
      a[i].push_back(x);
      c = (char) cin.get();
      if (c == '\n') {
        break;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < (int) a[i].size(); k++) {
      bool ok = true;  
      vector<vector<int>> b = a;
      b[i].erase(b[i].begin() + k);
      bool inc = true;
      bool dec = true;
      for (int j = 0; j < (int) b[i].size() - 1; j++) {
        int diff = b[i][j+1] - b[i][j];
        if (diff > 0) {
          dec = false;
        }
        if (diff < 0) {
          inc = false;
        }
        if (!(abs(diff) >= 1 && abs(diff) <= 3)) {
          ok = false;
        }
      }
      if (ok && (inc || dec)) {
        cnt++;
        break;
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
