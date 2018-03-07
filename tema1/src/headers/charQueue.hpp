#ifndef POO_TEMA1_CHARQUEUE_H_
#define POO_TEMA1_CHARQUEUE_H_

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

class CharQueue {
    Node* firstNode, *lastNode;
public:
    CharQueue(); ~CharQueue(); //Constructor + Destructor
    //Metode
};

#endif // POO_TEMA1_CHARQUEUE_H_