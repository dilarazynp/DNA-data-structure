#include "KromozomList.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

int main() {

    ifstream readFile;
    KromozomList* kromozomList = new KromozomList();
    readFile.open("Dna.txt");
    string line;
    Kromozom* kromozom;

    while (getline(readFile, line)) {  
        kromozom = new Kromozom();  
        stringstream ss(line);  
        char gen;

        while (ss >> gen) {  
            kromozom->add(gen);  
        }

        kromozomList->add(kromozom);  
    }
    readFile.close();

    int choice;
    do {
        cout << endl;
        cout << "1 - Caprazlama\n";
        cout << "2 - Mutasyon\n";
        cout << "3 - Otomatik Islemler\n";
        cout << "4 - Ekrana Yaz\n";
        cout << "5 - Cikis\n";
        cout << "Seciminizi yapiniz (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
               
                int index1, index2;
                cout << "Lutfen caprazlama yapilacak ilk kromozomun indexini giriniz: ";
                cin >> index1;
                cout << "Lutfen caprazlama yapilacak ikinci kromozomun indexini giriniz: ";
                cin >> index2;

               
                if (index1 < 0 || index1 >= kromozomList->Count() || index2 < 0 || index2 >= kromozomList->Count())
                 {
                    cout << "Hata: Gecersiz kromozom index!" << endl;
                    break;
                }

                
                try {
                    kromozomList->caprazla(index1, index2);
                    cout << "Caprazlama islemi tamamlandi." << endl;
                } catch (const char* error) {
                    cout << error << endl;
                }
                break;

            case 2:
                
                int kromozomIndex, genIndex;
                cout << "Mutasyon yapmak istediginiz kromozom indexini giriniz: ";
                cin >> kromozomIndex;
                cout << "Mutasyon yapmak istediginiz gen indexini giriniz: ";
                cin >> genIndex;

                try {
                    kromozomList->mutasyon(kromozomIndex, genIndex);
                    cout << "Mutasyon islemi tamamlandi." << endl;
                } catch (const char* error) {
                    cout << error << endl;
                }
                break;

            case 3:
               
                kromozomList->otoIslemler("Islemler.txt");
                break;

            case 4:
                kromozomList->yazdirEnKucukGen();
                break;

            case 5:
                
                cout << "Program sonlaniyor..." << endl;
                break;

            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
                break;
        }
    } while (choice != 5);

    kromozomList->clear();
    delete kromozomList;
    return 0;
}
