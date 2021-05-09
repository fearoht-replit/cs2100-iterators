#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include "List.h"
#include "ForwardListNode.h"
#include "Iterator.h"


template <typename T>
class ForwardList : public List<T>{
public:
    typedef ForwardListNode<T> node_t;
    
    friend class ForwardIterator;
    class ForwardIterator: public Iterator<node_t> {
        public:
            typedef typename Iterator<node_t>::node_t node_t;
            typedef typename Iterator<node_t>::value_t value_t;

        public: 
            ForwardIterator (node_t* pointer = nullptr)
            :Iterator<node_t>(pointer){
            }

            ~ForwardIterator (void){
            }

            ForwardIterator& operator++ (void){
                Iterator<node_t>::pointer = Iterator<node_t>::pointer->next; 
                return *this;
            }

    };


    protected:
        ForwardListNode<T> *head;
        ForwardListNode<T> *tail;

    public:
        ForwardList(void)
        :List<T>(), head(nullptr), tail(nullptr){
        }

        ~ForwardList (void){
        }

        ForwardIterator begin(){
            return ForwardIterator(head);
        }

        ForwardIterator end(){
            return ForwardIterator(tail);
        }

        void push_back(const T& element){
            ForwardListNode<T> *new_node = new ForwardListNode<T>(element);
            if (!head){
                tail = head = new_node;
            } else {
                tail->next = new_node;
                tail = tail->next;
            }
        }

        void push_front(const T& element){
            ForwardListNode<T> *new_node = new ForwardListNode<T>(element);
            if (!head){
                tail = head = new_node;
            } else {
                ForwardListNode<T> * tmp = head;
                head = new_node;
                head->next = tmp;
            }
        }

        T& front(void){
            return head->value;
        }; 

        T& back(void){
            return tail->value;
        }; 

        Node<T>* pop_back(void){
            Node<T>* tmpRes = new Node<T>(tail->value);
            ForwardListNode<T> * tmpPointer = head;
            while(tmpPointer->next!=tail){
                 tmpPointer = tmpPointer->next;
            }
            tail = tmpPointer;
            delete tail->next;
            tail->next = nullptr;
            return  tmpRes;
        };

        Node<T>* pop_front(void){
            Node<T>* tmpRes = new Node<T>(head->value);
            ForwardListNode<T> * tmpPointer = head;
            head = head->next;
            delete tmpPointer;
            return tmpRes;
        };  

        T& operator[] (const int& _position){
            ForwardListNode<T> * tmp = head;
            for (int i = 0; i < _position; i++, tmp = tmp->next);
            return tmp->value;
        }

        bool empty(void){
            return head == nullptr;
        }

        unsigned int size(void){
            int i = 0;
            for (ForwardListNode<T> * tmp = head; tmp != nullptr; i++, tmp = tmp->next);
            return i;
        }

        template<typename _T>
        inline friend ostream& operator<< (ostream& out, ForwardList<_T>& _list){
            typename ForwardList<_T>::ForwardIterator it = _list.begin();
            for(; it != _list.end(); ++it){
                out << *it << " -> ";
            }
            out << *it << " -> ";
            /*            
            if (!_list.head) return out;
            ForwardListNode<T> *tmp = _list.head;
            while(tmp){
                out << *tmp << " -> ";
                tmp = tmp->next;
            }
            */
            return out;
        }
};

#endif