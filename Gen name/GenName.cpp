#include "GenName.h"

using namespace std;

string i2s(int value) {
  string res;
  do {
    switch(value % 10) {
      case 0: res = "0" + res; break;
      case 1: res = "1" + res; break;
      case 2: res = "2" + res; break;
      case 3: res = "3" + res; break;
      case 4: res = "4" + res; break;
      case 5: res = "5" + res; break;
      case 6: res = "6" + res; break;
      case 7: res = "7" + res; break;
      case 8: res = "8" + res; break;
      case 9: res = "9" + res; break;
    }
    value /=  10;
  } while (value);
  return res;
}

int main(){
	GenName();

	return 0;
}