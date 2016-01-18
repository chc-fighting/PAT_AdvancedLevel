#define _CRT_SECURE_NO_WARNINGS
#include<stack>
#include<iostream>
#include<set>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	stack<int> stk;
	multiset<int> nums_set;
	for (int i = 0; i < N; i++) {
		char ch[12];
		scanf("%s", ch);
		string str(ch);
		if (str == "Push") {
			int num;
			scanf("%d", &num);
			stk.push(num);
			nums_set.insert(num);
		}
		else if (str == "Pop") {
			if (stk.empty())
				cout << "Invalid" << endl;
			else {
				cout << stk.top()<<endl;
				nums_set.erase(nums_set.find(stk.top()));
				stk.pop();
			}
		}
		else {
			if (stk.empty())
				cout << "Invalid" << endl;
			else {
				int len = nums_set.size();
				int mid = (len + 1) / 2 - 1;
				multiset<int>::iterator ite = nums_set.begin();
				while (mid--)
					++ite;
				cout << *ite << endl;
			}
		}
	}
	return 0;
}