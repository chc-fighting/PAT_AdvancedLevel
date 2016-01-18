#include<stdio.h>
#include<iostream>
#include<stack>
#include<math.h>

using namespace std;
#define INF 0x6FFFFFFF  
int edges[501][501];
int VterxN = 0;
int visited[501];
int minDist[501];
int minNumCollect[501];
int minNumSend[501];
int capacity[501];
int prevNode[501];
int cMax = 0;
void Dijkstra()
{
	for (int i = 1; i < VterxN; i++) {
		if (edges[0][i] != INF) {
			minDist[i] = edges[0][i];
			if (capacity[i] > cMax / 2) {
				minNumCollect[i] = capacity[i] - cMax / 2;
				minNumSend[i] = 0;
			}
			else {
				minNumSend[i] = cMax / 2 - capacity[i];
				minNumCollect[i] = 0;
			}
			prevNode[i] = 0;
		}
	}
	minDist[0] = 0;
	minNumCollect[0] = 0;
	minNumSend[0] = 0;
	prevNode[0] = -1;
	visited[0] = 1;
	for (int i = 1; i < VterxN; i++) {
		int minD = INF;
		int minV = 0;
		for (int v = 0; v < VterxN; v++) {
			if (!visited[v] && minDist[v] < minD) {
				minD = minDist[v];
				minV = v;
			}
		}
		if (minD == INF)
			break;
		visited[minV] = 1;
		// 用已知的这个最小点为中间节点去更新其他所有的顶点
		for (int w = 0; w < VterxN; w++) {
			if (!visited[w]) {
				int collect = minNumCollect[minV] + capacity[w] - cMax / 2;
				int send = minNumSend[minV];
				if (collect < 0) {
					send = send - collect;
					collect = 0;
				}
				if (minDist[minV] + edges[minV][w] < minDist[w]) {
					minDist[w] = minDist[minV] + edges[minV][w];
					prevNode[w] = minV;
					minNumSend[w] = send;
					minNumCollect[w] = collect;
				}
				else if (minDist[minV] + edges[minV][w] == minDist[w]) { // 不要设置非连通边为INT_MAX的用意在此，否则会溢出，不好比较
					if (send < minNumSend[w]) {
						minNumSend[w] = send;
						minNumCollect[w] = collect;
						prevNode[w] = minV;
					}
					else if (send == minNumSend[w]) {
						if (collect < minNumCollect[w]) {
							minNumCollect[w] = collect;
							prevNode[w] = minV;
						}
					}
				}
			}
		}
	}
}
int main()
{
	int N, sp, M;
	cin >> cMax >> N >> sp >> M;
	for (int i = 1; i <= N; i++)
		cin >> capacity[i];
	VterxN = N + 1;
	for (int i = 0; i < VterxN; i++) {
		for (int j = 0; j < VterxN; j++) {
			edges[i][j] = INF;
		}
		minDist[i] = INF;
		minNumCollect[i] = INF;
		minNumSend[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int v1, v2, val;
		cin >> v1 >> v2 >> val;
		edges[v1][v2] = edges[v2][v1] = val;
	}
	Dijkstra();
	stack<int> path;
	int dest = sp;
	path.push(sp);
	while (1) {
		int next = prevNode[dest];
		if (next == -1)
			break;
		path.push(next);
		dest = next;
	}
	cout << minNumSend[sp] << " 0";
	path.pop();
	while (!path.empty()) {
		cout << "->" << path.top();
		path.pop();
	}
	cout << " "<<minNumCollect[sp];
	return 0;
}