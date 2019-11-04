#include "Movie.h"
#include <string>

using namespace std;

Movie::Movie(string n, string r) : name(n), rating(r) {

}

Movie::Movie() {
	name = "Untitled";
	rating = "None";
}

string Movie::getName() {
	return name;
}

string Movie::getRating() {
	return rating;
}

void Movie::setName(string s) {
	name = s;
}

void Movie::setRating(string s) {
	rating = s;
}