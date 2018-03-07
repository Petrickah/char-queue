#include "headers/charQueue.hpp"

namespace NodeClass {
    Node::Node(char myChar) { this->myChar = myChar; nextNode = nullptr; }
    Node::Node() { this->myChar = '\0'; nextNode = nullptr; }
    Node::~Node() { 
        while(nextNode != nullptr) {
            delete this->nextNode;
            this->nextNode = this->nextNode->nextNode;
        }
    }
    Node* Node::getNextNode() { return this->nextNode; }
    void Node::setNextNode(Node* myNextNode) { this->nextNode = myNextNode; }
    char Node::getChar() { return this->myChar; }
    void Node::setChar(char myNewChar) { this->myChar = myNewChar; }
}

namespace CharQueueClass {
    CharQueue::CharQueue() { this->firstNode = nullptr; this->lastNode = nullptr; }
    CharQueue::~CharQueue() {
        while(firstNode != lastNode) {
            NodeClass::Node *p = firstNode->getNextNode();
            delete firstNode;
            firstNode = p;
        }
        delete lastNode;
    }
    bool CharQueue::isEmpty() {
        return (this->firstNode == this->lastNode && this->firstNode == nullptr);
    }
    void CharQueue::push(char myChar) {
        if(isEmpty())
            firstNode = lastNode = new NodeClass::Node(myChar);
        else {
            lastNode->setNextNode(new NodeClass::Node(myChar));
            this->lastNode = lastNode->getNextNode();
        }
    }
    char CharQueue::pop() {
        char myChar = '\0';
        if(firstNode != nullptr) {
            NodeClass::Node* p = firstNode->getNextNode();
            myChar = firstNode->getChar();
            delete firstNode;
            firstNode = p;
        }
        return myChar;
    }

    std::ostream& operator<<(std::ostream& out, CharQueue myQueue) {
        while(!myQueue.isEmpty()){
            out<<myQueue.pop();
        }
    }
    std::istream& operator>>(std::istream& in, CharQueue& myQueue) {
        char str[250];
        in.getline(str, 250);
        for(char myChar: str) {
            myQueue.push(myChar);
        }
        return in;
    }
}