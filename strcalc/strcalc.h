/*
  Name: StrCalc.h
  Copyright: Exinferis Inc.- 1999-2006
  URL: http://www.inexinferis.co.nr
  Author: Karman
  Date: 12/05/05 15:13
  Version: 0.95
  Description: Calculadora de Strings...
  
  Operandos:
    Enteros, Reales y ()
  Operaciones Permitidas:
    Matemáticas:
      + - / * % ^
    Funciones:
      asin(x) - ArcoSeno
      acos(x) - ArcoCoseno
      atan(x) - ArcoTangente
      abs(x)  - Absoluto (+)
      sin(x)  - Seno
      sinh(x) - Seno hiperbólico
      cos(x)  - Coseno
      cosh(x) - Coseno hiperbólico
      tan(x)  - Tangente
      tanh(x) - Tangente hiperbólica
      ln(x)   - Logaritmo natural
      log(x)  - Logaritmo base 10
      e(x)    - e a la n
      rand(x) - Número aleatorio
      rnd(x)  - Redondeo
      int(x)  - Truncado a entero
  
  Example:
    
    Calculate("2^5/(2*8)+9^(1/2)-(ln(e(1)))*(cos(90)-sin(90))");
*/

#ifndef	_STRCALCLIB_H_
#define	_STRCALCLIB_H_

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Operaciones válidas
#define isoper(a) (a=='+')||(a=='-')||(a=='*')||(a=='/')||(a=='^')||(a=='%')

//********************************************************
// Registro de funciones...
//********************************************************
typedef struct _FUNC_{
  char fname[6],func;
}FUNC;

//********************************************************
// Lista de argumentos...
//********************************************************
typedef struct calcs{
  double val;
  char op;
  struct calcs *sig;
}CALCS,*PCALCS;

//********************************************************
// Funciones Exportadas...
//********************************************************
double Calculate(char *arg);
unsigned char GetFunctionErrorPos(void);
char *GetFunctionError(void);

#endif //_STRCALCLIB_H_
