// Resolució d'equacions no lineals. Mètode de Newton-Rapshon

//Llibreries que utilzarem:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Iniciem el programa:

main(){

    //Declarem les variables:
    double x1, a, b, xn, xnn, fxn, fxnn, c, d, y, yy, z1, z2, z3, z4, z5, z6;

    int n, m, e, E;

    int i=0;
    
    //Utilitzarem el següent punter
    double *p;

    //Punter del fitxer
    FILE * fp;

    //Cadena del nom del fitxer (30 caràcters màxim)
    char nom_fitxer[30];

    //Presentem el programa:
    printf("\nPrograma per a calcular l'arrel de la funció f(x)=x-tan(x)\nque és més a prop ");
    printf("del punt que es demani, amb una certa tolerància\ni un màxim d'iteracions (entre 1 i 200000).");

    //Se li demana a l'usuari que doni un nom per al fitxer que es crearà amb les dades obtingudes
    printf("\n\nIntrodueix el nom del fitxer on es desaran les dades (màxim 30 caràcters): ");
    scanf("%s", nom_fitxer);

    //Es demana el punt inicial:
    printf("\nIndica el punt inicial: ");
    E=scanf("%lf", &xn);

    //Es demana la tolerància:
    printf("\nIndica la tolerància: ");
    E=scanf("%lf", &x1);

    //Es demana el nombre màxim d'iteracions:
    printf("\nIndica també el nombre màxim d'iteracions");
    E=scanf("%d", &n);

    //Amb això acceptarem un nombre màxim d'iteracions i només pot ser numèric.
    if(E!=0 && n>0 && n<=200000){

        //Obrim el fitxer per començar:
        //Afegim les columnes per al fitxer.
        fp = fopen(nom_fitxer, "w");
        fprintf(fp, "Iteració:\txn:\t\t\tf(xn):\n");

        //Calculem la imatge del punt inicial donat.
        fxn = xn - tan(xn);

        //La segona línia servirà per mostrar el número d'iteracions fetes (0), el punt inicial i la seva imatge.
        fprintf(fp, "0\t\t%.15lf\t%.15lf\n", xn, fxn);

            //Comencem la iteració amb el mètode de Newton-Rapshon:
            for(i=0; i<n; i++){

                //e és el número d'iteració
                e=i+1;

                //Calculem les funcions per poder utilitzar el mètode:
                a=xn-tan(xn);
                b=1/cos(xn);
                c=b*b;
                d=1-c;
                xnn=xn-(a/d);
                fxnn=xnn-tan(xnn);

                //Calculem la tolerància a cada iteració:
                yy=xnn-xn+tan(xn)-tan(xnn);
                y=fabs(yy);
                z3=xnn-tan(xnn);
                z4=xn-tan(xn);
                z5=fabs(z3);
                z6=fabs(z4);
                z1=z5+z6;
                z2=(x1*z1)/2;

                    //Si es compleix la tolerància, s'executa aquesta condició:
                    if(y<z2){
                    //Mostrem per pantalla la última iteració que no complia la condició.
                    printf("Iteració: %d\n", e);
                    printf("El valor de X(%d) és: %.15lf\n", e, xnn);
                    printf("El valor de la funció f[X(%d)] és: %.15lf\n\n", e, fxnn);

                    //Ho afegim al fitxer:
                    fprintf(fp, "%d\t\t%.15lf\t%.15lf\n", e, xnn, fxnn);

                    //Si el nombre d'iteracions és més petit, avisarà
                    if(e<n){

                    //El programa avisa si el nombre d'iteracions és inferior al nombre màxim indicat.
                    printf("\a\nNo calien tantes iteracions. Ja s'ha trobat l'arrel", e);
        
                    //Informem que es desa al fitxer:
                    fprintf(fp, "\nDesem les dades de les iteracions al fitxer", e);
                    fprintf(fp, "(no cal fer-ne %d).\n\n", n);

                    }
                    //Aturem el bucle
                    break;
            }

    //Mostrem les iteracions i els seus resultats:
    printf("Iteració: %d\n", e);
    printf("El valor de la funció f[x(%d)] és: %.15lf\n\n", e, fxnn);

    //Assignem valors:
    p = &xn;
    *p = xnn;

    //Escriu al fitxer les dades a cada iteració:
    fprintf(fp, "%d\t\t%.15lf\n", e, xnn, fxnn);


    }

//Tanquem el fitxer:
fclose(fp);

}

//Si no es compleix la condició del "if" inicial ho torna a preguntar.
else{
    printf("\a\nIntrodueix correctament les dades");
}

printf("\n#############  Procés finalitzat  ################\n\n");

//Finalitzem el programa:
return 0;
}
