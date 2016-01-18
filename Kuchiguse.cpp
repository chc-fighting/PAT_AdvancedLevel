#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

vector<string> caseString;
string longestSuffix(string &s1, string &s2)
{
	string res="";
	int len1 = s1.length();
	int len2 = s2.length();
	int len = len1 > len2 ? len2 : len1;
	if (len1 && len2) {
		while (len--) {
			if (s1[len1 - 1] != s2[len2 - 1])
				break;
			else {
				len1--;
				len2--;
			}
		}
		res = s1.substr(len1);
	}
	return res;
}
int main()
{
	int N;
	cin >> N;
	getchar();
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		caseString.push_back(str);
	}
	string res = caseString[0];
	for (int i = 1; i < N;i++) {
		res = longestSuffix(res, caseString[i]);
	}
	if (res == "")
		cout << "nai";
	else
		cout << res;
	return 0;
}