#include <iostream>
#include "vector.h"
#include <list>

int main() {

    Vector<int> a(50);
    std::cout << '\n' << "New vector" << '\n';
    for (int i = 0; i < a.Size(); ++i) {
        a[i] = (i % 3) * (i % 16);
    }
    for (int i = 0; i < a.Size(); ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n' << "Sorted vector" << '\n';
    Sort<int>(a.Begin(), a.End());
    for (int i = 0; i < a.Size(); ++i) {
        std::cout << a[i] << ' ';
    }

    std::cout << '\n' << "New list" << '\n';
    std::list<int> l;

    for (int i = 0; i < 10'000'000; ++i) {
        l.push_front((i % 3) * (i % 16));
    }
    std::cout << *(--l.end()); // last element % 3 = 0

    std::cout << '\n' << "Sorted list" << '\n';
    Sort<int>(l.begin(), l.end());
    std::cout << *(--l.end()); //Period of sequence is 15*3 = 48, so you can see main period subsequence at vector
    return 0;
}
