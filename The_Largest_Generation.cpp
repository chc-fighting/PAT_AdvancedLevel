#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <math.h>
using namespace std;
vector <int > G[101];
int main()
{
	int N,M;
	queue <int > que;
	cin >> N >> M;
	int root = 0;
	int level = 0;
	int maxLen = 0, LargestLevel = 0;
	for (int i = 0; i < M; i++) {
		int ID, K;
		cin >> ID >> K;
		while (K--) {
			int num;
			cin >> num;
			G[ID].push_back(num);
		}
	}
	que.push(1);
	while (!que.empty()) {
		level++;
		int len = que.size();
		if (len > maxLen) {
			maxLen = len;
			LargestLevel = level;
		}
		while (len--) {
			int t = que.front();
			if (!G[t].empty()) {
				for (int i = 0; i < G[t].size(); i++) {
					que.push(G[t][i]);
				}
			}
			que.pop();
		}
	}
	cout << maxLen << " "<< LargestLevel;
	return 0;
}

