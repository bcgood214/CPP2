#include <iostream>
#include <map>
#include "Prisoner.h"

using namespace std;

Prisoner* head = NULL;
Prisoner* cursor = NULL;
// int listCount = 0;
// map<int, int> idMap;

void insert(int id) {
	Prisoner* newPrisoner = new Prisoner(id);
	newPrisoner->setNext(head);
	head = newPrisoner;
	// listCount++;
	// idMap[listCount] = id;
}

Prisoner* get(int id, int limit) {
	Prisoner* index;
	index = head;
	for (int i = 0; i < limit; i++) {
		if (index->getId() == id)
			return index;
		index = index->getNext();
	}
	return nullptr;
}

void traverse(int limit, int prisonerCount) {
	Prisoner* index;
	Prisoner* temp = nullptr;
	int i = 0;
	int id;
	bool reversed = false;
	index = cursor;
	while (i < limit) {
		if (index->getNext() == nullptr) {
			index->setNext(head);
		}
		if (limit > 1) {
			if (i == limit - 1) {
				get(id, prisonerCount)->setNext(index->getNext());
				if (index == head) {
					head = head->getNext();
				}
				if (index->getNext() == nullptr) {
					cursor = head;
				}
				else {
					cursor = index->getNext();
				}
				delete index;
				break;
			}
		}
		else {
			if (prisonerCount > 1)
				index = index->getNext();
			cursor = index;
			head = index;
		}
		id = index->getId();
		index = index->getNext();
		i++;
	}
}



void findLastPrisoner(int wordCount, int prisoners) {
	cursor = head;
	for (int i = 0; i < prisoners - 1; i++) {
		traverse(wordCount, prisoners - i);
		/*if (head == nullptr) {
			head = get(idMap.begin()->second, listCount);
		}*/
	}
	cout << endl << "With " << prisoners << " prisoners and " << wordCount << 
		" words, I'd like to be number "<< head->getId() << "."<< endl;
}

void addToList(int count) {
	for (int i = 0; i < count; i++) {
		insert(count - i);
	}
}

int main() {
	int words;
	int prisoners;
	cout << "Number of words: ";
	cin >> words;
	cout << "There are " << words << " words." << endl;
	cout << "Number of prisoners: ";
	cin >> prisoners;
	addToList(prisoners);
	findLastPrisoner(words, prisoners);
}