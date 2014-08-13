#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	string s1;
	s1 = "Anatoliy";
	cout << "s1 is : " << s1 << endl;

	// copy constructor
	string s2(s1);
	cout << "s2 is : " << s2 << endl;

	char *line = "short line for testing";
	// one argument
	string s3(line);
	cout << "s3 is : " << s3 << endl;

	string s4(line, 10);
	cout << "s4 is : " << s4 << endl;

	string s5(s3, 6, 4);
	cout << "s5 is : " << s5 << endl;

	string s6(15,'*');
	cout << "s6 is : " << s6 << endl;

	string s7(s3.begin(), s3.end()-5);
	cout << "s7 is : " << s7 << endl;


	// you can instantiate string with assignment
	string s8 = "Anatoliy";
	cout << "s8 is : " << s8 << endl;

	string str;
	cout << "Enter string (EOL = $) : " << endl;
	getline(cin, str, '$');
	cout << "Str is : " << str << endl;
	cout << str.size() << ":" << str.capacity() << endl;

	ifstream In("data.dat");
	vector<string> v;

	cout << endl << "Read data from file" << endl;

	while(!In.eof()) {
		getline(In, str);
		v.push_back(str);
	}

	//vector<string>::interator iter;
	//for(iter = v.begin(); iter != v.end(); ++iter)
	//	cout << *iter;
	

	//copy(v.begin(), v.end(), ifostream_iterator(cout, "\n"));

	string str1 = "Hello!";
	string str2;

	str2 = str1;
	cout << str1 << "," << str2 << endl;

	string str3 = "Roy";

	str2 += str3;
	cout << "str2 : " << str2 << endl;
	str2 = str1.substr(0, 2);
	cout << "str2 : " << str2 << endl;
	cout << str1.find('e') << endl;

	const char *cstr1 = str1.c_str();

	char buf[100] = {0};
	str1.copy(buf, 5);
	cout << buf << endl;
	
	cout << endl;

	return 0;
}
