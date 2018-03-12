#include "headers/charQueue.hpp"

int main(int argc, char* argv[]) {
    std::cout<<"Hello, world!"<<std::endl;
    Classes::CharQueueClass::CharQueue myQueue;
    myQueue.push('E'); myQueue.push('x'); myQueue.push('a');
    myQueue.push('m'); myQueue.push('e'); myQueue.push('n');
    std::cout<<(myQueue.isEmpty()?"Coada este goala":"Coada contine cel putin un element")<<std::endl;
    while(!myQueue.isEmpty())
        std::cout<<myQueue.pop();

    std::cout<<std::endl;
    std::cout<<(myQueue.isEmpty()?"Coada este goala":"Coada contine cel putin un element")<<std::endl;
    return 0;
}