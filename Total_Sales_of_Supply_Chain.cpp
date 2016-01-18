#include<vector>
#include<queue>
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
vector <vector<int>> chain;
int amounts[100000];
int main()
{
	int N;
	double P, r;
	cin >> N >> P >> r;
	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int k;
		cin >> k;
		if (k == 0) {
			int num;
			cin >> num;
			amounts[i] = num;
		}
		else {
			while (k--) {
				int num;
				cin >> num;
				tmp.push_back(num);
			}
		}
		chain.push_back(tmp);
	}
	queue<int> que;
	que.push(0);
	int level = 0;
	double res = 0.0;
	while (!que.empty()) {
		int len = que.size();
		while (len--) {
			int t = que.front();
			if (chain[t].size() == 0) {
				res += P*pow(1 + r / 100, level)*amounts[t];
			}
			for (int i = 0; i < chain[t].size();i++) {
				que.push(chain[t][i]);
			}
			que.pop();
		}
		level++;
	}
	printf("%.1f", res);
	return 0;
}