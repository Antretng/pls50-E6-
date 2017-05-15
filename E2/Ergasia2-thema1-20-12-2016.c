#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Δομη για στοιχεια πελατων*/
typedef struct {
   char onomatepwnumo[40];          // το ονοματεπωνυμο (επωνυμο κενο ονομα)
   unsigned int arithmos_thesis;              // ο αριθμος της θεσης που εγινε κρατηση
   unsigned short tilefwno[10];      // το τηλεφωνο
   } EPIBATIS;


/* Το μενου με τις δραστηριοτητες που επιλεγει ο χρηστης */
int menu(){
    printf("\n\n1. Emfanisi kenwn thesewn\n");
    printf("2. Epilexte thesi gia kratisi\n");
    printf("3. Euresh krathshs epibath (onoma h thlefwno)\n");
    printf("4. Akurwsh krathshs\n");
    printf("5. Emfanisi krathsewn\n");
    printf("0. Termatismos \n");
}

/* Για αναγνωση και αποθηκευση των στοιχειων του λεοφωρειου απο txt */
char read_file(EPIBATIS thesi[], char *pinakida[], int *max){
    /* για φορτωση των μεταβλητων απο το bus.txt*/
    char found, temp_onoma[40], temp_epitheto[40];
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;
    int i, j;

    FILE *lewforeio;

    lewforeio = fopen("bus.txt", "r");

    if (lewforeio == NULL){ /*τερματιζει αν δεν υπαρχει αρχειο */
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }
    /* τραβαω πινακιδα και μεγεθος λεωφορειου*/
    fscanf(lewforeio, "%s %d", *pinakida, *max);



    /* αρχικοποιω βοηθητικες μεταβλητες που θα χρησιμοποιηθουν στο onomatepwnumo */
    for (i=0; i<40;i++){
        temp_epitheto[i] = '\0';
        temp_onoma[i] = '\0';
    }
    for (i=0; i<=10;i++){
        temp_tilefwno[i] = '\0';
    }
     temp_thesi = -1;


    /*τραβαω τις κρατησεις*/
    while (!feof(lewforeio)){

        fscanf(lewforeio, "\n%s %s %u ", temp_epitheto, temp_onoma, &temp_thesi); // Τις αποθηκευω προσωρινα

        for (i=0; i<10; i++){       //ωστε καθε ψηφιο να αποθηκευτει σε διαφορετικη θεση του πινακα temp_tilewno
                fscanf(lewforeio, "%1hu", &temp_tilefwno[i]);
        }


        i = 0;
        found = '0';
        while (found!= '1'){            // Βρισκω πρωτα το στοιχειο που αντιστοιχει η θεση. Σταματα να ψαχνει οταν βρεθει.
            if (i==temp_thesi-1){        // Προσοχη, οι θεσεις ξεκινουν απο 0 και οχι 1. Οποτε αφαιρω 1 για αντιστοιχια

                strcpy(thesi[i].onomatepwnumo, temp_epitheto);
                strcat(thesi[i].onomatepwnumo, " ");
                strcat(thesi[i].onomatepwnumo, temp_onoma);

                thesi[i].arithmos_thesis = temp_thesi;

                for (j=0; j<10;j++) {                           // Ωστε καθε θεση του tilefwno να εχει ενα ψηφιο.
                        thesi[i].tilefwno[j] = temp_tilefwno[j];
                }
                found = '1';            // Αλλαζει σε ενα εφοσον βρεθηκε για να σταματησει το loop.
            }
            i++;
        }
    }

    fclose(lewforeio);

}

