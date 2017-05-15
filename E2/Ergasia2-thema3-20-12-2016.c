#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Για τις καρτες */
typedef struct{
    char xrwma[2], sxima[2], arithmos[2], ufh[2]; // τα χαρακτηριστικα των καρτων
    char enniaio[5];      // string που περιεχει ως μια λεξη τα χαρακτηριστικα
}   KARTES;

/* Για τους παικτες */
typedef struct{
    char id, onoma[17];
    unsigned int score;
}   PAIKTIS;

/* Για ελεγχο εαν εκανε set */
char test_if_set(KARTES karta[3][4], int prwth_seira, int prwth_sthlh, int deuterh_seira, int deuterh_sthlh, int trith_seira, int trith_sthlh){
    char set='0'; // το θετω ισο με το μηδεν
    int point=0;

    /* για καθε χαρακτηριστικο (πχ πρωτα χρωμα, μετα σχημα κλπ) ελεγχουμε εαν ειναι σε ολες τις καρτες ιδιο ή σε ολες τις καρτες διαφορετικο */
    /* αν ισχυει καποιο απο το δυο αυξανουμε το point κατα 1. Οποτε στο τελος ελεγχουμε εαν συγκεντρωσαμε 4 για να κανουμε set */

    if (strcmp(karta[prwth_seira][prwth_sthlh].xrwma, karta[deuterh_seira][deuterh_sthlh].xrwma)==0){
                if (strcmp(karta[trith_seira][trith_sthlh].xrwma, karta[deuterh_seira][deuterh_sthlh].xrwma)==0){
                    point++;    // εαν ολες οι καρτες εοχυν ιδιο χρωμα αυξανουμε το point κατα 1
                }
    }

    else if (strcmp(karta[prwth_seira][prwth_sthlh].xrwma, karta[deuterh_seira][deuterh_sthlh].xrwma)!=0){
                if (strcmp(karta[trith_seira][trith_sthlh].xrwma, karta[deuterh_seira][deuterh_sthlh].xrwma)!=0){
                    if (strcmp(karta[trith_seira][trith_sthlh].xrwma, karta[prwth_seira][prwth_sthlh].xrwma)!=0){
                        point++; // εαν σε ολες τις καρτες διαφορετικο χρωμα αυξανουμε το point κατα 1
                    }
                }
    }

    if (strcmp(karta[prwth_seira][prwth_sthlh].sxima, karta[deuterh_seira][deuterh_sthlh].sxima)==0){
                if (strcmp(karta[trith_seira][trith_sthlh].sxima, karta[deuterh_seira][deuterh_sthlh].sxima)==0){
                    point++;    // εαν ολες οι καρτες εοχυν ιδιο σχημα αυξανουμε το point κατα 1
                }
    }

    else if (strcmp(karta[prwth_seira][prwth_sthlh].sxima, karta[deuterh_seira][deuterh_sthlh].sxima)!=0){
                if (strcmp(karta[trith_seira][trith_sthlh].sxima, karta[deuterh_seira][deuterh_sthlh].sxima)!=0){
                    if (strcmp(karta[trith_seira][trith_sthlh].sxima, karta[prwth_seira][prwth_sthlh].sxima)!=0){
                        point++;    // εαν σε ολες τις καρτες διαφορετικο σχημα αυξανουμε το point κατα 1
                    }
                }
    }

    if (strcmp(karta[prwth_seira][prwth_sthlh].arithmos, karta[deuterh_seira][deuterh_sthlh].arithmos)==0){
                if (strcmp(karta[trith_seira][trith_sthlh].arithmos, karta[deuterh_seira][deuterh_sthlh].arithmos)==0){
                    point++;    // εαν ολες οι καρτες εοχυν ιδιο αριθμο αυξανουμε το point κατα 1
                }
    }

    else if (strcmp(karta[prwth_seira][prwth_sthlh].arithmos, karta[deuterh_seira][deuterh_sthlh].arithmos)!=0){
                if (strcmp(karta[trith_seira][trith_sthlh].arithmos, karta[deuterh_seira][deuterh_sthlh].arithmos)!=0){
                    if (strcmp(karta[trith_seira][trith_sthlh].arithmos, karta[prwth_seira][prwth_sthlh].arithmos)!=0){
                        point++;    // εαν σε ολες τις καρτες διαφορετικο αριθμο αυξανουμε το point κατα 1
                    }
                }
    }

    if (strcmp(karta[prwth_seira][prwth_sthlh].ufh, karta[deuterh_seira][deuterh_sthlh].ufh)==0){
                if (strcmp(karta[trith_seira][trith_sthlh].ufh, karta[deuterh_seira][deuterh_sthlh].ufh)==0){
                    point++;    // εαν ολες οι καρτες εοχυν ιδια υφη αυξανουμε το point κατα 1
                }
    }

    else if (strcmp(karta[prwth_seira][prwth_sthlh].ufh, karta[deuterh_seira][deuterh_sthlh].ufh)!=0){
                if (strcmp(karta[trith_seira][trith_sthlh].ufh, karta[deuterh_seira][deuterh_sthlh].ufh)!=0){
                    if (strcmp(karta[trith_seira][trith_sthlh].ufh, karta[prwth_seira][prwth_sthlh].ufh)!=0){
                        point++;    // εαν σε ολες τις καρτες διαφορετικη υφη αυξανουμε το point κατα 1
                    }
                }
    }


    if (point==4) set='1';      // εαν συγκεντρωσαμε 4 τοτε σημαινει οτι εχουμε σετ

    return set;
}



