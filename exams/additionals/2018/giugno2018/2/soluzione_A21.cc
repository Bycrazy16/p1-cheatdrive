using namespace std;
#include <iostream>

// Inserire qui sotto la dichiarazione della funzione shift

int* shift(int v[], int n, int j);
void left_shift(int v1[], int v2[], int n, int j, int i);
	
int main(){
         
   int J = 0;      
   const int N = 15;
   int vector[] = {2, 17, 44, 202, 5, 13, 26, 7, 9, 131, 51, 79, 88, 96, 32};

   cout << "Array iniziale: ";   
   for(int i=0; i<N; i++) {
      cout << vector[i] << " ";
   }
   cout << endl;
   
   cout << "Numero spostamenti a sinistra: ";
   cin >> J;

   int* new_vect = shift(vector, N, J);
   
   cout << "Nuovo array: ";
   for(int i=0; i<N; i++) {
      cout << new_vect[i] << " ";
   }
   cout << endl;
   
   delete[] new_vect;
        
	return 0;
}

// Inserire qui sotto la definizione della funzione shift


int* shift(int v[], int n, int j) {
   int *new_v = new int[n];
   left_shift(v, new_v, n, j, 0);
   return new_v;
}  

void left_shift(int v1[], int v2[], int n, int j, int i) {
   if (i >= n) {
      return;
   } else {
      if (i+j < n) {   
         v2[i] = v1[i+j];         
      } else {
         v2[i] = 0;
      }
      left_shift(v1, v2, n, j, i+1);
   }  
}
