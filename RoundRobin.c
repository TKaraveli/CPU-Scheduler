#include<stdio.h> 
#include<stdlib.h>
int main() 
{
  int i,sure,KalanIslem,durum=0,QuantumSuresi; 
  int GelisSirasi[3],CalismaSuresi[3],IslemSuresi[3];
  KalanIslem=4;
  float BeklemeSuresi=0,DonusSuresi=0;
  
  for(i=0;i<4;i++) 
  { 
    printf("--%d.Process(Islem) Icin Gelis Sirasini Ve Calisma Suresini Girin:\n",i+1);
    scanf("%d",&GelisSirasi[i]); 
    scanf("%d",&CalismaSuresi[i]); 
    IslemSuresi[i]=CalismaSuresi[i]; 
  } 
  printf("Quantum Suresini Girin:"); 
  scanf("%d",&QuantumSuresi); 
  printf("\n\nProcess\t|Donus Suresi|Bekleme Suresi\n\n"); 
  for(sure=0,i=0;KalanIslem!=0;) 
  { 
    if(IslemSuresi[i]<=QuantumSuresi && IslemSuresi[i]>0) 
    { 
      sure+=IslemSuresi[i]; 
      IslemSuresi[i]=0;
      durum=1; 
    } 
    else if(IslemSuresi[i]>0) 
    { 
      IslemSuresi[i]-=QuantumSuresi; 
      sure+=QuantumSuresi; 
    } 
    if(IslemSuresi[i]==0  && durum==1) 
    { 
      KalanIslem--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,sure-GelisSirasi[i],sure-GelisSirasi[i]-CalismaSuresi[i]); 
      BeklemeSuresi+=sure-GelisSirasi[i]-CalismaSuresi[i];
      DonusSuresi+=sure-GelisSirasi[i];
      durum=0;
    } 
    if(i==3) 
      i=0; 
    else 
      i++; 
  } 
  printf("\nOrtalama Bekleme Suresi= %f\n",BeklemeSuresi/4);
  printf("Ortalama Donus Suresi = %f\n",DonusSuresi/4);
  system("pause");
  return 0; 
}