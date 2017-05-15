#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Δομη για στοιχεια πελατων*/
typedef struct{
   char onomatepwnumo[40];          // το ονοματεπωνυμο (επωνυμο κενο ονομα)
   unsigned int arithmos_thesis;              // ο αριθμος της θεσης που εγινε κρατηση
   unsigned short tilefwno[10];      // το τηλεφωνο
} EPIBATIS;

/*Για την εξοδο οπου η ασκηση ζητα Linked list*/
typedef struct epib{
   char onomatepwnumo[40];          // το ονοματεπωνυμο (επωνυμο κενο ονομα)
   unsigned int arithmos_thesis;              // ο αριθμος της θεσης που εγινε κρατηση
   unsigned short tilefwno[10];      // το τηλεφωνο
   struct epib *next;
} Node, *List;

/* Μενου επιλογων */
int menu(){
    printf("\n\n1. Emfanisi kenwn thesewn\n");
    printf("2. Epilexte thesi gia kratisi\n");
    printf("3. Euresh krathshs epibath (onoma h thlefwno)\n");
    printf("4. Akurwsh krathshs\n");
    printf("5. Emfanisi krathsewn\n");
    printf("0. Termatismos \n");
}


char initialize_arithmos_thesewn(int *max){
    char temp_pinakida[8];

    // για φορτωση των μεταβλητων απο το bus.txt
    FILE *leofwreio;
    leofwreio = fopen("bus.txt", "r");

    if (leofwreio == NULL){ //τερματιζει αν δεν υπαρχει αρχειο
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }

    // τραβαω πινακιδα και μεγεθος λεοφωρειου
    fscanf(leofwreio, "%s %d\n", temp_pinakida, *max);

    fclose(leofwreio);

}

EPIBATIS read_file(EPIBATIS *thesi, char *pinakida[]){
    char found, temp_onoma[40], temp_epitheto[40], temp_max;
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;
    int i, j;

    // για φορτωση των μεταβλητων απο το bus.txt
    FILE *leofwreio;
    leofwreio = fopen("bus.txt", "r");

    if (leofwreio == NULL){ //τερματιζει αν δεν υπαρχει αρχειο
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }

    // τραβαω πινακιδα και μεγεθος λεοφωρειου

    fscanf(leofwreio, "%s %d\n", *pinakida, &temp_max);



    while (!feof(leofwreio)){
            fscanf(leofwreio, "%s %s %u ", temp_epitheto, temp_onoma, &temp_thesi); // Τις αποθηκευω προσωρινα

            for (i=0; i<9; i++){                                 //ωστε καθε ψηφιο να αποθηκευτει σε διαφορετικη θεση του πινακα temp_tilewno
                    fscanf(leofwreio, "%1hu", &temp_tilefwno[i]);
            }
            fscanf(leofwreio, "%1hu\n", &temp_tilefwno[9]);    // χωριστο για να εισαγω το \n προκειμενου να τελειωνει στη τελευταια σειρα το αρχειο και οχι να χει να διαβασει ενα \n ακομα


            found = '0';
            for (i=0;i<temp_max && found!='1';i++){                  // Βρισκω πρωτα το στοιχειο που αντιστοιχει η θεση. Σταματα να ψαχνει οταν βρεθει.

                if (thesi[i].arithmos_thesis == temp_thesi){           // Προσοχη, οι θεσεις ξεκινουν απο 0 και οχι 1. Οποτε αφαιρω 1 για αντιστοιχια

                    strcpy(thesi[i].onomatepwnumo, temp_epitheto);
                    strcat(thesi[i].onomatepwnumo, " ");
                    strcat(thesi[i].onomatepwnumo, temp_onoma);

                    for (j=0; j<10;j++) {                       // Ωστε καθε θεση του tilefwno να εχει ενα ψηφιο.
                            thesi[i].tilefwno[j] = temp_tilefwno[j];
                    }
                    found = '1';                                // Αλλαζει σε ενα εφοσον βρεθηκε για να σταματησει το loop.
                }

            }

    }


    fclose(leofwreio);

}

