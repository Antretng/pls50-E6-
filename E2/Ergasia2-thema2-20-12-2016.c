#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* ���� ��� �������� �������*/
typedef struct{
   char onomatepwnumo[40];          // �� ������������� (������� ���� �����)
   unsigned int arithmos_thesis;              // � ������� ��� ����� ��� ����� �������
   unsigned short tilefwno[10];      // �� ��������
} EPIBATIS;

/*��� ��� ����� ���� � ������ ���� Linked list*/
typedef struct epib{
   char onomatepwnumo[40];          // �� ������������� (������� ���� �����)
   unsigned int arithmos_thesis;              // � ������� ��� ����� ��� ����� �������
   unsigned short tilefwno[10];      // �� ��������
   struct epib *next;
} Node, *List;

/* ����� �������� */
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

    // ��� ������� ��� ���������� ��� �� bus.txt
    FILE *leofwreio;
    leofwreio = fopen("bus.txt", "r");

    if (leofwreio == NULL){ //���������� �� ��� ������� ������
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }

    // ������ �������� ��� ������� ����������
    fscanf(leofwreio, "%s %d\n", temp_pinakida, *max);

    fclose(leofwreio);

}

EPIBATIS read_file(EPIBATIS *thesi, char *pinakida[]){
    char found, temp_onoma[40], temp_epitheto[40], temp_max;
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;
    int i, j;

    // ��� ������� ��� ���������� ��� �� bus.txt
    FILE *leofwreio;
    leofwreio = fopen("bus.txt", "r");

    if (leofwreio == NULL){ //���������� �� ��� ������� ������
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }

    // ������ �������� ��� ������� ����������

    fscanf(leofwreio, "%s %d\n", *pinakida, &temp_max);



    while (!feof(leofwreio)){
            fscanf(leofwreio, "%s %s %u ", temp_epitheto, temp_onoma, &temp_thesi); // ��� ��������� ���������

            for (i=0; i<9; i++){                                 //���� ���� ����� �� ����������� �� ����������� ���� ��� ������ temp_tilewno
                    fscanf(leofwreio, "%1hu", &temp_tilefwno[i]);
            }
            fscanf(leofwreio, "%1hu\n", &temp_tilefwno[9]);    // ������� ��� �� ������ �� \n ����������� �� ��������� ��� ��������� ����� �� ������ ��� ��� �� ��� �� �������� ��� \n �����


            found = '0';
            for (i=0;i<temp_max && found!='1';i++){                  // ������ ����� �� �������� ��� ����������� � ����. ������� �� ������ ���� ������.

                if (thesi[i].arithmos_thesis == temp_thesi){           // �������, �� ������ �������� ��� 0 ��� ��� 1. ����� ������ 1 ��� �����������

                    strcpy(thesi[i].onomatepwnumo, temp_epitheto);
                    strcat(thesi[i].onomatepwnumo, " ");
                    strcat(thesi[i].onomatepwnumo, temp_onoma);

                    for (j=0; j<10;j++) {                       // ���� ���� ���� ��� tilefwno �� ���� ��� �����.
                            thesi[i].tilefwno[j] = temp_tilefwno[j];
                    }
                    found = '1';                                // ������� �� ��� ������ ������� ��� �� ���������� �� loop.
                }

            }

    }


    fclose(leofwreio);

}

/* ������� 1 �������� ��������� ������� ����� ������ ��� ������������� ������ ������� ����*/
int emfanisi_kenwn(EPIBATIS thesi[], int max, int i, int kenes){
    kenes = 0;
    printf("\nKenes theseis einai oi: ");
    for (i=0; i<max;i++){          // ���������� �� ������ ��� �� ����� ����� �� max
            if (thesi[i].onomatepwnumo[0] == '\0'){       // ��� ��� ����� ����
                printf("%u ", thesi[i].arithmos_thesis);  // ���� ��� ������ ��� �����

                ++kenes;     // ������ ��� ������� ����� ������ ���� 1
            }
    }
    if (kenes>0) printf("\n\nSunolika einai %d kenes theseis", kenes);
    else printf("\n\nDen uparxoun kenes theseis");     // ��� �� kenes ��� ����� ����� ���������� ��� ������� ���� ��� ������ ����� ������

}

