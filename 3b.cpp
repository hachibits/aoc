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
  string s, t;
  for (int i = 0; i < n && cin >> t; s += t);
  auto Num = [&](int& i) {
    int x = 0;
    while (isdigit(s[i])) {
      x = 10 * x + (s[i] - '0');
      i++;
    }
    return x;
  };
  int k = (int) s.size();
  bool enable = true;
  int ans = 0;
  for (int i = 0; i < k - 7; i++) {
    if (s.substr(i, 4) == "do()") {
      enable = true;
    }
    if (s.substr(i, 7) == "don\'t()") {
      enable = false;
    }
    if (enable && s[i] == 'm') {
      if (i + 3 < k && s.substr(i + 1, 3) == "ul(") {
        i += 4;
        int x = Num(i);
        if (i + 1 < k && s[i] == ',') {
          i++;
          int y = Num(i);
          if (i + 1 < k && s[i] == ')') {
            ans += x * y;
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
