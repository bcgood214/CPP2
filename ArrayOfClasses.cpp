#include <iostream>
#include "Movie.h"

using namespace std;

Movie* sort(Movie* mo, int size) {
	int n1;
	int n2;

	for (int i = 0; i < size; i++) {
		int l = size - i - 1;
		for (int n = 0; n < l; n++, mo++) {
			Movie m1 = *mo;
			Movie m2 = *(mo + 1);
			n1 = m1.getName().at(0);
			n2 = m2.getName().at(0);

			if (n1 > n2) {
				swap(*mo, *(mo + 1));
			}
		}
		mo -= l;
	}

	return mo;
}

int main() {
	Movie movies[6];

	movies[0].setName("Black Panther");
	movies[0].setRating("PG-13");
	movies[1].setName("Avengers: Infinity War");
	movies[1].setRating("PG-13");
	movies[2].setName("A Wrinkle In Time");
	movies[2].setRating("PG");
	movies[3].setName("Ready Player One");
	movies[3].setRating("PG-13");
	movies[4].setName("Red Sparrow");
	movies[4].setRating("R");
	movies[5].setName("The Incredibles");
	movies[5].setRating("G");

	Movie *sortedMovies = sort(movies, 6);

	for (int i = 0; i < 6; i++, sortedMovies++) {
		cout << sortedMovies->getName() << endl;
		cout << sortedMovies->getRating() << endl;
	}
}