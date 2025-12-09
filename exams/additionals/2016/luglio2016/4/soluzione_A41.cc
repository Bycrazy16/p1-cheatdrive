using namespace std;
#include <iostream>

int converti (char * s,int sign,int currvalue) {
	int res;
	if (*(s+1) == '\0') 
		res = sign*(currvalue*10+(*s-'0'));
	else if ((*s >= '0') && (*s <= '9'))	// *s is a digit
		res = converti(s+1,sign,currvalue*10+(*s-'0'));
	else if (*s == '+')						// *s is '-'
		res = converti(s+1,sign,currvalue);
	else if (*s == '-')						// *s is '-'
		res = converti(s+1,sign*-1,currvalue);
	return res;
}

int main (int argc, char * argv[]) {
  cout	<< "Ho letto " 
  		<< converti(argv[1],1,0) 
		<< ", il numero moltiplicato per 5 e`: " 
		<< 5*converti(argv[1],1,0) << endl;
}
