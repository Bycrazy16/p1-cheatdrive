using namespace std;
#include <iostream>
#include "queue.h"

int main() 
{
    char res;
    char num;  
    queue q;
    int maxdim = -1;
    while (maxdim <= 0) {
        cout << "Inserire il numero massimo di elementi della coda di char: ";
        cin >> maxdim;
    }
  
    init(q, maxdim);
    do {
        cout << "\nOperazioni possibili:\n"
             << "Accoda (e)\n" 
             << "Estrai testa (d)\n" 
             << "Testa (f)\n"  
             << "Stampa (p)\n" 
             << "Quit (q)\n";
        cin >> res;
        switch (res) {
        case 'e':
            cout << "Valore: ";
            cin >> num;
            if (!accoda(q, num)) {
                cout << "Coda piena\n";
            }
            break;
        case 'd':
            if (!estrai_testa(q)) {
                cout << "Coda vuota\n";
            }
            break;
        case 'f':
            if (!testa(q, num)) {
                cout << "Coda vuota!\n";
            } else {
                cout << "First = " << num << endl;
            }
            break;
        case 'p':
            stampa(q);
            break;
        case 'q':
            break;
        default:
            cout << "Valore errato!\n";
        }
    } while (res != 'q');
    deinit(q);

    return 0;
}
