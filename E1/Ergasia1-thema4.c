#include <stdio.h>
#include <stdlib.h>


/* To menou me tis drasthriothtes poy mporei na epilegjei o xrhsths */
int menu(){
    printf("1. Emfanisi kenwn thesewn\n");
    printf("2. Epilexte thesi gia kratisi\n");
    printf("3. Kratisi ths pios mprostinhs eleytherhs thesis se parathuro\n");
    printf("4. Akurwsh krathshs\n");
    printf("5. Elegxo kratisis\n");
    printf("6. Emfanisi krathsewn\n");
    printf("7. Stoixeia leofwreiou kai diagramma thesewn\n");
    printf("8. Apothikeush stoixeiwn \n");
    printf("0. Termatismos \n");
    }




int main(){
    /* gia fortwsh twn metablhtwn me tis times tou arxeiou bus.txt*/
    FILE *leofwreio;
    char pinakida[8];
    int max, kenes;
    leofwreio = fopen("bus.txt", "r");

    if (leofwreio == NULL){ /*termatizei an den uparxei to arxeio */
        printf("Den brethike to arxeio bus.txt\n");
        exit(1);
    }
    fscanf(leofwreio, "%s %d\n", pinakida, &max);
    fclose(leofwreio);
    printf("Dwsate leofwreio me pinakida %s kai %d theseis.\n", pinakida, max);
    if (max>53){
        printf("Sfalma! Dwsate leofwreio me perissoteres apo 53 theseis.\n");
        exit(1);
    }

    /* ston parakatw elegxo afairoyme tis 5 theseis tis galarias kai elegxoume an diaireite akribws me to 4*/
    if ( (max-5)%4 > 0 ){       /* an exei ypoloipo > 0 => den einai typos leofwreiou 4N+5  */
        printf("Sfalma! Dwsate leofwreio pou den exei seires twn 4arwn kai galaria twn 5 thesewn.\n");
        exit(1);
    }

    printf("Ola ok\n");


    int i, epilogi=-1;
    char thesi[max+1];   /* pinakas me stoixeia oses einai kai oi theseis tou leofwreiou +1 pseudes stoixeio sth thesi 0 tou pinaka gia dieykolinsi arithmisis thesewn */
    for (i=1; i<=max;i++){
        thesi[i] = '_';                     /*gemizw kenes theseis to pinaka*/
    }
    int omax = max +((max-5)/2)+1;          /* gia tin epilogh 7 opou 8a kanoume ena diplo for-loop gia to diagramma twn thesewn */
    char output[omax];                      /* gia thn apo8hkeush tou diagrammatos mias kai 8a zhth8ei na apo8hkeutei sthn epilogh 8 */
    output[0] = '0';                        /* elegxo gia thn 8 an zhthse apo8ikeush xwris na xei ginei diagramma (dhladh xwris na pathse prwta to 7) */

    while (epilogi!=0){                     /* epanalmabanete mexri na dwsei 0 o xrhsths gia eksodo */
        printf("\nTi thelete na kanete?\n");
        menu();
        scanf("%d", &epilogi);

        /*epilogi 1: Emfanizei poies theseis einai kenes */
        if (epilogi ==1){
            kenes = 0;
            printf("\nEinai kenes oi theseis: ");
            for (i=1; i<=max;i++)
            if (thesi[i] == '_'){           /* opote to thesi[] = '_' tha emfanizei th thesi toy pinaka */
                printf("%d ", i);
                kenes++ ;                   /* prosthetei mia akoma sto metrhth gia tis kenes theseis */
            }

            printf("\nSunolika einai %d eleutheres theseis.\n", kenes);
        }

        /*epilogi 2. Kratisis tis thesis poy zhta o xrhsths*/
        if (epilogi ==2){
            printf("\nPoia thesi thelete gia krathsh?\n");
            scanf("%d", &i);
            if (thesi[i] == '_' && i<=max){                                                             /* proxwra mono an einai kenh h 8esh kai entos ton orion twn 8esewn tou leofwreiou */
                thesi[i] = '*';                                                                         /* kanei kratisi ti 8esh pou zhthse */
                printf("Kanate krathsh thn thesi %d\n", i);
            }
            else if (thesi[i]=='*' && i<=max) printf("H thesi %d den einai eleutheri\n", i);                      /* Mhnyma an den einai eleu8erh */
            else  printf("Den uparxei thesi %d.\nTo leofwreio exei theseis apo 1 mexri %d\n", i, max);  /* Mhnuma an zhthsei arithmo 8eshs ektos twn oriwn tou leofwreio */
        }

        /*epilogi 3: Kratisi tis prwtis kenis thesis se parathuro*/
        if (epilogi ==3){
            i=1;                                    /* 8a xrhsimopoih8ei gia to loop opou 8a to auksanoume kata 4 wste na antistoixei se epomenh seira */
            int kratisi, stop = 0, none =0;
            while (stop!=1){                        /* 8a epanalambanetai mexri na bre8ei h prwth 8esh dipla se para8uro opou kai 8a allakaei to stop se 1 */
            if (i < max -5){                            /* Gia tis seires twn 4 8esewn pou einai prin ti galaria */
                if (thesi[i] == '_'){                       /* H prwth aristerh 8esh ths seiras pou profanws einai para8uro. An einai kenh */
                    kratisi = i;                            /* tote kratisi = ari8mos auths ths 9eshs */
                    thesi[i] = '*';                         /* Allazei to stoixeio tou pinaka wsta apo eleu8erh '_' na ginei krathmenh '*' */
                    stop = 1;                               /* Allazei to stop se 1 wste na stamathsei h epalaipsi tou loop */
                }
                else if (thesi[i+3] == '_'){                /* Atnistoixa bhmata me prin gia thn eksetash ths tetarth 8esh ths seiras*/
                    kratisi = i+3;
                    thesi[kratisi] = '*';
                    stop = 1;
                    }
                else i= i+4;                            /* Auksanei to i kata 4 wste na pame sthn epomenh seira */
                }

            else{                                   /* gia th teleutaia seira (galaria) pou einai 5 8eseis */
                if (thesi[i] == '_'){                   /* H prwth aristerh 8esh ths seiras (idia bhmata me grammes 93-96 tou kwdika) */
                    kratisi = i;
                    thesi[kratisi] = '*';
                    stop = 1;
                }
                else if (thesi[i+4] == '_'){            /* Antistoixa bhmata gia 5h 8esh pou einai kai auth para8uro */
                    kratisi = i+4;
                    thesi[kratisi] = '*';
                    stop = 1;
                    }
                else{                                   /* Sth periptwsh pou ftasoume ws edw, den brhke kenh 8esh. */
                    none =1;                            /* Opote bazoume none =1 (anagkaio gia th seira 124) */
                    stop = 1;                           /* kai stop =1 gia na stamathsei to loop */
                    }
            }
            }
        (none ==1)? printf("\nDen uparxei eleutheri thesi se parathuro"):printf("\nEgine krathsh tis thesis %d\n\n", kratisi);    /* none =1 den brhke eleu8erh 8esh opote kai to emfanizei minima sto xrhsth. */
        }                                                                                                                       /* Diaforetika emfanizei poia 8esh krati8ike */

        /*epilogi 4: Akurwsi krathshs */
         if (epilogi ==4){
            printf("\nPoia kratisi thelete na akurwsete?\n");
            scanf("%d", &i);
            if (thesi[i] == '*' && i<=max){             /* elegxos an einai krathmenh kai entos twn oriwn tou leforeiou */
                thesi[i] = '_';
                printf("Akurwsate thn krathsh ths thesis %d\n", i);
            }
            else if (thesi[i]=='_' && i<=max) printf("H thesi %d den einai krathmenh\n", i);                      /* Mhnuma sth periptwsh poy einai hdh eleu8erh */
            else  printf("Den uparxei thesi %d.\nTo leofwreio exei theseis apo 1 mexri %d\n", i, max);  /* sth periptwsh pou zhthse akurwsh 8eshs ektos twn oriwn tou lefwreiou. */
        }

        /*epilogi 5: Elegxos 8eshs pou rwta o xrhsths an einai krathmenh */
         if (epilogi ==5){
            printf("\nPoia thesh thelete na elegjete an einai krathmenh?\n");
            scanf("%d", &i);
            if (thesi[i] == '*' && i<=max) printf("H thesi %d einai krathmenh\n", i);                    /* thesh eleu8erh kai entos oriwn */
            else if (thesi[i]=='_' && i<=max) printf("H thesi %d den einai krathmenh\n", i);                      /* an einai krathmenh */
            else  printf("Den uparxei thesi %d.\nTo leofwreio exei theseis apo 1 mexri %d\n", i, max);  /* Sth periptwsh pou zhthse thesi ektos oriwn */
        }

        /*epilogi 6: emfanisi listas krathmenwn thesewn kata arithmo thesis */
        if (epilogi ==6){
            printf("\nOi krathmenes theseis einai: ");
            for (i=1; i<=max;i++)
            if (thesi[i] == '*') printf("%d ", i);
            printf("\n");
        }

        /* epilogi 7: Emfanisi pinakidas leofwreiou kai diagrammatos 8esewn leofwreio gia tis kratiseis */
        if (epilogi == 7){
            for (i=0; i<=omax; i++) output[i]= '\0';    /*arxikopoihsh. Blepe kai grammh 54 */
            int j, white=0;                             /* to i metraei tis seires kai to j tis 4 8eseis ka8e seiras. To white metra ta kena kai tis allages seiras */
            for (i=1; i<=max-5; i=i+4){                 /* einai gia tis seires twn 4 kai auksanei kata 4, dhladh se ka8e loop mas paei mia seira pio katw */

                for (j=0; j<=3;j++) {                       /* paei apo 0 ws 3 gia tis 4 8eseis pou xei kaue seira */
                        output[i+j+white-1]= thesi[i+j];    /* sto pinaka ouptput[] afairoume 1 giati o pinakas thesi[] exei kai mia pseutikh metablhth sth 8esh mhden */
                        if (j==1) {
                                output[i+j+white]= ' ';     /* meta th 2h 8esh ths ka8e seiras pos8etei ena akoma stoixeio me ' ' gia to diagramma */
                                white++;                    /* auksanei o metrhths twn kenwn/allaghs seirwn kata 1 */
                        }
                }
                output[i+3+white]= '\n';                    /* afou teleiwse to loop twn 4 8esewn bazei ena akoma stoixeio me '\n' gia allagh seiras sto diagramma */
                white++;                                    /* auksanei o metrhths twn kenwn/allaghs seirwn kata 1 */
            }

            for (i=max-4;i<=max;i++) output[i+white-1]=thesi[i];    /* gia th galaria */

            /* Emfanisi pinakidas kai diagrammatos */
            printf("\n%s\n", pinakida);
            printf("%s\n", output);
        }

        /*epilogi 8: Apothikeush pinakidas kai diagrammatos tis epilogis 7 */
        if (epilogi ==8){
            /* elegxoume prwta an o xrhsths exei prwta dhmiourghsei to diagramma me thn epilogh 7 */
            if (output[0] == '0') printf("To diagramma einai keno.\nEplekste prwta thn dhmiourgia toy (epilogi 7) kai meta ksanadokimaste. \n");
            else {
                FILE *layout;
                layout = fopen("layout.txt", "w");
                fprintf(layout,"%s\n%s", pinakida, output);
                fclose(layout);
                printf("\nTo diagramma kai pinakida apo8hkeutikan.\n\nProsoxh! Tuxon allages poy kanate meta thn apo th teleutaia fora \npou pathsate 7 den 8a apo8hkeutoun.\n");
            }
        }
    }
}