/* Επιλογη 1 εμφάνιση συνολικού πλήθους κενών θέσεων και ταξινομημένης λίστας αριθμών τους*/
int emfanisi_kenwn(EPIBATIS thesi[], int max, int i, int kenes){
    kenes = 0;
    printf("\nKenes theseis einai oi: ");
    for (i=0; i<max;i++){          // σκαναρουμε το πινακα απο το μηδεν μεχρι το max
            if (thesi[i].onomatepwnumo[0] == '\0'){       // εαν δεν ειναι κενο
                printf("%u ", thesi[i].arithmos_thesis);  // δωσε τον αριθμο της θεσης

                ++kenes;     // αυξησε τον μετρητη κενων θεσεων κατα 1
            }
    }
    if (kenes>0) printf("\n\nSunolika einai %d kenes theseis", kenes);
    else printf("\n\nDen uparxoun kenes theseis");     // Εαν το kenes δεν ειναι ειναι μεγαλυτερο του μηδενος τοτε δεν ειχαμε κενες θεσεις

}

/* Επιλογη 2 "κράτηση θέσης με συγκεκριμένο αριθμό */
int kratisi_thesis(EPIBATIS thesi[], int max, int i, int j){
    char temp_epitheto[40], temp_onoma[40];
    printf("\nPoia thesi thelete na kanete kratisi?\n");
    scanf("%d", &i);
    --i;    // αφαιρω 1 γιατι ο πινακας ξεκινα απο μηδεν

    if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] != '\0') printf("H thesi %u einai kratimeni.\n", thesi[i].arithmos_thesis); //ελεγχος αν ειναι ελευθερη

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
    else printf("Dwsate arithmo ektos oriwn tou leofwreiou\n");

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
                printf("H thesi %u einai kratimeni ston %s poy anazitisate.\n", thesi[i].arithmos_thesis, thesi[i].onomatepwnumo);
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
                    match = '0';    // Ελεγχουμε ψηφιο προς ψηφιο. Αν καποιο δεν ειναι ιδιο γινεται μηδεν
                }
            if (match == '1') {     // Αν παρεμεινε ισο με 1 τοτε δεν διαφερει κανενα ψηφιο => το τηλεφωνο που ψαχναμε
                printf("H thesi %d einai kratimeni sto tilefwno poy anazitisate.\n", i+1);
                found = '1';        // Αν βρεθει εστω και μια κρατηση γινεται ισο με 1.
            }
        }
        if (found == '0') printf("Den uparxoun kratiseis me ton arithmo pou zitisate.\n");  // Αν παρεμεινε ισο με 0 τοτε δεν βρεθηκε καμια κρατηση
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
            for (j=0; j<40; j++){
                    thesi[i].onomatepwnumo[j] = '\0';
            }
            for (j=0; j<10; j++){
                    thesi[i].tilefwno[j]= -1;
            }
    printf("H krathsh sth thesi %u akurwthike.\n", thesi[i].arithmos_thesis);
    }
    else printf("Dwsate arithmo ektos oriwn tou leofwreiou\n");  // στη περιπτωση που η θεση ειναι <0 ή >μεγιστου αριθμου

}

