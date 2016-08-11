#include "testlib.h"
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
    int n = inf.readInt(1, 50000);
    inf.readSpace();

    const int MAX = 1000000;
    long long r = inf.readInt(0, MAX);
    inf.readEoln();

    FOR(i,1,n) {
        long long x = inf.readInt(-MAX, MAX);
        inf.readSpace();
        long long y = inf.readInt(-MAX, MAX);
        inf.readEoln();

        ensuref(x*x + y*y > r*r, "must be outside");
    }
    inf.readEof();
}
