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
    }
}