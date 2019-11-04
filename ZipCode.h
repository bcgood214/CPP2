#pragma once
#include <string>
class ZipCode
{
private:
	std::string code;
	std::string crunchCode(std::string code);
	int getSum(std::string c);
public:
	ZipCode(int zip);
	ZipCode(std::string code);
	std::string getNumber();
	std::string getString();
};

