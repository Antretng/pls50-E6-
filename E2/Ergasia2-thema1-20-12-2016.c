#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* ���� ��� �������� �������*/
typedef struct {
   char onomatepwnumo[40];          // �� ������������� (������� ���� �����)
   unsigned int arithmos_thesis;              // � ������� ��� ����� ��� ����� �������
   unsigned short tilefwno[10];      // �� ��������
   } EPIBATIS;


/* �� ����� �� ��� �������������� ��� �������� � ������� */
int menu(){
    printf("\n\n1. Emfanisi kenwn thesewn\n");
    printf("2. Epilexte thesi gia kratisi\n");
    printf("3. Euresh krathshs epibath (onoma h thlefwno)\n");
    printf("4. Akurwsh krathshs\n");
    printf("5. Emfanisi krathsewn\n");
    printf("0. Termatismos \n");
}

/* ��� �������� ��� ���������� ��� ��������� ��� ���������� ��� txt */
char read_file(EPIBATIS thesi[], char *pinakida[], int *max){
    /* ��� ������� ��� ���������� ��� �� bus.txt*/
    char found, temp_onoma[40], temp_epitheto[40];
    unsigned short temp_tilefwno[10];
    unsigned int temp_thesi;
    int i, j;

    FILE *lewforeio;

    lewforeio = fopen("bus.txt", "r");

    if (lewforeio == NULL){ /*���������� �� ��� ������� ������ */
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }
    /* ������ �������� ��� ������� ����������*/
    fscanf(lewforeio, "%s %d", *pinakida, *max);



    /* ���������� ���������� ���������� ��� �� ��������������� ��� onomatepwnumo */
    for (i=0; i<40;i++){
        temp_epitheto[i] = '\0';
        temp_onoma[i] = '\0';
    }
    for (i=0; i<=10;i++){
        temp_tilefwno[i] = '\0';
    }
     temp_thesi = -1;


    /*������ ��� ���������*/
    while (!feof(lewforeio)){

        fscanf(lewforeio, "\n%s %s %u ", temp_epitheto, temp_onoma, &temp_thesi); // ��� ��������� ���������

        for (i=0; i<10; i++){       //���� ���� ����� �� ����������� �� ����������� ���� ��� ������ temp_tilewno
                fscanf(lewforeio, "%1hu", &temp_tilefwno[i]);
        }


        i = 0;
        found = '0';
        while (found!= '1'){            // ������ ����� �� �������� ��� ����������� � ����. ������� �� ������ ���� ������.
            if (i==temp_thesi-1){        // �������, �� ������ �������� ��� 0 ��� ��� 1. ����� ������ 1 ��� �����������

                strcpy(thesi[i].onomatepwnumo, temp_epitheto);
                strcat(thesi[i].onomatepwnumo, " ");
                strcat(thesi[i].onomatepwnumo, temp_onoma);

                thesi[i].arithmos_thesis = temp_thesi;

                for (j=0; j<10;j++) {                           // ���� ���� ���� ��� tilefwno �� ���� ��� �����.
                        thesi[i].tilefwno[j] = temp_tilefwno[j];
                }
                found = '1';            // ������� �� ��� ������ ������� ��� �� ���������� �� loop.
            }
            i++;
        }
    }

    fclose(lewforeio);

}

/* ������� 1 �������� ��������� ������� ����� ������ ��� ������������� ������ ������� ����*/
int emfanisi_kenwn(EPIBATIS thesi[], int max, int i, int kenes){
    kenes = 0;
    printf("\nKenes theseis einai oi: ");
    for (i=0; i<max;i++){          // ���������� �� ������ ��� �� ����� ����� �� max
            if (thesi[i].onomatepwnumo[0] == '\0'){  // ��� ��� ����� ���� �� onomatepwnumo
                printf("%d ", i+1);                 // ���� ��� ������ ��� ������ ��� ������ +1 ���� �� ����������� ���� ������ ��� �����

                ++kenes;     // ������ ��� ������� ����� ������ ���� 1.
            }
    }
    if (kenes>0) printf("\n\nSunolika einai %d kenes theseis", kenes);
    else printf("\n\nDen uparxoun kenese theseis");     // ��� �� kenes ��� ����� ����� ���������� ��� ������� ���� ��� ������ ����� ������

}

