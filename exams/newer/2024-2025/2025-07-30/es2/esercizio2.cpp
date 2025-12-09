#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>


typedef struct _Testo * Testo;

struct _Testo {
    char c;
    Testo next;
};


// Inserire qui sotto la dichiarazione della funzione elabora!


// Inserire qui sopra la dichiarazione della funzione elabora!


int main(int argc, char **argv) {
    if (argc != 3) {
        std::cout << "Errore sul numero di parametri!!!" << std::endl;
        std::cout << "Uso: " << argv[0] << " <nomefile> <int>" << std::endl;
        exit(1);
    }
    int len = strtol(argv[2], NULL, 10);
    if (errno == ERANGE || errno == EINVAL) {
        std::cout << "Second argument: \"" << argv[2] << "\" is not a number!" << std::endl;
        exit(1);
    }

    std::fstream f(argv[1], std::fstream::in);
    if (f.fail()) {
        std::cout << "Errore nell'aprire il file: " << argv[1] << std::endl;
        exit(1);
    }

    char mappa['Z'-'A'+1];
    for (int i = 0; i <= 'Z'-'A'; i++) mappa[i] = 'Z' - i;
    // for (int i = 0; i <= 'Z'-'A'; i++) std::cout << mappa[i]; std::cout << std::endl;
    
    Testo testo = nullptr;
    Testo last = testo;
    char c;
    while (f >> std::noskipws >> c) {
        if (c == EOF) break;
        Testo cp = new _Testo{c, nullptr};
        if (nullptr == last) {
            testo = last = cp;
        } else {
            last->next = cp;
            last = cp;
        }
    }
    f.close();

    elabora(testo, mappa, len); std::cout << std::endl;

    while(testo != nullptr) {
        Testo t = testo;
        testo = t->next;
        delete t;
    }
}

// Inserire qui sotto la definizione della funzione elabora!


// Inserire qui sopra la definizione della funzione elabora!