/* Επιλογη 1 εμφάνιση συνολικού πλήθους κενών θέσεων και ταξινομημένης λίστας αριθμών τους*/
int emfanisi_kenwn(EPIBATIS thesi[], int max, int i, int kenes){
    kenes = 0;
    printf("\nKenes theseis einai oi: ");
    for (i=0; i<max;i++){          // σκαναρουμε το πινακα απο το μηδεν μεχρι το max
            if (thesi[i].onomatepwnumo[0] == '\0'){  // εαν δεν ειναι κενο το onomatepwnumo
                printf("%d ", i+1);                 // δωσε τον αριθμο του δεικτη του πινακα +1 ωστε να αντιστοιχει στον αριθμο της θεσης

                ++kenes;     // αυξησε τον μετρητη κενων θεσεων κατα 1.
            }
    }
    if (kenes>0) printf("\n\nSunolika einai %d kenes theseis", kenes);
    else printf("\n\nDen uparxoun kenese theseis");     // Εαν το kenes δεν ειναι ειναι μεγαλυτερο του μηδενος τοτε δεν ειχαμε κενες θεσεις

}

/* Επιλογη 2 "κράτηση θέσης με συγκεκριμένο αριθμό" */
int kratisi_thesis(EPIBATIS thesi[], int max, int i, int j){
    char temp_epitheto[40], temp_onoma[40];
    printf("\nPoia thesi thelete na kanete kratisi?\n");
    scanf("%d", &i);
    --i;    // αφαιρω 1 γιατι ο πινακας ξεκινα απο μηδεν

    if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] != '\0') printf("H thesi %d einai kratimeni.\n", i+1); //ελεγχος αν ειναι ελευθερη

    /* καταχωρηση στοιχειων */
    else if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] == '\0') {
            thesi[i].arithmos_thesis = i+1;  // για να αναιρεσω τη προηγουμενη διορθωση αφου αυτο το πεδιο ειναι = αριθμο θεσης

            printf("Dwste epitheto (prwto gramma kefalaio): ");
            scanf("%s", temp_epitheto);
            printf("Dwste onoma (prwto gramma kefalaio): ");
            scanf("%s", temp_onoma);


            strcpy(thesi[i].onomatepwnumo, temp_epitheto); //για να αποθηκευτουν στο πεδιο onomatepwnumo
            strcat(thesi[i].onomatepwnumo, " ");
            strcat(thesi[i].onomatepwnumo, temp_onoma);

            printf("Dwste tilefwno (10 psifia): "); //ωστε καθε ψηφιο να αποθηκευτει σε διαφορετικη θεση του πεδιου tilewno
            for (j=0; j<10; j++){
                    scanf("%1hu", &thesi[i].tilefwno[j]);
            }

    }
    else printf("Dwsate arithmo ektos oriwn tou lewforeiou\n");

}

