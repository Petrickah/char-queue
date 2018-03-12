#include "headers/charQueue.hpp"

namespace Classes {
    namespace NodeClass {
        Node::Node() {
            this->nextNode = nullptr; this->info = '\0';
        }
        Node::Node(char myInfo) {
            this->nextNode = nullptr; this->info = myInfo;
        }
        Node::Node(char myInfo, Node* nextNode) {
            this->nextNode = nextNode; this->info = myInfo;
        }
        Node::~Node() {
            delete this->nextNode;
        }
    }

    namespace CharQueueClass {
        CharQueue::CharQueue() {
            this->firstNode = this->lastNode = nullptr;
        }
        CharQueue::~CharQueue() {
            while(this->firstNode != this->lastNode){
                NodeClass::Node* p = this->firstNode->getNextNode();
                this->firstNode = p;
                delete p;
            }
        }
    }
}