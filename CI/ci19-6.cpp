/*
19.6 Given an integer between 0 and 999,999, print an English phrase that describes the integer 
(eg, ¡°One Thousand, Two Hundred and Thirty Four¡±).
*/

#include <string>
#include <map>
#include <iostream>

using namespace std;

class InWords
{
private:
	map<int,string> m_map;

	string print1k(int num) {
		string s1;
		int h = 0;

		if(num/100) {
			s1 += m_map[num/100];
			cout << s1 << " " << m_map[num/100] << endl;
			s1 += string(" hundred ");
			num = num%100;
			h = 1;
		}

		if(num/10) {
			if(h)
				s1 += string("and ");
			if(num/10 >= 2) {
				s1 += m_map[(num/10)*10];

				if(num%10 != 0) {
					s1 += " ";
					s1 += m_map[num%10];
					return s1;
				}

				return s1;
			} else {
				s1 += m_map[num];
				return s1;
			}
		}

		if(!num)
			return s1;
		else {
			if(h)
				s1 += string(" and ");
			s1 += m_map[num];
			return s1;
		}
	}
	
public:
	InWords()	{
		m_map.insert(make_pair(1,"one"));
		m_map.insert(make_pair(2,"two"));
		m_map.insert(make_pair(3,"three"));
		m_map.insert(make_pair(4,"four"));
		m_map.insert(make_pair(5,"five"));
		m_map.insert(make_pair(6,"six"));
		m_map.insert(make_pair(7,"seven"));
		m_map.insert(make_pair(8,"eight"));
		m_map.insert(make_pair(9,"nine"));
		m_map.insert(make_pair(10,"ten"));
		m_map.insert(make_pair(11,"eleven"));
		m_map.insert(make_pair(12,"twelve"));
		m_map.insert(make_pair(13,"thirteen"));
		m_map.insert(make_pair(14,"fourteen"));
		m_map.insert(make_pair(15,"fifteen"));
		m_map.insert(make_pair(16,"sixteen"));
		m_map.insert(make_pair(17,"seventeen"));
		m_map.insert(make_pair(18,"eighteen"));
		m_map.insert(make_pair(19,"nineteen"));
		m_map.insert(make_pair(20,"twenty"));
		m_map.insert(make_pair(30,"thirty"));
		m_map.insert(make_pair(40,"forty"));
		m_map.insert(make_pair(50,"fifty"));
		m_map.insert(make_pair(60,"sixty"));
		m_map.insert(make_pair(70,"seventy"));
		m_map.insert(make_pair(80,"eighty"));
		m_map.insert(make_pair(90,"ninety"));
	}

	string getWords(int num) {
		string s1;

		if(num <= 999)
			return print1k(num);
		else {
			s1 = print1k(num/1000);
			s1 += string(" thousand ");
			s1 += print1k(num%1000);
			return s1;
		}
	}

};

int main()
{
	InWords w;
	//for(int i = 1; i <= 999,999; i++);
	//cout << w.getWords(i) << endl;
	cout << w.getWords(4) << endl;
	cout << w.getWords(18) << endl;
	cout << w.getWords(39) << endl;
	cout << w.getWords(297) << endl;
	cout << w.getWords(1024) << endl;
	cout << w.getWords(51824) << endl;
	cout << w.getWords(241724) << endl;
	cout << w.getWords(999999) << endl;
}


