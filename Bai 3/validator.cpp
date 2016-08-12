#include "testlib.h"
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)
using namespace std;

const int MN = 1000111;
struct DSU {
    int lab[MN];
    void init(int n) {
        REP(i,n+1) lab[i] = -1;
    }

    int getRoot(int u) {
        if (lab[u] < 0) return u;
        return lab[u] = getRoot(lab[u]);
    }

    bool merge(int u, int v) {
        u = getRoot(u); v = getRoot(v);
        if (u == v) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }
};

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
    int n = inf.readInt(1, 200000);
    inf.readEoln();
    DSU dsu;
    dsu.init(n);
    FOR(i,2,n) {
        int u = inf.readInt();
        inf.readSpace();
        int v = inf.readInt();
        inf.readEoln();

        ensuref(dsu.getRoot(u) != dsu.getRoot(v), "no cycle");
        dsu.merge(u, v);
    }
    inf.readEof();
}
