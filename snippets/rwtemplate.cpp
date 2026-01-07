#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    
    //check parametri con uscira
    if(argc!=2){
        cout<<"numero argomenti sbagliato";
        exit(1);
    }


    fstream read;
    read.open(argv[1], ios::in);
    
    
    //con a capo, singolo char
    char c;
    while(!read.eof() && !read.fail()){
        if(read.get(c)){
            cout<<c;
        }
    }

    read.close();
    read.open(argv[1], ios::in);

    //senza a capo
    char buffer;
    while(!read.eof() && !read.fail()){
        read>>buffer;
        cout<<buffer;
    }

    read.close();
    read.open(argv[1], ios::in);

    cout<<endl;

    //con getline
    char array[256];
    while(!read.eof() && !read.fail()){
        read.getline(array,256);
        cout<<array<<endl;
    }

    cout << endl;

    //chiusura file
    read.close();

    /*

    write template

    fstream write;                 // creo lo stream
    write.open(argv[1], ios::out); // apro il file in scrittura

    if (!write || write.fail()) {                  // controllo apertura
        cerr << "Error " << argv[1] << endl;
        return 1;
    }

    write << "John Doe\n";

    write.close();                 // chiudo il file
    */

    return 0;
}