/* ������� 2 "������� ����� �� ������������ ������" */
int kratisi_thesis(EPIBATIS thesi[], int max, int i, int j){
    char temp_epitheto[40], temp_onoma[40];
    printf("\nPoia thesi thelete na kanete kratisi?\n");
    scanf("%d", &i);
    --i;    // ������ 1 ����� � ������� ������ ��� �����

    if (i<=max && i>= 0 && thesi[i].onomatepwnumo[0] != '\0') printf("H thesi %d einai kratimeni.\n", i+1); //������� �� ����� ��������

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
    else printf("Dwsate arithmo ektos oriwn tou lewforeiou\n");

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
                printf("H thesi %d einai kratimeni ston %s poy anazitisate.\n", i+1, thesi[i].onomatepwnumo);
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
                    match = '0';        // ��������� ����� ���� �����. �� ������ ��� ����� ���� ������� �����
                }
            if (match == '1') {         // �� ��������� ��� �� 1 ���� ��� �������� ������ ����� => �� �������� ��� �������
                printf("H thesi %d einai kratimeni sto tilefwno poy anazitisate.\n", i+1);
                found = '1';            // �� ������ ���� ��� ��� ������� ������� ��� �� 1.
            }
        }
        if (found == '0') printf("Den uparxoun kratiseis me ton arithmo pou zitisate.\n");      // �� ��������� ��� �� 0 ���� ��� ������� ����� �������
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

/* ������� 5 �������� ������ ���������� ������ ������������ ���� ������ ����� */
int emfanisi_listas(EPIBATIS thesi[], int max, int i, int j){

/* ������� ������ ��������� ���� ������ �����. */
for (i=0; i<max;i++){
        if (thesi[i].onomatepwnumo[0] != '\0'){     //����������� ���� ��� ����������. ��� ��� ����������� ����� ��� ����� '\0'
            printf("%s, tilefwno ", thesi[i].onomatepwnumo);

            for (j=0; j<10;j++) {
                    printf("%hu", thesi[i].tilefwno[j]);
            }
            printf(", sth thesi %u.\n", thesi[i].arithmos_thesis);
        }
    }
}

/* ����������� �� ���������� ����� ��������� ���������� ��� ��������� ��� txt */
char termatismos_apothikeusi(EPIBATIS thesi[], char pinakida[], int max, int i, int j){
    char found, temp_onoma[40], temp_epitheto[40], temp_tilefwno[11];
    unsigned int temp_thesi;

    /* ��� ���������� ��� ���������� ��� bus.txt*/
    FILE *lewforeio;
    lewforeio = fopen("bus.txt", "w");

    if (lewforeio == NULL){ /*���������� �� ��� ������� ������ */
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }

    /* ��������� �������� ��� ������� ����������*/
    fprintf(lewforeio, "%s %d", pinakida, max);

    /*��������� ��� ���������*/
    for (i =0; i<max;i++)
        if (thesi[i].onomatepwnumo[0]!='\0'){

            fprintf(lewforeio, "\n%s %u ", thesi[i].onomatepwnumo, thesi[i].arithmos_thesis); // ��� ��������� ���������

            for (j=0; j<10; j++){       //���� ���� ����� �� ����������� �� ����������� ���� ��� ������ temp_tilewno
                    fprintf(lewforeio, "%1hu", thesi[i].tilefwno[j]);
            }

    }

    fclose(lewforeio);
    printf("\nZitisate eksodo. Ta dedomena sas apothikeytikan sto arxeio bus.txt\n");
}

int main(){
    EPIBATIS thesi[53]; // �������!!! ������ ��� �����. ���� ���������� ��� ������ �� ������ �� ���������� ���.
    char *pinakida[8];
    int  *max;
    int  kenes, i, j, epilogi = -1;

    max = (int *) malloc(sizeof(int));  // ���������� �������� �����
    *pinakida = (char *) malloc(8*sizeof(char));

    /* ���������� �� ������ ��������� */
    for (i=0; i<53;i++){  // ������ �� ����� ������ ����� ��� �� ������� ���� ��� ���� �� ���������
        thesi[i].onomatepwnumo[0] = '\0';
        thesi[i].arithmos_thesis = -1 ;
        thesi[i].tilefwno[0] = -1 ;
    }

    read_file(thesi, pinakida, &max);   // ��� �� ��������� �� �������� ��� �� txt

    printf("Dwsate lewforeio %d thesewn kai pinakida %s.\n", *max, *pinakida);

    while (epilogi!=0){     // ��������������� ����� �� ������� ����� � �������
            menu();
            printf("\nDwste arithmo epilogis: ");
            scanf("%d", &epilogi); // ������ ��� �� ������ �� ����� ��� ������� ��� ��� �������� ��������� �� ��� ��� �� ��������

            if (epilogi == 1) emfanisi_kenwn(thesi, *max, i, kenes);        // ��� �������� ����� ������
            else if (epilogi == 2) kratisi_thesis(thesi, *max, i, j);       // ��� ������� �����
            else if (epilogi == 3) anazitisi_kratisis(thesi, *max, i, j);   // ��� ��������� �����
            else if (epilogi == 4) akurwsi_kratisis(thesi, *max, i, j);     // ��� ������� ��������
            else if (epilogi == 5) emfanisi_listas(thesi, *max, i, j);      // ��� �������� ������ ���������
            else if (epilogi == 0) termatismos_apothikeusi(thesi, *pinakida, *max, i, j); // ��� ���������� ��� ����������
            else printf("\nDen uparxei drasthriothta %d.\nDwste mia apo tis parakatw epiloges:", epilogi);  // ���� ��������� ��� ����� ���� ����� � �������
    }

}
