#include <iostream>
#include <fstream>

using namespace std;

const int n = 9;

int Occorrenze (const char*, int[9]);
double Converti (int);

int main (){

int count[n] = {0};
fstream fin;
int time, id;
int pointers[n] = {0};


int max = Occorrenze("Log.txt", count);

if (max == -1){
    cout<<"Errore nella lettura del file";
    return -1;}

fin.open("Log.txt", ios::in);

if (!fin || fin.fail()){
    cout<<"Errore nella lettura del file";
    return -1;
}

double* dati [n]; 
for (int i = 0; i < n; i++){
    dati[i] = new double[max];
    for (int j = 0; j < max; j++)
        dati[i][j] = 0;
}


fin>>time>>id;
while(!fin.eof())
{    
    dati[id][pointers[id]] = Converti(time);
    // cout<<"val: "<< dati[id][pointers[id]];
    pointers[id]++;
    fin>>time>>id;

}

fin.close();

double tot = 0;
for (int i = 0; i < n; i++){
    double sum = 0; 
    for (int j = 0; j < max; j++)
        sum += dati[i][j];
    tot += sum;
    if (sum > 5 && sum < 30)
        cout<<"App "<< i<<endl; 
}

if (tot > 60)
   cout<<"Alert!" <<endl;


for (int i = 0; i < n; i++)
    delete [] dati[i];

return 0;
}

int Occorrenze (const char* nome, int count[n]){
    fstream fin;
    fin.open(nome, ios::in);
    int time, id;

    if (!fin || fin.fail())
        return -1;

   fin>>time>>id;
    while(!fin.eof())
    {    
        count[id]++; 
        fin>>time>>id;

    }

    fin.close();

    for (int i = 0; i < n; i++) cout<<count[i]<< " ";
    cout << endl;

    int max = count[0];
    for (int i = 1; i < n; i++)
        if (count[i] > max)
            max = count[i];
    return max;
}

double Converti(int ms)
{

    return ms / 60000.0;

}