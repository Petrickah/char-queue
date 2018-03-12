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
            this->firstNode = this->lastNode = nullptr;
        }
        CharQueue::CharQueue(CharQueue& obj) {
            if(obj.isEmpty()) return;
            this->firstNode = this->lastNode = new NodeClass::Node(obj.firstNode->getInfo());
            NodeClass::Node* p = obj.firstNode;
            while(p->getNextNode() != NULL) {
                this->lastNode->setNextNode(new NodeClass::Node(p->getNextNode()->getInfo()));
                p = p->getNextNode(); this->lastNode = this->lastNode->getNextNode();
            }
        }
        CharQueue::~CharQueue() {
            while(this->firstNode != this->lastNode){
                NodeClass::Node* p = this->firstNode->getNextNode();
                this->firstNode = p;
                delete p;
            }
        }
        bool CharQueue::isEmpty() {
            return (this->firstNode == nullptr && this->firstNode == this->lastNode);
        }
        void CharQueue::push(char myChar) {
            if(isEmpty()){
                this->firstNode = new NodeClass::Node(myChar);
                this->lastNode = this->firstNode;
            }
            else{
                this->lastNode->setNextNode(new NodeClass::Node(myChar));
                this->lastNode = this->lastNode->getNextNode();
            }
        }
        char CharQueue::pop() {
            NodeClass::Node *p = this->firstNode;
            char info = p->getInfo();
            delete p;
            if(this->firstNode == this->lastNode) {
                this->firstNode = this->lastNode = nullptr;
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
            CharQueue *myNewCharQueue = new CharQueue(myQueue);
            this->lastNode->setNextNode(myNewCharQueue->firstNode);
            this->lastNode = myNewCharQueue->lastNode;
            return *this;
        }
    }
}