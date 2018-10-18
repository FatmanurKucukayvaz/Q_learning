#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <istream>
#include <ostream>
#include <math.h>
#include <cstring>
#include<map>
#include<limits.h>
#include<set>
#include <allegro.h>

using namespace std;

void Baslat();
void Bitir();

int convert(char *x)
{
    char digit;
    int result = 0;
    while (digit = *x++)
        result = result * 10 + digit - '0';
    return result;
}
int sayi_cevir(int i,char x[2])
{
    int result = 0;
    i=i-2;
    int carp=1;
    while (i!=-1){
        result = result+(x[i] - '0')*carp;
        carp=carp*10;
        i--;
    }

    return result;
}
using namespace std;

int main()
{
    Baslat();

    ifstream satirOku;
    satirOku.open("input44.txt",ios::in);
    int i,satir=0;
    string a;
    while(!satirOku.eof()){
        satirOku>>a;
        satir++;
    }
    satir=satir-1;
    satirOku.close();
    ifstream dosyaOku;
    dosyaOku.open("input44.txt",ios::in);
    char komsular[100];
    char* parcalar;
    int dizi[100];
    int b=0;
    int indis;
    indis=satir;
    int R[indis][indis];
    for(i=0;i<indis;i++){
        for(int j=0;j<indis;j++){
            R[i][j]=-1;
        }
    }
    float Q[indis][indis];
    for(i=0;i<indis;i++){
        for(int j=0;j<indis;j++){
            Q[i][j]=0;
        }
    }
    for(i=0;i<satir;i++){
        dosyaOku>>komsular;
        parcalar=strtok(komsular,",");
        while (parcalar != NULL) {
            //cout << parcalar << '\n';
            dizi[b]=convert(parcalar);
            parcalar = strtok(NULL, ",");
            b++;
        }
        for(int j=0;j<b;j++){
            R[i][dizi[j]]=0;
        }
        b=0;
    }
    dosyaOku.close();

    //----------------------------------------------
    satir=sqrt(satir);
    BITMAP *buffer=create_bitmap(SCREEN_W,SCREEN_H);//

	int sil_gx,sil_gy,sil_hx,sil_hy;
    //DRAW
    for(i=0;i<satir;i++)
    {
       	for(int j=0;j<satir;j++)
       	{
               rect(buffer,35+j*25,35+i*25,60+j*25,60+i*25,makecol(255,255,255));//kareleri cizdirme
       	}
    }
    draw_sprite(screen,buffer,0,0);//cizdirme
    sil_hx=5;
    int komsu1, komsu2;
    int kom1x, kom1y, kom2x, kom2y;
    int satir1=satir*satir;
    for(int x=0;x<satir1;x++){
        for(int y=0;y<satir1;y++){
            if(R[x][y]==0 || R[x][y]==100){
                komsu1=x;
                komsu2=y;
                kom1x=(komsu1%satir)*25+35;
                kom1y=(komsu1/satir)*25+35;
                kom2x=(komsu2%satir)*25+35;
                kom2y=(komsu2/satir)*25+35;
                if(kom1x==kom2x){
                    if(komsu2>komsu1){
                        kom1y=((komsu1/satir)+1)*25+35;
                        line(screen, kom1x, kom1y, kom1x+25, kom1y, makecol(0, 0, 0));
                    }
                    else if(komsu2<komsu1){
                        line(screen, kom1x, kom1y, kom1x+25, kom1y, makecol(0, 0, 0));
                    }
                }
                else if(kom1y==kom2y){
                    if(komsu2>komsu1){
                        line(screen, kom2x, kom2y, kom2x, kom2y+25, makecol(0, 0, 0));
                    }
                    else if(komsu2<komsu1){
                        line(screen, kom1x, kom1y, kom1x, kom1y+25, makecol(0, 0, 0));
                    }
                }
            }
        }
    }
    //--------------------------------------------------
    int test=0;
	char val[3];
	int tusg,tush,tusi;
	int giris,e=0;
	int hedef,e1=0;
	int iter,e2=0,k1=10,k2=20;
	while(test!=1){
        textout_right_ex(screen, font, "Hangi odadan girmek istiyorsunuz?",SCREEN_W - 10, k1, makecol(255,255,255), -1);
        while(tusg!=13){
            val[e] = readkey();
            tusg=val[e];
            e++;
        }
        tusg=0;
        giris=sayi_cevir(e,val);
        textprintf_right_ex(screen, font, SCREEN_W - 10, k2,makecol(255, 255, 255), -1,"GIRIS= %d", giris);
        if(giris/satir==(satir-1))
            test=1;
        else if(giris%satir==0 && giris!=0)
            test=1;
        else if(giris/satir==0)
            test=1;
        else if(giris%satir==(satir-1) && giris/satir>0)
            test=1;
        else
            test=0;
        k1=k1+20;
        k2=k2+20;
        e=0;
	}
    if(giris/satir==(satir-1)){
        sil_gy=((giris/satir)+1)*25+35;
        sil_gx=(giris%satir)*25+35;
        line(screen, sil_gx, sil_gy, sil_gx+25, sil_gy, makecol(0, 0, 0));
    }
    else if(giris%satir==0 && giris!=0){
        sil_gx=(giris%satir)*25+35;
        sil_gy=(giris/satir)*25+35;
        line(screen, sil_gx, sil_gy, sil_gx, sil_gy+25, makecol(0, 0, 0));
    }
    else if(giris/satir==0){
        sil_gx=(giris%satir)*25+35;
        sil_gy=(giris/satir)*25+35;
        line(screen, sil_gx, sil_gy, sil_gx+25, sil_gy, makecol(0, 0, 0));
    }
    else if(giris%satir==(satir-1) && giris/satir>0){
        sil_gy=(giris/satir)*25+35;
        sil_gx=((giris%satir)+1)*25+35;
        line(screen, sil_gx, sil_gy, sil_gx, sil_gy+25, makecol(0, 0, 0));
    }
    test=0;
    k1=k1+20;
    k2=k2+20;
    while(test!=1){
        textout_right_ex(screen, font, "Hangi odadan cikmak istiyorsunuz?",SCREEN_W - 10, k1, makecol(255,255,255), -1);
        char val1[3];

        while(tush!=13){
            val1[e1] = readkey();
            tush=val1[e1];
            e1++;
        }
        tush=0;
        hedef=sayi_cevir(e1,val1);
        textprintf_right_ex(screen, font, SCREEN_W - 10, k2,makecol(255, 255, 255), -1,"HEDEF= %d", hedef);
        if(hedef/satir==(satir-1))
            test=1;
        else if(hedef%satir==0)
            test=1;
        else if(hedef/satir==0)
            test=1;
        else if(hedef%satir==(satir-1) && hedef/satir>0)
            test=1;
        else
            test=0;
        e1=0;
        k1=k1+20;
        k2=k2+20;
	}

    if(hedef/satir==(satir-1)){
        sil_gy=((hedef/satir)+1)*25+35;
        sil_gx=(hedef%satir)*25+35;
        line(screen, sil_gx, sil_gy, sil_gx+25, sil_gy, makecol(0, 0, 0));
    }
    else if(hedef%satir==0){
        sil_gx=(hedef%satir)*25+35;
        sil_gy=(hedef/satir)*25+35;
        line(screen, sil_gx, sil_gy, sil_gx, sil_gy+25, makecol(0, 0, 0));
    }
    else if(hedef/satir==0){
        sil_gx=(hedef%satir)*25+35;
        sil_gy=(hedef/satir)*25+35;
        line(screen, sil_gx, sil_gy, sil_gx+25, sil_gy, makecol(0, 0, 0));
    }
    else if(hedef%satir==(satir-1) && hedef/satir>0){
        sil_gy=(hedef/satir)*25+35;
        sil_gx=((hedef%satir)+1)*25+35;
        line(screen, sil_gx, sil_gy, sil_gx, sil_gy+25, makecol(0, 0, 0));
    }
    k1=k1+20;
    k2=k2+20;
    textout_right_ex(screen, font, "Iterasyon sayisini girin.",SCREEN_W - 10,k1 , makecol(255,255,255), -1);
    char val2[10];

	while(tusi!=13){
        val2[e2] = readkey();
        tusi=val2[e2];
        e2++;
	}
	iter=sayi_cevir(e2,val2);
    textprintf_right_ex(screen, font, SCREEN_W - 10, k2,makecol(255, 255, 255), -1,"ITERASYON= %d", iter);

    for(int i=0;i<satir1;i++){
        if(R[i][hedef]==0){
            R[i][hedef]=100;
        }
    }
    R[hedef][hedef]=100;



    satir=satir1;
    int sayac=0;
    int rastgele;
    int say=0;
    int aksiyon;
    float enb=-1;
    int durum;
    durum=giris;
    float sabit=0.8;
    int q=0;
    while(q<iter){
        for(i=0;i<satir;i++){
            if(R[durum][i]==0 || R[durum][i]==100){
                sayac++;
            }
        }
        rastgele=1+rand()%sayac;
        for(i=0;i<satir;i++){
            if(R[durum][i]==0 || R[durum][i]==100){
                say++;
                if(say==rastgele){
                    aksiyon=i;
                }
            }
        }
        for(int y=0;y<satir;y++){
            if(R[aksiyon][y]==0 || R[aksiyon][y]==100){
                if(Q[aksiyon][y]>=enb){
                    enb=Q[aksiyon][y];
                }
            }
        }
        say=0;
        sayac=0;
        Q[durum][aksiyon]=R[durum][aksiyon]+(sabit*enb);
        durum=aksiyon;
        enb=-1;
        if(durum==hedef){
            durum=giris;
            q++;
        }
    }

    int yol=giris;
    int yol1;
    int buyuk_komsu;
    int o=0;
    int yollar[satir];
    while(yol!=hedef){
        buyuk_komsu=Q[yol][0];
        for(int p=0;p<satir;p++){
            if(Q[yol][p]>=buyuk_komsu){
                buyuk_komsu=Q[yol][p];
                yol1=p;
            }
        }
        yollar[o]=yol;
        o++;
        yol=yol1;
    }
    if(yol==hedef){
        yollar[o]=hedef;
    }
    for(i=0;i<satir1;i++){
        for(int j=0;j<satir1;j++){
            Q[i][j]=Q[i][j]*sil_hx;
        }
    }

    ofstream outR("outR.txt",ios::out);
    outR<<"R matrisi"<<endl;
    for(int i=0;i<satir;i++){
        for(int j=0;j<satir;j++){
            outR<<R[i][j]<<" ";
        }
        outR<<endl;
    }
    outR.close();
    ofstream outQ("outQ.txt",ios::out);
    outQ<<"Q matrisi"<<endl;
    for(int i=0;i<satir;i++){
        for(int j=0;j<satir;j++){
            outQ<<Q[i][j]<<" ";
        }
        outQ<<endl;
    }
    outQ.close();
    ofstream outPath("outPath.txt",ios::out);
    for(int i=0;i<=o;i++){
        outPath<<yollar[i]<<"-";
    }
    outPath.close();

    satir=sqrt(satir);
    int yol1_x,yol1_y,yol2_x,yol2_y;
        for(int i=0;i<o;i++){
            yol1_x=(yollar[i]%satir)*25+35;
            yol1_y=(yollar[i]/satir)*25+35;
            yol2_x=(yollar[i+1]%satir)*25+35;
            yol2_y=(yollar[i+1]/satir)*25+35;
            line(screen, yol1_x+12.5, yol1_y+12.5, yol2_x+12.5, yol2_y+12.5, makecol(250, 0, 0));
        }
    readkey();
    return 0;

}
END_OF_MAIN()
void Baslat()
{
	int depth,res;
	allegro_init();
	install_keyboard();
	depth=desktop_color_depth();
	if(depth==0)
        depth=32;
	set_color_depth(depth);//renk derinligi

	res=set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0);//sanal ekran olusturur

if(res !=0)
{
	allegro_message(allegro_error);
	exit(-1);
}
	install_timer();
	install_keyboard();
	install_mouse();
}
void Bitir()
{
	clear_keybuf();
}