/* Επιλογη 3 αναζητηση κρατησης (ειτε με ονοματεπωνυμο ειτε με τηλεφωνο)*/
int anazitisi_kratisis(EPIBATIS thesi[], int max, int i, int j){
    char temp_epitheto[40], temp_onoma[40], found ='0', match;
    unsigned short temp_tilefwno[10];

    /* Ρωταμε τον χρηστη αν θελει αναζητη με ονοματεπωνυμο ή τηλεφωνο και δινει 1 ή 2 αντιστοιχα */
    printf("\nAnazitisi krathshs. Dwste\n1 gia anazitisi me onomatepwnumo\n2 gia anazitisi me tilefwno\n");
    scanf("%d", &i);

    /* Αναζητηση με ονοματεπωνυμο */
    if (i == 1) {
        printf("Dwste epitheto (prwto gramma kefalaio): ");
        scanf("%s", temp_epitheto);
        printf("Dwste onoma (prwto gramma kefalaio): ");
        scanf("%s", temp_onoma);

        //για να συγκριθει με το πεδιο onomatepwnumo
        strcat(temp_epitheto, " ");
        strcat(temp_epitheto, temp_onoma);

        /* θα τυπωσει ολες τις θεσεις που ειναι κρατημενες στο ονοματεπωνυμο.  */
        for (i=0; i<max;i++)
            if(strcmp(temp_epitheto, thesi[i].onomatepwnumo)==0) {// εαν ειναι ιδια θα ειναι ισο με μηδεν οποτε αυτο ψαχναμε
                printf("H thesi %d einai kratimeni ston %s poy anazitisate.\n", i+1, thesi[i].onomatepwnumo);
                found = '1';
            }

        if (found == '0') printf("Den uparxoun kratiseis sto onomatepwnumo %s pou zitisate.\n", temp_epitheto);
    }

    /* Αναζητηση με τηλεφωνο */
    if (i == 2) {

        printf("Dwste tilefwno (10 psifia): "); //ωστε καθε ψηφιο να αποθηκευτει σε διαφορετικη θεση του πεδιου tilewno
            for (j=0; j<10; j++){
                    scanf("%1hu", &temp_tilefwno[j]);
            };

        for (i=0; i<max;i++){
            match = '1' ;  //αν παραμεινει 1 => ολα τα ψηφια ιδια => τυπωσε τη θεση
            for (j=0; j<10 && match != '0'; j++)
                if (temp_tilefwno[j] != thesi[i].tilefwno[j]) {
                    match = '0';        // Ελεγχουμε ψηφιο προς ψηφιο. Αν καποιο δεν ειναι ιδιο γινεται μηδεν
                }
            if (match == '1') {         // Αν παρεμεινε ισο με 1 τοτε δεν διαφερει κανενα ψηφιο => το τηλεφωνο που ψαχναμε
                printf("H thesi %d einai kratimeni sto tilefwno poy anazitisate.\n", i+1);
                found = '1';            // Αν βρεθει εστω και μια κρατηση γινεται ισο με 1.
            }
        }
        if (found == '0') printf("Den uparxoun kratiseis me ton arithmo pou zitisate.\n");      // Αν παρεμεινε ισο με 0 τοτε δεν βρεθηκε καμια κρατηση
    }

}

/* Επιλογη 4 ακυρωση κρατησης (με αριθμο θεσης)*/
int akurwsi_kratisis(EPIBATIS thesi[], int max, int i, int j){
    char temp_epitheto[40], temp_onoma[40];

    /* Ρωταμε και καταχωρουμε τον αριθμο θεσης που θελει ο χρηστης */
    printf("\nPoia thesi thelete na akurwsete thn kratisi?\n");
    scanf("%d", &i);
    --i;    // αφαιρω ενα για να συμβαδιζει η αριθμηση του πινακα με των θεσεων

    if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] == '\0')
        printf("H thesi %i den einai kratimeni.\n", i); //ελεγχος αν ειναι ελευθερη

    /* ακυρωση στοιχειων αυτης της θεσης */
    else if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] != '\0') {
            thesi[i].arithmos_thesis = -1;
            for (j=0; j<40; j++){
                    thesi[i].onomatepwnumo[j] = '\0';
            }
            for (j=0; j<10; j++){
                    thesi[i].tilefwno[j]= -1;
            }
    printf("H krathsh sth thesi %i akurwthike.\n", i+1);
    }
    else printf("Dwsate arithmo ektos oriwn tou lewforeiou\n");

}

/* Επιλογη 5 εμφανιση λιστας κρατημενων θεσεων ταξινομημενη κατα αριθμο θεσης */
int emfanisi_listas(EPIBATIS thesi[], int max, int i, int j){

/* Προβολη λιστας κρατησεων κατα αριθμο θεσης. */
for (i=0; i<max;i++){
        if (thesi[i].onomatepwnumo[0] != '\0'){     //Εμφανιζουμε μονο τις κρατημενες. Αρα δεν εμφανιζουμε αυτες που εχουν '\0'
            printf("%s, tilefwno ", thesi[i].onomatepwnumo);

            for (j=0; j<10;j++) {
                    printf("%hu", thesi[i].tilefwno[j]);
            }
            printf(", sth thesi %u.\n", thesi[i].arithmos_thesis);
        }
    }
}