/* ������� 2 "������� ����� �� ������������ ������ */
int kratisi_thesis(EPIBATIS thesi[], int max, int i, int j){
    char temp_epitheto[40], temp_onoma[40];
    printf("\nPoia thesi thelete na kanete kratisi?\n");
    scanf("%d", &i);
    --i;    // ������ 1 ����� � ������� ������ ��� �����

    if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] != '\0') printf("H thesi %u einai kratimeni.\n", thesi[i].arithmos_thesis); //������� �� ����� ��������

    /* ���������� ��������� */
    else if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] == '\0') {
            thesi[i].arithmos_thesis = i+1;  // ��� �� �������� �� ����������� �������� ���� ���� �� ����� ����� = ������ �����

            printf("Dwste epitheto (prwto gramma kefalaio): ");
            scanf("%s", temp_epitheto);
            printf("Dwste onoma (prwto gramma kefalaio): ");
            scanf("%s", temp_onoma);


            strcpy(thesi[i].onomatepwnumo, temp_epitheto); //��� �� ������������ ��� ����� onomatepwnumo
            strcat(thesi[i].onomatepwnumo, " ");
            strcat(thesi[i].onomatepwnumo, temp_onoma);

            printf("Dwste tilefwno (10 psifia): "); //���� ���� ����� �� ����������� �� ����������� ���� ��� ������ tilewno
            for (j=0; j<10; j++){
                    scanf("%1hu", &thesi[i].tilefwno[j]);
            }

    }
    else printf("Dwsate arithmo ektos oriwn tou leofwreiou\n");

}

/* ������� 3 ��������� �������� (���� �� ������������� ���� �� ��������)*/
int anazitisi_kratisis(EPIBATIS thesi[], int max, int i, int j){
    char temp_epitheto[40], temp_onoma[40], found ='0', match;
    unsigned short temp_tilefwno[10];

    /* ������ ��� ������ �� ����� ������� �� ������������� � �������� ��� ����� 1 � 2 ���������� */
    printf("\nAnazitisi krathshs. Dwste\n1 gia anazitisi me onomatepwnumo\n2 gia anazitisi me tilefwno\n");
    scanf("%d", &i);

    /* ��������� �� ������������� */
    if (i == 1) {
        printf("Dwste epitheto (prwto gramma kefalaio): ");
        scanf("%s", temp_epitheto);
        printf("Dwste onoma (prwto gramma kefalaio): ");
        scanf("%s", temp_onoma);

        //��� �� ��������� �� �� ����� onomatepwnumo
        strcat(temp_epitheto, " ");
        strcat(temp_epitheto, temp_onoma);

        /* �� ������� ���� ��� ������ ��� ����� ���������� ��� �������������.  */
        for (i=0; i<max;i++)
            if(strcmp(temp_epitheto, thesi[i].onomatepwnumo)==0) {// ��� ����� ���� �� ����� ��� �� ����� ����� ���� �������
                printf("H thesi %u einai kratimeni ston %s poy anazitisate.\n", thesi[i].arithmos_thesis, thesi[i].onomatepwnumo);
                found = '1';
            }

        if (found == '0') printf("Den uparxoun kratiseis sto onomatepwnumo %s pou zitisate.\n", temp_epitheto);
    }

    /* ��������� �� �������� */
    if (i == 2) {

        printf("Dwste tilefwno (10 psifia): "); //���� ���� ����� �� ����������� �� ����������� ���� ��� ������ tilewno
            for (j=0; j<10; j++){
                    scanf("%1hu", &temp_tilefwno[j]);
            };

        for (i=0; i<max;i++){
            match = '1' ;  //�� ���������� 1 => ��� �� ����� ���� => ������ �� ����
            for (j=0; j<10 && match != '0'; j++)
                if (temp_tilefwno[j] != thesi[i].tilefwno[j]) {
                    match = '0';    // ��������� ����� ���� �����. �� ������ ��� ����� ���� ������� �����
                }
            if (match == '1') {     // �� ��������� ��� �� 1 ���� ��� �������� ������ ����� => �� �������� ��� �������
                printf("H thesi %d einai kratimeni sto tilefwno poy anazitisate.\n", i+1);
                found = '1';        // �� ������ ���� ��� ��� ������� ������� ��� �� 1.
            }
        }
        if (found == '0') printf("Den uparxoun kratiseis me ton arithmo pou zitisate.\n");  // �� ��������� ��� �� 0 ���� ��� ������� ����� �������
    }

}

/* ������� 4 ������� �������� (�� ������ �����)*/
int akurwsi_kratisis(EPIBATIS thesi[], int max, int i, int j){
    char temp_epitheto[40], temp_onoma[40];

    /* ������ ��� ����������� ��� ������ ����� ��� ����� � ������� */
    printf("\nPoia thesi thelete na akurwsete thn kratisi?\n");
    scanf("%d", &i);
    --i;    // ������ ��� ��� �� ���������� � �������� ��� ������ �� ��� ������

    if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] == '\0')
        printf("H thesi %i den einai kratimeni.\n", i); //������� �� ����� ��������

    /* ������� ��������� ����� ��� ����� */
    else if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] != '\0') {
            for (j=0; j<40; j++){
                    thesi[i].onomatepwnumo[j] = '\0';
            }
            for (j=0; j<10; j++){
                    thesi[i].tilefwno[j]= -1;
            }
    printf("H krathsh sth thesi %u akurwthike.\n", thesi[i].arithmos_thesis);
    }
    else printf("Dwsate arithmo ektos oriwn tou leofwreiou\n");  // ��� ��������� ��� � ���� ����� <0 � >�������� �������

}

