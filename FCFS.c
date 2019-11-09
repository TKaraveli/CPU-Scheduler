#include<stdio.h>
#include<stdlib.h>
int main()
{
    int CalismaSuresi[3],BeklemeSuresi[3],DonusSuresi[3],i,j;
    float OrtalamaBeklemeSuresi=0,OrtalamaDonusSuresi=0;
 
    printf("Process(Islem) Surelerini Girin:\n");
    for(i=0;i<4;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&CalismaSuresi[i]);
    }
 
    BeklemeSuresi[0]=0;
 
    
    for(i=1;i<4;i++)
    {
        BeklemeSuresi[i]=0;
        for(j=0;j<i;j++)
            BeklemeSuresi[i]+=CalismaSuresi[j];
    }
 
    printf("\nProcess\t\tCalisma Suresi\tBekleme Suresi\tDonus Suresi");
 
    
    for(i=0;i<4;i++)
    {
        DonusSuresi[i]=CalismaSuresi[i]+BeklemeSuresi[i];
        OrtalamaBeklemeSuresi+=BeklemeSuresi[i];
        OrtalamaDonusSuresi+=DonusSuresi[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,CalismaSuresi[i],BeklemeSuresi[i],DonusSuresi[i]);
    }
 
    OrtalamaBeklemeSuresi/=i;
    OrtalamaDonusSuresi/=i;
    printf("\n\nOrtalama Bekleme Suresi:%f",OrtalamaBeklemeSuresi);
    printf("\nOrtalama Donus Suresi:%f\n",OrtalamaDonusSuresi);
    
    system("pause");
    return 0;
}