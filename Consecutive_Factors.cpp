#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int maxLen = 1;
	int startIndex = N;
	int sqN = sqrt(N);
	for (int start = 2; start <= sqN; start++) {
		if (N % start == 0) {
			int cnt = 1;
			int number = N/start;
			for (int i = start+1; ;i++) {
				if (number%i == 0) {
					cnt++;
					number /= i;
				}
				else
					break;
			}
			if (cnt > maxLen || (cnt==maxLen&&start < startIndex)) {
				maxLen = cnt;
				startIndex = start;
			}
		}
	}
	cout << maxLen << endl;
	for (int i = 0; i < maxLen-1;i++)
		cout << startIndex+i << "*";
	cout << startIndex + maxLen - 1;
	return 0;
}