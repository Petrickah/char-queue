#include "headers/charQueue.hpp"

int main(int argc, char* argv[]) {
    Classes::CharQueueClass::CharQueue myFirstQueue, mySecondQueue, myThirdQueue;
    Classes::CharQueueClass::CharQueue myFirstResult, mySecondResult;
    /*myQueue.push('E'); myQueue.push('x'); myQueue.push('a');
    myQueue.push('m'); myQueue.push('e'); myQueue.push('n');*/
    std::cout<<"Introduceti elementele primei cozi: "; std::cin>>myFirstQueue;
    std::cout<<"Introduceti elementele celei de a doua cozi: "; std::cin>>mySecondQueue;
    std::cout<<"Introduceti elementele celei de a treia cozi: "; std::cin>>myThirdQueue;
    //std::cout<<(myQueue.isEmpty()?"Coada este goala":"Coada contine cel putin un element")<<std::endl;
    
    myFirstResult = mySecondQueue + myThirdQueue;
    std::cout<<"Noua coada dupa concatenare este: "<<myFirstResult<<std::endl;
    
    mySecondResult = myFirstQueue - (mySecondQueue + myThirdQueue);
    std::cout<<"Noua coada dupa scadere este: "<<mySecondResult<<std::endl;

    std::cout<<"Elementele primei cozi: "<<myFirstQueue<<std::endl;
    std::cout<<"Elementele celei de doua cozi: "<<mySecondQueue<<std::endl;
    std::cout<<"Elementele celei de a treia cozi: "<<myThirdQueue<<std::endl;
    
    //std::cout<<(myQueue.isEmpty()?"Coada este goala":"Coada contine cel putin un element")<<std::endl;
    return 0;
}