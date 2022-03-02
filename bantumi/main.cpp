#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <time.h>
#include "bantumi.h"

using namespace std;

//colori


const int CIOTOLE = 14;

int main(){
	
	srand(time(0));
	
	initwindow(1800,900);
	//menu
	
	//regole
	setcolor(COLOR(255,255,0));
	rectangle(0,0,getmaxx(),getmaxy());
	setfillstyle(1,COLOR(255,255,0));
	floodfill(50,50,COLOR(255,255,0));
	
	setcolor(COLOR(0,0,0));
	setbkcolor(COLOR(255,255,0));
	settextstyle(3,0,7);
	settextjustify(1,1);
	outtextxy(getmaxx()/2,80,"Bantumi");
	
	settextstyle(3,0,5);
	outtextxy(getmaxx()/2,180,"Scopo del Gioco:");
	
	outtextxy(getmaxx()/2,240,"Lo scopo del gioco e' avere il maggior numero di semi nelle proprie ciotole rettangolari");
	outtextxy(getmaxx()/2,300,"Si gioca in due(Giocatore P1 in basso P2 in alto) Il gioco consiste nel cliccare su una ciotola ");
	outtextxy(getmaxx()/2,360,"di modo che i semi al suo interno si distribuiscano uno in ogni ciotola in senso antiorario ");
	
	outtextxy(getmaxx()/2,440,"Casi particolari: ");
	outtextxy(getmaxx()/2,500,"Se l' ultimo seme distribuito si posa nella ciotola rettangolare e' possibile rigiocare");
	outtextxy(getmaxx()/2,560,"Se l' ultimo seme distribuito si posa in una ciotola senza semi");
	outtextxy(getmaxx()/2,620,"acquisisci i semi avversari che si trovano nella ciotola direttamente sovrastante o sottostante");
	
	outtextxy(getmaxx()/2,700,"Fine Gioco: ");
	outtextxy(getmaxx()/2,760,"La partita si conclude quando tutte le ciotole di un giocatore sono vuote");
	outtextxy(getmaxx()/2,820,"I semi rimanenti nelle ciotole tonde vengono sommati sommati a quelli della ciotola rettangolare");
	setcolor(COLOR(255,0,0));
	outtextxy(getmaxx()/2,getmaxy()-10,"Premi qualsiasi pulsante per iniziare");
	
	getch();
	

	cleardevice();
	
	
	setcolor(COLOR(0,0,0));
	rectangle(0,0,getmaxx(),getmaxy());
	setfillstyle(1,COLOR(0,0,0));
	floodfill(50,50,COLOR(0,0,0));
	

	/*
	delay(100);
	setcolor(COLOR(255,255,0));
	rectangle(0,0,getmaxx(),getmaxy());
	setfillstyle(1,COLOR(255,255,0));
	floodfill(50,50,COLOR(255,255,0));
	*/
	
	//table game
	readBMP("tablepixel.bmp");
	
	int select=0;
	
	bool ia=false;
	//selezione giocatore o IA
	settextstyle(3,0,4);
	setcolor(COLOR(0,0,0));
	setbkcolor(COLOR(255,255,0));
	outtextxy(getmaxx()/2,getmaxy()/2-110,"Digita 0 per fare P1 vs P2");
	outtextxy(getmaxx()/2,getmaxy()/2-70,"Digita 1 per sfidare la CPU");
	outtextxy(getmaxx()/2,getmaxy()/2-30,"poi premi invio per confermare");
	
	outtextxy(getmaxx()/2,getmaxy()/2+30,"P1   VS  P2");
	
	while(select!=13){
		select = getch();

		
		
		if(select==48){
			outtextxy(getmaxx()/2,getmaxy()/2+30,"P1   VS  P2");
			ia=false;
		}
		
		if(select==49){
			outtextxy(getmaxx()/2,getmaxy()/2+30,"P1 VS CPU");
			ia=true;
		}
		
		
	}
	
	select=0;
	
	end();
	//numero semi
	int nSemi = 3;
	char num[2];
	num[1]='\0';

	settextstyle(3,0,4);
	setcolor(COLOR(0,0,0));
	setbkcolor(COLOR(255,255,0));
	outtextxy(getmaxx()/2,getmaxy()/2-110,"Digita un numero da 3 a 6 per indicare");
	outtextxy(getmaxx()/2,getmaxy()/2-70,"il numero di semi poi premi invio");
	outtextxy(getmaxx()/2,getmaxy()/2-30,"seleziona 0 per semi casuali");
	
	settextstyle(3,0,5);
	
	outtextxy(getmaxx()/2,getmaxy()/2+30,"3");
	while(select!=13){
		select = getch();
		
		if(select>=51 && select<=54){
			setcolor(COLOR(255,255,0));
			outtextxy(getmaxx()/2,getmaxy()/2+30,"Random");
			setcolor(COLOR(0,0,0));			
		}

		
		
		if(select>=51 && select<=54){
			nSemi=select-48;
			num[0]=select;
			outtextxy(getmaxx()/2,getmaxy()/2+30,num);
		}
		
		if(select==48){
			outtextxy(getmaxx()/2,getmaxy()/2+30,"Random");
			nSemi=rand()%4+3;
		}
		
		
	}
	end();
	
	
	//random start
	int animazione=100, scelta=0;
	settextstyle(3,0,4);
	outtextxy(getmaxx()/2,getmaxy()/2-110,"Scegliendo il primo giocatore");
	outtextxy(getmaxx()/2,getmaxy()/2-70,"che inizia...");
	
	while(animazione!=700){
		setcolor(COLOR(255,0,0));
		circle(getmaxx()/2, getmaxy()/2+40,80);
		setfillstyle(1,COLOR(255,0,0));
		floodfill(getmaxx()/2,getmaxy()/2,COLOR(255,0,0));
		
		setcolor(COLOR(255,255,255));
		setbkcolor(COLOR(255,0,0));
		outtextxy(getmaxx()/2,getmaxy()/2+40,"P2");
		
		delay(animazione);
		
		setcolor(COLOR(0,0,255));
		circle(getmaxx()/2, getmaxy()/2+40,80);
		setfillstyle(1,COLOR(0,0,255));
		floodfill(getmaxx()/2,getmaxy()/2,COLOR(0,0,255));
		setcolor(COLOR(255,255,255));
		setbkcolor(COLOR(0,0,255));
		outtextxy(getmaxx()/2,getmaxy()/2+40,"P1");
		
		
		delay(animazione);
		animazione+=100;	
	}
	
	bool p1=true, p2=true;
	scelta=rand()%2;
	if(scelta==0){
		setcolor(COLOR(0,0,255));
		circle(getmaxx()/2, getmaxy()/2+40,80);
		setfillstyle(1,COLOR(0,0,255));
		floodfill(getmaxx()/2,getmaxy()/2,COLOR(0,0,255));
		setcolor(COLOR(255,255,255));
		setbkcolor(COLOR(0,0,255));
		outtextxy(getmaxx()/2,getmaxy()/2+40,"P1");
	}
	
	else{
		setcolor(COLOR(255,0,0));
		circle(getmaxx()/2, getmaxy()/2+40,80);
		setfillstyle(1,COLOR(255,0,0));
		floodfill(getmaxx()/2,getmaxy()/2,COLOR(255,0,0));
		setcolor(COLOR(255,255,255));
		setbkcolor(COLOR(255,0,0));
		outtextxy(getmaxx()/2,getmaxy()/2+40,"P2");
		p1=false;
		
		
	}
	
	delay(1000);
	end();
	//ciotole
	int xCiotola=265, yCiotola=150;
	
	
	
	int semiTavolo[CIOTOLE]; //Ciotole giocatori
	char scritta[10];


	
	//Inizializzazione ciotole con n semi
	for(int i=0; i<CIOTOLE; i++){
		semiTavolo[i]=nSemi;
		if(i==6 || i==13){
			semiTavolo[i]=0;
			
		}
		
	}
	
	for(int k = 1; k<=2; k++){
		
		for(int i=0; i<CIOTOLE/2-1; i++){

			ciotola(xCiotola, yCiotola);
			
			setcolor(COLOR(255,255,255));
			setbkcolor(COLOR(33, 22, 10));
			settextstyle(3,0,4);
			settextjustify(1,1);
			
			if(k==1){
				
				itoa(semiTavolo[5-i], scritta, 10 );
			}
			
			else{
				
				itoa(semiTavolo[i+7], scritta, 10 );
			}

			outtextxy(xCiotola,yCiotola, scritta);
			xCiotola+=250;

		}
		yCiotola=getmaxy()-150;
		xCiotola = 265;
	}
	
	
	xCiotola=265;
	yCiotola = getmaxy()-(70*2);
	
	//ciotole grandi
	
	//rosso
	setcolor(COLOR(0,0,0));
	rectangle(50,getmaxy()/2-170,300,getmaxy()/2+170);
	rectangle(70,getmaxy()/2-150,280,getmaxy()/2+150);
	setfillstyle(1,COLOR(101, 67, 33));
	floodfill(60,getmaxy()/2, COLOR(0,0,0) );
	setfillstyle(1,COLOR(255, 0, 0));
	floodfill(150,getmaxy()/2, COLOR(0,0,0) );
	setcolor(COLOR(255,255,255));
	setbkcolor(COLOR(255,0,0));
	itoa(semiTavolo[CIOTOLE/2-1],scritta,10);
	outtextxy(175,getmaxy()/2,scritta);
	
	
	
	//blu
	setcolor(COLOR(0,0,0));
	rectangle(getmaxx()-50,getmaxy()/2-170,getmaxx()-300,getmaxy()/2+170);
	rectangle(getmaxx()-70,getmaxy()/2-150,getmaxx()-280,getmaxy()/2+150);
	setfillstyle(1,COLOR(101, 67, 33));
	floodfill(getmaxx()-55,getmaxy()/2, COLOR(0,0,0) );
	setfillstyle(1,COLOR(0, 0, 255));
	floodfill(getmaxx()-250,getmaxy()/2, COLOR(0,0,0) );
	setcolor(COLOR(255,255,255));
	setbkcolor(COLOR(0,0,255));
	itoa(semiTavolo[CIOTOLE-1],scritta,10);
	outtextxy(getmaxx()-175,getmaxy()/2,scritta);





	//user indicator	
	
	
	
	
	

	bool move = true, partita=true;
	int xm, ym, posizione, semiValore, rubaSemi=0, sommaVittoriaP1=0, sommaVittoriaP2=0;
	int y1, y2;
	
	while(partita==true){
		
		
		if(p1==true){
			//user p1
			user(0,0,255);
			setcolor(COLOR(255,255,255));
			setbkcolor(COLOR(0,0,255));
			outtextxy(getmaxx()/2,getmaxy()/2+85,"P1");
		}

		
		
		
		//mossa p1
		while(p1==true){
		//click mouse p1
			while(!ismouseclick(WM_LBUTTONDOWN)){
					delay(20);
			}
			getmouseclick(WM_LBUTTONDOWN, xm, ym);
			setfillstyle(1,COLOR(0, 0, 255));
				
			posizione=mossa(xm,ym,true,getmaxy()-50, getmaxy()-250);
			if(posizione==300){
				p1=true;
			}
		
			else{
				semiValore=semiTavolo[posizione];
				
				if(semiValore!=0){
					semiTavolo[posizione]=0;
					
					
					setcolor(COLOR(255,255,255));
					setbkcolor(COLOR(33, 22, 10));
					settextstyle(3,0,4);
					settextjustify(1,1);				
					itoa(semiTavolo[posizione], scritta, 10 );
					clear(xCiotola+250*(posizione-7),getmaxy()-150);
					outtextxy(xCiotola+250*(posizione-7),getmaxy()-150, scritta);
					
					//distribuzione semi
					for(int i=1; i<=semiValore; i++){
						delay(750);
											
						if(posizione + i == 14){
							semiValore -= i;

							posizione = 0;
							i=0;
						}
						
						if(posizione+i==6){
							posizione++;
						}
						

						
						semiTavolo[posizione+i]++;
						itoa(semiTavolo[posizione+i], scritta, 10 );
						
						//mostrare valori
						
						if(posizione+i == CIOTOLE-1){
							setbkcolor(COLOR(0,0,255));
							outtextxy(getmaxx()-175,getmaxy()/2,scritta);
						}
						
						else if(posizione+i == (CIOTOLE/2)-1){
							setbkcolor(COLOR(255,0,0));
							outtextxy(175,getmaxy()/2,scritta);
						}
						
						
						else{
							setbkcolor(COLOR(33, 22, 10));
							if(posizione+i>=7){
								outtextxy(xCiotola+250*((posizione+i)-7),getmaxy()-150, scritta);	
							}
							
							else{
								outtextxy(xCiotola+250*((posizione-i)+5),150, scritta);
							}
							
						}
						
						//colora contorno in movimento
						setfillstyle(1,COLOR(0,0,255));
						selezione(posizione, i);
						
						//continua turno
						if(i == semiValore && posizione + i == CIOTOLE-1 ){
							p1 = true;	
						}
						
						//ruba semi
						
						else if( i == semiValore && semiTavolo[posizione+i]==1 && posizione + i > 6){
							
							//scrpt
							rubaSemi = semiTavolo[posizione+i] + semiTavolo[posizione+i-((posizione+i-6)*2)];
							semiTavolo[13]+=rubaSemi;
							semiTavolo[posizione+i] = 0;
							semiTavolo[posizione+i-((posizione+i-6)*2)] = 0;	
							
							//grafica
							scritta[0]=48;
							clear(xCiotola+250*(posizione+i-7),getmaxy()-150);
							outtextxy(xCiotola+250*(posizione+i-7),getmaxy()-150, scritta);
							clear(xCiotola+250*(posizione+i-7),150);
							outtextxy(xCiotola+250*(posizione+i-7),150, scritta);
							itoa (semiTavolo[13], scritta, 10 );
							setbkcolor(COLOR(0,0,255));
							outtextxy(getmaxx()-175,getmaxy()/2,scritta);
							p1 = false;
						}
						
						else{
							p1 = false;
						}
	
					}
				}
				
				
				
				
				//ciotola senza volore
				else{
					p1=true;
					setcolor(COLOR(0,0,0));
					setbkcolor(COLOR(255,255,0));
					outtextxy(getmaxx()/2,getmaxy()/2+132,"Non puoi scegliere questa Ciotola");
					delay(1800);
					
					setcolor(COLOR(255,255,0));
					setbkcolor(COLOR(255,255,0));
					outtextxy(getmaxx()/2,getmaxy()/2+132,"Non puoi scegliere questa Ciotola");	
				}
			}
			
			for(int i = 0; i< 6; i++){
				sommaVittoriaP1+=semiTavolo[i+7];	
			}
			
			if(sommaVittoriaP1==0){
				p1=false;
				partita=false;
			}
			
			else{
				sommaVittoriaP1=0;	
			}
			
			
			
		}
		

		if(partita==false){
			break;
		}
		

		
		
		
		delay(500);
		
		
		
		//user p2
		user(255,0,0);
		setcolor(COLOR(255,255,255));
		setbkcolor(COLOR(255,0,0));
		outtextxy(getmaxx()/2,getmaxy()/2+85,"P2");
		bool strat=true;
		//mossa p2
		do{
			
			
			
			if(ia==false){
				//click mouse p2
				while(!ismouseclick(WM_LBUTTONDOWN)){
						delay(20);
				}
				getmouseclick(WM_LBUTTONDOWN, xm, ym);
				setfillstyle(1,COLOR(255,0,0));
				posizione=mossa(xm,ym,false,250,50);
			}
			
			
			//script IA
			
			else{
				
				if(semiTavolo[13]>semiTavolo[6]+3){
					strat=false;
				}
				
				else{
					strat=true;
				}
				
				int iamove;
				
				delay(300);
				iamove=iamain(semiTavolo, strat);
				if(iamove==300){
					do{
						posizione=rand()%6;
					}while(semiTavolo[posizione]==0);
					
				}
				else{
					posizione=iamove;
				}
				
				//colore selezione
				setfillstyle(1,COLOR(255,0,0));
				selection(1500-(250*(posizione+1)),false);
				delay(1000);
				resetSelection(1500-(250*(posizione+1)),false);
			}
			
			
			
			
			
			
			if(posizione==300){
				p2=true;
			}
			
			else{
				p1=false;
				semiValore=semiTavolo[posizione];
				
				if(semiValore!=0){
					semiTavolo[posizione]=0;
					

					setcolor(COLOR(255,255,255));
					setbkcolor(COLOR(33, 22, 10));
					settextstyle(3,0,4);
					settextjustify(1,1);
					itoa(semiTavolo[posizione], scritta, 10 );	
					
					clear(xCiotola+1500-(250*(posizione+1)),150);			
					outtextxy(xCiotola+1500-(250*(posizione+1)),150, scritta);
					
					//distribuzione semi
					for(int i=1; i<=semiValore; i++){
						delay(750);
						if(posizione + i == 13){
							semiValore -= i;

							posizione = 0;
							i=0;
						}
						

						semiTavolo[posizione+i]++;
						itoa(semiTavolo[posizione+i], scritta, 10 );
						
						//mostrare valori
						
						if(posizione+i == (CIOTOLE/2)-1){
							setbkcolor(COLOR(255,0,0));
							outtextxy(175,getmaxy()/2,scritta);
						}
						
						else if(posizione+i == CIOTOLE-1){
							setbkcolor(COLOR(0,0,255));
							outtextxy(getmaxx()-175,getmaxy()/2,scritta);							
						}
						
						
						else{
							setbkcolor(COLOR(33, 22, 10));
							if(posizione+i<6){
								outtextxy(xCiotola+1500-(250*(posizione+i+1)),150, scritta);
								
							}
							
							else{
								outtextxy(xCiotola+250*(posizione+i-7),getmaxy()-150, scritta);	
							}
							
						}
						
						//colora contorno in movimento
						setfillstyle(1,COLOR(255,0,0));
						selezione(posizione, i);
						
						//continua turno
						if(i == semiValore && posizione + i == (CIOTOLE/2 )-1){
							p2 = true;	
						}
						
						//ruba semi
						
						else if( i == semiValore && semiTavolo[posizione+i]==1 && posizione + i < 6){
							
							//scrpt
							rubaSemi = semiTavolo[posizione+i] + semiTavolo[posizione+i+(-1*(posizione+i-6)*2)];
	
							semiTavolo[6]+=rubaSemi;
							semiTavolo[posizione+i] = 0;
							semiTavolo[posizione+i+(-1*(posizione+i-6)*2)] = 0;	
							
							//grafica
							scritta[0]=48;
							clear(xCiotola+1500-(250*(posizione+i+1)),150);
							outtextxy(xCiotola+1500-(250*(posizione+i+1)),150, scritta);
							clear(xCiotola+250*(5-(posizione+i)),getmaxy()-150);
							outtextxy(xCiotola+250*(5-(posizione+i)),getmaxy()-150, scritta);	
							itoa (semiTavolo[6], scritta, 10 );
							setbkcolor(COLOR(255,0,0));
							outtextxy(175,getmaxy()/2,scritta);
							p2 = false;
						}
						
						else{
							p2 = false;
						}
	
					}
				}
				
				
				
				
				//ciotola senza volore
				else{
					p2=true;
					setcolor(COLOR(0,0,0));
					setbkcolor(COLOR(255,255,0));
					outtextxy(getmaxx()/2,getmaxy()/2+132,"Non puoi scegliere questa Ciotola");
					delay(1800);
					
					setcolor(COLOR(255,255,0));
					setbkcolor(COLOR(255,255,0));
					outtextxy(getmaxx()/2,getmaxy()/2+132,"Non puoi scegliere questa Ciotola");	
				}
			}
			
			
			for(int i = 0; i< 6; i++){
				sommaVittoriaP2+=semiTavolo[i];	
			}
			
			
			if(sommaVittoriaP2==0){
				p2=false;
				partita=false;
			}
				
			else{
				sommaVittoriaP2=0;	
			}
			
			
		}while(p2==true);
		
		p2=true;
		p1=true;
	}
	
	end();
	outtextxy(getmaxx()/2,getmaxy()/2,"Sommando le ciotole rimaste...");
	delay(300);
	

	
	//azzeramento ciotole
	xCiotola=265;
	yCiotola=150;

	for(int k = 1; k<=2; k++){
		for(int i=0; i<CIOTOLE/2-1; i++){
			setcolor(COLOR(255,255,255));
			setbkcolor(COLOR(33, 22, 10));
			settextstyle(3,0,4);
			settextjustify(1,1);
			
			if(k==1){
				
				itoa(0, scritta, 10 );
			}
			
			else{
				
				itoa(0, scritta, 10 );
			}
			
			clear(xCiotola,yCiotola);	
			outtextxy(xCiotola,yCiotola, scritta);
			xCiotola+=250;
			delay(200);
		}
		yCiotola=getmaxy()-150;
		xCiotola = 265;
	}
	
	//somma ciotole rimaste
	setcolor(COLOR(255,255,255));
	
	for(int i = 0; i< 6; i++){
		sommaVittoriaP2+=semiTavolo[i];	
	}
	semiTavolo[6]+=sommaVittoriaP2;
	itoa(semiTavolo[CIOTOLE/2-1],scritta,10);
	setbkcolor(COLOR(255,0,0));
	outtextxy(175,getmaxy()/2,scritta);
	
	
	for(int i = 0; i< 6; i++){
		sommaVittoriaP1+=semiTavolo[i+7];	
	}
	semiTavolo[13]+=sommaVittoriaP1;
	itoa(semiTavolo[CIOTOLE-1],scritta,10);
	setbkcolor(COLOR(0,0,255));
	outtextxy(getmaxx()-175,getmaxy()/2,scritta);
	delay(1200);
	
	//scelta vincitore
	end();
	if(semiTavolo[6]>semiTavolo[13]){

		outtextxy(getmaxx()/2,getmaxy()/2,"Player 2 Hai vinto!");
	}
	
	else if(semiTavolo[13]>semiTavolo[6]){		
		outtextxy(getmaxx()/2,getmaxy()/2,"Player 1 Hai vinto!");	
	}
	
	else{
		outtextxy(getmaxx()/2,getmaxy()/2,"Pareggio");	
	}
	
	
	outtextxy(getmaxx()/2,getmaxy()/2+132,"Premi qualsiasi tasto per uscire");
	
	
	
	
	getch();
	
}


