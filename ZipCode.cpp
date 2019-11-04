#include "ZipCode.h"
#include <string>

using std::string;
using std::to_string;

ZipCode::ZipCode(int code) {
	this->code = to_string(code);
}

ZipCode::ZipCode(string code) {
	code = code.substr(1, code.length() - 2);
	this->code = crunchCode(code);
}

string ZipCode::crunchCode(string code) {
	string segments[5];
	segments[0] = code.substr(0, 4);
	segments[1] = code.substr(5, 9);
	segments[2] = code.substr(10, 14);
	segments[3] = code.substr(15, 19);
	segments[4] = code.substr(20, 24);

	int s1 = getSum(segments[0]);
	int s2 = getSum(segments[1]);
	int s3 = getSum(segments[2]);
	int s4 = getSum(segments[3]);
	int s5 = getSum(segments[4]);

	return to_string(s1) + to_string(s2) + to_string(s3) + to_string(s4) + to_string(s5);

}

string ZipCode::getNumber() {
	return code;
}

string ZipCode::getString() {
	string s = "1";
	for (char c : code) {
		switch (c) {
		case '9':
			s += "10100";
			break;
		case '7':
			s += "10000";
			break;
		case '5':
			s += "01010";
			break;
		case '4':
			s += "01001";
			break;
		case '3':
			s += "00110";
			break;
		case '2':
			s += "00101";
			break;
		case '1':
			s += "00011";
			break;
		case '6':
			s += "01100";
			break;
		case '0':
			s += "11000";
			break;
		case '8':
			s += "10010";
			break;
		}
	}

	return s.append("1");
}

int ZipCode::getSum(string c) {
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;
	int i5 = 0;

	int index = 0;
	for (char ch : c) {
		if (ch == '1') {
			switch (index) {
			case 0:
				i1 = 7;
				break;
			case 1:
				i2 = 4;
				break;
			case 2:
				i3 = 2;
				break;
			case 3:
				i4 = 1;
				break;
			case 4:
				i5 = 0;
				
			}
		}
		index++;
	}

	int sum =  i1 + i2 + i3 + i4 + i5;
	if (sum == 11)
		return 0;
	else
		return sum;
}