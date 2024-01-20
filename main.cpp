#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

constexpr auto MaxP = 10000000LL + 6;

vb sieve(MaxP, true);
vl plist;

void BuildPrime() {
  sieve[0] = false;
  sieve[1] = false;

  plist.reserve(4000000LL + 6);

  for (auto i = 2LL; i < MaxP; ++i) {
    if (!sieve[i])
      continue;

    plist.push_back(i);

    for (auto j = i * 2; j < MaxP; j += i) {
      sieve[j] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  BuildPrime();

  ll a, b;
  cin >> a >> b;

  auto ans = ll{0};
  for (const auto& p : plist) {
    if (b < p) {
      break;
    }

    auto t = 2LL;
    while (true) {
      const auto& q = pow(p, t);

      if (b < q)
        break;

      if (a <= q && q <= b) {
        ++ans;
      }

      ++t;
    }
  }

  cout << ans;

  return 0;
}