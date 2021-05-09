#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

#include "Node.h"

template <typename T>
class List {
    protected:
        Node<T>* head;

    public:
        List(const List&):head(nullptr){ 
        }
        
        List(T*):head(nullptr){ 
        }

        List(Node<T>*):head(nullptr){ 
        }

        List(int):head(nullptr){ 
        }

        List(void):head(nullptr){ 
        }

        ~List(void){
        }
        
        
        virtual void push_back(const T& element) = 0; 
        virtual void push_front(const T& element) = 0; 

        virtual T& front(void) = 0; 
        virtual T& back(void) = 0; 

        virtual Node<T>* pop_back(void) = 0;
        virtual Node<T>* pop_front(void) = 0;  

        virtual T& operator[] (const int&) = 0; 
        
        virtual bool empty(void){
            return head == nullptr;
        }; 

        virtual unsigned int size(void) = 0; 

        template<typename _T>
        inline friend ostream& operator<< (ostream& out, const List<_T>&){
            out << "Nothing to print in father" << endl;
            return out;
        }

        
        List& operator<< (const T& _value){
            this->push_back(_value);
            return *this;
        }

        List& operator>> (const T& _value){
            this->push_front(_value);
            return *this;
        }
};

#endif