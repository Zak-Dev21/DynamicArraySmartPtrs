#ifndef Header_h
#define Header_h

using namespace std;
#include <iostream>;

void DynamicArraySumSmartPtr() {
    int capacity = 5;
    int entries = 0;
    auto numbers = unique_ptr<int[]>(new int[capacity]);

    while (true) {

        cout << "Enter numbers: ";
        cin >> numbers[entries];


        if (cin.fail()) break;

        if (entries >= capacity) {

            capacity *= 2;
            auto temp = unique_ptr<int[]>(new int[capacity]);

            for (int i = 0; i < entries; i++) {
                temp[i] = numbers[i]; // copying data from numbers array to new temp array
            }

            numbers = move(temp); // transfer ownership to original unique ptr
        }

        entries++;
    }

    int sum = 0;

    for (int i = 0; i < entries; i++) {
        sum += numbers[i];
    }

    cout << "Sum of numbers given is: " << sum << endl;


}
#endif // !Header_h

