#include<stdio.h>
#include<iostream>
#include<set>
#include<math.h>

using namespace std;

int value[100001];
int nextAddr[100001];
int firsrList[100001];
int secondList[100001];
int main()
{
	int firstAddr, N;
	set<int> container;
	cin >> firstAddr >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		scanf("%d %d", &value[temp], &nextAddr[temp]);
	}
	int l1 = 0;
	int l2 = 0;
	int addr = firstAddr;
	while (addr != -1) {
		if (container.find(abs(value[addr])) == container.end()) {
			container.insert(abs(value[addr]));
			firsrList[l1++] = addr;
		}
		else {
			secondList[l2++] = addr;
		}
		addr = nextAddr[addr];
	}
	firsrList[l1] = -1;
	secondList[l2] = -1;
	printf("\n");
	for (int i = 0; i < l1-1; i++) {
		printf("%05d %d %05d\n", firsrList[i], value[firsrList[i]], firsrList[i+1]);
	}
	printf("%05d %d -1\n", firsrList[l1-1], value[firsrList[l1-1]]);
	for (int i = 0; i < l2-1; i++) {
		printf("%05d %d %05d\n", secondList[i], value[secondList[i]], secondList[i+1]);
	}
	printf("%05d %d -1", secondList[l2-1], value[secondList[l2-1]]);
	return 0;
}