#include<stdio.h>
#include<stdlib.h>
void main()
{
    int CalismaSuresi[3],Islem[3],BeklemeSuresi[3],DonusSuresi[3],i,j,toplam=0,sira,gecici;
    float OrtalamaBeklemeSuresi,OrtalamaDonusSuresi;
 
    printf("Process(Islem) Surelerini Girin:\n");
    for(i=0;i<4;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&CalismaSuresi[i]);
        Islem[i]=i+1;
    }
 
    
    for(i=0;i<4;i++)
    {
        sira=i;
        for(j=i+1;j<4;j++)
        {
            if(CalismaSuresi[j]<CalismaSuresi[sira])
                sira=j;
        }
 
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
 
        toplam+=BeklemeSuresi[i];
    }
 
    OrtalamaBeklemeSuresi=(float)toplam/4;
    toplam=0;
 
    printf("\nProcess\t    Calisma Suresi    \tBekleme Suresi\tDonus Suresi");
    for(i=0;i<4;i++)
    {
        DonusSuresi[i]=CalismaSuresi[i]+BeklemeSuresi[i];
        toplam+=DonusSuresi[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",Islem[i],CalismaSuresi[i],BeklemeSuresi[i],DonusSuresi[i]);
    }
 
    OrtalamaDonusSuresi=(float)toplam/4;
    printf("\n\nOrtalama Bekleme Suresi=%f",OrtalamaBeklemeSuresi);
    printf("\nOrtalama Donus Suresi=%f\n",OrtalamaDonusSuresi);
    system("pause");
}