#include <stdio.h>

/* Oi arithmitikes prakseis poy mporoun na ginoun */
int menu(){
    printf("+ gia prosthesi\n");
    printf("- gia afairesesi\n");
    printf("* gia polaplasiasmo\n");
    printf("/ gia diairesi\n\n");
}

int main(){
    float arithmos1, arithmos2, apotelesma;     /* gia tous arithmous */
    char praji;                                 /* gia to eidos ths prakshs, dhladh +, -, * kai / */
    int swsto = 0, oloklirothike = 1;           /* swsto: an edwse mia apo tis dia8esimes prakseis .
                                                   oloklhrothike: an ekane diairesi me mhdeniko arithmo*/

    printf("Dwse arithmo praji arithmo \n");
    printf("Opoy praji mporeite na balete ena apo ta parakatw \n");

    while (swsto != 1){                 /* ean egine lathos kai zhthse o xrhsths na epanalhfthei */
        menu();                         /* emfanizei poies prakseis mporei na zhthsei */
        scanf("%f %c %f", &arithmos1, &praji, &arithmos2);

        /* elegxos gia to ti praksh zhthse o xrhsths kai analogws proxwraei to programma se
           prosthesi, afairesh, pollaplasiasmos, diairesi h diairesi me mhdeniko arithmo */
        if (praji == '+') {
                apotelesma = arithmos1 + arithmos2;
                swsto = 1;
        }
        else if (praji == '-' ) {
                apotelesma = arithmos1 - arithmos2;
                swsto = 1;
        }
        else if (praji == '*' ) {
                apotelesma = arithmos1 * arithmos2;
                swsto = 1;
        }
        else if (praji == '/' && arithmos2 != 0) {
                apotelesma = arithmos1 / arithmos2;
                swsto = 1;
        }
        else if (praji == '/' && arithmos2 == 0){
                printf("\nZhthsate diairesi me diaireth to 0. \n");                     /* enhmerwsh xrhsth oti zhthse diairesh me to mhden*/
                printf("Parakalw pathste 1 gia kainoyrgia praksh h 2 gia eksodo. \n");  /* rwta xrhsth an epithimei kainoyrgia praksh*/
                scanf(" %d", &oloklirothike);
                swsto = oloklirothike - 1;                                              /* ean edwse 1 => swsto != 1 => epenalambanete h diadikasia */
        }


        /* Ean o xrhsths zhthse kati diaforetiko, enhmerwnei to xrhsth kai ton rwta an thelei na to epanalabei */
        else {
            printf("Zhthsate kapoia praksh diaforetiki apo tis dia8esimes toy programatos.\n");
            printf("Parakaleiste na dwsete mono enan apo toys parakatw sumbola gia tis antistoixes prakseis: \n");
        }
    }

    if (oloklirothike == 1) printf("Apotelesma = %f", apotelesma);
    else printf("\nZhthsate mh efikth diairesh me diaireth to mhden. To programma tha termatistei\n"); /* apo seira 37, an oloklhrothike == 1 tote
                                                                                                      zhthse diairesi me mhden kai den egine epalaipsi*/

}
