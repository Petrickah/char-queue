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
            this->info = '\0';
        }
    }

    namespace CharQueueClass {
        CharQueue::CharQueue() {
            this->firstNode = this->lastNode = nullptr; this->size = 0;
        }
        CharQueue::CharQueue(CharQueue& obj) {
            if(obj.isEmpty()) return;
            this->firstNode = this->lastNode = new NodeClass::Node(obj.firstNode->getInfo());
            NodeClass::Node* p = obj.firstNode;
            while(p->getNextNode() != NULL) {
                this->lastNode->setNextNode(new NodeClass::Node(p->getNextNode()->getInfo()));
                p = p->getNextNode(); this->lastNode = this->lastNode->getNextNode();
            }
            this->size = obj.size;
        }
        CharQueue::~CharQueue() {
            while(this->firstNode != this->lastNode){
                NodeClass::Node* p = this->firstNode->getNextNode();
                this->firstNode = p;
                delete p;
            }
            this->size = 0;
        }
        bool CharQueue::isEmpty() {
            return (this->firstNode == nullptr && this->firstNode == this->lastNode);
        }
        void CharQueue::push(char myChar) {
            if(isEmpty()){
                this->firstNode = new NodeClass::Node(myChar);
                this->lastNode = this->firstNode;
                this->size = 1;
            }
            else{
                this->lastNode->setNextNode(new NodeClass::Node(myChar));
                this->lastNode = this->lastNode->getNextNode();
                this->size++;
            }
        }
        char CharQueue::pop() {
            NodeClass::Node *p = this->firstNode;
            char info = p->getInfo();
            delete p; this->size --;
            if(this->firstNode == this->lastNode) {
                this->firstNode = this->lastNode = nullptr; this->size = 0;
            }
            if(this->firstNode)
                this->firstNode = this->firstNode->getNextNode();
            return info;
        }
        std::ostream& operator<<(std::ostream& out, CharQueue& myQueue) {
            while(!myQueue.isEmpty())
                out<<myQueue.pop();
            return out;
        }
        std::istream& operator>>(std::istream& in, CharQueue& myQueue) {
            char str[250];
            in.getline(str, 250);
            int k=0;
            while(str[k] != '\0'){
                myQueue.push(str[k]);
                k++;
            }
            return in;
        }
        CharQueue& CharQueue::operator+(CharQueue myQueue) {
            CharQueue *myNewQueue = new CharQueue(myQueue);
            CharQueue *myThisQueue = new CharQueue(*this);
            myThisQueue->lastNode->setNextNode(myNewQueue->firstNode);
            myThisQueue->lastNode = myNewQueue->lastNode;
            myThisQueue->size = myThisQueue->size + myNewQueue->size;
            return *myThisQueue;
        }
        CharQueue& CharQueue::operator-(CharQueue myQueue) {
            CharQueue *myNewQueue = new CharQueue(myQueue);
            CharQueue *myThisQueue = new CharQueue(*this);

            auto minSizeQueue = (myNewQueue->size < myThisQueue->size)?myNewQueue:myThisQueue;
            auto otherQueue = (minSizeQueue != myNewQueue)?myNewQueue:minSizeQueue;

            CharQueue* resultQueue = new CharQueue();
            while(!minSizeQueue->isEmpty()) {
                char firstChar = minSizeQueue->pop(); char secondChar = otherQueue->pop();
                (firstChar > secondChar)?resultQueue->push(firstChar):resultQueue->push(secondChar);
            }
            return *resultQueue;
        }
    }
}