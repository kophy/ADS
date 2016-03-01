#include <iostream>
#include <cstdlib>
#include <string>

#include "BloomFilter.h"

using namespace std;

int main() {
    BloomFilter *bf = new BloomFilter(128, 10);
    string data[] = {"Alice", "Bob", "Cathy", "Danny"};
    
    for(int i = 0; i < 4; ++i) {
    	cout << "Inserting element: " << data[i] << endl;
    	bf->insertElement(data[i]);
    }
	
    cout << "Cathy is in the set: " << bf->existsElement("Cathy") << endl;
    cout << "Eddie is in the set: " << bf->existsElement("Eddie") << endl;
	
    delete bf;
    return 0;
}
