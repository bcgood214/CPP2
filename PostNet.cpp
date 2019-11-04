#include <iostream>
#include "ZipCode.h"

using namespace std;

int main() {
	string oc = "110100101000101011000010011";
	ZipCode zp(oc);
	cout << "Original code: " << oc << endl;
	cout << zp.getNumber() << endl;
	cout << zp.getString() << endl;
	if (oc != zp.getString())
		cout << "The bar codes are not equal!" << endl;

	cout << "Second zip code" << endl;
	ZipCode zp2(99506);
	cout << zp2.getNumber() << endl;
	cout << zp2.getString() << endl;

	ZipCode zp3(zp2.getString());
	cout << zp3.getNumber() << endl;
	cout << zp3.getString() << endl;
}