/* Επιλογη 5 εμφανιση λιστας κρατημενων θεσεων ταξινομημενη κατα αριθμο θεσης ή ονοματεπωνυμο*/
int emfanisi_listas(EPIBATIS thesi[], int max, int i, int j){
    int swap=1;
    char temp_onomatepwnumo[40];
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;

    /* Ρωταμε το χρηστη τι ταξινομηση θελει. Αν δωσει 1 ειναι κατα αριθμο θεσης και 2 κατα ονοματεπωνυμο */
    printf("Pws thelete na emfanisete th lista?\nDwste:\n\t1 gia probolh listas taksinomimenh kata thesi.\n\t2 gia probolh listas taksinomimenh kata onomatepwnumo.\n");
    scanf("%d", &i);

    /* Προβολη λιστας με ταξινομηση κατα αριθμο θεσης. */
    /* Επειδη ειναι ηδη ταξινομημενη ετσι, προχωραμε στην εμφανιση της */
    if (i == 1){
        for (i=0; i<max;i++){
            if (thesi[i].onomatepwnumo[0] != '\0'){  //Εμφανιζουμε μονο τις κρατημενες. Αρα δεν εμφανιζουμε αυτες που εχουν '\0'
                printf("%s, tilefwno ", thesi[i].onomatepwnumo);

                for (j=0; j<10;j++) {
                        printf("%hu", thesi[i].tilefwno[j]);
                }
                printf(", sth thesi %u.\n", thesi[i].arithmos_thesis);
            }
        }
    }

    /* Προβολη λιστας κατα αλφαβητικη σειρα. */
    else if (i == 2){
            // Ταξινονηση κατα αλφαβητικη σειρα
            while (swap){   //οσο εχει γινει τουλαχιστον μια αλλαγη
                swap =0;    //αρχικα το μηδενιζουμε
                for (i=0; i<max-1;i++){
                        if (strcmp(thesi[i].onomatepwnumo, thesi[i+1].onomatepwnumo)>0){  // εαν το ονοματεπωνυμο του i αλφαβητικα επεται του i+1

                            /* Ανταλλαγη στοιχειων onomatepwnumo */
                            strcpy(temp_onomatepwnumo, thesi[i+1].onomatepwnumo);         // προσωρινη αποθηκευση του onomatepwnumo του i+1
                            strcpy(thesi[i+1].onomatepwnumo, thesi[i].onomatepwnumo);     // το onomatepwnumo του i+1 παιρνει το onomatepwnumo του i
                            strcpy(thesi[i].onomatepwnumo, temp_onomatepwnumo);           // το onomatepwnumo του i παιρνει το onomatepwnumo του i+1 μεσω του temp_onomatepwnumo

                            /* Ανταλλαγη στοιχειων tilefwno */
                            for (j=0; j<10;j++) {                                     // Ιδια διαδικασια μονο που θα χρειαστει να το κανουμε ψηφιο προς ψηφιο
                                    temp_tilefwno[j]=thesi[i+1].tilefwno[j];          // αρκει ισοτητα γιατι ειναι integer και οχι string
                                    thesi[i+1].tilefwno[j]=thesi[i].tilefwno[j];
                                    thesi[i].tilefwno[j]=temp_tilefwno[j];
                            }

                            /* Ανταλλαγη στοιχειων arithmos thesis.  */
                            temp_thesi = thesi[i+1].arithmos_thesis;                // Ιδια διαδικασια με onomatepwnumo. Aρκει ισοτητα γιατι ειναι integer
                            thesi[i+1].arithmos_thesis = thesi[i].arithmos_thesis;
                            thesi[i].arithmos_thesis = temp_thesi;

                            swap=1;         // εαν υπηρξε εστω μια ανταλλαγη ισουτε με 1 ωστε να επαναλυφθει η διαδικασια
                        }
                }
            }



        //για εμφανιση στην οθονη
            for (i=0; i<max;i++){
                if (thesi[i].onomatepwnumo[0] != '\0'){
                    printf("%s, tilefwno ", thesi[i].onomatepwnumo);

                    for (j=0; j<10;j++) {
                            printf("%hu", thesi[i].tilefwno[j]);
                    }
                    printf(", sth thesi %u.\n", thesi[i].arithmos_thesis);
                }
        }

        // Επαναφορα στην αρχικη κατασταση του πινακα, ταξινομημενο κατα αριθμο θεσης. Παρομοια λογικη με σορταρισμα κατα ονομα
        swap=1;
        while (swap){
                swap =0;
                for (i=0; i<max-1;i++){
                        if (thesi[i].arithmos_thesis > thesi[i+1].arithmos_thesis){
                            strcpy(temp_onomatepwnumo, thesi[i+1].onomatepwnumo);
                            strcpy(thesi[i+1].onomatepwnumo, thesi[i].onomatepwnumo);
                            strcpy(thesi[i].onomatepwnumo, temp_onomatepwnumo);

                            for (j=0; j<10;j++) {
                                    temp_tilefwno[j]=thesi[i+1].tilefwno[j];
                                    thesi[i+1].tilefwno[j]=thesi[i].tilefwno[j];
                                    thesi[i].tilefwno[j]=temp_tilefwno[j];
                            }

                            temp_thesi = thesi[i+1].arithmos_thesis;
                            thesi[i+1].arithmos_thesis = thesi[i].arithmos_thesis;
                            thesi[i].arithmos_thesis = temp_thesi;

                            swap=1;
                        }
                }
            }


    }
}

