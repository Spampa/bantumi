#include <iostream>
using namespace std;

//functions
const int NC = 14;

void raedBMP(char* filename);
void ciotola(int xc, int yc);
void cotolaGrande(int xg, int yg);
void user(int r, int g, int b);
void selection(int sum, bool yC=true);
void resetSelection(int sum, bool yC );
int mossa(int xmouse, int ymouse, bool y, int y1, int y2);
void clear(int x, int y);
void end(void);
int iamain(int v[], bool phase);
void selezione(int pos ,int indice);

void selezione(int pos ,int indice){
	
	if(pos+indice<13 && pos+indice>6 ){
		selection(250*(pos+indice-7),true);
		delay(500);
		resetSelection(250*(pos+indice-7),true);		
	}
						
	else if(pos+indice+1<7){
		selection(1500-(250*(pos+indice+1)),false);
		delay(500);
		resetSelection(1500-(250*(pos+indice+1)),false);							
	}
	
	else if(pos+indice==6){
		floodfill(55,getmaxy()/2-150,COLOR(0,0,0));
		delay(500);
		setfillstyle(1,COLOR(101, 67, 33));
		floodfill(55,getmaxy()/2-150,COLOR(0,0,0));
	}
	
	else if(pos+indice==13){
		
		floodfill(getmaxx()-55,getmaxy()/2-165,COLOR(0,0,0));
		delay(500);
		setfillstyle(1,COLOR(101, 67, 33));
		floodfill(getmaxx()-55,getmaxy()/2-165,COLOR(0,0,0));
	}
	
}


int iamain(int v[], bool phase){
	
	//semi nel granaio
	int valore;
	for(int i=5; i>=0; i--){
		valore=v[i];
		if(i+valore==6){
			return i;
		}
	}
	
	//semi nello zero
	int zero, max, indice, maxSemi=-1;
	
	for(int i=0; i<6; i++){
		valore=v[i];
		for(int k=i; k<6; k++){
			if(v[k]==0 && valore!=0){
				if(i+valore==k){
					
					max=v[k+(-1*(k-6)*2)];
					if(max>=maxSemi){
						indice=i;
						maxSemi=max;		
					}
					
					
					
				}
			}
			
		}
		
	}
	if(maxSemi!=-1){
		return indice;
	}

	
	maxSemi=-1;
	if(phase==true){
		//prepara prossima mossa
		for(int i=0; i<6; i++){
			valore=v[i];
			for(int k=i; k<6; k++){
				if(i+valore==k && valore!=0){	
					max=v[k+(-1*(k-6)*2)];
					if(max>=maxSemi){
						indice=i+valore;
						maxSemi=max;		
					}	
				}	
			}	
		}
	}
	
	if(maxSemi!=-1){
		return indice;
	}
	
	//difesa
	else if(phase==false || maxSemi==-1){
		int valuep1;
		for(int i=7; i<13; i++){
			valuep1=v[i];
			if(valore+i==0){
				for(int k=0; k<6; k++){
					valore=v[k];
					if(valore+k>=valuep1){
						return k;
					}
				}
			}
		}
		
		for(int i=7; i<13; i++){
			valuep1=v[i];
			if(valore+i==0){
				indice=i-((i-6)*2);	
				return indice;
			}
		}
		
		//temporeggia
		int s1=0, s2=0;
		for(int i=0; i<6; i++){
			s1+=v[i];
		}
		
		for(int i=7; i<13; i++){
			s2+=v[i];
		}
		
		int indMin=100;
		
		for(int i=0; i<6; i++){
			valore=v[i];
			if(valore<indMin){
				indMin=valore;
				indice=i;
			}
		}
		
		if(indMin!=100){
			return indice;
		}
		
	}

	else{
		return 300;
	}
	
}

void showResults(int vetCiotole[]){
	for(int i=0; i<NC; i++){
			cout<<vetCiotole[i]<<"\t";
			if(i==6){
				cout<<endl;
			}
		}
	cout<<endl;	
}


void end(void){
	setcolor(COLOR(100,0,0));
	rectangle(getmaxx()/2-290,getmaxy()/2-140, getmaxx()/2+290,getmaxy()/2+132);
	setfillstyle(1,COLOR(255,255,0));
	floodfill(getmaxx()/2,getmaxy()/2,COLOR(100,0,0));
	setcolor(COLOR(255,255,0));
	rectangle(getmaxx()/2-290,getmaxy()/2-140, getmaxx()/2+290,getmaxy()/2+132);
	setcolor(COLOR(0,0,0));
	setbkcolor(COLOR(255, 255, 0));
}

void clear(int x, int y){
		setcolor(COLOR(0,0,0));
		circle(x,y,40);
		setfillstyle(1,COLOR(33, 22, 10));
		floodfill(x,y,COLOR(0,0,0));
		setcolor(COLOR(33, 22, 10));
		circle(x,y,40);
		setcolor(COLOR(255,255,255));
}