/* μηχανη τυχαιων αριθμων μεταξυ αριθμων min και max που δινει ο χρηστης */
int getRandomNumber(int Min, int Max){
    double rnd= (double)rand()/((double)RAND_MAX+1);
    return   (int)(rnd*(Max-Min+1))+Min;
}


/* Για να δημιουργουμε καινουργιο συνολο καρτων */
KARTES getNextCard(char set_xrwmata[], char set_sximata[], char set_arithmoi[], char set_ufes[]){
    KARTES card;

    // επειδη δεν θελουμε αριθμους αλλα γραμματα (πχ r για κοκκινο) εχω κανει πινακες που περιεχουν αυτα τα γραμματα
    card.arithmos[0]= set_arithmoi[getRandomNumber(0,2)]; // οποτε κανω random ποια θεση θελω του πινακα και τραβαω το στοιχειο του
    card.xrwma[0]= set_xrwmata[getRandomNumber(0,2)];
    card.sxima[0]= set_sximata[getRandomNumber(0,2)];
    card.ufh[0]= set_ufes[getRandomNumber(0,2)];

    // για να μπορω να κανω strcpy ή strcmp πρεπει να καταλαβαινει που τελειωνει
    // ετσι ολα τα χαρακτηριστικα ειναι πινακες 2 στοιχειων οπου το πρωτο αντιστοιχει στο χαρακτηριστικο
    card.arithmos[1]= '\0';    // και το δευτερο στο τελος του string '\0'
    card.xrwma[1]= '\0';
    card.sxima[1]= '\0';
    card.ufh[1]= '\0';

    // τα περναμε ολα στο enniaio ωστε να μπορουμε να το διαχειριζομαστε ευκολοτερα σε ελεγχους και σε printf
    card.enniaio[0]=card.xrwma[0];
    card.enniaio[1]=card.sxima[0];
    card.enniaio[2]=card.arithmos[0];
    card.enniaio[3]=card.ufh[0];
    card.enniaio[4]='\0';
    return card;

}

