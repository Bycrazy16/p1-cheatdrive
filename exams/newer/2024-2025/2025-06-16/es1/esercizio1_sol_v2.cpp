#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int righe = 40;
const int colonne = 3;
const int n = 16;

void calcola_modulo(double[righe][colonne], double[righe]);
void normalizza(double[righe], double[righe]);
void quantizza(double[righe], int[righe], int);

int main()
{
    fstream fin;
    double campioni[righe][colonne];
    double modulo_acc[righe];
    double modulo_acc_norm[righe];
    int q[righe];

    fin.open("Test.txt", ios::in);

    if (!fin)
    {
        cout << "File non esiste!" << endl;
        return -1;
    }

    fin >> campioni[0][0];
    if (fin.eof())
    {
        cout << "File vuoto" << endl;
        fin.close();
        return -2;
    }

    fin >> campioni[0][1] >> campioni[0][2];

    for (int i = 1; i < righe; i++)
    {
        fin >> campioni[i][0] >> campioni[i][1] >> campioni[i][2];
    }
    fin.close();

    calcola_modulo(campioni, modulo_acc);
    normalizza(modulo_acc, modulo_acc_norm);
    quantizza(modulo_acc_norm, q, n);

    for (int i = 0; i < righe; i++)
        cout << q[i] << " ";
    cout << endl;
    return 0;
}

void calcola_modulo(double campioni[righe][colonne], double modulo_acc[righe])
{
    for (int i = 0; i < righe; i++)
    {
        modulo_acc[i] = sqrt(pow(campioni[i][0], 2) + pow(campioni[i][1], 2) + pow(campioni[i][2], 2));
    }
    return;
}

void normalizza(double modulo_acc[righe], double modulo_acc_norm[righe])
{
    double max = modulo_acc[0];
    for (int i = 1; i < righe; i++)
    {
        if (modulo_acc[i] > max)
            max = modulo_acc[i];
    }

    for (int i = 0; i < righe; i++)
    {
        modulo_acc_norm[i] = modulo_acc[i] / max;
    }

    return;
}
void quantizza(double modulo_acc_norm[righe], int q[righe], int n)
{
    for (int i = 0; i < righe; i++)
    {
        q[i] = round(modulo_acc_norm[i] * (pow(2, n - 1)));
    }
    return;
}
