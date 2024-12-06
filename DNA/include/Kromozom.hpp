#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP

#include "GenNode.hpp"
#include <iostream>
using namespace std;

class Kromozom {
private:
    GenNode* head;  
    GenNode* tail;  
    int size;      

    GenNode* FindPreviousByPosition(int index);

public:
  
    Kromozom();
    ~Kromozom();

    void add(const char& item);          
    void insert(int index, const char& item); 
    void clear();                  
    int Count() const;                   
    bool isEmpty() const;                 
    const char& elementAt(int index);   
    const char& lastChar();           
    friend ostream& operator<<(ostream& screen, Kromozom& rgt);  
    GenNode* getHead() const;

    void mutasyon(int genIndex);
};

#endif