/* Τερματισμος με αποθηκευση πρωτα στοιχειων λεοφωρειου και κρατησεις στο txt */
char termatismos_apothikeusi(EPIBATIS thesi[], char pinakida[], int max, int i, int j){
    List epibatis,tmp,start=NULL;       // Το start χρειαζεται για την linked list οπου αποθηκευσουμε τη θεση που ξεκινα η λιστα.
    char temp_onomatepwnumo[40];
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;
    int swap=1;

    /* Κανουμε πρωτα ταξινομηση αλφαβητικη οπως στην επιλογη 4*/
    while (swap){
            swap =0;
            for (i=0; i<max-1;i++){
                    if (strcmp(thesi[i].onomatepwnumo, thesi[i+1].onomatepwnumo)>0){
                        strcpy(temp_onomatepwnumo, thesi[i+1].onomatepwnumo);
                        strcpy(thesi[i+1].onomatepwnumo, thesi[i].onomatepwnumo);
                        strcpy(thesi[i].onomatepwnumo, temp_onomatepwnumo);

                        for (j=0; j<10;j++) {
                                temp_tilefwno[j]=thesi[i+1].tilefwno[j];
                                thesi[i+1].tilefwno[j]=thesi[i].tilefwno[j];
                                thesi[i].tilefwno[j]=temp_tilefwno[j];
                        }

                        temp_thesi = thesi[i+1].arithmos_thesis;
                        thesi[i+1].arithmos_thesis = thesi[i].arithmos_thesis;
                        thesi[i].arithmos_thesis = temp_thesi;

                        swap=1;
                    }
            }
    }

    //printf("Teleiwse taksinomisi\n");
    // Περναμε τα στοιχεια στη linked list
    for (i=0;i<max;i++){
        if (thesi[i].onomatepwnumo[0] != '\0'){     // Εφοσον δεν ειναι ισο με '\0', δηλαδη εφοσον ειναι κρατημενη η θεση
            epibatis = (Node *) malloc (sizeof(Node));      // Δεσμευουμε μνημη για το προσωρινο epibatis
            epibatis->next = NULL;                          // Αρχικοποιουμε με NULL το πεδιο nexy
            strcpy(epibatis->onomatepwnumo,thesi[i].onomatepwnumo);     // Τραβαμε τα στοιχεια της θεσης i του πινακα
            epibatis->arithmos_thesis = thesi[i].arithmos_thesis;

            for (j=0; j<10;j++){
                epibatis->tilefwno[j] = thesi[i].tilefwno[j];

            //printf("Teleiwse prosorini apothikeusi tou %d\t", i);

            }



            if (start ==NULL) start = epibatis;     // Για το αρχικο node
            else {                                  // Προσθετουμε ενα node στο τελος της λιστας
                tmp = start;
                while (tmp->next !=NULL) tmp=tmp->next;
                tmp->next = epibatis;
            }
            //printf("\nTeleiwse metafora tou %d", i);
        }

    }
    //printf("\nTeleiwse oloklhrh thn metafora");

    // για αποθηκευση των μεταβλητων στο bus.txt
    FILE *lewforeio;

    lewforeio = fopen("bus.txt", "w");

    if (lewforeio == NULL){ //τερματιζει αν δεν υπαρχει αρχειο
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }

    // αποθηκευω πινακιδα και μεγεθος λεοφωρειου
    fprintf(lewforeio, "%s %d", pinakida, max);

    //αποθηκευω τις κρατησεις
    tmp =start;
    while(tmp != NULL){
            fprintf(lewforeio, "\n%s %u ", tmp->onomatepwnumo, tmp->arithmos_thesis); // Τις αποθηκευω προσωρινα
            for (j=0; j<10; j++){       //ωστε καθε ψηφιο να αποθηκευτει σε διαφορετικη θεση του πινακα temp_tilewno
                    fprintf(lewforeio, "%1hu", tmp->tilefwno[j]);
            }
    tmp=tmp->next;
    }

    fclose(lewforeio);

    printf("\nZitisate eksodo. Ta dedomena sas apothikeytikan sto arxeio bus.txt\n");

}

