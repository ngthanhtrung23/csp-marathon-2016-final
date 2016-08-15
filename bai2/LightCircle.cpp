/**
 *	Original Problem: CCC 2016 S5 - Circle of Life
 *	Solution author: nullptr
 *	Link: https://dmoj.ca/problem/ccc16s5
 **/
#include <bits/stdc++.h>

using namespace std;

int N;
long long T;
char S[100001];
int A[100001];
int B[100001];

void step(int k)
{
	int pos=(1LL<<k)%N;
	int pos2=(N-pos)%N;
	for(int i=0; i<N; i++)
		B[i]=A[(i+pos)%N]^A[(i+pos2)%N];
	memcpy(A, B, sizeof A);
}

int main()
{
	scanf("%d%lld", &N, &T);
	scanf("%s", S);
	for(int i=0; i<N; i++)
		A[i]=S[i]-'0';
	for(int i=60; i>=0; i--) if((T>>i)&1)
		step(i);
	for(int i=0; i<N; i++)
		printf("%d", A[i]);
	printf("\n");
	return 0;
}
