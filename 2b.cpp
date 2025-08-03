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

bool valid(vector<int> a) {
  bool ok = true;  
  bool inc = true;
  bool dec = true;
  for (int i = 0; i < (int) a.size() - 1; i++ ) {
    int diff = a[i+1] - a[i];
    if (diff > 0) {
      dec = false;
    } else if (diff < 0) {
      inc = false;
    }
    if (!(abs(diff) >= 1 && abs(diff) <= 3)) {
      ok = false;
      break;
    }
  }
  return ok && (inc || dec);
}

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
    bool ok = false;
    auto consider = [&](int x) {
      vector<int> b = a[i];
      b.erase(b.begin() + x);
      if (valid(b)) {
        ok = true;
      }
    };
    consider(0);
    for (int j = 0; j < (int) a[i].size() - 1; j++) {
      int diff = a[i][j+1] - a[i][j];
      if (abs(diff) < 1 || abs(diff) > 3) {
        consider(j);
        consider(j+1);
        break;
      }
      if (j + 2 < (int) a[i].size()) {
        int diff2 = a[i][j+2] - a[i][j+1];
        if ((diff > 0) != (diff2 > 0)) {
          consider(j);
          consider(j+1);
          consider(j+2);
          break;
        }
      }
    }
    if (ok) {
      cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}
