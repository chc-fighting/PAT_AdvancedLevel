#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<math.h>
using namespace std;
vector<int> G[100001];
int main()
{
	int N;
	queue<int> que;
	double p, r;
	double res = 0.0;
	cin >> N >> p >> r;
	int root = 0;
	int level = 0;
	int finalPath = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num != -1)
			G[num].push_back(i);
		else
			root = i;
	}
	que.push(root);
	while (!que.empty()) {
		int len = que.size();
		finalPath = len;
		while (len--) {
			int t = que.front();
			if (!G[t].empty()) {
				for (int i = 0; i < G[t].size(); i++) {
					que.push(G[t][i]);
				}
			}
			que.pop();
		}
		level++;
	}
	res = p*pow(1 + r / 100, double(level-1));
	printf("%.2f %d", res, finalPath);
	return 0;
}