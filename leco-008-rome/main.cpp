#include<iostream>
#include<string>
using namespace std;
/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
class Solution {
public:
    string intToRoman(int num) {
	string s = "";
	int next = num;
	if( next >= 1000 ){for (int i = 0;i < num/1000;++i){s += 'M';}
		next = next%1000;
	}
	if( next >= 900 ){s += "CM";next -= 900;}
	if( next >= 500 ){s += 'D';next -= 500;}
	if( next >= 400 ){s += "CD";next -= 400;}
	if (next >= 100 ){for (int i = 0;i < next/100;++i){s += 'C';}
		next = next%100;
	}
	if (next >= 90 ){s += "XC";next -= 90;}
	if (next >= 50 ){s += 'L';next -= 50;}
	if (next >= 40 ){s += "XL";next -= 40;}
	if (next >= 10 ){for (int i = 0; i < next/10;++i){s += 'X';}
		next = next%10;
	}
	if( next == 9 ){s += "IX";return s;}
	if (next >= 5 ){s += 'V';next -= 5;}
	if (next == 4 ){s += "IV";return s;}
	if (next < 4 ){for( int i = 0;i < next;++i){s += 'I';}
	}
	return s;
    }
};
int main(int argc, char *argv[])
{
	int num = 1994;
	Solution sol;
	string s = sol.intToRoman(num);
	cout<<"rome num is:"<< s <<endl;
	return 0;
}
