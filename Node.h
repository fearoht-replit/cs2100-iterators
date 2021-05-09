#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

template <typename T>
class Node {
    public: 
        typedef T value_t;

    public:
        T value;

    public:
        Node(const T& _value):value(_value){
        }

        ~Node(void){
        }

        T& operator*(void){
            return value;
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const Node<_T>& _node){
            _out << "Nodo: " <<  _node.value;
            return _out;
        }
};

#endif