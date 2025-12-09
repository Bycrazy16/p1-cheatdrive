#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 1000;

char * palindroma1(char * stringa, int l, int r);
bool palindroma(char * stringa, char *& err);

int main() {
	int n;
	char a[SIZE];
	char * b;
	
	do {
		if (palindroma(a, b)) {
			cout << "La frase `" << a << "' e` palindroma\n";
		} else {
			cout << "La sotto-frase `" << b << "' non e` palindroma\n";     
		}
		
		cout << "\nImmetti un'altra frase che ritieni palindroma: ";
		
		cin.getline(a,SIZE);
	} while (a[0] != '\0');
	
	return 0;
}

char * palindroma1(char * s, int l, int r) { 
	char * res;
	char lc = s[l];
	char rc = s[r];
	
	if (r-l <= 1) {
		res = NULL;
	} else if (!isalpha(lc)) {
		res = palindroma1(s, l + 1, r);
	} else if (!isalpha(rc)) {
		res = palindroma1(s, l, r-1);
	} else if (rc == lc || rc == lc-'A'+'a' || rc == lc+'A'-'a') {
		res = palindroma1(s, l+1, r-1);
	} else {
		res = new char[r-l+2];
		strncpy(res, &s[l], r-l+1);
		strcat(res,"\0");
	}
	
	return res;
}


bool palindroma(char * stringa, char *& err) {
	err = palindroma1(stringa, 0, strlen(stringa) - 1);
	return (err == NULL);
}
