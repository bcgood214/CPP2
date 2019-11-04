#pragma once
#include <string>

using std::string;
class Movie
{
private:
	string name;
	string rating;
public:
	Movie(string n, string r);
	Movie();
	string getName();
	string getRating();
	void setName(string name);
	void setRating(string rating);
};

