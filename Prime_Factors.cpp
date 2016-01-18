#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
bool isPrime(int x) {
	if (x == 1) return false;
	if (x == 2 || x == 3) return true;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0)
			return false;
	}
	return true;
}

int main()
{
	long long n;
	cin >> n;
	if (n == 1) {
		cout << n << "=" << n;
		return 0;
	}
	if (isPrime(n)) {
		cout << n << "=" << n;
		return 0;
	}
	int i, k = (int)sqrt(n + 0.0);//n的素因子不可能超过k
	bool first = true;
	cout << n << "=";
	for (i = 2; i <= k; i++) //从最小的素数2开始对n进行分解
	{
		int tot = 0;  //某个素因子出现的次数(幂指数)
		if (n%i == 0)  //i是素因子
		{
			while (n%i == 0)//对n进行分解
			{
				tot++;  //累计素因子出现的次数
				n /= i;   //对n进行分解
			}
			if (first)   //处理n的第1个素因子,按p1^k1的格式打印
			{
				first = false;
				if (tot >= 2)cout << i << "^" << tot;//按幂指数方式打印
				else cout << i;   //素因子只出现1次,直接打印该素因子
			}
			else    //从第2个素因子开始,按*p2^k2的格式打印
			{
				if (tot >= 2)cout << "*" << i << "^" << tot;
				else cout << "*" << i;
			}
		}
		//某个素因子不能分解n后得到的新的n,新的n的素因子不可能超过k
		//这是本题的关键之处,即每得到一个新的n,均对其开平方根,否则会超时
		k = (int)sqrt(n + 0.0);
	}
	if (n>1)cout << "*" << n;    //输出最后一个素因子
	return 0;
}