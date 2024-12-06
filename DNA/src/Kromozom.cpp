#include "Kromozom.hpp"

Kromozom::Kromozom() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

int Kromozom::Count() const {
    return size;
}

bool Kromozom::isEmpty() const {
    return size == 0;
}

GenNode* Kromozom::FindPreviousByPosition(int index) {
    if (index < 0 || index > size) throw ("No Such Element");
    GenNode* prv = head;
    int i = 1;
    for (GenNode* itr = head; itr->next != nullptr && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

void Kromozom::add(const char& item) {
    insert(size,item);
}

void Kromozom::insert(int index, const char& item) {
    if (index < 0 || index > size) throw "Index out of Range";
    if (index == 0) {
        head = new GenNode(item, head, nullptr);
        if (head->next != nullptr) head->next->prev = head;
    } else {
        GenNode* prv = FindPreviousByPosition(index);
        prv->next = new GenNode(item, prv->next, prv);
        if (prv->next->next != nullptr)
            prv->next->next->prev = prv->next;
    }
    size++;
}


char const& Kromozom::lastChar() {
    if (isEmpty()) throw "No Such Element";
    return FindPreviousByPosition(size)->data;
}



const char& Kromozom::elementAt(int index) {
    if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void Kromozom::clear() {
    GenNode* current = head;
    while (current != nullptr) {
        GenNode* next = current->next; 
        delete current;           
        current = next;            
    }

    head = nullptr; 
    tail = nullptr; 
    size = 0;       
}


ostream& operator<<(ostream& screen, Kromozom& rgt) {
    for (GenNode* itr = rgt.getHead(); itr != nullptr; itr = itr->next) {
        screen << itr->data << " ";
    }
    return screen;
}


Kromozom::~Kromozom() {
    GenNode* current = head;
    while (current != nullptr) {
        GenNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

GenNode* Kromozom::getHead() const {
        return head;  
    }


void Kromozom::mutasyon(int genIndex) {
    if (genIndex < 0 || genIndex >= size) {
        throw "Gen index out of range";  
    }

    GenNode* current = head;
    for (int i = 0; i < genIndex; i++) {
        current = current->next;
    }
    current->data = 'X';  
}