/* ������� 5 �������� ������ ���������� ������ ������������ ���� ������ ����� � �������������*/
int emfanisi_listas(EPIBATIS thesi[], int max, int i, int j){
    int swap=1;
    char temp_onomatepwnumo[40];
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;

    /* ������ �� ������ �� ���������� �����. �� ����� 1 ����� ���� ������ ����� ��� 2 ���� ������������� */
    printf("Pws thelete na emfanisete th lista?\nDwste:\n\t1 gia probolh listas taksinomimenh kata thesi.\n\t2 gia probolh listas taksinomimenh kata onomatepwnumo.\n");
    scanf("%d", &i);

    /* ������� ������ �� ���������� ���� ������ �����. */
    /* ������ ����� ��� ������������ ����, ��������� ���� �������� ��� */
    if (i == 1){
        for (i=0; i<max;i++){
            if (thesi[i].onomatepwnumo[0] != '\0'){  //����������� ���� ��� ����������. ��� ��� ����������� ����� ��� ����� '\0'
                printf("%s, tilefwno ", thesi[i].onomatepwnumo);

                for (j=0; j<10;j++) {
                        printf("%hu", thesi[i].tilefwno[j]);
                }
                printf(", sth thesi %u.\n", thesi[i].arithmos_thesis);
            }
        }
    }

    /* ������� ������ ���� ���������� �����. */
    else if (i == 2){
            // ���������� ���� ���������� �����
            while (swap){   //��� ���� ����� ����������� ��� ������
                swap =0;    //������ �� �����������
                for (i=0; i<max-1;i++){
                        if (strcmp(thesi[i].onomatepwnumo, thesi[i+1].onomatepwnumo)>0){  // ��� �� ������������� ��� i ���������� ������ ��� i+1

                            /* ��������� ��������� onomatepwnumo */
                            strcpy(temp_onomatepwnumo, thesi[i+1].onomatepwnumo);         // ��������� ���������� ��� onomatepwnumo ��� i+1
                            strcpy(thesi[i+1].onomatepwnumo, thesi[i].onomatepwnumo);     // �� onomatepwnumo ��� i+1 ������� �� onomatepwnumo ��� i
                            strcpy(thesi[i].onomatepwnumo, temp_onomatepwnumo);           // �� onomatepwnumo ��� i ������� �� onomatepwnumo ��� i+1 ���� ��� temp_onomatepwnumo

                            /* ��������� ��������� tilefwno */
                            for (j=0; j<10;j++) {                                     // ���� ���������� ���� ��� �� ��������� �� �� ������� ����� ���� �����
                                    temp_tilefwno[j]=thesi[i+1].tilefwno[j];          // ����� ������� ����� ����� integer ��� ��� string
                                    thesi[i+1].tilefwno[j]=thesi[i].tilefwno[j];
                                    thesi[i].tilefwno[j]=temp_tilefwno[j];
                            }

                            /* ��������� ��������� arithmos thesis.  */
                            temp_thesi = thesi[i+1].arithmos_thesis;                // ���� ���������� �� onomatepwnumo. A���� ������� ����� ����� integer
                            thesi[i+1].arithmos_thesis = thesi[i].arithmos_thesis;
                            thesi[i].arithmos_thesis = temp_thesi;

                            swap=1;         // ��� ������ ���� ��� ��������� ������ �� 1 ���� �� ����������� � ����������
                        }
                }
            }



        //��� �������� ���� �����
            for (i=0; i<max;i++){
                if (thesi[i].onomatepwnumo[0] != '\0'){
                    printf("%s, tilefwno ", thesi[i].onomatepwnumo);

                    for (j=0; j<10;j++) {
                            printf("%hu", thesi[i].tilefwno[j]);
                    }
                    printf(", sth thesi %u.\n", thesi[i].arithmos_thesis);
                }
        }

        // ��������� ���� ������ ��������� ��� ������, ������������ ���� ������ �����. �������� ������ �� ���������� ���� �����
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

/* ����������� �� ���������� ����� ��������� ���������� ��� ��������� ��� txt */
char termatismos_apothikeusi(EPIBATIS thesi[], char pinakida[], int max, int i, int j){
    List epibatis,tmp,start=NULL;       // �� start ���������� ��� ��� linked list ���� ������������� �� ���� ��� ������ � �����.
    char temp_onomatepwnumo[40];
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;
    int swap=1;

    /* ������� ����� ���������� ���������� ���� ���� ������� 4*/
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
    // ������� �� �������� ��� linked list
    for (i=0;i<max;i++){
        if (thesi[i].onomatepwnumo[0] != '\0'){     // ������ ��� ����� ��� �� '\0', ������ ������ ����� ��������� � ����
            epibatis = (Node *) malloc (sizeof(Node));      // ���������� ����� ��� �� ��������� epibatis
            epibatis->next = NULL;                          // ������������� �� NULL �� ����� nexy
            strcpy(epibatis->onomatepwnumo,thesi[i].onomatepwnumo);     // ������� �� �������� ��� ����� i ��� ������
            epibatis->arithmos_thesis = thesi[i].arithmos_thesis;

            for (j=0; j<10;j++){
                epibatis->tilefwno[j] = thesi[i].tilefwno[j];

            //printf("Teleiwse prosorini apothikeusi tou %d\t", i);

            }



            if (start ==NULL) start = epibatis;     // ��� �� ������ node
            else {                                  // ����������� ��� node ��� ����� ��� ������
                tmp = start;
                while (tmp->next !=NULL) tmp=tmp->next;
                tmp->next = epibatis;
            }
            //printf("\nTeleiwse metafora tou %d", i);
        }

    }
    //printf("\nTeleiwse oloklhrh thn metafora");

    // ��� ���������� ��� ���������� ��� bus.txt
    FILE *lewforeio;

    lewforeio = fopen("bus.txt", "w");

    if (lewforeio == NULL){ //���������� �� ��� ������� ������
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }

    // ��������� �������� ��� ������� ����������
    fprintf(lewforeio, "%s %d", pinakida, max);

    //��������� ��� ���������
    tmp =start;
    while(tmp != NULL){
            fprintf(lewforeio, "\n%s %u ", tmp->onomatepwnumo, tmp->arithmos_thesis); // ��� ��������� ���������
            for (j=0; j<10; j++){       //���� ���� ����� �� ����������� �� ����������� ���� ��� ������ temp_tilewno
                    fprintf(lewforeio, "%1hu", tmp->tilefwno[j]);
            }
    tmp=tmp->next;
    }

    fclose(lewforeio);

    printf("\nZitisate eksodo. Ta dedomena sas apothikeytikan sto arxeio bus.txt\n");

}

int main(){
    EPIBATIS *thesi; // �������!!! ������ ��� �����. ���� ���������� ��� ������ �� ������ �� ���������� ���.
    char *pinakida[8], found, temp_onoma[40], temp_epitheto[40];
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;
    int *max, kenes, i, j = 0, epilogi = -1;

    max = (int *) malloc(sizeof(int));  // ���������� �������� �����
    *pinakida = (char *) malloc(8*sizeof(char));


    initialize_arithmos_thesewn(&max);  // ��� �� ���������� ��� ������� ������ ������

    thesi = (EPIBATIS *) malloc (*max * sizeof(EPIBATIS));  // ���������� �������� ����� ��� max ������ ����������

    for (i=0; i<*max ; i++){ // ������ �� ����� ������ ����� ��� �� ������� ���� ��� ���� �� ���������
        thesi[i].onomatepwnumo[0] = '\0';
        thesi[i].arithmos_thesis = i+1;
        thesi[i].tilefwno[0] = -1 ;
    }

    read_file(thesi, pinakida);     // ��� �� ��������� �� �������� ��� �� txt

    printf("Dwsate lewforeio %d thesewn kai pinakida %s.\n", *max, *pinakida);


    while (epilogi!=0){     // ��������������� ����� �� ������� ����� � �������

            menu();
            printf("\nDwste arithmo epilogis: ");
            scanf("%d", &epilogi);   // ������ ��� �� ������ �� ����� ��� ������� ��� ��� �������� ��������� �� ��� ��� �� ��������


            if (epilogi == 1) emfanisi_kenwn(thesi, *max, i, kenes);       // ��� �������� ����� ������
            else if (epilogi == 2) kratisi_thesis(thesi, *max, i, j);       // ��� ������� �����
            else if (epilogi == 3) anazitisi_kratisis(thesi, *max, i, j);   // ��� ��������� �����
            else if (epilogi == 4) akurwsi_kratisis(thesi, *max, i, j);     // ��� ������� ��������
            else if (epilogi == 5) emfanisi_listas(thesi, *max, i, j);      // ��� �������� ������ ���������
            else if (epilogi == 0) termatismos_apothikeusi(thesi, *pinakida, *max, i, j);   // ��� ���������� ��� ����������
            else printf("\nDen uparxei drasthriothta %d.\nDwste mia apo tis parakatw epiloges:", epilogi);  // ���� ��������� ��� ����� ���� ����� � �������

    }

}

