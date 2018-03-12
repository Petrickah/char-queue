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
            CharQueue(); ~CharQueue();
            bool isEmpty();
            void push(char myChar);
            char pop();
        };
    }
}

#endif // POO_TEMA1_CHARQUEUE_H_