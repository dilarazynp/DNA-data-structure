#include "KromozomList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


KromozomList::KromozomList() : head(nullptr), size(0) {}


KromozomList::~KromozomList() {
    clear();
}


 KromozomListNode* KromozomList:: FindPrevByPosition(int position) {
        if (position < 0 || position > size) throw "Index out of range";
        int index = 1;
        for (KromozomListNode* itr = head; itr != NULL; itr = itr->next, index++) {
            if (position == index) return itr;	
        }
        return NULL;
    }

void KromozomList::add(Kromozom* item){
		insert(size,item);
	}

void KromozomList::insert(int index,Kromozom* item){
		if(index==0) head = new KromozomListNode(item,head);
		else{
			KromozomListNode* prev = FindPrevByPosition(index);
			prev->next = new KromozomListNode(item,prev->next);
		}
		size++;			
}


void KromozomList::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw "Index out of range";
    }

    KromozomListNode* del;
    if (index == 0) {
        del = head;
        head = head->next; 
    } else {
        KromozomListNode* prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next; 
        }
        del = prev->next;
        prev->next = del->next; 
    }

    size--;
    delete del; 
}


const Kromozom& KromozomList::get(int index) const {
    if (index < 0 || index >= size) {
        throw "Index out of range"; 
    }

    KromozomListNode* itr = head;
    for (int i = 0; i < index; i++) {
        itr = itr->next; 
    }
    return *(itr->data);
}


int KromozomList::Count() const {
    return size;
}


bool KromozomList::isEmpty() const {
    return size == 0;
}


void KromozomList::clear() {
    while (!isEmpty()) {
        removeAt(0);
    }
}

// Listeyi yazdırır.
ostream& operator<<(ostream& screen, const KromozomList& liste) {
    KromozomListNode* itr = liste.head;
    while (itr != nullptr) {
        screen << *(itr->data) << endl; 
        itr = itr->next;
    }
    return screen;
}

Kromozom* KromozomList::elementAt(int index) {
    if (index < 0 || index >= size) throw "Index out of range";
    KromozomListNode* itr = head;
    for (int i = 0; i < index; i++) {
        itr = itr->next;
    }
    return itr->data;
	};


void KromozomList::mutasyon(int kromozomIndex, int genIndex) {
    if (kromozomIndex < 0 || kromozomIndex >= size) {
        throw "gecersiz index";
    }

    Kromozom* kromozom = elementAt(kromozomIndex); 

    if (genIndex < 0 || genIndex >= kromozom->Count()) {
        throw "gecersiz index";
    }

    kromozom->mutasyon(genIndex);  
}

void KromozomList::otoIslemler(const char* fileName) {
    ifstream file(fileName);  
    if (!file.is_open()) {
        cout << "Islemler.txt dosyasi acilamadi" << endl;
        return;
    }

    string line;  
    while (getline(file, line)) {  
        istringstream ss(line);  
        char operation;
        ss >> operation;  

        if (operation == 'M' || operation == 'm') {
    int kromozomIndex, genIndex;
    ss >> kromozomIndex >> genIndex;

    if (kromozomIndex >= 0 && kromozomIndex < size) {  
        Kromozom* kromozom = elementAt(kromozomIndex);
        if (genIndex >= 0 && genIndex < kromozom->Count()) { 
            try {
                kromozom->mutasyon(genIndex); 
                cout << "Mutasyon basarili: Kromozom " << kromozomIndex << ", Gen " << genIndex << endl;
            } catch (const char* e) {
                cout << "Error: " << e << endl;
            }
        } else {
            cout << "Error: Chromosome " << kromozomIndex << " exists, but Gene " << genIndex << " does not." << endl;
        }
    } else {
        cout << "Error: Gene " << genIndex << " exists, but Chromosome " << kromozomIndex << " does not." << endl;
    }
}
        else if (operation == 'C' || operation == 'c') {
            int kromozomIndex1, kromozomIndex2;
            ss >> kromozomIndex1 >> kromozomIndex2;

            if (kromozomIndex1 >= 0 && kromozomIndex1 < size && kromozomIndex2 >= 0 && kromozomIndex2 < size) {
                try {
                    caprazla(kromozomIndex1, kromozomIndex2);  
                    cout << "caprazlama basarili: kromozom " << kromozomIndex1 << " ve kromozom " << kromozomIndex2 << endl;
                } catch (const char* e) {
                    cout << "Error: " << e << endl;
                }
            } else {
                cout << "Error: Invalid chromosome indices." << endl;
            }
        }

    }

    file.close();  
}

void KromozomList::caprazla(int index1, int index2) {
    
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size || index1 == index2) {
        throw "gecersiz index";
    }

    
    Kromozom* k1 = elementAt(index1);
    Kromozom* k2 = elementAt(index2);

    int size1 = k1->Count();
    int size2 = k2->Count();

    
    int halfSize1 = size1 / 2;
    int halfSize2 = size2 / 2;

    if (size1 % 2 != 0) {
        halfSize1 = (size1 - 1) / 2; 
    }
    if (size2 % 2 != 0) {
        halfSize2 = (size2 - 1) / 2;  
    }

    
    Kromozom* newK1 = new Kromozom();
    for (int i = 0; i < halfSize1; i++) {
        newK1->add(k1->elementAt(i));  
    }
    for (int i = (size2 % 2 == 0 ? halfSize2 : halfSize2 + 1); i < size2; i++) {
        newK1->add(k2->elementAt(i));  
    }

    
    Kromozom* newK2 = new Kromozom();
    for (int i = (size1 % 2 == 0 ? halfSize1 : halfSize1 + 1); i < size1; i++) {
        newK2->add(k1->elementAt(i));  
    }
    for (int i = 0; i < halfSize2; i++) {
        newK2->add(k2->elementAt(i));  
    }

    
    add(newK1);
    add(newK2);
}



void KromozomList::yazdirEnKucukGen() {
  
    for (int i = 0; i < size; i++) {
        Kromozom* kromozom = elementAt(i);

        
        char firstGen = kromozom->elementAt(0);

        
        char enKucukGen = firstGen; 

        for (int j = kromozom->Count() - 1; j >= 0; j--) {
            char gen = kromozom->elementAt(j);

            
            if (gen < firstGen) {
                enKucukGen = gen;
                break; 
            }
        }

        
        cout << enKucukGen<< " ";
    }
}


