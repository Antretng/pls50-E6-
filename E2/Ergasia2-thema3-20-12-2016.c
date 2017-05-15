#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ��� ��� ������ */
typedef struct{
    char xrwma[2], sxima[2], arithmos[2], ufh[2]; // �� �������������� ��� ������
    char enniaio[5];      // string ��� �������� �� ��� ���� �� ��������������
}   KARTES;

/* ��� ���� ������� */
typedef struct{
    char id, onoma[17];
    unsigned int score;
}   PAIKTIS;

/* ��� ������ ��� ����� set */
char test_if_set(KARTES karta[3][4], int prwth_seira, int prwth_sthlh, int deuterh_seira, int deuterh_sthlh, int trith_seira, int trith_sthlh){
    char set='0'; // �� ���� ��� �� �� �����
    int point=0;

    /* ��� ���� �������������� (�� ����� �����, ���� ����� ���) ��������� ��� ����� �� ���� ��� ������ ���� � �� ���� ��� ������ ����������� */
    /* �� ������ ������ ��� �� ��� ��������� �� point ���� 1. ����� ��� ����� ��������� ��� ������������� 4 ��� �� ������� set */

    if (strcmp(karta[prwth_seira][prwth_sthlh].xrwma, karta[deuterh_seira][deuterh_sthlh].xrwma)==0){
                if (strcmp(karta[trith_seira][trith_sthlh].xrwma, karta[deuterh_seira][deuterh_sthlh].xrwma)==0){
                    point++;    // ��� ���� �� ������ ����� ���� ����� ��������� �� point ���� 1
                }
    }

    else if (strcmp(karta[prwth_seira][prwth_sthlh].xrwma, karta[deuterh_seira][deuterh_sthlh].xrwma)!=0){
                if (strcmp(karta[trith_seira][trith_sthlh].xrwma, karta[deuterh_seira][deuterh_sthlh].xrwma)!=0){
                    if (strcmp(karta[trith_seira][trith_sthlh].xrwma, karta[prwth_seira][prwth_sthlh].xrwma)!=0){
                        point++; // ��� �� ���� ��� ������ ����������� ����� ��������� �� point ���� 1
                    }
                }
    }

    if (strcmp(karta[prwth_seira][prwth_sthlh].sxima, karta[deuterh_seira][deuterh_sthlh].sxima)==0){
                if (strcmp(karta[trith_seira][trith_sthlh].sxima, karta[deuterh_seira][deuterh_sthlh].sxima)==0){
                    point++;    // ��� ���� �� ������ ����� ���� ����� ��������� �� point ���� 1
                }
    }

    else if (strcmp(karta[prwth_seira][prwth_sthlh].sxima, karta[deuterh_seira][deuterh_sthlh].sxima)!=0){
                if (strcmp(karta[trith_seira][trith_sthlh].sxima, karta[deuterh_seira][deuterh_sthlh].sxima)!=0){
                    if (strcmp(karta[trith_seira][trith_sthlh].sxima, karta[prwth_seira][prwth_sthlh].sxima)!=0){
                        point++;    // ��� �� ���� ��� ������ ����������� ����� ��������� �� point ���� 1
                    }
                }
    }

    if (strcmp(karta[prwth_seira][prwth_sthlh].arithmos, karta[deuterh_seira][deuterh_sthlh].arithmos)==0){
                if (strcmp(karta[trith_seira][trith_sthlh].arithmos, karta[deuterh_seira][deuterh_sthlh].arithmos)==0){
                    point++;    // ��� ���� �� ������ ����� ���� ������ ��������� �� point ���� 1
                }
    }

    else if (strcmp(karta[prwth_seira][prwth_sthlh].arithmos, karta[deuterh_seira][deuterh_sthlh].arithmos)!=0){
                if (strcmp(karta[trith_seira][trith_sthlh].arithmos, karta[deuterh_seira][deuterh_sthlh].arithmos)!=0){
                    if (strcmp(karta[trith_seira][trith_sthlh].arithmos, karta[prwth_seira][prwth_sthlh].arithmos)!=0){
                        point++;    // ��� �� ���� ��� ������ ����������� ������ ��������� �� point ���� 1
                    }
                }
    }

    if (strcmp(karta[prwth_seira][prwth_sthlh].ufh, karta[deuterh_seira][deuterh_sthlh].ufh)==0){
                if (strcmp(karta[trith_seira][trith_sthlh].ufh, karta[deuterh_seira][deuterh_sthlh].ufh)==0){
                    point++;    // ��� ���� �� ������ ����� ���� ��� ��������� �� point ���� 1
                }
    }

    else if (strcmp(karta[prwth_seira][prwth_sthlh].ufh, karta[deuterh_seira][deuterh_sthlh].ufh)!=0){
                if (strcmp(karta[trith_seira][trith_sthlh].ufh, karta[deuterh_seira][deuterh_sthlh].ufh)!=0){
                    if (strcmp(karta[trith_seira][trith_sthlh].ufh, karta[prwth_seira][prwth_sthlh].ufh)!=0){
                        point++;    // ��� �� ���� ��� ������ ����������� ��� ��������� �� point ���� 1
                    }
                }
    }


    if (point==4) set='1';      // ��� ������������� 4 ���� �������� ��� ������ ���

    return set;
}



