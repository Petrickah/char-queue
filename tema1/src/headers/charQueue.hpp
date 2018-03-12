#ifndef POO_TEMA1_CHARQUEUE_H_
#define POO_TEMA1_CHARQUEUE_H_

#include <iostream>

namespace Classes {
    namespace NodeClass {
        class Node {
            char info; Node* nextNode;
        public:
            Node(); Node(char myInfo); Node(char myInfo, Node* nextNode); ~Node();
            Node* getNextNode() { return nextNode; }
            void setNextNode(Node* newNextNode) { nextNode = newNextNode; }
            char getInfo() { return info; }
            void setInfo(char myChar) { info = myChar; }
        };
    }

    namespace CharQueueClass {
        class CharQueue {
            NodeClass::Node* firstNode;
            NodeClass::Node* lastNode;
        public:
            CharQueue(CharQueue& obj); 
            CharQueue(); ~CharQueue();
            bool isEmpty();
            void push(char myChar);
            char pop();
            friend std::ostream& operator<<(std::ostream&, CharQueue&);
            friend std::istream& operator>>(std::istream&, CharQueue&);
            CharQueue& operator+(CharQueue myQueue);
        };
    }
}

#endif // POO_TEMA1_CHARQUEUE_H_