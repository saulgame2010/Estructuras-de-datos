#include <stdio.h>
#include <stdlib.h>
#include "strcalc.h"

//********************************************************
// Proceso Principal...
//********************************************************
int main(void){
  char *num="2^5+(4-4)+9^(1/2)-(ln(e(1)))*(cos(90)-sin(90))";
  printf("%f\n",Calculate(num));
  if(GetFunctionErrorPos())
    printf("Error en pos: %d - %s\n",GetFunctionErrorPos(),GetFunctionError());
  system("PAUSE");	
  return 0;
}
