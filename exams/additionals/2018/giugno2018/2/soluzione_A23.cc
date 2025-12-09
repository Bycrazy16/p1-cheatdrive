using namespace std;
#include <iostream>

// Inserire qui sotto la dichiarazione della funzione shift

char* shift(char v[], int n, int j);
void right_shift(char v1[], char v2[], int n, int j, int i);
	
int main(){
         
   int J = 0;      
   const int N = 12;
   char vector[] = {'c', 'l', 'w', 'a', 'p', 'r', 't', 'm', 'q', 'e', 'y', 'v'};

   cout << "Array iniziale: ";   
   for(int i=0; i<N; i++) {
      cout << vector[i] << " ";
   }
   cout << endl;
   
   cout << "Numero spostamenti a destra: ";
   cin >> J;

   char* new_vect = shift(vector, N, J);
   
   cout << "Nuovo array: ";
   for(int i=0; i<N; i++) {
      cout << new_vect[i] << " ";
   }
   cout << endl;
   
   delete[] new_vect;
        
	return 0;
}

// Inserire qui sotto la definizione della funzione shift


char* shift(char v[], int n, int j) {
   char *new_v = new char[n];
   right_shift(v, new_v, n, j, 0);
   return new_v;
}  

void right_shift(char v1[], char v2[], int n, int j, int i) {
   if (i >= n) {
      return;
   } else {
      if (i < j) {   
         v2[i] = 'x';         
      } else {
         v2[i] = v1[i-j];
      }
      right_shift(v1, v2, n, j, i+1);
   }  
}