int main(){
    EPIBATIS *thesi; // ΠΡΟΣΟΧΗ!!! Ξεκινα απο μηδεν. Οταν εμφανιζεις στο χρηστη θα πρεπει να προσθετεις ενα.
    char *pinakida[8], found, temp_onoma[40], temp_epitheto[40];
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;
    int *max, kenes, i, j = 0, epilogi = -1;

    max = (int *) malloc(sizeof(int));  // Δεσμευουμε αναγκαια μνημη
    *pinakida = (char *) malloc(8*sizeof(char));


    initialize_arithmos_thesewn(&max);  // Για να τραβηξουμε τον μεγιστο αριθμο θεσεων

    thesi = (EPIBATIS *) malloc (*max * sizeof(EPIBATIS));  // Δεσμευουμε αναγκαια μνημη για max θεσεις λεωφορειου

    for (i=0; i<*max ; i++){ // γεμιζω με κενες θεσεις μεχρι και τη μεγιστη θεση που εχει το λεοφωρειο
        thesi[i].onomatepwnumo[0] = '\0';
        thesi[i].arithmos_thesis = i+1;
        thesi[i].tilefwno[0] = -1 ;
    }

    read_file(thesi, pinakida);     // Για να περασουμε τα δεδομενα απο το txt

    printf("Dwsate lewforeio %d thesewn kai pinakida %s.\n", *max, *pinakida);


    while (epilogi!=0){     // Επαναλαμβανεται μεχρι να ζητησει εξοδο ο χρηστης

            menu();
            printf("\nDwste arithmo epilogis: ");
            scanf("%d", &epilogi);   // Ζηταμε απο το χρηστη να δωσει την επιλογη του και αναλογως προχωραμε σε ενα απο τα παρακατω


            if (epilogi == 1) emfanisi_kenwn(thesi, *max, i, kenes);       // Για εμφανιση κενων θεσεων
            else if (epilogi == 2) kratisi_thesis(thesi, *max, i, j);       // Για κρατηση θεσης
            else if (epilogi == 3) anazitisi_kratisis(thesi, *max, i, j);   // Για αναζητηση θεσης
            else if (epilogi == 4) akurwsi_kratisis(thesi, *max, i, j);     // Για ακυρωση κρατησης
            else if (epilogi == 5) emfanisi_listas(thesi, *max, i, j);      // Για εμφανιση λιστας κρατησεων
            else if (epilogi == 0) termatismos_apothikeusi(thesi, *pinakida, *max, i, j);   // Για τερμετισμο και αποθηκευση
            else printf("\nDen uparxei drasthriothta %d.\nDwste mia apo tis parakatw epiloges:", epilogi);  // Στην περιπτωση που εδωσε κατι λαθος ο χρηστης

    }

}

