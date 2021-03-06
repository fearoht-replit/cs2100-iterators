#ifndef FORWARD_LIST_NODE_H
#define FORWARD_LIST_NODE_H

#include "Node.h"

template <typename T>
class ForwardListNode : public Node<T> {
    public:
    typedef typename Node<T>::value_t value_t;

    public:
        ForwardListNode<T>* next;

    public:
        ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
        }

        ~ForwardListNode(void){
        }

        template <typename _T>
        inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
            _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
            return _out;
        }
};

#endif