/* Cheat mode για ευρεση και εμφανιση καρτων που κανουν σετ */
char cheat(KARTES karta[3][4], int i, int j, int k, int l, int print){
    int w, z;
    char set='0';
    for (i=0;i<3 && set!= '1';i++)
        for (j=0;j<4 && set!= '1';j++)
            for (k=i;k<3 && set!= '1';k++)
                for (l=j;l<4 &&  set!= '1';l++)
                    if (k!=i || l != j)
                        for (w=k;w<3 && set!= '1';w++)
                            for (z=l;z<4 && set!= '1';z++)
                                if (k!=w || l != z) {
                                        set = test_if_set(karta, i, j, k, l, w, z); // ελεγχουμε ανα 3 καρτες αν ειναι set
                                        if (set == '1' && print == 1) printf("Set einai %d %d, %d %d, %d %d\n", i, j, k, l, w, z);
                                }
    return set;
}

/* Για να τραβηξουμε ενα συνολο καρτων */
char kainourgio_set(KARTES karta[3][4], int i, int j, int k, int l, int dublicate, char set_xrwmata[], char set_sximata[], char set_arithmoi[], char set_ufes[]){
    char set = '0';

    while (set!='1'){
        for (i=0;i<3;i++){
            for (j=0;j<4;j++){
                karta[i][j]= getNextCard(set_xrwmata, set_sximata, set_arithmoi, set_ufes); // κανουμε draw μια καρτα
                dublicate =1;
                while(dublicate != 0){    // επαναλαμβανουμε μεχρι να μην βρισκουμε πια ιδια καρτα
                        dublicate = 0;
                        for (k=0;k<i && dublicate != 1; k++){          // ελεγχω μια προς μια της καρτες μεχρι να βρεθει καποια ιδια
                            for (l=0;l<j && dublicate != 1; l++)
                                if (strcmp(karta[i][j].enniaio,karta[k][l].enniaio)==0){        // ελεγχουμε αν ειναι ιδια με καποια απο τις προηγουμενες καρτες
                                    karta[i][j] = getNextCard(set_xrwmata, set_sximata, set_arithmoi, set_ufes);  // αν ναι τραβαμε καινουργια
                                    dublicate =1;   //επειδη ομως αυτη η καινουργια καρτα μπορει να ειναι ιδια με καποια απο τις προηγουμενες,
                                                    //βαζουμε 1 ωστε να επαναλαβουμε τον ελεγχο απο την αρχη
                                }
                        }
                }
            }
        }
        set = cheat(karta, i, j, k, l, 0);
    }

}


