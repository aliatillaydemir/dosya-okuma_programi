#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct noktalar
{
    float x;
    float y;
    float z;


} nokta[100000];

struct Noktalar
{

    float x;
    float y;
    float z;



    int r;
    int g;
    int b;

} nrkta[100000];




int main()
{
    FILE *dosya= fopen("binaryXYZRGB.nkt","r");
    FILE *dosya2=fopen("output.nkt","w+b");
    char *ptr;
    char *ptr2;
    int sayi[10];
    int b=2;
    int i=0,j;
    char tutucu;
    int kontrol;
    int z=0;



XD:
    printf("1-> dosya kontrolu\n");
    printf("2-> en yakin/uzak noktalar\n");
    printf("3-> kup\n");
    printf("4-> kure\n");
    printf("5-> noktalarin birbirlerine olan uzakliklari\n");
    printf("6-> programi  sonlandirir\n");

    printf("tusa basiniz");
    scanf("%d",&kontrol);

    int n=0;
    int r;
    char cumle1[50]="# Noktalar dosya format";
    char cevap1[50];
    char cumle2[30]="VERSION 1";
    char cevap2[30];
    char cumle3[55]="ALANLAR x y z";
    char cevap3[55];
    char cumle6[55]="ALANLAR x y z r g b";
    char cevap6[55];
    char cumle4[55]="NOKTALAR";
    char cevap4[55];
    char cumle5[55]="DATA binary";
    char cevap5[55];
    char cumle7[55]="DATA ascii";
    char cevap7[55];
    char cevaps[10];
    char ctrl[20];

    char noktalar[10];
    int noktasayi;


    if(kontrol==1)
    {


        if(dosya!=NULL)
        {
            for(int k=0; k<23; k++)

            {
                fscanf(dosya,"%c",&cevap1[k]);
            }
        }


        if(strstr(cevap1,cumle1)==NULL)
        {
            printf("Cumle bilgileri dosya bilgilerine uymuyor1");
            return 0;
        }

        else
        {
            printf("satir1 uyuyor.");
            z++;

        }
        fseek(dosya,24,SEEK_SET);

        if(dosya!=NULL)
        {

            for(int t=0; t<9; t++)

            {
                fscanf(dosya,"%c",&cevap2[t]);

            }

        }

        if(strstr(cevap2,cumle2)==NULL)
        {
            printf("\nCumle bilgileri dosya bilgilerine uymuyor2 ");
            return 0;
        }

        else
            printf("\nsatir 2 uyuyor.");
        z++;


        fseek(dosya,48,SEEK_SET);
        fscanf(dosya,"%c",&cevap3[0]);

        if(cevap3[0]=='r')
        {
            fseek(dosya,34,SEEK_SET);
            if(dosya!=NULL)
            {
                for(int t=0; t<19; t++)
                {

                    fscanf(dosya,"%c",&cevap6[t]);

                }
            }

            if(strstr(cevap6,cumle6)==NULL)
            {
                printf("\nCumle bilgileri dosya bilgilerine uymuyor3 ");
                return 0;
            }

            else
                printf("\nsatir 3 uyuyor.");
            z++;

            b=1;
        }



        if(b!=1)
        {
            fseek(dosya,34,SEEK_SET);
            if(dosya!=NULL)
            {
                for(int t=0; t<13; t++)
                {

                    fscanf(dosya,"%c",&cevap3[t]);

                }
            }


            if(strstr(cevap3,cumle3)==NULL)
            {
                printf("\nCumle bilgileri dosya bilgilerine uymuyor3 ");

            }

            else
                printf("\nsatir 3 uyuyor.");
            z++;

        }


        if(b==1)
        {
            fseek(dosya,54,SEEK_SET);
            if(dosya!=NULL)
            {
                for(int t=0; t<8; t++)
                {
                    fscanf(dosya,"%c",&cevap4[t]);
                }
                fseek(dosya,63,SEEK_SET);

                for(int t=0; t<8; t++)
                {
                    fscanf(dosya,"%c",&cevaps[t]);
                    if(isdigit(cevaps[t])==1)
                    {
                        noktalar[n]=cevaps[t];
                        printf("%c",noktalar[n]);

                        n++;
                    }
                }
                noktasayi=atoi(noktalar);

            }

            printf("\t nokta: %d",noktasayi);

            if(strstr(cevap4,cumle4)==NULL)
            {
                printf("\nCumle bilgileri dosya bilgilerine uymuyor4 ");
                return 0;

            }

            else
            {
                printf("\nsatir 4 uyuyor.");
                z++;
            }
        }

        if(b!=1)
        {
            fseek(dosya,48,SEEK_SET);
            for(int t=0; t<8; t++)
            {

                fscanf(dosya,"%c",&cevap4[t]);

            }
            fseek(dosya,57,SEEK_SET);
            for(int t=0; t<8; t++)
            {
                fscanf(dosya,"%c",&cevaps[t]);
                if(isdigit(cevaps[t])==1)
                {
                    noktalar[n]=cevaps[t];
                    printf("%c",noktalar[n]);

                    n++;
                }
            }
            noktasayi=atoi(noktalar);


            if(strstr(cevap4,cumle4)==NULL)
            {
                printf("\nCumle bilgileri dosya bilgilerine uymuyor 4");
                return 0;

            }

            else
            {
                printf("\nsatir 4 uyuyor.");
                z++;
            }

        }

        printf("\t nokta: %d",noktasayi);

        if(noktasayi<10)
            r=1;
        if(noktasayi>=10 && noktasayi<=99)
            r=2;
        if(noktasayi>=100 && noktasayi<1000)
            r=3;
        if(noktasayi>=1000 && noktasayi<10000)
            r=4;
        if(noktasayi>=10000 && noktasayi<100000)
            r=5;
        if(noktasayi>=100000 && noktasayi<1000000)
            r=6;
        if(noktasayi>=1000000)
            r=7;



        if(b==1)
        {
            fseek(dosya,64+r,SEEK_SET);
            for(int t=0; t<6; t++)
                fscanf(dosya,"%c",&ctrl[t]);

            if(ctrl[5]=='a')
            {

                fseek(dosya,64+r,SEEK_SET);

                for(int t=0; t<10; t++)
                {
                    fscanf(dosya,"%c",&cevap7[t]);
                }

                if(strstr(cevap7,cumle7)==NULL)
                {
                    printf("\nCumle bilgileri dosya bilgilerine uymuyor 5");
                    return 0;

                }

                else
                {
                    printf("\nsatir 5 uyuyor.\n");
                    z++;
                }


                fseek(dosya,75+r,SEEK_SET);
            }

            if(ctrl[5]=='b')
            {

                fseek(dosya,64+r,SEEK_SET);

                for(int t=0; t<11; t++)
                {
                    fscanf(dosya,"%c",&cevap5[t]);
                }

                if(strstr(cevap5,cumle5)==NULL)
                {
                    printf("\nCumle bilgileri dosya bilgilerine uymuyor 5");

                    return 0;
                }

                else
                {
                    printf("\nsatir 5 uyuyor.\n");
                    z++;
                }
                fseek(dosya,76+r,SEEK_SET);


            }

        }



        if(b!=1)
        {
            fseek(dosya,58+r,SEEK_SET);

            for(int t=0; t<6; t++)
                fscanf(dosya,"%c",&ctrl[t]);

            if(ctrl[5]=='b')  //DATA SONRASİ ASCİİ Mİ BİNARY Mİ?
            {
                fseek(dosya,58+r,SEEK_SET);

                for(int t=0; t<11; t++)
                {
                    fscanf(dosya,"%c",&cevap5[t]);
                }

                if(strstr(cevap5,cumle5)==NULL)
                {
                    printf("\nCumle bilgileri dosya bilgilerine uymuyor 5");

                    return 0;
                }

                else
                {
                    printf("\nsatir 5 uyuyor.\n");
                    z++;
                }
                fseek(dosya,70+r,SEEK_SET);
            }

            if(ctrl[5]=='a')  //DATA SONRASİ ASCİİ Mİ BİNARY Mİ?
            {
                fseek(dosya,58+r,SEEK_SET);
                for(int t=0; t<10; t++)
                {
                    fscanf(dosya,"%c",&cevap7[t]);
                }

                if(strstr(cevap7,cumle7)==NULL)
                {
                    printf("\nCumle bilgileri dosya bilgilerine uymuyor5 ");
                    return 0;

                }

                else
                {
                    printf("\nsatir 5 uyuyor.\n");
                    z++;
                }

                fseek(dosya,69+r,SEEK_SET);

            }

        }



        if(b==1 && ctrl[5]=='a')
        {


            for(i=-38; i<noktasayi; i++)
            {

                while(!feof(dosya))
                {

                    tutucu=getc(dosya);


                    if(tutucu=='\n')
                    {
                        fscanf(dosya,"%f %f %f %d %d %d",&nrkta[i].x,&nrkta[i].y,&nrkta[i].z,&nrkta[i].r,&nrkta[i].g,&nrkta[i].b);
                        j++;
                    }


                    i++;
                }

            }
        }


        if(b!=1 && ctrl[5]=='a')
        {


            for (i=0; i<noktasayi; i++)
            {
                while(!feof(dosya))
                {

                    tutucu=getc(dosya);


                    if(tutucu=='\n')
                    {
                        fscanf(dosya,"%f %f %f",&nokta[i].x,&nokta[i].y,&nokta[i].z);
                        j++;
                    }


                    i++;
                }

            }
        }


        if(b!=1 && ctrl[5]=='b')
        {

            for(i=0; i<noktasayi; i++)
            {
                fread(&nokta[i],sizeof(struct noktalar),1,dosya);

            }
        }


        if(b==1 && ctrl[5]=='b')
        {

            for(i=0; i<noktasayi; i++)
            {
                fread(&nrkta[i],sizeof(struct Noktalar),1,dosya);

            }
        }


        j=noktasayi;
        /*
            if(b==1)
            {
                for(i=0; i<j; i++)
                    printf("%f %f %f %d %d %d \n",nrkta[i].x,nrkta[i].y,nrkta[i].z,nrkta[i].r,nrkta[i].g,nrkta[i].b);
            }

            if(b!=1)
            {
                for(i=0; i<j; i++)
                    printf("%f %f %f \n",nokta[i].x,nokta[i].y,nokta[i].z);
           }

           */
        if(z==5)
        {
            printf("\nDosyalar uyumlu\n");
            fprintf(dosya2,"Dosyalar uyumlu\n\n\n");
        }
        else
        {
            printf("\nDosyalar uyumsuz\n");
            fprintf(dosya2,"Dosyalar uyumsuz\n");
            return 0;
        }
        goto XD;
    }


    if(kontrol==2)
    {
        float uzaklik[1000];
        int kayit;
        int k1,k2,k3,k4;
        float enb_uzak=0;
        float enk_kisa=3132;

        int t=0;
        for(int a=0; a<j; a++)
        {
            t++;


            for(int z=t; z<j; z++)
            {

                if(b!=1)
                    uzaklik[a]=sqrt(pow(nokta[a].x-nokta[z].x,2)+pow(nokta[a].y-nokta[z].y,2)+pow(nokta[a].z-nokta[z].z,2));

                if(b==1)
                    uzaklik[a]=sqrt(pow(nrkta[a].x-nrkta[z].x,2)+pow(nrkta[a].y-nrkta[z].y,2)+pow(nrkta[a].z-nrkta[z].z,2));

                if(uzaklik[a]>enb_uzak)
                {
                    enb_uzak=uzaklik[a];
                    k1=a;
                    k2=z;
                }

                if(uzaklik[a]<enk_kisa)
                {
                    enk_kisa=uzaklik[a];
                    k3=a;
                    k4=z;
                }

            }


        }
        if(b!=1)
        {
            printf("en uzak nokta bilgileri:\n");
            printf("en uzun mesafe =%f\n",enb_uzak);
            printf("\n%d. nokta-->%f %f %f\n",k1,nokta[k1].x,nokta[k1].y,nokta[k1].z);
            printf("%d. nokta-->%f %f %f\n",k2,nokta[k2].x,nokta[k2].y,nokta[k2].z);


            printf("\nEn yakin nokta bilgileri:\n");
            printf("en kisa mesafe =%f\n",enk_kisa);
            printf("\n%d. nokta-->%f %f %f\n",k3,nokta[k3].x,nokta[k3].y,nokta[k3].z);
            printf("%d. nokta-->%f %f %f\n",k4,nokta[k4].x,nokta[k4].y,nokta[k4].z);

            fprintf(dosya2,"en uzak nokta bilgileri:\n");
            fprintf(dosya2,"en uzun mesafe =%f\n",enb_uzak);
            fprintf(dosya2,"\n%d. nokta-->%f %f %f\n",k1,nokta[k1].x,nokta[k1].y,nokta[k1].z);
            fprintf(dosya2,"%d. nokta-->%f %f %f\n",k2,nokta[k2].x,nokta[k2].y,nokta[k2].z);


            fprintf(dosya2,"\nEn yakin nokta bilgileri:\n");
            fprintf(dosya2,"en kisa mesafe =%f\n",enk_kisa);
            fprintf(dosya2,"\n%d. nokta-->%f %f %f\n",k3,nokta[k3].x,nokta[k3].y,nokta[k3].z);
            fprintf(dosya2,"%d. nokta-->%f %f %f\n",k4,nokta[k4].x,nokta[k4].y,nokta[k4].z);
        }

        if(b==1)
        {
            printf("en uzak nokta bilgileri:\n");
            printf("en uzun mesafe =%f\n",enb_uzak);
            printf("\n%d. nokta-->%f %f %f %d %d %d\n",k1,nrkta[k1].x,nrkta[k1].y,nrkta[k1].z,nrkta[k1].r,nrkta[k1].g,nrkta[k1].b);
            printf("%d. nokta-->%f %f %f %d %d %d\n",k2,nrkta[k2].x,nrkta[k2].y,nrkta[k2].z,nrkta[k2].r,nrkta[k2].g,nrkta[k2].b);


            printf("\nEn yakin nokta bilgileri:\n");
            printf("en kisa mesafe =%f\n",enk_kisa);
            printf("\n%d. nokta-->%f %f %f %d %d %d\n",k3,nrkta[k3].x,nrkta[k3].y,nrkta[k3].z,nrkta[k3].r,nrkta[k3].g,nrkta[k3].b);
            printf("%d. nokta-->%f %f %f %d %d %d\n",k4,nrkta[k4].x,nrkta[k4].y,nrkta[k4].z,nrkta[k4].r,nrkta[k4].g,nrkta[k4].b);

            fprintf(dosya2,"en uzak nokta bilgileri:\n");
            fprintf(dosya2,"en uzun mesafe =%f\n",enb_uzak);
            fprintf(dosya2,"\n%d. nokta-->%f %f %f %d %d %d\n",k1,nrkta[k1].x,nrkta[k1].y,nrkta[k1].z,nrkta[k1].r,nrkta[k1].g,nrkta[k1].b);
            fprintf(dosya2,"%d. nokta-->%f %f %f %d %d %d\n",k2,nrkta[k2].x,nrkta[k2].y,nrkta[k2].z,nrkta[k2].r,nrkta[k2].g,nrkta[k2].b);


            fprintf(dosya2,"\nEn yakin nokta bilgileri:\n");
            fprintf(dosya2,"en kisa mesafe =%f\n",enk_kisa);
            fprintf(dosya2,"\n%d. nokta-->%f %f %f %d %d %d\n",k3,nrkta[k3].x,nrkta[k3].y,nrkta[k3].z,nrkta[k3].r,nrkta[k3].g,nrkta[k3].b);
            fprintf(dosya2,"%d. nokta-->%f %f %f %d %d %d\n",k4,nrkta[k4].x,nrkta[k4].y,nrkta[k4].z,nrkta[k4].r,nrkta[k4].g,nrkta[k4].b);
        }

        goto XD;
    }


    if(kontrol==3)
    {

        fprintf(dosya2,"\n \n \nKUP KENAR NOKTA BILGILERI\n");
        float uzaklik[100000];
        float k1,k2,k3,k4,k5,k6,k7,k8;
        float enb_uzak=uzaklik[0];
        int m1,m2;

        int t=0;
        for(int a=0; a<j; a++)
        {
            t++;


            for(int z=t; z<=j; z++)
            {
                if(b!=1)
                    uzaklik[a]=sqrt(pow(nokta[a].x-nokta[z].x,2)+pow(nokta[a].y-nokta[z].y,2)+pow(nokta[a].z-nokta[z].z,2));

                if(b==1)
                    uzaklik[a]=sqrt(pow(nrkta[a].x-nrkta[z].x,2)+pow(nrkta[a].y-nrkta[z].y,2)+pow(nrkta[a].z-nrkta[z].z,2));

                if(uzaklik[a]>enb_uzak)
                {

                    enb_uzak=uzaklik[a];

                    m1=a;
                    m2=z;
                }
            }
        }


        float  a=enb_uzak/pow(3,0.5);
        if(b!=1)
        {
            printf("\nnokta-->%f %f %f \n",nokta[m1].x,nokta[m1].y,nokta[m1].z);
            printf("\nnokta-->%f %f %f \n",nokta[m1].x,nokta[m1].y+a,nokta[m1].z);
            printf("\nnokta-->%f %f %f \n",nokta[m1].x-a,nokta[m1].y+a,nokta[m1].z);
            printf("\nnokta-->%f %f %f \n",nokta[m1].x-a,nokta[m1].y,nokta[m1].z);


            printf("\n nokta-->%f %f %f \n",nokta[m2].x,nokta[m2].y,nokta[m2].z);
            printf("\n nokta-->%f %f %f \n",nokta[m2].x+a,nokta[m2].y,nokta[m2].z);
            printf("\n nokta-->%f %f %f \n",nokta[m2].x,nokta[m2].y-a,nokta[m2].z);
            printf("\n nokta-->%f %f %f \n",nokta[m2].x+a,nokta[m2].y-a,nokta[m2].z);


            fprintf(dosya2,"\nnokta-->%f %f %f \n",nokta[m1].x,nokta[m1].y,nokta[m1].z);
            fprintf(dosya2,"\nnokta-->%f %f %f \n",nokta[m1].x,nokta[m1].y+a,nokta[m1].z);
            fprintf(dosya2,"\nnokta-->%f %f %f \n",nokta[m1].x-a,nokta[m1].y+a,nokta[m1].z);
            fprintf(dosya2,"\nnokta-->%f %f %f \n",nokta[m1].x-a,nokta[m1].y,nokta[m1].z);


            fprintf(dosya2,"\nnokta-->%f %f %f \n",nokta[m2].x,nokta[m2].y,nokta[m2].z);
            fprintf(dosya2,"\nnokta-->%f %f %f \n",nokta[m2].x+a,nokta[m2].y,nokta[m2].z);
            fprintf(dosya2,"\nnokta-->%f %f %f \n",nokta[m2].x,nokta[m2].y-a,nokta[m2].z);
            fprintf(dosya2,"\nnokta-->%f %f %f \n",nokta[m2].x+a,nokta[m2].y-a,nokta[m2].z);
        }

        if(b==1)
        {
            printf("\n nokta-->%f %f %f %d %d %d\n",nrkta[m1].x,nrkta[m1].y,nrkta[m1].z,nrkta[m1].r,nrkta[m1].g,nrkta[m1].b);
            printf("\n nokta-->%f %f %f \n",nrkta[m1].x,nrkta[m1].y+a,nrkta[m1].z);
            printf("\n nokta-->%f %f %f \n",nrkta[m1].x-a,nrkta[m1].y+a,nrkta[m1].z);
            printf("\n nokta-->%f %f %f \n",nrkta[m1].x-a,nrkta[m1].y,nrkta[m1].z);


            printf("\n nokta-->%f %f %f \n",nrkta[m2].x,nrkta[m2].y,nrkta[m2].z);
            printf("\n nokta-->%f %f %f \n",nrkta[m2].x+a,nrkta[m2].y,nrkta[m2].z);
            printf("\n nokta-->%f %f %f \n",nrkta[m2].x,nrkta[m2].y-a,nrkta[m2].z);
            printf("\n nokta-->%f %f %f \n",nrkta[m2].x+a,nrkta[m2].y-a,nrkta[m2].z);


            fprintf(dosya2,"\n nokta-->%f %f %f %d %d %d\n",nrkta[m1].x,nrkta[m1].y,nrkta[m1].z,nrkta[m1].r,nrkta[m1].g,nrkta[m1].b);
            fprintf(dosya2,"\n nokta-->%f %f %f \n",nrkta[m1].x,nrkta[m1].y+a,nrkta[m1].z);
            fprintf(dosya2,"\n nokta-->%f %f %f \n",nrkta[m1].x-a,nrkta[m1].y+a,nrkta[m1].z);
            fprintf(dosya2,"\n nokta-->%f %f %f \n",nrkta[m1].x-a,nrkta[m1].y,nrkta[m1].z);


            fprintf(dosya2,"\n nokta-->%f %f %f \n",nrkta[m2].x,nrkta[m2].y,nrkta[m2].z);
            fprintf(dosya2,"\n nokta-->%f %f %f \n",nrkta[m2].x+a,nrkta[m2].y,nrkta[m2].z);
            fprintf(dosya2,"\n nokta-->%f %f %f \n",nrkta[m2].x,nrkta[m2].y-a,nrkta[m2].z);
            fprintf(dosya2,"\n nokta-->%f %f %f \n",nrkta[m2].x+a,nrkta[m2].y-a,nrkta[m2].z);
        }

        goto XD;
    }



    if(kontrol==4)
    {

        printf("\n \t kurenin merkez x,y,z kordinatlarini girin");
        float a;
        float d;
        float c;
        float yaricap;
        scanf("%f %f %f",&a,&d,&c);
        fprintf(dosya2,"\nkurenin x,y,x kordinatlari:x:%f   y:%f    z:%f  ",a,d,c);
        printf("\n \tkurenin yaricapini girin");
        scanf("%f",&yaricap);
        fprintf(dosya2,"\nkure yaricapi:%f",yaricap);
        printf("\n \n \n KURENIN ICINDE KALAN NOKTALAR");
        fprintf(dosya2,"\n \n KURENIN ICINDE KALAN NOKTALAR");

        for(i=0; i<j; i++)
        {
            if(b!=1)
            {
                if(a<nokta[i].x && nokta[i].x<(a+yaricap) && d<nokta[i].y && nokta[i].y<(d+yaricap)&& c<nokta[i].z && nokta[i].z<(c+yaricap))
                {

                    printf("\n %d.nokta => %f %f %f  ",i,nokta[i].x,nokta[i].y,nokta[i].z);
                    fprintf(dosya2,"\n %d.nokta => %f %f %f  ",i,nokta[i].x,nokta[i].y,nokta[i].z);

                }

            }

            if(b==1)
            {
                if(a<nrkta[i].x && nrkta[i].x<(a+yaricap) && d<nrkta[i].y && nrkta[i].y<(d+yaricap)&& c<nrkta[i].z && nrkta[i].z<(c+yaricap))
                {

                    printf("\n %d.nokta => %f %f %f  ",i,nrkta[i].x,nrkta[i].y,nrkta[i].z);
                    fprintf(dosya2,"\n %d.nokta => %f %f %f  ",i,nrkta[i].x,nrkta[i].y,nrkta[i].z);

                }

            }
        }
        goto XD;
    }


    if(kontrol==5)
    {
        float mesafe=0;
        float ortalama;
        float uzaklik[100000];
        int sayac=0;
        int t=0;
        for(int a=0; a<j; a++)
        {
            t++;


            for(int z=t; z<j; z++)
            {

                if(b!=1)
                {
                    uzaklik[a]=sqrt(pow(nokta[a].x-nokta[z].x,2)+pow(nokta[a].y-nokta[z].y,2)+pow(nokta[a].z-nokta[z].z,2));
                    mesafe+=uzaklik[a];
                }

                if(b==1)
                {
                    uzaklik[a]=sqrt(pow(nrkta[a].x-nrkta[z].x,2)+pow(nrkta[a].y-nrkta[z].y,2)+pow(nrkta[a].z-nrkta[z].z,2));
                    mesafe+=uzaklik[a];
                }
                sayac++;
            }
        }
        ortalama=mesafe/sayac;
        printf("Sayilarin birbirlerine olan uzaklik ortalamasi = %f",ortalama);
        fprintf(dosya2,"\n\nSayilarin birbirlerine olan uzaklik ortalamasi = %f",ortalama);

        goto XD;
    }


    fclose(dosya);


    return 0;
}
