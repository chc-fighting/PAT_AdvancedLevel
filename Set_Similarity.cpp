#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<stdio.h>
#include<algorithm>
#include<iterator>
using namespace std;
set<int> sets[50];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int M;
		scanf("%d", &M);
		while (M--) {
			int number;
			scanf("%d", &number);
			sets[i].insert(number);
		}
	}
	int K;
	scanf("%d", &K);
	while (K--) {
		int i, j;
		scanf("%d%d", &i,&j);
		set<int> inter_set, union_set;
		set_intersection(sets[i - 1].begin(), sets[i - 1].end(), sets[j - 1].begin(), sets[j - 1].end(),inserter(inter_set,inter_set.begin()));
		//set_union(sets[i - 1].begin(), sets[i - 1].end(), sets[j - 1].begin(), sets[j - 1].end(), insert_iterator<set<int>>(union_set, union_set.begin()));
		double nc = inter_set.size();
		double nt = sets[i - 1].size() + sets[j - 1].size() - nc;
		printf("%.1f%%\n", nc / nt * 100);
	}
	return 0;
}