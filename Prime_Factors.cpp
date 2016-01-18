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
	int i, k = (int)sqrt(n + 0.0);//n�������Ӳ����ܳ���k
	bool first = true;
	cout << n << "=";
	for (i = 2; i <= k; i++) //����С������2��ʼ��n���зֽ�
	{
		int tot = 0;  //ĳ�������ӳ��ֵĴ���(��ָ��)
		if (n%i == 0)  //i��������
		{
			while (n%i == 0)//��n���зֽ�
			{
				tot++;  //�ۼ������ӳ��ֵĴ���
				n /= i;   //��n���зֽ�
			}
			if (first)   //����n�ĵ�1��������,��p1^k1�ĸ�ʽ��ӡ
			{
				first = false;
				if (tot >= 2)cout << i << "^" << tot;//����ָ����ʽ��ӡ
				else cout << i;   //������ֻ����1��,ֱ�Ӵ�ӡ��������
			}
			else    //�ӵ�2�������ӿ�ʼ,��*p2^k2�ĸ�ʽ��ӡ
			{
				if (tot >= 2)cout << "*" << i << "^" << tot;
				else cout << "*" << i;
			}
		}
		//ĳ�������Ӳ��ֽܷ�n��õ����µ�n,�µ�n�������Ӳ����ܳ���k
		//���Ǳ���Ĺؼ�֮��,��ÿ�õ�һ���µ�n,�����俪ƽ����,����ᳬʱ
		k = (int)sqrt(n + 0.0);
	}
	if (n>1)cout << "*" << n;    //������һ��������
	return 0;
}