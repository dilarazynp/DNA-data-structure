#ifndef KROMOZOMLIST_HPP
#define KROMOZOMLIST_HPP

#include "KromozomListNode.hpp"
#include <iostream>
using namespace std;

class KromozomList {
private:
    KromozomListNode* head;      
    int size;              

public:
    KromozomList();
    ~KromozomList();
    KromozomListNode* FindPrevByPosition(int position);
    void add(Kromozom* item);
	void insert(int index,Kromozom* item);
    void removeAt(int index);
    const Kromozom& get(int index) const;
    int Count() const;
    bool isEmpty() const;
    void clear();
    Kromozom* elementAt(int index);

    void mutasyon(int kromozomIndex, int genIndex); 
    void otoIslemler(const char* fileName);
    void caprazla(int index1, int index2) ;
    void yazdirEnKucukGen();


    friend ostream& operator<<(ostream& screen, const KromozomList& liste);
};

#endif 
