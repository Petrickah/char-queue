#ifndef POO_TEMA1_CHARQUEUE_H_
#define POO_TEMA1_CHARQUEUE_H_

#include <iostream>

namespace NodeClass {
    class Node {
        char myChar; Node* nextNode;
    public:
        Node(char myChar); Node(); ~Node(); //Constructori + Destructori
        //Metode
        Node* getNextNode();
        void setNextNode(Node* myNextNode);
        char getChar();
        void setChar(char myNewChar);
    };
}

namespace CharQueueClass {
    class CharQueue {
        NodeClass::Node* firstNode, *lastNode;
    public:
        CharQueue(); ~CharQueue(); //Constructor + Destructor
        //Metode
        void push(char myChar);
        char pop();
        bool isEmpty();
        friend std::ostream& operator<<(std::ostream& out, CharQueue myQueue);
        friend std::istream& operator>>(std::istream& in, CharQueue& myQueue);
        CharQueue& operator+(CharQueue myQueue);
        CharQueue& operator-(CharQueue myQueue);
    };
}

#endif // POO_TEMA1_CHARQUEUE_H_