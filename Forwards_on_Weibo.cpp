#include<iostream>
#include<queue>
using namespace std;

int matrix[101][101];
int N,L;
int bfs(int start)
{
	queue<int> que;
	int level = L;
	int res = 0;
	int visited[101] = {0};
	que.push(start);
	visited[start] = 1;
	for (int i = 0; i < level;i++) {
		if (que.empty())
			break;
		int len = que.size();
		while (len--) {
			int t = que.front();
			for (int k = 0; k < N;k++) {
				if (!visited[k] && matrix[t][k]) {
					res++;
					que.push(k);
					visited[k] = 1;
				}
			}
			que.pop();
		}
	}
	return res;
}
int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		while (k--) {
			int id;
			cin >> id;
			matrix[id - 1][i] = 1;
		}
	}
	int K;
	cin >> K;
	while (K--) {
		int id;
		cin >> id;
		//dfs(id-1, 0, res); 用广度优先搜索而不是深度优先，否则在有环的情况下不好处理
		cout << bfs(id-1) << endl; 
	}
	return 0;
}