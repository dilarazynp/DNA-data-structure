#ifndef GENNODE_HPP
#define GENNODE_HPP

#include <string>
#include <iostream>

using namespace std;

class GenNode {
public:
    char data;         
    GenNode* next;     
    GenNode* prev;    

    GenNode(const char&,GenNode*,GenNode*);
};

#endif 
