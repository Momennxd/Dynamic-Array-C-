#include <iostream>
#include <vector>
#include <numeric>
#include <array>
#include <iterator>
#include "DynamicArray.h"
using namespace std;





int main() {

    
    DynamicArray arr;

    arr.push(1);
    arr.push(21);
    arr.push(21);
    arr.push(21);
    arr.deleteAt(0);


    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
