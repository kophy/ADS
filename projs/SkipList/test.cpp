#include <iostream>
#include <cstdlib>
#include <ctime>

#include "SkipList.h"

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	
	SkipList *s = new SkipList(4);
    
	// For the data field of nodes.
	int *data = new int[16];
	for(int i = 0; i < 16; ++i)
		data[i] = i;

	// Test inserting.
	cout << "Inserting 0 ~ 15." << endl;
	for(int i = 0; i < 16; ++i)
		s->insertNode(i, new int(i));
	s->displayList();
	cout << endl;

	// Test deleting.
	cout << "Deleting 3 and 7." << endl;
	s->deleteNode(3);
	s->deleteNode(7);
	s->displayList();
	cout << endl;

	// Test Searching.
	cout << "Searching 5 and 9." << endl;
	cout << "key = 5, val = " << *static_cast<int *>(s->getData(5)) << endl;
	cout << "key = 9, val = " << *static_cast<int *>(s->getData(9)) << endl;

	//cout << *static_cast<int *>(s->getData(3)) << endl;
	delete s;
	delete data;
	return 0;
}

