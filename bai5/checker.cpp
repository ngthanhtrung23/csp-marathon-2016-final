#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int) (x).size())
using namespace std;

double safe_sqrt(double x) {
    return sqrt(max((double)0.0,x));
}
int GI(ll& x) {
    return scanf("%lld", &x);
}

int m, n;

char rev(const char& c) {
    if (c == 'L' || c == 'R') return 'L' + 'R' - c;
    if (c == 'U' || c == 'D') return 'U' + 'D' - c;
    assert(0);
}

struct Move {
    int piece;
    char dir;
    int len;

    Move rev() const {
        Move res;
        res.piece = piece;
        res.dir = ::rev(dir);
        res.len = len;
        return res;
    }
};

struct State {
    char a[8][8];

    ll hash() {
        ll res = 0;
        FOR(i,1,m) FOR(j,1,n) {
            int val;
            if (a[i][j] == '.') val = 10;
            else if (a[i][j] >= '0' && a[i][j] <= '9') val = a[i][j] - '0';
            else val = a[i][j] - 'A' + 11;

            res = res * 17 + val;
        }
        return res;
    }

    set<char> getPieces() {
        set<char> all;
        FOR(i,1,m) FOR(j,1,n) if (a[i][j] != '.') all.insert(a[i][j]);
        return all;
    }

    int isPiece(int u, int v) const {
        if (a[u][v] == '.') return -1;
        assert((a[u][v] >= '0' && a[u][v] <= '9') || (a[u][v] >= 'A' && a[u][v] <= 'Z'));
        return a[u][v];
    }

    vector< pair<int,int> > locate(int piece) const {
        vector< pair<int,int> > res;
        FOR(i,1,m) FOR(j,1,n) {
            if (isPiece(i, j) == piece) {
                res.emplace_back(i, j);
            }
        }
        return res;
    }
} cur;

pair<int,int> getDir(char c) {
    if (c == 'L') return make_pair(0, -1);
    if (c == 'R') return make_pair(0, 1);
    if (c == 'U') return make_pair(-1, 0);
    if (c == 'D') return make_pair(1, 0);
    assert(0);
}

bool canMove(const State& s, const Move& m) {
    auto pos = s.locate(m.piece);

    assert(SZ(pos) >= 2);
    if (pos[0].first == pos[1].first) { // on same row
        if (m.dir == 'U' || m.dir == 'D') return false;
    }
    else { // on same col
        if (m.dir == 'L' || m.dir == 'R') return false;
    }

    auto dir = getDir(m.dir);

    FOR(step,1,m.len) {
        for(auto p : pos) {
            int u = p.first + dir.first * step;
            int v = p.second + dir.second * step;

            if (s.a[u][v] != '.' && s.a[u][v] != m.piece) return false;
        }
    }
    return true;
}

void makeMove(State& s, const Move& m) {
    assert(canMove(s, m));

    auto pos = s.locate(m.piece);
    auto dir = getDir(m.dir);

    for(auto p : pos) {
        s.a[p.first][p.second] = '.';
    }

    for(auto p : pos) {
        int u = p.first + dir.first * m.len;
        int v = p.second + dir.second * m.len;

        s.a[u][v] = m.piece;
    }
}

void wa(string comment) {
//    cout << comment << endl;
    cout << 0.0 << endl;
    exit(0);
}

int main() {
    m = n = 6;
    string test; cin >> test;
    string contestant; cin >> contestant;

    // read input
    fstream fin(test + "/unblock.inp", fstream :: in);
    memset(cur.a, ' ', sizeof cur.a);
    FOR(i,1,6) FOR(j,1,6) fin >> cur.a[i][j];
    fin.close();

    // read solution
    fstream fsol(test + "/unblock.out", fstream :: in);
    int opt; fsol >> opt;
    fsol.close();

    // read output
    fstream fcon(contestant + "/unblock.out", fstream :: in);
    int s;
    if (!(fcon >> s)) {
        wa("invalid s");
    }
    if (s < 0 || s > 1000) {
        wa("invalid s");
    }

    auto allPieces = cur.getPieces();
    FOR(i,1,s) {
        char p, d; int k;
        if (!(fcon >> p >> d >> k)) {
            wa("invalid input");
        }

        if (!allPieces.count(p)) {
            wa("invalid piece");
        }
        if (d != 'L' && d != 'R' && d != 'U' && d != 'D') wa("invalid dir");
        if (k < 0 || k > 4) wa("invalid len");

        Move m;
        m.piece = p;
        m.dir = d;
        m.len = k;
        if (!canMove(cur, m)) {
            wa("invalid move");
        }

        makeMove(cur, m);
    }
    fcon.close();

    if (cur.a[3][6] != '0') {
        wa("incomplete solution");
    }

    cout << "correct move" << endl;
    if (s > opt) cout << 0.7 * (opt / s) << endl;
    else cout << 1.0 << endl;
}
