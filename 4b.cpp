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
  const vector<int> dx = {-1, -1, 1, 1};
  const vector<int> dy = {-1, 1, 1, -1};
  int cnt = 0;
  for (int x = 1; x < r - 1; x++) {
    for (int y = 1; y < c - 1; y++) { 
      if (a[x][y] != 'A') {
        continue;
      }
      auto valid_diag = [](char a, char b) {
        return (a == 'M' && b == 'S') || (a == 'S' && b == 'M');
      };
      if (valid_diag(a[x-1][y-1], a[x+1][y+1]) && valid_diag(a[x-1][y+1], a[x+1][y-1])) {
        cnt++;
      }
    }
  }
  cout << cnt << '\n';
  return 0;
}
