#include <stdio.h>

/*orizoume prwta thn timh tou diaireth = 2 */
const int duo = 2;


int main(){
    int num, u;
    char ok =0;     /* gia elegxo an edwse arnitiko arithmo o xrhsths */
    printf("Dwste thetiko arithmo gia metatroph se duadiko\n");

    /*elegxos an edwse thetiko arithmo o xrhsths opote to ok ginetai 1 */
    while (ok != 1){
        scanf("%d", &num);
        (num>=0)? ok =1:printf("Sfalma! Dwsate arnhtiko arithmo.\nParakalw dwste thetiko arithmo.\n");  /* gia n>=0 tote bazei ok =1 kai oloklhrwnetai h diadikasia */
    }                                                                                                   /* gia n<0 emfanizei mhnyma lathous kai to ok paramenei 0 gia na epanalafthei*/

    /*metatroph se duadiko */
    while (num!=0){
            u = num%duo;        /*ypoloipo*/
            num /= duo;         /*to antikatastei me to piliko tou*/
            (u ==1)? putchar('1'):putchar('0');
    }
}
