/*      
────────────────────────────
░░░░░░░░░░░░░░░░░░░░░░░░
Dad is watching over--->
░░░░░░░░░░░░░░░░░░░░░░░░
────────────────────────────
Prahlad_07     
*/
#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include <climits>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<climits>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#include<random>
using namespace std;
#define greet          cout<<"Hare Krishna"<<endl;
#define int            long long int
#define F              first
#define S              second
#define ll             long long
#define MOD            1000000007  
#define N              cout<<"No"<<endl
#define Y              cout<<"YES"<<endl
#define pb             push_back
#define si             set<int>
#define vi             vector<int>
#define pii            pair<int, int>
#define vpi            vector<pii>
#define MASK(x)        (1LL << (x))
#define BIT(x, i)      (((x) >> (i)) & 1)
#define all(x)         (x).begin(), (x).end()
#define rall(X)        X.rbegin(),X.rend()
#define rep(a, b)      for (int a = 0; a < (b); a++)
#define vpp            vector<pair<int, pii>>
#define mii            map<int, int>
#define mpi            map<pii, int>
#define spi            set<pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define double         long double
#define que_max        priority_queue<int>
#define que_min        priority_queue<int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) { const char* comma = strchr (names + 1, ','); cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...); }
ll power(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a) % MOD; a = (a * a) % MOD; b >>= 1; } return ans; }
ll power1(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a); a = (a * a); b >>= 1; } return ans; }
ll prod(ll a, ll b) { ll c = 0; while (b > 0) { if ((b & 1) == 1) { c += a; } a <<= 1; b >>= 1; } return c; }
struct Edge {
    int id;
    int u, v;
};

struct DSU {
    vector<int> par;
    DSU(int n) {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
    }
    int find(int i) {
        return par[i] == i ? i : par[i] = find(par[i]);
    }
    void unite(int i, int j) {
        int a = find(i), b = find(j);
        if (a != b) par[a] = b;
    }
};

int calculate_f(const vector<Edge>& edges) {
    if (edges.empty()) return 0;
    vector<pair<int, int>> seg;
    for (auto& e : edges) seg.push_back({e.u, e.v});
    sort(seg.begin(), seg.end());

    vector<pair<int, int>> merged = {seg[0]};
    for (int i = 1; i < seg.size(); ++i) {
        if (seg[i].first < merged.back().second) {
            merged.back().second = max(merged.back().second, seg[i].second);
        } else {
            merged.push_back(seg[i]);
        }
    }

    int total = 0;
    for (auto& s : merged) total += s.second - s.first;
    return total;
}

void _RusHErrr(int tt) { 
    int n;
    cin >> n;
    vector<int> pos(n, -1);
    function<void(int)> solve = [&](int row){
        if(row == n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    cout << (pos[i]==j ? "Q " : ". ");
                cout << endl;
            }
            cout << endl;
            return;
        }
        for(int col=0;col<n;col++){
            bool ok = true;
            for(int i=0;i<row;i++)
                if(pos[i]==col || abs(pos[i]-col)==row-i) { ok=false; break; }
            if(ok){ pos[row]=col; solve(row+1); pos[row]=-1; }
        }
    };
    solve(0);
}



int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

    clock_t z = clock();
    int tt = 1; cin >> tt;
    while (tt--) { 
        _RusHErrr(tt); 
    }
    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
