#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float L1, L2, B1, B3, A3;
  //Aquest programa ens indica el tipus de cònica que és depenent dels coeficients que introduim.
  printf ("CONIQUES\n");
  printf ("Programa realitzat per:\n");
  printf ("Jesus Vidal i Pluja\n");
  printf ("L1*y1² + L2*y2² + B1*y1 + B3*y2 + A3\n");
  printf ("Escriu el coeficient d'un dels termes quadratics (L1):");
  scanf ("%f", &L1);
  printf ("\nEscriu el coeficient de l'altre terme quadratic (L2):");
  scanf ("%f", &L2);
  printf ("\n");
  if ((L1!=0)&&(L2!=0))
  {
    printf ("Escriu el coeficient de l'altre terme quadratic (B3):");
    scanf ("%f", &B3);
    printf ("\n");
    if ((B3!=0)&&(L1*L2>0))
    {
        if ((L1*B3)>0)
            printf ("Els coeficients que m'has donat son propis d'una el.lipse imaginaria");
        else
            printf ("Els coeficients que m'has donat son propis d'una el.lipse");
    }
    else if ((L1*L2<0)&&(B3!=0)) 
        printf ("Els coeficients que m'has donat son propis d'una hiperbola");
    else if ((B3==0)&&(L1*L2>0))
        printf ("M'has donat un punt");
    else 
        printf ("Els coeficients que m'has donat son propis de dues rectes diferents no paral.leles");               
  }
  else
  {
    printf ("\n");
    printf ("Escriu el coeficient del terme que acompanya la x (B1)");
    scanf ("%f", &B1);
    if (B1!=0) 
        printf ("Els coeficients que m'has donat son propis d'una parabola");
    else
    {
        printf ("Escriu-me el coeficient que no acompanya cap variable (A3)");
        scanf ("%f", &A3);
        if (A3*L2>0)
            printf ("Els coeficients que m'has donat son propis de dues rectes imaginaries");
        else if (A3!=0)
            printf ("Els coeficients que m'has donat son propis de dues rectes paralel.les");
        else 
            printf ("Els coeficients que m'has donat son propis d'una recta");
    }
  }
  system("PAUSE");	
  return 4;
}
