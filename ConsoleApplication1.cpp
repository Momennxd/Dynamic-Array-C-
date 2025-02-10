#include <iostream>
#include <vector>
#include <numeric>
#include <array>
#include <iterator>
#include "DynamicArray.h"
using namespace std;





int main() {

    
    DynamicArray arr = DynamicArray(3);

    arr.push(1);
    arr.push(2);

    DynamicArray da(move(arr));
    cout << da.capacity() << endl; cout << da.size() << endl;

    for (int i = 0; i < da.size(); i++) {
        cout << da[i] << endl;
    }

    return 0;
}