/* ������ ������� ������� ������ ������� min ��� max ��� ����� � ������� */
int getRandomNumber(int Min, int Max){
    double rnd= (double)rand()/((double)RAND_MAX+1);
    return   (int)(rnd*(Max-Min+1))+Min;
}


/* ��� �� ������������ ���������� ������ ������ */
KARTES getNextCard(char set_xrwmata[], char set_sximata[], char set_arithmoi[], char set_ufes[]){
    KARTES card;

    // ������ ��� ������� �������� ���� �������� (�� r ��� �������) ��� ����� ������� ��� ��������� ���� �� ��������
    card.arithmos[0]= set_arithmoi[getRandomNumber(0,2)]; // ����� ���� random ���� ���� ���� ��� ������ ��� ������ �� �������� ���
    card.xrwma[0]= set_xrwmata[getRandomNumber(0,2)];
    card.sxima[0]= set_sximata[getRandomNumber(0,2)];
    card.ufh[0]= set_ufes[getRandomNumber(0,2)];

    // ��� �� ����� �� ���� strcpy � strcmp ������ �� ������������ ��� ���������
    // ���� ��� �� �������������� ����� ������� 2 ��������� ���� �� ����� ����������� ��� ��������������
    card.arithmos[1]= '\0';    // ��� �� ������� ��� ����� ��� string '\0'
    card.xrwma[1]= '\0';
    card.sxima[1]= '\0';
    card.ufh[1]= '\0';

    // �� ������� ��� ��� enniaio ���� �� �������� �� �� ��������������� ���������� �� �������� ��� �� printf
    card.enniaio[0]=card.xrwma[0];
    card.enniaio[1]=card.sxima[0];
    card.enniaio[2]=card.arithmos[0];
    card.enniaio[3]=card.ufh[0];
    card.enniaio[4]='\0';
    return card;

}

/* Cheat mode ��� ������ ��� �������� ������ ��� ������ ��� */
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
                                        set = test_if_set(karta, i, j, k, l, w, z); // ��������� ��� 3 ������ �� ����� set
                                        if (set == '1' && print == 1) printf("Set einai %d %d, %d %d, %d %d\n", i, j, k, l, w, z);
                                }
    return set;
}

