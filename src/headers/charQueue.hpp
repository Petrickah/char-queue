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
            int size;
        public:
            CharQueue(CharQueue& obj); //Constructor de copiere
            CharQueue(); ~CharQueue(); //Constructor de initializare + destructor 
            bool isEmpty(); //Metoda de verificare daca coada este vida
            void push(char myChar); //Metoda de insertie a unui element nou in coada
            char pop(); //Metoda de extragere si stergere a unui element din coada
            friend std::ostream& operator<<(std::ostream&, CharQueue&); //Functie de citire a unei cozi
            friend std::istream& operator>>(std::istream&, CharQueue&); //Functie de afisare a unei cozi
            CharQueue& operator+(CharQueue myQueue); //Metoda a concatenare a doua cozi
            CharQueue& operator-(CharQueue myQueue); //Metoda de diferentiere a doua cozi
        };
    }
}

#endif // POO_TEMA1_CHARQUEUE_H_