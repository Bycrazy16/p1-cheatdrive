#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int leggi(char[], int[], int);
bool verifica(int[], int, int, int);
int voto(int[], int[], int);

int main()
{

    const int dim = 15;
    int sol[dim] = {0};
    int inf = 1;
    int sup = 3;
    int num_stud;
    int risp[dim] = {0};
    fstream fout;

    int validity = leggi("Soluzioni.txt", sol, dim);

    if (validity == -1)
    {
        cout << "Errore nell'apertura del file!" << endl;
        exit(0);
    }

    validity = verifica(sol, dim, inf, sup);

    if (validity == -1)
    {
        cout << "Errore!";
        exit(1);
    }

    cout << "Inserisci il numero degli studenti partecipanti a questo appello: ";
    cin >> num_stud;

    for (int i = 0; i < num_stud; i++)
    {
        char nome[24] = "Studente";
        strcat(nome, to_string(i + 1).c_str());
        strcat(nome, ".txt");

        cout << "Sto elaborando il file: " << nome << endl;

        validity = leggi(nome, risp, dim);

        if (validity == -1)
        {
            cout << "Errore nell'apertura del file!" << endl;
            continue;
        }

        int v = voto(sol, risp, dim);

        fout.open(nome, ios::app);
        if (v >= 18)
        {
            fout << endl;
            fout << v;
        }
        else
        {
            fout << endl;
            fout << "Non sufficiente";
        }

        fout.close();
    }

    return 0;
}

int leggi(char nomefile[], int s[], int dim)
{
    fstream fin;
    fin.open(nomefile, ios::in);

    if (!fin)
        return -1;

    for (int i = 0; i < dim; i++)
        s[i] = 0;

    int count = 0;

    fin >> s[count];

    while (!fin.eof() && count < dim)
    {
        count++;
        fin >> s[count];
    }

    fin.close();

    return count;
}

bool verifica(int c[], int dim, int a, int b)
{
    for (int i = 0; i < dim; i++)
        if (c[i] < a || c[i] > b)
            return 0;
    return 1;
}

int voto(int a[], int b[], int dim)
{
    int v = 0;
    for (int i = 0; i < dim; i++)
    {
        if (a[i] == b[i])
            v += 2;
        else if (b[i] != 0)
            v -= 1;
    }
    return v;
}