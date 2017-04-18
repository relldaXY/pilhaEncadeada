//!  Copyright [2017] <Copyright relldaXY>"
#include "linkedList.h"
#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! Class Linked stack
/*!
 *  this is a stack linked by reference. It has functions like push, pop, insert 
 *  and some like that. 
*/
class LinkedStack {
 public:
    LinkedStack() {
        top_ = NULL;
        size_ = -1;
    }

    ~LinkedStack() {
        clear();
    }
    //! method clear
    /*!
        While the stack is empty is false the elements go out from list
    */
    void clear() {
        while (!empty()) {
            pop();
        }
        size_ = -1;
    }
    //! method push
    /*!
        push data to top of stack
    */
    void push(const T& data) {
        Node* newNode = new Node(data, NULL);
        if (newNode == NULL) {
            throw std::out_of_range("Full list");
        } else {
            if (empty()) {
                top_ = newNode;
                size_++;
            } else {
                newNode -> next(top_);
                top_ = newNode;
                size_++;
            }
        }
    }
     //! method pop
    /*!
        pop data from top of stack
    */
    T pop() {
        if (empty()) {
            throw std::out_of_range("Empty List");
        } else {
            Node* quitNode;
            T data;
            data = top_->data();
            quitNode = top_;
            top_ = quitNode->next();
            delete quitNode;
            size_--;
            return data;
        }
    }
    //! method top
    /*!
        find out the data from top of stack
    */
    T& top() const {
        if (empty()) {
            throw std::out_of_range("Empty List");
        } else {
            return top_->data();
        }
    }
     //! method empty
    /*!
        to know if the stack is empty or not
    */
    bool empty() const {
        return size_ == -1;
    }
     //! method size
    /*!
        to know the size of stack 
    */
    std::size_t size() const {
        return (size_ + 1);
    }

 private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {   // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* top_{nullptr};  // nodo-topo
    std::size_t size_{0u};  // tamanho
};

}  // namespace structures

