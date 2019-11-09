#include<stdio.h>
#include<stdlib.h>
int main()
{
    int CalismaSuresi[3],Islem[3],BeklemeSuresi[3],DonusSuresi[3],Oncelik[3],i,j,sira,gecici;
    float OrtalamaBeklemeSuresi,OrtalamaDonusSuresi,Toplam=0;
 
    printf("Process(Islem) Suresini Ve Priority(Oncelik) Sirasini Girin:\n");
    for(i=0;i<4;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Calisma Suresi:");
        scanf("%d",&CalismaSuresi[i]);
        printf("Oncelik:");
        scanf("%d",&Oncelik[i]);
        Islem[i]=i+1;
    }
 
    
    for(i=0;i<4;i++)
    {
        sira=i;
        for(j=i+1;j<4;j++)
        {
            if(Oncelik[j]<Oncelik[sira])
                sira=j;
        }
 
        gecici=Oncelik[i];
        Oncelik[i]=Oncelik[sira];
        Oncelik[sira]=gecici;
 
        gecici=CalismaSuresi[i];
        CalismaSuresi[i]=CalismaSuresi[sira];
        CalismaSuresi[sira]=gecici;
 
        gecici=Islem[i];
        Islem[i]=Islem[sira];
        Islem[sira]=gecici;
    }
 
    BeklemeSuresi[0]=0;
 
    
    for(i=1;i<4;i++)
    {
        BeklemeSuresi[i]=0;
        for(j=0;j<i;j++)
            BeklemeSuresi[i]+=CalismaSuresi[j];
 
        Toplam+=BeklemeSuresi[i];
    }
 
    OrtalamaBeklemeSuresi=Toplam/4;
    Toplam=0;
 
    printf("\nProcess\t    Calisma Suresi    \tBekleme Suresi\tDonus Suresi");
    for(i=0;i<4;i++)
    {
        DonusSuresi[i]=CalismaSuresi[i]+BeklemeSuresi[i];
        Toplam+=DonusSuresi[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",Islem[i],CalismaSuresi[i],BeklemeSuresi[i],DonusSuresi[i]);
    }
 
    OrtalamaDonusSuresi=Toplam/4;
    printf("\n\nOrtalama Bekleme Suresi=%f",OrtalamaBeklemeSuresi);
    printf("\nOrtalama Donus Suresi=%f\n",OrtalamaDonusSuresi);
    system("pause");
    return 0;
}