#ifndef KromozomListNode_HPP
#define KromozomListNode_HPP


#include <cstdlib>
#include <iostream>
#include "Kromozom.hpp"


using namespace std;

class KromozomListNode {
public:
    Kromozom* data;       
    KromozomListNode* next;      

    KromozomListNode(Kromozom*, KromozomListNode*);
};

#endif 
