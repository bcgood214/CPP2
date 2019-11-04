// DecryptionCS211.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void decrypt(char *c, int key) {
	char newChars[4];
	char temp[4];
	char* message;
	int* num;
	int index = 0;
	for (int n = 0; n < 4; n++) {
		for (int i = 0; i < 4; i++, c++) {
			temp[i] = *c;
		}
		num = (int*)temp;
		*num -= key;
		message = (char*)num;

		for (int j = 0; j < 4; j++) {
			cout << message[j];
		}
		
	}

	cout << endl;

}

int main()
{
	char m[] = ",vtaNm a_\"dabp!!";
	for (int i = 1; i < 501; i++) {
		cout << "The key is " << i << ":" << endl;
		decrypt(m, i);
	// 'Attack at dawn!!' is at key 491.
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