main(){
    KARTES karta[3][4];
    int i, j, k, l, dublicate, point, num;
    int prwth_seira, prwth_sthlh, deuterh_seira, deuterh_sthlh, trith_seira, trith_sthlh;
    char epilogi[2], set = '1', set_xrwmata[]= {'r', 'g', 'b'}, set_sximata[]= {'c', 't', 'r'};
    char set_ufes[] = {'b', 'h', 'e'}, set_arithmoi[] = { '1', '2', '3'};
    char repeat;
    PAIKTIS paiktis[3];
    srand(time(NULL));

    // Δινω στοιχεα παικτων
    paiktis[0].id ='a';
    strcpy(paiktis[0].onoma, "Marina Andreou");
    paiktis[1].id ='g';
    strcpy(paiktis[1].onoma,"Kostas Grammenos");
    paiktis[2].id ='p';
    strcpy(paiktis[2].onoma,"Maria Perdika");

    // Αρχικοποιω τις βαθμολογιες σε 0
    for (i=0;i<3;i++) paiktis[i].score=0;

    printf("H bathmologia einai h ekshs\n");
    for (i=0;i<3;i++) printf("Id: %c\nOnoma: %s\nScore: %u\n\n", paiktis[i].id, paiktis[i].onoma, paiktis[i].score);

    // Για τις επιλογες του χρηστη.  Προκειμενου να μπορεσει να ξεκινησει το while loop το αρχικοποιουμε σε 1
    epilogi[0] = '1';
    epilogi[1] = '\0';
    while (epilogi[0] !='0'){   // Το παιχνιδι επαναλαμβανεται μεχρι να ζητηθει το αντιθετο (δηλαδη να δωθει 0

            /* Τραβαμε καινουργιο συνολο καρτων */
            printf("\nKainoyrgio set:\n\n");
            kainourgio_set(karta, i, j, k, l, dublicate, set_xrwmata, set_sximata, set_arithmoi, set_ufes);
            set = '0';


            /* Διαδικασια επαναλαμβανεται μεχρι να γινει καποιο set */
            while(set!='1'){

                /* Εμφανιζουμε τις καρτες */
                for (i=0;i<3;i++){
                    for (j=0;j<4;j++){
                        //printf("%s ", karta[i][j].enniaio);
                        printf("[%s,%s,%s,%s] ", karta[i][j].xrwma, karta[i][j].sxima, karta[i][j].arithmos, karta[i][j].ufh);
                    }
                    printf("\n");
                }

                printf("\nH arithmisi twn suntetagmenwn ksekina apo 0 \n(px karta prwths seira kai deuterh sthlh einai 0 1)\n");
                /* Δινεται ποιος παικτης παιζει ή αν θα τερματιστει. */
                repeat = '1';     // αρχικοποιω σε μηδεν για να ξεκινησει το while loop
                while (repeat == '1') {   // Η διαδικασια επαναλαμβανεται μεχρι να δωσει σωστα καποιο id παικτη ή εξοδο
                        repeat='0';       // Δινουμε repeat =0 . Εαν παραμεινει ως τελος σημαινει οτι δοθηκε σωστη επιλογη και τελειωνει το loop
                        printf("\nDwste id paikth h 0 gia eksodo");
                        scanf(" %c", epilogi);

                        if (epilogi[0] == '0'){     // Εαν δωσει μηδεν ζητα εξοδο. Εμφανιζει τα σκορ και τερματιζει το προγραμα.
                            for (i=0;i<3;i++) printf("Id: %c\nOnoma: %s\nScore: %u\n\n", paiktis[i].id, paiktis[i].onoma, paiktis[i].score);
                           exit(1);
                        }
                        else if (epilogi[0] == 'a') num = 0;        // αναλογως τον παικτη δινουμε διαφορετικη τιμη στο num οπου θα χρησιμοποιηθει ως δεικτης στο πινακα των παικτων
                        else if (epilogi[0] == 'g') num = 1;
                        else if (epilogi[0] == 'p') num = 2;
                        else if (epilogi[0] == 'C') {               // Cheat Mode.
                                printf("Cheat mode!");
                                repeat = cheat(karta, i, j, k, l, 1);
                                            // Επειδη εμφανισε απλα το cheat, δινουμε 0 ωστε να επαναληφθει το loop και να δοθει παικτης.
                        }
                        else {
                            printf("Den uparxei paiktis me id: %s\nDokimaste ksana\n", epilogi);
                            repeat ='1';                  // Εγινε καποιο λαθος => δινουμε 0 για να επαναλυφθει.
                        }
                }

                /* Εμφανιζεται το ονομα του ενεργου παικτη και των καλει να δωσει τις συνταταγμενες */
                printf("\n%s dwste tis suntetagmenes twn 3 kartwn.\n", paiktis[num].onoma);

                printf("Syntetagmenes prwths karta.\nSeira: ");
                scanf("%d", &prwth_seira);
                while (prwth_seira<0 | prwth_seira>2){          // σε καθε μια εισοδο των συντεταγμενων ελεγχεται εαν ειναι εντος οριων.
                    printf("Dwsate arithmo seiras ektos oriwn");
                    printf("\nDwste ksana thn seira ths prwths kartas: ");
                    scanf("%d", &prwth_seira);                  // Αν ειναι εκτος καλει τον χρηστη να την ξαναδωσει.
                }

                printf("Sthlh: ");
                scanf("%d", &prwth_sthlh);
                while (prwth_sthlh<0 | prwth_sthlh>3){
                    printf("Dwsate arithmo sthlhs ektos oriwn");
                    printf("\nDwste ksana thn sthlh ths prwths kartas: ");
                    scanf("%d", &prwth_sthlh);
                }

                printf("\nSyntetagmenes deuterhs kartas.\nSeira: ");
                scanf("%d", &deuterh_seira);
                while (deuterh_seira<0 | deuterh_seira>2){
                    printf("Dwsate arithmo seiras ektos oriwn");
                    printf("\nDwste ksana thn seira ths deuterhs kartas: ");
                    scanf("%d", &deuterh_seira);
                }

                printf("Sthlh: ");
                scanf("%d", &deuterh_sthlh);
                while (deuterh_sthlh<0 | deuterh_sthlh>3){
                    printf("Dwsate arithmo sthlhs ektos oriwn");
                    printf("\nDwste ksana thn sthlh ths deuterhs kartas: ");
                    scanf("%d", &deuterh_sthlh);
                }


                printf("\nSyntetagmenes tritis kartas.\nSeira: ");
                scanf("%d", &trith_seira);
                while (trith_seira<0 | trith_seira>2){
                    printf("Dwsate arithmo seiras ektos oriwn");
                    printf("\nDwste ksana thn seira ths triths kartas: ");
                    scanf("%d", &trith_seira);
                }

                printf("Sthlh: ");
                scanf("%d", &trith_sthlh);
                while (trith_sthlh<0 | trith_sthlh>3){
                    printf("Dwsate arithmo sthlhs ektos oriwn");
                    printf("\nDwste ksana thn sthlh ths triths kartas: ");
                    scanf("%d", &trith_sthlh);
                }

                /* Εαν εκανε set παιρνει την τιμη ιση με 1. Για να ακνυοεμ τον ελεγχο αν εκανε σετ καλουμε το gunction test_if_set */
                set = test_if_set(karta, prwth_seira, prwth_sthlh, deuterh_seira, deuterh_sthlh, trith_seira, trith_sthlh);


                if (set=='1'){      // εαν εκανε σετ εμφανιζουμε σχετικο μηνυμα αυξανουμε το σκορ κατα 2. Φροντιζουμε ομως να μην ξεπερνα την τιμη 255
                    printf("\nKanate set!!! Duo pontoi gia to paikti me id %c\n", paiktis[num].id);
                    if (paiktis[num].score <254) paiktis[num].score = paiktis[num].score + 2;       // Οποτε την προσθεση των 2 μοναδων την κανει εφοσον ειναι μικροτερο απο 254
                    else paiktis[num].score =255;                                                   // Αλλιως του βαζουμε το μεγιστο σκορ = 255
                    printf("To score tou einai %u \n\n", paiktis[num].score);                       // και εμφανιζουμε το σκορ του


                }

                else {          // εαν οχι μειωνουμε το σκορ κατα 1 μοναδα. Φροντιζουμε ομως να μην γινει αρνητικος
                    if (paiktis[num].score >0) paiktis[num].score = paiktis[num].score -1;  // Οποτε την αφαιρεση της 1 μοναδας την κανει εφοσον ειναι μεγαλυτερο του 0
                    printf("\nOi kartes pou epileksate den einai SET. O paiktis me id %c xanei mia monada\nTo score tou einai %d\n", paiktis[num].id, paiktis[num].score);  // Εμφανιζουμε σχετικο μηνυμα μαζι με το σκορ
                    printf("\nSunexizoume me idies kartes mexri na brethei set\n\n");

            }

        }
        if (paiktis[num].score >=10){       // εαν εφτασε τους 10 ποντους κερφισε το παιχνιδι.
                printf("%s kerdisate!!!\nTo teliko score einai:\n", paiktis[num].onoma);    // Εμφανιζει σχετικο μηνυμα
                for (i=0;i<3;i++)                                           // Καθως και την τελικη βαθμολογια ολων των παικτων
                    printf("Id: %c\nOnoma: %s\nScore: %u\n\n", paiktis[i].id, paiktis[i].onoma, paiktis[i].score);

               exit(1);                     // Και τερματιζει.
            }
    }


}

