using namespace std;
#include <iostream>

#include "queue.h"


int main ()
{
    char scelta;
    queue q;
  
    double val;
    
    crea(q);

    do 
    {
        cout << "Operazioni possibili:\n"
             << "i : inserisci\n"
             << "e : elimina\n"
             << "p : primo\n"
             << "s : stampa\n"
             << "u : uscita\n"
             << "Che operazione vuoi eseguire? ";
        cin >> scelta;
        switch (scelta) {
          case 'i':
            cout << "Valore da inserire? ";
            cin >> val;
            inserisci(q, val);
            break;
          case 'e':
            if (! elimina(q)) 
                cout << "Coda vuota!\n";
            else 
                cout << "Eliminazione ok!\n"; 
            break;
          case 'p':
            if (! primo(q, val))
                cout << "Coda vuota!\n";
            else
              cout << "Primo elemento della coda: " << val << endl;
            break;            
          case 's':
            cout << "Contenuto della coda: ";
            stampa(q);
            break;
          default:
            if (scelta != 'u') 
                cout << "Operazione non valida: " << scelta << endl;
        }
    } while (scelta != 'u');

    return 0;
}