/* Τερματισμος με αποθηκευση πρωτα στοιχειων λεοφωρειου και κρατησεις στο txt */
char termatismos_apothikeusi(EPIBATIS thesi[], char pinakida[], int max, int i, int j){
    char found, temp_onoma[40], temp_epitheto[40], temp_tilefwno[11];
    unsigned int temp_thesi;

    /* για αποθηκευση των μεταβλητων στο bus.txt*/
    FILE *lewforeio;
    lewforeio = fopen("bus.txt", "w");

    if (lewforeio == NULL){ /*τερματιζει αν δεν υπαρχει αρχειο */
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }

    /* αποθηκευω πινακιδα και μεγεθος λεοφωρειου*/
    fprintf(lewforeio, "%s %d", pinakida, max);

    /*αποθηκευω τις κρατησεις*/
    for (i =0; i<max;i++)
        if (thesi[i].onomatepwnumo[0]!='\0'){

            fprintf(lewforeio, "\n%s %u ", thesi[i].onomatepwnumo, thesi[i].arithmos_thesis); // Τις αποθηκευω προσωρινα

            for (j=0; j<10; j++){       //ωστε καθε ψηφιο να αποθηκευτει σε διαφορετικη θεση του πινακα temp_tilewno
                    fprintf(lewforeio, "%1hu", thesi[i].tilefwno[j]);
            }

    }

    fclose(lewforeio);
    printf("\nZitisate eksodo. Ta dedomena sas apothikeytikan sto arxeio bus.txt\n");
}

int main(){
    EPIBATIS thesi[53]; // ΠΡΟΣΟΧΗ!!! Ξεκινα απο μηδεν. Οταν εμφανιζεις στο χρηστη θα πρεπει να προσθετεις ενα.
    char *pinakida[8];
    int  *max;
    int  kenes, i, j, epilogi = -1;

    max = (int *) malloc(sizeof(int));  // Δεσμευουμε αναγκαια μνημη
    *pinakida = (char *) malloc(8*sizeof(char));

    /* αρχικοποιω το πινακα κρατησεων */
    for (i=0; i<53;i++){  // γεμιζω με κενες θεσεις μεχρι και τη μεγιστη θεση που εχει το λεωφορειο
        thesi[i].onomatepwnumo[0] = '\0';
        thesi[i].arithmos_thesis = -1 ;
        thesi[i].tilefwno[0] = -1 ;
    }

    read_file(thesi, pinakida, &max);   // Για να περασουμε τα δεδομενα απο το txt

    printf("Dwsate lewforeio %d thesewn kai pinakida %s.\n", *max, *pinakida);

    while (epilogi!=0){     // Επαναλαμβανεται μεχρι να ζητησει εξοδο ο χρηστης
            menu();
            printf("\nDwste arithmo epilogis: ");
            scanf("%d", &epilogi); // Ζηταμε απο το χρηστη να δωσει την επιλογη του και αναλογως προχωραμε σε ενα απο τα παρακατω

            if (epilogi == 1) emfanisi_kenwn(thesi, *max, i, kenes);        // Για εμφανιση κενων θεσεων
            else if (epilogi == 2) kratisi_thesis(thesi, *max, i, j);       // Για κρατηση θεσης
            else if (epilogi == 3) anazitisi_kratisis(thesi, *max, i, j);   // Για αναζητηση θεσης
            else if (epilogi == 4) akurwsi_kratisis(thesi, *max, i, j);     // Για ακυρωση κρατησης
            else if (epilogi == 5) emfanisi_listas(thesi, *max, i, j);      // Για εμφανιση λιστας κρατησεων
            else if (epilogi == 0) termatismos_apothikeusi(thesi, *pinakida, *max, i, j); // Για τερμετισμο και αποθηκευση
            else printf("\nDen uparxei drasthriothta %d.\nDwste mia apo tis parakatw epiloges:", epilogi);  // Στην περιπτωση που εδωσε κατι λαθος ο χρηστης
    }

}
