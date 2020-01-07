#include <iostream>

using namespace std;
const double dmpfct=0.85; // sabit olarak verilen dumpfactor

int komsulukMatrisi[10][10]=
{
{0,0,0,0,0,1,1,1,1,0},
{0,0,0,0,0,1,1,0,0,0},
{0,0,0,0,0,1,1,0,0,0},
{0,0,0,0,0,1,1,1,1,0},
{0,0,0,0,0,1,0,1,1,1},
{1,1,1,1,1,0,1,1,0,1},
{1,1,1,1,0,1,0,1,1,1},
{1,0,0,1,1,1,1,0,1,1},
{1,0,0,1,1,0,1,1,0,1},
{0,0,0,0,1,1,1,1,1,0}
};


struct node{ //dugumleri tirettigim struct yapisi
float pageRank=1/10;
int gelensayisi=0; //
int gidensayisi=0; //
}dugum[10];


void rankCalculation(int matris [][10]){ //her bur dugum icin page ranki hesap;ayacal fonksiyon
int tekrar=0;
 while(tekrar<1000){


    for(int i=0;i<10;i++){
        float toplam=0;
            for(int j=0;j<10;j++){
                if (matris[j][i]==1){

                   toplam=toplam+(dugum[j].pageRank/dugum[j].gidensayisi);

                };

            };

        dugum[i].pageRank=(toplam*dmpfct)+((0.1)*(1-dmpfct));

        };

    tekrar=tekrar+1;
 };
};


void bxkumesiSayma(int sayim [][10]){
    for(int s=0;s<10;s++){
            for(int a=0;a<10;a++){
                if(sayim[s][a]==1)
                    {
                        dugum[s].gidensayisi=dugum[s].gidensayisi+1;
                    };

            };
    };


};

int main()
{
bxkumesiSayma(komsulukMatrisi);
rankCalculation(komsulukMatrisi);

for(int f=0;f<10;f++){
cout<<dugum[f].pageRank<<endl;

};

 return 0;
}
