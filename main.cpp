#include "DynamicArray.h"
#include <iostream>

//Function to create and return a DynamicArray (used to test move constructor)
DynamicArray<int> makeArray() {
    DynamicArray<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    return temp;
}

int main() {
    std::cout << "Creating arr1:\n";
    DynamicArray<int> arr1 = makeArray();

    std::cout << "arr1 contents: ";
    for (int value : arr1) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "\nCopying arr1 into arr2:";
    DynamicArray<int> arr2 = arr1;
    std::cout << "\narr2 contents (copied): ";
    for (int value : arr2) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "\nMoving arr1 into arr3:\n";
    DynamicArray<int> arr3;
    arr3 = std::move(arr1);

    std::cout << "arr3 contents: ";
    for (int value : arr3) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "arr1 size after move = " << arr1.getSize() << "\n";

    std::cout << "\nTesting push_back and pop_back:\n";
    arr3.push_back(4);
    arr3.push_back(5);

    std::cout << "After pushing 4 and 5: ";
    for (int value : arr3) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    arr3.pop_back();

    std::cout << "After one pop_back(): ";
    for (int value : arr3) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    std::cout << "Size: " << arr3.getSize()
        << "  Capacity: " << arr3.getCapacity() << "\n";

    return 0;
}
