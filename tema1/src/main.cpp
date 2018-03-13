#include "headers/charQueue.hpp"

int main(int argc, char* argv[]) {
    Classes::CharQueueClass::CharQueue myFirstQueue, mySecondQueue;
    /*myQueue.push('E'); myQueue.push('x'); myQueue.push('a');
    myQueue.push('m'); myQueue.push('e'); myQueue.push('n');*/
    std::cout<<"Introduceti elementele primei cozi: "; std::cin>>myFirstQueue;
    std::cout<<"Introduceti elementele celei de a doua coada: "; std::cin>>mySecondQueue;
    //std::cout<<(myQueue.isEmpty()?"Coada este goala":"Coada contine cel putin un element")<<std::endl;
    myFirstQueue = myFirstQueue + mySecondQueue;
    std::cout<<"Noua coada dupa concatenare este: "<<myFirstQueue<<std::endl;
    //std::cout<<(myQueue.isEmpty()?"Coada este goala":"Coada contine cel putin un element")<<std::endl;
    return 0;
}