#include <iostream>
using namespace std;

#include "ForwardList.h"

typedef ForwardList<int> list_t;
typedef list_t::ForwardIterator iterator_t;

int main (int, char *[]){
    list_t list;
    cout << "empty: " << list.empty() << endl;
    list << 10 << 12 << 3;
    cout << list << endl;
    cout << "back: " << list.back() << endl;
    cout << "popF: " <<  *list.pop_front() << endl;
    cout << "popB: " << *list.pop_back() << endl;
    list >> 5 << 20 >> 30 << 100;
    cout << list << endl;
    cout << "front: " << list.front() << endl;
    cout << "back: " << list.back() << endl;
    cout << "rand: " << list[1] << endl;
    cout << "empty: " << list.empty() << endl;
    cout << "size: " << list.size() << endl;

    iterator_t it = list.begin();
    cout << *it << endl;
    iterator_t et = list.end();
    cout << *et << endl;
    return 1;
}