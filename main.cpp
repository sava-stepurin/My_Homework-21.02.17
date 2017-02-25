#include "string.h"

using namespace mipt;

int main() {
	String s1("Helloe");
	String s2 = s1;
	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;
	std::cout << "'e' in s1 : " << s1.find('e') << std::endl;
	std::cout << "size s2 : " << s2.size() << std::endl;
	(s1 + s2).print();
	(s1 + 'c').print();
	(s1 + "bans").print();
	std::cout << "bans" + s1 << std::endl;
	String s3 = "hahfdhg";
	std::cout << "s3 : " << s3 << std::endl;
	char *ch = s1;
	std::cout << "char * ch = " << ch << std::endl;
	int cap;
	std::cout << "enter number of chars : " << std::endl;
	std::cin >> cap;
	String s5(cap + 1);
	std::cout << "enter your string : " << std::endl;
	std::cin >> s5;
	std::cout << "your string is : " << s5 << std::endl;
	String s6("a");
	std::cout << "s6 = " << s6 << std::endl;
	s6.append('b');
	s6.append("dfnd");
	s6.append(s1);
	s6[3] = 'q';
	std::cout << "new string s6 : " << s6 << std::endl;
	String s7("abcdf");
	std::cout << "string s7 : " << s7 << std::endl;
	std::cout << "substring from 1 to 3 of s7 : " <<  s7.substring(1, 3) << std::endl;
	String s8 = "jjj";
	std::cout << "string s8 = " << s8 << std::endl;
	s8 = 'a';
	std::cout << "new s8 : " << s8 << std::endl;
	s8 = "202.4jjj";
	std::cout << "new string s8 : " << s8 << std::endl;
	std::cout << "int string s8 + 2 : " << int(s8) + 2 << std::endl;
	std::cout << "double string s8 + 2.5 : " << double(s8) + 2.5 << std::endl;
	system("pause"); 
	return 0;
}