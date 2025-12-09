using namespace std;
#include <iostream>

// Inserire qui sotto la dichiarazione della funzione shift

float* shift(float v[], int n, int j);
void right_shift(float v1[], float v2[], int n, int j, int i);
	
int main(){
         
   int J = 0;      
   const int N = 10;
   float vector[] = {5.0, 13.2, 26.5, 7.2, 10.7, 9.3, 14.0, 81.0, 65.9, 32.1};

   cout << "Array iniziale: ";   
   for(int i=0; i<N; i++) {
      cout << vector[i] << " ";
   }
   cout << endl;
   
   cout << "Numero spostamenti a destra: ";
   cin >> J;

   float* new_vect = shift(vector, N, J);
   
   cout << "Nuovo array: ";
   for(int i=0; i<N; i++) {
      cout << new_vect[i] << " ";
   }
   cout << endl;
   
   delete[] new_vect;
        
	return 0;
}

// Inserire qui sotto la definizione della funzione shift


float* shift(float v[], int n, int j) {
   float *new_v = new float[n];
   right_shift(v, new_v, n, j, 0);
   return new_v;
}  

void right_shift(float v1[], float v2[], int n, int j, int i) {
   if (i >= n) {
      return;
   } else {
      if (i < j) {   
         v2[i] = 0.0;         
      } else {
         v2[i] = v1[i-j];
      }
      right_shift(v1, v2, n, j, i+1);
   }  
}
