#include "headers/charQueue.hpp"

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

CharQueue::CharQueue() { this->firstNode = nullptr; this->lastNode = nullptr; }
CharQueue::~CharQueue() {
    while(firstNode != lastNode) {
        Node *p = firstNode->getNextNode();
        delete firstNode;
        firstNode = p;
    }
    delete lastNode;
}