#include "testlib.h"
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)
using namespace std;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
    int n = inf.readInt(1, 100000);
    inf.readSpace();
    long long t = inf.readLong(0, 1000000000000000LL);
    inf.readEoln();
    stringstream ss;
    ss << "[01]{" << n << "}";
    inf.readToken(ss.str());
    inf.readEoln();
    inf.readEof();
}