/* ��� �� ���������� ��� ������ ������ */
char kainourgio_set(KARTES karta[3][4], int i, int j, int k, int l, int dublicate, char set_xrwmata[], char set_sximata[], char set_arithmoi[], char set_ufes[]){
    char set = '0';

    while (set!='1'){
        for (i=0;i<3;i++){
            for (j=0;j<4;j++){
                karta[i][j]= getNextCard(set_xrwmata, set_sximata, set_arithmoi, set_ufes); // ������� draw ��� �����
                dublicate =1;
                while(dublicate != 0){    // ��������������� ����� �� ��� ��������� ��� ���� �����
                        dublicate = 0;
                        for (k=0;k<i && dublicate != 1; k++){          // ������ ��� ���� ��� ��� ������ ����� �� ������ ������ ����
                            for (l=0;l<j && dublicate != 1; l++)
                                if (strcmp(karta[i][j].enniaio,karta[k][l].enniaio)==0){        // ��������� �� ����� ���� �� ������ ��� ��� ������������ ������
                                    karta[i][j] = getNextCard(set_xrwmata, set_sximata, set_arithmoi, set_ufes);  // �� ��� ������� ����������
                                    dublicate =1;   //������ ���� ���� � ���������� ����� ������ �� ����� ���� �� ������ ��� ��� ������������,
                                                    //������� 1 ���� �� ������������ ��� ������ ��� ��� ����
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

    // ���� ������� �������
    paiktis[0].id ='a';
    strcpy(paiktis[0].onoma, "Marina Andreou");
    paiktis[1].id ='g';
    strcpy(paiktis[1].onoma,"Kostas Grammenos");
    paiktis[2].id ='p';
    strcpy(paiktis[2].onoma,"Maria Perdika");

    // ���������� ��� ����������� �� 0
    for (i=0;i<3;i++) paiktis[i].score=0;

    printf("H bathmologia einai h ekshs\n");
    for (i=0;i<3;i++) printf("Id: %c\nOnoma: %s\nScore: %u\n\n", paiktis[i].id, paiktis[i].onoma, paiktis[i].score);

    // ��� ��� �������� ��� ������.  ����������� �� �������� �� ��������� �� while loop �� ������������� �� 1
    epilogi[0] = '1';
    epilogi[1] = '\0';
    while (epilogi[0] !='0'){   // �� �������� ��������������� ����� �� ������� �� �������� (������ �� ����� 0

            /* ������� ���������� ������ ������ */
            printf("\nKainoyrgio set:\n\n");
            kainourgio_set(karta, i, j, k, l, dublicate, set_xrwmata, set_sximata, set_arithmoi, set_ufes);
            set = '0';


            /* ���������� ��������������� ����� �� ����� ������ set */
            while(set!='1'){

                /* ����������� ��� ������ */
                for (i=0;i<3;i++){
                    for (j=0;j<4;j++){
                        //printf("%s ", karta[i][j].enniaio);
                        printf("[%s,%s,%s,%s] ", karta[i][j].xrwma, karta[i][j].sxima, karta[i][j].arithmos, karta[i][j].ufh);
                    }
                    printf("\n");
                }

                printf("\nH arithmisi twn suntetagmenwn ksekina apo 0 \n(px karta prwths seira kai deuterh sthlh einai 0 1)\n");
                /* ������� ����� ������� ������ � �� �� �����������. */
                repeat = '1';     // ���������� �� ����� ��� �� ��������� �� while loop
                while (repeat == '1') {   // � ���������� ��������������� ����� �� ����� ����� ������ id ������ � �����
                        repeat='0';       // ������� repeat =0 . ��� ���������� �� ����� �������� ��� ������ ����� ������� ��� ��������� �� loop
                        printf("\nDwste id paikth h 0 gia eksodo");
                        scanf(" %c", epilogi);

                        if (epilogi[0] == '0'){     // ��� ����� ����� ���� �����. ��������� �� ���� ��� ���������� �� ��������.
                            for (i=0;i<3;i++) printf("Id: %c\nOnoma: %s\nScore: %u\n\n", paiktis[i].id, paiktis[i].onoma, paiktis[i].score);
                           exit(1);
                        }
                        else if (epilogi[0] == 'a') num = 0;        // �������� ��� ������ ������� ����������� ���� ��� num ���� �� �������������� �� ������� ��� ������ ��� �������
                        else if (epilogi[0] == 'g') num = 1;
                        else if (epilogi[0] == 'p') num = 2;
                        else if (epilogi[0] == 'C') {               // Cheat Mode.
                                printf("Cheat mode!");
                                repeat = cheat(karta, i, j, k, l, 1);
                                            // ������ �������� ���� �� cheat, ������� 0 ���� �� ����������� �� loop ��� �� ����� �������.
                        }
                        else {
                            printf("Den uparxei paiktis me id: %s\nDokimaste ksana\n", epilogi);
                            repeat ='1';                  // ����� ������ ����� => ������� 0 ��� �� �����������.
                        }
                }

                /* ����������� �� ����� ��� ������� ������ ��� ��� ����� �� ����� ��� ������������� */
                printf("\n%s dwste tis suntetagmenes twn 3 kartwn.\n", paiktis[num].onoma);

                printf("Syntetagmenes prwths karta.\nSeira: ");
                scanf("%d", &prwth_seira);
                while (prwth_seira<0 | prwth_seira>2){          // �� ���� ��� ������ ��� ������������� ��������� ��� ����� ����� �����.
                    printf("Dwsate arithmo seiras ektos oriwn");
                    printf("\nDwste ksana thn seira ths prwths kartas: ");
                    scanf("%d", &prwth_seira);                  // �� ����� ����� ����� ��� ������ �� ��� ���������.
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

                /* ��� ����� set ������� ��� ���� ��� �� 1. ��� �� ������� ��� ������ �� ����� ��� ������� �� gunction test_if_set */
                set = test_if_set(karta, prwth_seira, prwth_sthlh, deuterh_seira, deuterh_sthlh, trith_seira, trith_sthlh);


                if (set=='1'){      // ��� ����� ��� ����������� ������� ������ ��������� �� ���� ���� 2. ����������� ���� �� ��� ������� ��� ���� 255
                    printf("\nKanate set!!! Duo pontoi gia to paikti me id %c\n", paiktis[num].id);
                    if (paiktis[num].score <254) paiktis[num].score = paiktis[num].score + 2;       // ����� ��� �������� ��� 2 ������� ��� ����� ������ ����� ��������� ��� 254
                    else paiktis[num].score =255;                                                   // ������ ��� ������� �� ������� ���� = 255
                    printf("To score tou einai %u \n\n", paiktis[num].score);                       // ��� ����������� �� ���� ���


                }

                else {          // ��� ��� ��������� �� ���� ���� 1 ������. ����������� ���� �� ��� ����� ���������
                    if (paiktis[num].score >0) paiktis[num].score = paiktis[num].score -1;  // ����� ��� �������� ��� 1 ������� ��� ����� ������ ����� ���������� ��� 0
                    printf("\nOi kartes pou epileksate den einai SET. O paiktis me id %c xanei mia monada\nTo score tou einai %d\n", paiktis[num].id, paiktis[num].score);  // ����������� ������� ������ ���� �� �� ����
                    printf("\nSunexizoume me idies kartes mexri na brethei set\n\n");

            }

        }
        if (paiktis[num].score >=10){       // ��� ������ ���� 10 ������� ������� �� ��������.
                printf("%s kerdisate!!!\nTo teliko score einai:\n", paiktis[num].onoma);    // ��������� ������� ������
                for (i=0;i<3;i++)                                           // ����� ��� ��� ������ ���������� ���� ��� �������
                    printf("Id: %c\nOnoma: %s\nScore: %u\n\n", paiktis[i].id, paiktis[i].onoma, paiktis[i].score);

               exit(1);                     // ��� ����������.
            }
    }


}

