#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;

bool is_upper(char c);

int main(int argc,char* argv[]){

  fstream my_in, my_out;
  char tmp[31];
  
  if (argc!=3) {
    cout << "Usage: ./a.out <sourcefile>\n";
    exit(0);
  }

  my_in.open(argv[1],ios::in);
  my_out.open(argv[2],ios::out);
  
  my_in >> tmp;
  int l = strlen(tmp);
  if(l > 0 && is_upper(tmp[0])) {
    tmp[0] = tmp[0] + ('A' - 'a');
  }

  while(!my_in.eof()){
    my_out << tmp << " ";
    if((l > 0) && (tmp[l-1] == ',' || tmp[l-1] == ';' || tmp[l-1] == ':')) {
      my_in >> tmp;
      l = strlen(tmp);
      if(l > 0 && is_upper(tmp[0])) {
        tmp[0] = tmp[0] - ('A' - 'a');
      }
    } else {
      my_in >> tmp;
      l = strlen(tmp);
    }
  }

  my_in.close();
  my_out.close();
  return(0);
}

bool is_upper(char c) {
  return (c >= 'A' && c <= 'Z');
}
