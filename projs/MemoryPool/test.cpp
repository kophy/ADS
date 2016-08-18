#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "MemoryPool.h"

class A {
    public:
        A() {
            d = rand();
            cout << "++A(" << d << ") is created." << endl;
        }
        ~A() {
            cout << "--A(" << d << ") is destroyed." << endl;
        }
    private:
        int d;
};

int main() {
    MemoryPool<A, 32> m;
    cout << endl;

    for (int i = 0; i < 5; ++i) {
        cout << "***** " << i << " *****" << endl << endl;
        A *temp = m.allocate();
        cout << "return pointer = " << static_cast<const void *>(temp) << endl;
        m.deallocate(temp);
        cout << endl;
    }

    return 0;
}
