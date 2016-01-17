#include <iostream>
#include <string>

using namespace std;


void getBaseExponents(string& str, string& base, int& exponents, int& N);

int main()
{
    // ��������
    int N; string str1, str2;
    cin >> N >> str1 >> str2;

    // �õ�����λ��û��0.����ָ��
    string base1, base2;
    int exponents1, exponents2;
    getBaseExponents(str1, base1, exponents1, N);
    getBaseExponents(str2, base2, exponents2, N);

    // ������
    if(base1 == base2 && exponents1 == exponents2) {
        cout << "YES 0." << base1 << "*10^" << exponents1 << endl;
    } else {
        cout << "NO 0." << base1 << "*10^" << exponents1 \
            << " 0." << base2 << "*10^" << exponents2 << endl;
    }
    return 0;
}

void getBaseExponents(string& str, string& base, int& exponents, int& N)
{
    int length = str.length();
    // �Ƿ���С���㣬���õ�ָ��λ��
    string::size_type pos = str.find('.');
    if(pos == string::npos) {
        exponents = length;
    } else {
        exponents = pos;
        str.erase(pos, 1);
    }

    // �Ƿ�ǰ����0
    int i=0; length = str.length();
    for(; i<length; i++) {
        if(str[0] == '0') {
            exponents--;
            str.erase(0, 1);
        } else {
            break;
        }
    }
    if(length == i) {
        exponents = 0;
    }

    // �õ�base
    base = ""; length = str.length();
    for(i=0; i<N; i++) {
        if(i<length) {
            base += str[i];
        } else {
            base += '0';
        }
    }
}
