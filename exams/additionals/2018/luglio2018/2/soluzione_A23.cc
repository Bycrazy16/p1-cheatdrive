using namespace std;
#include <iostream>

// Inserire qui sotto la dichiarazione della funzione crea_vettore

int* crea_vettore(int n);
void numeri_esagonali(int v[], int n, int i);
	
int main(){
           
   int N;

   cout << "Dimensione: ";   
   cin >> N;
   
   if (N < 0) {
      cout << "Attenzione: inserire intero positivo!\n";
      return 1;
   }

   int* vector = crea_vettore(N);
   
   cout << "Array creato: ";
   for(int i=0; i<N; i++) {
      cout << vector[i] << " ";
   }
   cout << endl;
   
   delete[] vector;
        
	return 0;
}

// Inserire qui sotto la definizione della funzione crea_vettore

int* crea_vettore(int n) {
   int *v = new int[n];
   numeri_esagonali(v, n, 0);
   return v;
}  
      
void numeri_esagonali(int v[], int n, int i) {
   if (i>= n) {
      return;
   } else {
      v[i] = i*(2*i-1);
      numeri_esagonali(v, n, i+1);
   }
}
