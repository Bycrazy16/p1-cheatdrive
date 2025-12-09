#include <iostream>
#include <iomanip>

using namespace std;

void stampaarray(const int V[],int n);
void leggiarray(int V[],int & n);
void intersezione(const int A[], int dima,
                  const int B[], int dimb,
                  int C[], int & dimc) ;

int main () {
   int MAXDIM = 100;
   int A[MAXDIM] = {1,3,4,5,7,9,10,11,14,19,21,24};
   int dima = 12;
   int B[MAXDIM] = {0,1,2,4,5,6,8,11,12,13,15,19,22,23,24,27};
   int dimb = 16;
   int C[MAXDIM];
   int dimc;
   intersezione(A,dima,B,dimb,C,dimc);
   stampaarray(C,dimc);
   leggiarray(A,dima);
   leggiarray(B,dimb);
   intersezione(A,dima,B,dimb,C,dimc);
   stampaarray(C,dimc);
}

void leggiarray(int V[],int & n) {
   cout << "Dimensione: ";
   cin >> n;
   for (int i=0;i<n;i++) {
     cout << setw(2) << i << ": " ;
     cin >> V[i];
   }
}

void stampaarray(const int V[],int n) {
   cout << "[";
   for (int i=0;i<n;i++) {
     cout << setw(3) << V[i];
   }
   cout << "]" << endl;
}

void intersezione_ric(const int A[],int mina,int maxa,
                      const int B[],int minb,int maxb,
                      int C[], int & dimc) {
   if ((mina>maxa)||(minb>maxb))
     ;
   else if (A[mina]==B[minb]) {
     C[dimc]=A[mina];
     dimc++;
     intersezione_ric(A,mina+1,maxa,B,minb+1,maxb,C,dimc);
   }
   else if (A[mina]<B[minb]) {
     intersezione_ric(A,mina+1,maxa,B,minb,maxb,C,dimc);
   }
   else  { // (A[mina]>B[minb])
     intersezione_ric(A,mina,maxa,B,minb+1,maxb,C,dimc);
   }
}

void intersezione(const int A[], int dima,
                  const int B[],int dimb,
                  int C[], int & dimc) {
   dimc=0;
   intersezione_ric(A,0,dima-1,B,0,dimb-1,C,dimc);
}
