#include <stdio.h>
#include <math.h>

int menu(){
    printf("\nParakalw pathste \n");
    printf("1. An einai tetragwno\n");
    printf("2. An einai parallhlogramo\n");
    printf("3. An einai orthogwnio trigwno\n");
    printf("4. An einai kuklos\n");
    printf("0. Gia eksodo\n\n");
}

/* Perimetros tetragwnou */
float tetragwno(float a) {
            float perimetros = 4*a;
            return perimetros;                              /* Perimetros tetragwnou = 4*a */
}
/* Perimetros parallhlogramou */
float parallhlogramo(float a, float b) {
            float perimetros = 2*a + 2*b;                   /* Perimetros parallhlogramou = 2*a+2*b */
            return perimetros;
}
/* Perimetros trigwnou */
float trigwno (float a, float b) {
            float c= sqrt(a*a + b*b);                       /* Ypologismos tritis pleuras me pu8agoreio */
            float perimetros = a+b+c;                       /* Perimetros trigwnou = a+b+c */
            return perimetros;
}
/* Perimetros kuklou */
float kuklos(float a){
            float perimetros = 2*3.14*(a*a);                /* Perimetros kuklou = 2*pi^2 */
            return perimetros;
}


int main(){
    char choice;                                            /* gia thn diakrisi metaksu tetragwnou, parallhlogramou, trigwnou h kuklou*/
    float a, b;
    printf("To programma upologizei ti perimetro geometrikwn sxhmatwn.\n");

    while(choice!='0'){                                     /* diadikasia epanalambanetai mexri na zhthsei eksodo grafontas 0 */
    menu();
    scanf(" %c", &choice);                                  /* o xrhsths epilegei to typo grafontas 1, 2, 3 h 4 */

        if (choice == '1') {                                /* Tetragwno*/
            printf("Dwse mhkos pleuras tetragwnou: ");
            scanf("%f", &a);                                /* Pleura tetragwnou*/
            printf("H perimetros tou tetragwnou einai: %f\n", tetragwno(a));
        }
        else if (choice == '2') {                           /* Parallhlogramo*/
            printf("Dwse mhkos pleuras a: ");
            scanf("%f", &a);                                /* Pleura a*/
            printf("Dwse mhkos pleuras b: ");
            scanf("%f", &b);                                /* Pleura b*/
            printf("H perimetros tou parallhlogramou einai: %f\n", parallhlogramo(a,b));
        }
        else if (choice == '3') {                           /* Trigwno*/
            printf("Dwse mhkos kathetis pleuras a: ");
            scanf("%f", &a);                                /* Orthogonia pleura a*/
            printf("Dwse mhkos kathetis pleuras b: ");
            scanf("%f", &b);                                /* Orthogonia pleura b*/
            printf("H perimetros tou orthogwniou trigwnou einai: %f\n", trigwno(a,b));
        }
         else if (choice == '4'){
            printf("Dwse mhkos aktinas tou kuklou: ");
            scanf("%f", &a);                                /* Aktina kuklou*/
            printf("H perimetros tou kuklou einai: %f\n", kuklos(a));
         }
    }
    printf("\nZhthsate eksodo. Eis to epanidein!!! :)\n");

}

