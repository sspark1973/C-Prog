/*
Reverse a string and also check whether it is palindrome or not while you are reversing
*/

#include <iostream>
#include <string>

using namespace std;

bool check(string str)
{
	int len = str.length();
	int start = 0;
	int end = len - 1;
	bool flag = 1;
	char temp;

	while(start < end) {
		if(str[start] != str[end]) {
			flag = 0;
		}
		//swap(str[start], str[end]);
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}

	//if(flag != 0 )
	//	flag = 1;

	cout << "Reversed string : " << str << endl;

	return flag;
			
}

int main()
{
	string str;
	cout << "Enter String: \n";
	cin >> str;

	if(!check(str)) {
		cout << "Not a palindrome" << endl;
	} else {
		cout << "Palindrom" << endl;
	}

	return 0;
}

