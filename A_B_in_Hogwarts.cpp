#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	char str1[15], str2[15];
	int a[3], b[3],c[3];
	scanf("%s%s", str1, str2);
	char *tmp = strtok(str1, ".");
	int i = 0;
	while (tmp != NULL) {
		sscanf(tmp, "%d", &a[i++]);
		tmp = strtok(NULL, ".");
	}
	tmp = strtok(str2, ".");
	i = 0;
	while (tmp != NULL) {
		sscanf(tmp, "%d", &b[i++]);
		tmp = strtok(NULL, ".");
	}
	int carry = 0;
	if (a[2] + b[2] >= 29) {
		c[2] = (a[2] + b[2]) % 29;
		carry = 1;
	}
	else
		c[2] = (a[2] + b[2]);
	if (a[1] + b[1] + carry >= 17) {
		c[1] = (a[1] + b[1]+carry) % 17;
		carry = 1;
	}
	else {
		c[1] = (a[1] + b[1])+carry ;
		carry = 0;
	}
	c[0] = a[0] + b[0] + carry;
	printf("%d.%d.%d",c[0],c[1],c[2]);
	return 0;
}