int mossa(int xmouse, int ymouse, bool y, int y1, int y2){
	
	int add=250, pos=0;
	bool move=true;
	
	if(xmouse>=165 && xmouse<=365 && ymouse<=y1 && ymouse>=y2){	
			selection(0,y);
			
			if(y==true){
				pos=7;
			}
			
			else{
				pos=5;
			}
			
			move=false;
	}
					
	else if(xmouse>=165+add && xmouse<=365+add && ymouse<=y1 && ymouse>=y2){
			selection(add, y);
			if(y==true){
				pos=8;
			}
			
			else{
				pos=4;
			}	
			move=false;
	}
					
	else if(xmouse>=165+add*2 && xmouse<=365+add*2 && ymouse<=y1 && ymouse>=y2){
		add*=2;
		selection(add, y);
		if(y==true){
			pos=9;
		}
			
		else{
			pos=3;
		}
		move=false;
	}
	else if(xmouse>=165+add*3 && xmouse<=365+add*3 && ymouse<=y1 && ymouse>=y2){
		add*=3;
		selection(add, y);
		if(y==true){
			pos=10;
		}
			
		else{
			pos=2;
		}
		move=false;
	}
					
	else if(xmouse>=165+add*4 && xmouse<=365+add*4 && ymouse<=y1 && ymouse>=y2){
		add*=4;
		selection(add, y);
		if(y==true){
			pos=11;
		}
			
		else{
			pos=1;
		}
		move=false;
	}
				
	else if(xmouse>=165+add*5 && xmouse<=365+add*5 && ymouse<=y1 && ymouse>=y2){
		add*=5;
		selection(add, y);
		if(y==true){
			pos=12;
		}
			
		else{
			pos=0;
		}
		move=false;
	}
	
	if(move == true){
		return 300;
	}
	
	else{
		delay(1000);	
		if(xmouse>=165 && xmouse<=365){
			resetSelection(0,y);
		}
		
		else{
			resetSelection(add,y);
		}
		
		return pos;
			
	}
}
			
 

void selection(int sum, bool yC){
	int xC=265;
	int alt;
	
	if(yC==true){
		alt=getmaxy()-(70*2);
	}
	
	else{
		alt=150;
	}
	floodfill(xC+85+sum,alt, COLOR(0,0,0) );
}


void resetSelection(int sum, bool yC){
	int xC=265;
	int alt;
	if(yC==true){
		alt=getmaxy()-(70*2);
	}
	
	else{
		alt=150;
	}
	setfillstyle(1,COLOR(101, 67, 33));
	floodfill(xC+85+sum,alt, COLOR(0,0,0) );
}

//creazione ciotole
void ciotola(int xc, int yc){
	setcolor(COLOR(0,0,0));
	circle(xc,yc,100);
	circle(xc,yc,80);
	setfillstyle(1,COLOR(101, 67, 33));
	floodfill(xc+60, yc+60,COLOR(0,0,0));
	setfillstyle(1,COLOR(33, 22, 10));
	floodfill(xc, yc,COLOR(0,0,0));
}
	             
	                         
  
//player turn
void user(int r, int g, int b){
	
	setcolor(COLOR(r,g,b));
	line(getmaxx()/2, getmaxy()/2+100, getmaxx()/2+100, getmaxy()/2+100);
	line(getmaxx()/2, getmaxy()/2+100, getmaxx()/2-100, getmaxy()/2+100);
	arc (getmaxx()/2, getmaxy()/2+100, -1, 181, 100);
	setfillstyle(1,COLOR(r,g,b));
	floodfill(getmaxx()/2, getmaxy()/2+50,COLOR(r,g,b));
	
	setcolor(COLOR(0,0,0));
	circle(getmaxx()/2, getmaxy()/2-30,80);
	setfillstyle(1,COLOR(253,222,203));
	floodfill(getmaxx()/2, getmaxy()/2,COLOR(0,0,0));
}


//images
void readBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];

    // read the 54-byte header
    fread(info, sizeof(unsigned char), 54, f);

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
        std::cout<<width<<" x "<<height<<std::endl;
    // allocate 3 bytes per pixel
    int size = 3 * width * height;
    int off=0;
        int of=0;
        if ((width*3+of)%4!=0) of=2;
        size+=of*height;
   
    unsigned char* data = new unsigned char[size];
       

    // read the rest of the data at once
    fread(data, sizeof(unsigned char), size, f);  //devo leggere anche gli spazi tra una riga %8 e l'altra
    fclose(f);
   
       
        std::cout<<of<<" offset "<<std::endl;
        for(int y = 0; y < height; y ++){
             for(int x = 0; x < width; x ++){
                        putpixel(x,height-y,COLOR((int)data[y*width*3+x*3+off+2],(int)data[y*width*3+x*3+1+off],(int)data[y*width*3+x*3+off]));
                 }
                off+=of;
        }
}






