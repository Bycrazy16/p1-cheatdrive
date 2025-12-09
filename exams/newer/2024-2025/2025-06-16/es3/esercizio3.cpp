#include <iostream>
#include <cstdlib>
#include <cstring>
#include "stack.h"

void mystrrevcat(char * dest, char * src) {
    int srclen = strlen(src);
    int destlen = strlen(dest);
    int i = destlen-1;
    dest[destlen + srclen] = '\0';
    while (i >= 0) {
        dest[srclen + i] = dest[i];
        i--;
    }
    i = 0;
    while (i < srclen) {
        dest[i] = src[srclen - 1 - i];
        i++;
    }
}

void mystrcat(char * dest, char * src) {
    strcat(dest, src);
}

// Inserire qui sott la dichiarazione della funzione estrai_messaggio
void estrai_messaggio(Stack s, int id, char * & messaggio, int size = 0);
// Inserire qui sopra la dichiarazione della funzione estrai_messaggio

int main(int argc, char * argv[]) {
    if (argc != 1) {
        std::cerr << "Usage: " << argv[0] << std::endl;
        return 1;
    }

    Stack s = init_stack();
    Message m;

    m.id = 1;
    strcpy(m.message, "Hello ");
    push(s, m);

    m.id = 3;
    strcpy(m.message, "Esame ");
    push(s, m);

    m.id = 2;
    strcpy(m.message, "Il ");
    push(s, m);

    m.id = 1;
    strcpy(m.message, "World");
    push(s, m);

    m.id = 3;
    strcpy(m.message, "molto ");
    push(s, m);

    m.id = 2;
    strcpy(m.message, "professore ");
    push(s, m);

    m.id = 1;
    strcpy(m.message, "!");
    push(s, m);

    m.id = 3;
    strcpy(m.message, "Difficile!");
    push(s, m);

    m.id = 2;
    strcpy(m.message, "ha molta ");
    push(s, m);

    m.id = 2;
    strcpy(m.message, "fantasia!");
    push(s, m);

    char * messaggio;
    std::cout << "Messaggio: 2" << std::endl;
    estrai_messaggio(s, 2, messaggio);
    std::cout << "\t" << messaggio << std::endl;
    delete [] messaggio;

    std::cout << "Messaggio: 1" << std::endl;
    estrai_messaggio(s, 1, messaggio);
    std::cout << "\t" << messaggio << std::endl;
    delete [] messaggio;

    std::cout << "Messaggio: 4" << std::endl;
    estrai_messaggio(s, 4, messaggio);
    std::cout << "\t" << messaggio << std::endl;
    delete [] messaggio;

    std::cout << "Stack -- " << std::endl;
    print_stack(s);
    delete_stack(s);
    return 0;
}


// Inserire qui sotto la definizione della funzione estrai_messaggio

// Inserire qui sopra la definizione della funzione estrai_messaggio
