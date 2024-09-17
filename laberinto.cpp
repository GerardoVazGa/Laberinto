/*
	Universidad Autonoma de Aguascalientes
	Logica de programacion
	Mtra. Estela Lizbeth Mu�oz Andrade
	
	Ing. Sistemas Computacionales	1ero B
	
	Autores:
	Angel Ernesto Becerra Estrada
	Iram de la Rosa Hernandez
	Jaime...
	Gerardo Vazquez Galindo
*/

#include<iostream>
#include<windows.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

//definicion de las teclas de movimiento
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27

//Constantes delas medidas de los mapas
const int REN=19;
const int COL=25;

//Prototipos
void menu();
void cicloJuego();
void teclas();
void gotoxy(int x, int y);
void DibujarMapa1(int mapa[REN][COL]);
void DibujarMapa2(int mapa[REN][COL]);
void DibujarMapa3(int mapa[REN][COL]);
void borrar_cuerpo();
void guardar_posicion();
void dibujar_cuerpo();
void Ocultar_cursor();
void fin(int xf, int yf, int ds,int seg,int min);
void mostrarRecord(int ds1,int seg1,int min1, int ds2,int seg2,int min2, int ds,int seg,int min,int score);
void obstaculos();
void obstaculos2();
void obstaculos3();
void caso1();
void caso2();
void caso3();
void caso99();


//Variables globales
int cuerpo[200][2];
int n = 1;
int x = 0, y = 1;
int xc = 1, yc = 15;
int velocidad = 100;
char tecla;
int mapa[REN][COL];
int cont=0;
int xf, yf;
int opc;
char cadena1[15], cadena2[15];
int vidas=3;
int bandera=0;
int score=0, suma;
int min1, min2, seg1, seg2, ds1, ds2, ds, seg, min;


int main(){
	//En este apartado se preguntara dos veces al usuario su nombre y si coinciden al ser comparados lo mandaran al menu y si no coincide mostrara un mensaje.
	char cadena1[15], cadena2[15];
	printf("Introduce tu nombre: ");
	scanf("%s", cadena1);
	printf("Vuelve a introducir tu nombre: ");
	scanf("%s", cadena2);
	system("cls");
	if(strcmp(cadena1, cadena2)==0){
		menu();
	}
	else{
		printf("No coincide con lo verificado");
	}
	return 0;
	
}

//Sera el inicio del juego, es para seleccionar lo que es el mapa y realizar todo lo debido al prograna
void menu(){
	do{
		int c, f;
		printf("     %c                   %c          %c%c%c%c%c%c%c    %c%c%c%c%c%c%c   %c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c   %c%c       %c   %c%c%c%c%c%c%c%c%c      %c%c%c%c%c\n",219,219,219,223,223,223,223,223,219,219,223,223,223,223,223,219,219,223,223,223,223,223,219,223,223,223,223,219,223,223,223,223,219,219,219,223,223,223,223,219,223,223,223,223,219,223,223,223,219);
		printf("     %c                  %c %c         %c      %c   %c         %c      %c      %c       %c %c      %c       %c         %c     %c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		printf("     %c                 %c   %c        %c      %c   %c         %c      %c      %c       %c  %c     %c       %c        %c       %c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		printf("     %c                %c%c%c%c%c%c%c       %c%c%c%c%c%c%c    %c%c%c%c%c     %c%c%c%c%c%c%c       %c       %c   %c    %c       %c       %c         %c\n",219,219,220,220,220,220,220,219,219,220,220,220,220,220,219,219,219,219,219,219,219,220,220,220,220,220,219,219,219,219,219,219,219,219);
		printf("     %c               %c       %c      %c     %c    %c         %c%c%c%c          %c       %c    %c   %c       %c       %c         %c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		printf("     %c              %c         %c     %c      %c   %c         %c  %c%c         %c       %c     %c  %c       %c        %c       %c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		printf("     %c             %c           %c    %c      %c   %c         %c   %c%c        %c       %c      %c %c       %c         %c     %c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
		printf("     %c%c%c%c%c%c%c%c%c%c   %c             %c   %c%c%c%c%c%c%c    %c%c%c%c%c%c%c   %c    %c%c   %c%c%c%c%c%c%c%c%c   %c       %c%c       %c          %c%c%c%c%C\n",219,220,220,220,220,220,220,220,220,220,219,219,219,220,220,220,220,220,219,219,220,220,220,220,220,219,219,219,219,220,220,220,220,219,220,220,220,220,219,219,219,219,219,220,220,220,219);
		printf("\n\n");
		printf("Bienvenid@ jugador o jugadora\n\n");
		printf("Jugar el primer nivel..............1\n");
		printf("Jugar el segundo nivel.............2\n");
		printf("Jugar el tercer nivel..............3\n");
		printf("Salir..............................4\n");
		printf("Escoge tu opcion: \t");
		scanf("%d",&opc);
		switch(opc){
			case 1: caso1(); break;
			
			case 2:	caso2(); break;
					
			case 3: caso3(); break;	
			
			case 99: caso99(); break;
						
		}
		system("cls");
	}while(opc!=4);
}

//Crea el ciclo infinito que habra para el juego
void cicloJuego(){
	ds=10, seg=59, min=4;
	while(bandera==0){	
		borrar_cuerpo();
		guardar_posicion();
		dibujar_cuerpo();
		teclas();
		teclas();
		
		obstaculos();
		obstaculos2();
		obstaculos3();
		ds--;
		if(ds==0){
			ds=10;
			seg--;
			if(seg==0){
				seg=59;
				min--;
			}
		}
		gotoxy(30, 0); printf("[%.2d:%.2d:%.2d]    ",min,seg,ds);
		gotoxy(30, 2); printf("Jugador #1/jugadora #2");
		Sleep(100);
		fin(xf, yf, ds, seg, min);
		if(tecla == ESC){
			bandera=1;
		}
	}
	//mostrarRecord(ds,seg,min, cont);
	
}

void caso1(){
	system("cls");
	printf("\n\n");
	Ocultar_cursor();
	DibujarMapa1(mapa);
	cicloJuego();
	cicloJuego();
	printf("\n");
	gotoxy(30,4);system("pause");
}

void caso2(){
	system("cls");
	printf("\n\n");
	Ocultar_cursor();
	DibujarMapa2(mapa);
	cicloJuego();
	cicloJuego();
	printf("\n");
	gotoxy(30,4);system("pause");
}

void caso3(){
	system("cls");
	printf("\n\n");
	Ocultar_cursor();
	DibujarMapa3(mapa);
	cicloJuego();
	cicloJuego();
	printf("\n");
	gotoxy(30,4);system("pause");
}

void caso99(){
	mostrarRecord(ds1, seg1, min1, ds2, seg2, min2, ds, seg, min, score);
	bandera=1;
	gotoxy(30,10);printf("Presione una tecla para continuar . . .");
}

//Movera el cursor a la coordenada que se indico
void gotoxy(int x, int y){
    HANDLE hCon;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

//Ocultara el cursor que se muestra al ejecutar un programa
void Ocultar_cursor() {
    CONSOLE_CURSOR_INFO cci = {100, FALSE};
    
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

//Ocultara el rastro que deje el caracter que se esta imprimiendo.
void borrar_cuerpo(){
	gotoxy(cuerpo[n][0], cuerpo[n][1]);printf(" ");
}

//Guardara la posicion en x,y del cuerpo o caracter a mover en el mapa
void guardar_posicion(){
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
}

//Imprimir el caracter que hara de personaje
void dibujar_cuerpo(){
	gotoxy(x,y);printf("%c",169);	
}

//Guardar la tecla presionada y hara el movimientodel personaje
void teclas(){
	if(kbhit()){
		tecla=getch();
		if(tecla==ARRIBA && mapa[y-1][x]==1){
			y--;
		}
		if(tecla==ABAJO&& mapa[y+1][x]==1){
			y++;
		}
		if(tecla==IZQUIERDA && mapa[y][x-1]==1){
			x--;
		}
		if(tecla==DERECHA && mapa[y][x+1]==1){
			x++;
		}
	}
}

//Matriz del mapa 1	
int mapa1[REN][COL]={
		{0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
		{0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0},
		{0,0,0,0,1,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,0,0,1,0},
		{0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,1,0},
		{0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0},
		{0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,1,1,0},
		{0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0},
		{0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	
//Matriz del mapa 2	
int mapa2[REN][COL]={
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{3,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,0,0},
		{0,1,0,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,1,1,1,0,1,1,0},
		{0,1,1,0,1,0,1,0,1,0,0,1,1,1,1,0,1,1,1,0,1,0,0,1,0},
		{0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1,0,0},
		{0,1,1,0,1,0,1,0,1,1,1,1,1,0,0,1,0,1,1,0,1,1,1,1,0},
		{0,1,0,0,1,0,1,0,1,0,0,1,0,1,1,1,0,0,1,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,1,0,0,1,0,1,1,0,1,0},
		{0,1,1,1,1,0,1,1,0,1,1,0,0,1,0,1,0,1,1,0,0,1,0,1,0},
		{0,1,1,1,0,0,0,1,0,1,0,0,1,1,0,1,1,1,1,1,1,1,0,1,0},
		{0,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,1,0,0,1,1,1},
		{0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,0,0},
		{0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,1,0,0},
		{0,1,1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,1,1,1,1,0,1,0,0},
		{0,1,0,0,0,0,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,1,1,1,0},
		{0,1,0,0,1,1,1,0,0,0,1,1,0,1,0,1,1,1,0,1,1,1,0,0,0},
		{0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

//matriz del mapa 3		
int mapa3[REN][COL]={
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0},
		{0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0},
		{0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,0,0,0},
		{0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1,0},
		{0,1,1,1,0,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0},
		{0,1,0,1,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,0,1,1,1,0},
		{0,1,1,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,1,0},
		{0,1,1,1,0,0,0,1,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,1,0},
		{0,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0},
		{0,1,0,1,0,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,0,1,0,0,0},
		{0,1,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0},
		{1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	
//Mostrara en el programa el primer mapa
void DibujarMapa1(int mapa[REN][COL]){
	for(int f=0;f<REN;f++){
		for(int c=0;c<COL;c++){		
			mapa[f][c]=mapa1[f][c];
			if(mapa1[f][c]==0){
			  gotoxy(c, f);printf("%c", 219);
			}
			else{
				if(mapa1[f][c]==1||mapa1[f][c]==3){
					printf("%c",32);
				}
			}
		}
	}			    
}

//Mostrara en el programa el segundo mapa
void DibujarMapa2(int mapa[REN][COL]){
	for(int r=0;r<REN;r++){
		for(int k=0;k<COL;k++){
			mapa[r][k]=mapa2[r][k];
			if(mapa2[r][k]==0){
			  gotoxy(k, r);printf("%c", 219);
			}
			else{
				if(mapa2[r][k]==1||mapa2[r][k]==3){
					printf("%c",32);
				}
			}
		}
	}		    
}

//Mostrara en el programa el ultimo mapa
void DibujarMapa3(int mapa[REN][COL]){
	for(int g=0; g<REN; g++){
		for(int p=0; p<COL; p++){
			mapa[g][p]=mapa3[g][p];
			if(mapa3[g][p]==0){
				gotoxy(p, g); printf("%c", 219);
			}
			else{
				if(mapa3[g][p]==1 || mapa3[g][p]==3){
					printf("%c", 32);
				}
			}
		}
	}
}

//Esta funcion creara los obstaculos que se encuentran en el mapa y cada vez que los toque el personaje lo mandara al inicio del mapa, le quitara una vida y le quitara 100 de puntaje
void obstaculos(){
	if(opc=1){
		gotoxy(3,8); printf("%c", 88);
		gotoxy(19,3); printf("%c",88);
		if((x==3 && y==8)||(x==19 && y==3)){
			x=0;
			y=1;
			cont++;
			vidas--;
			score-=100;
		}
		gotoxy(30,1);printf("Vidas: %d    Score: %d",vidas,score);
		if(vidas==0){
			gotoxy(30,3); printf("Has fracasado en el intento :(");
			bandera=1;
		}
	}
}

void obstaculos2(){
	if(opc=2){
		gotoxy(7,10); printf("%c", 88);
		gotoxy(8,5); printf("%c", 88);
		gotoxy(12,14); printf("%c", 88);
		if((x==7 && y==10) || (x==8 && y==5) || (x==12 &&  y==14)){
			x=0;
			y=1;
			cont++;
			vidas--;
			score-=100;
		}
			gotoxy(30,1);printf("Vidas: %d    Score: %d",vidas,score);
		if(vidas==0){
			gotoxy(30,3); printf("Has fracasado en el intento :(");
			bandera=1;
		}
	}
}

void obstaculos3(){
	if(opc=3){
		gotoxy(2,14); printf("%c",88);
		gotoxy(7,13); printf("%c",88);
		gotoxy(19,3); printf("%c",88);
		if((x==2 && y==14) || (x==7 && y==13) || (x==19 && y==3)){
			x=0;
			y=1;
			cont++;
			vidas--;
			score-=100;
		}
			gotoxy(30,1);printf("Vidas: %d    Score: %d",vidas, score);
		if(vidas==0){
			gotoxy(30,3); printf("Has fracasado en el intento :(");
			bandera=1;
		}
	}
				
}
			
//Esta funcion lo que hara es que cuando el personaje llegue a determinado punto acabara lo que es el mapa y lo mandara al siguiente o bien lo mandara al record
void fin(int xf, int yf, int ds,int seg,int min){
	if(opc=1){
		xf=11;
		yf=18;
		if(xf==x && yf==y){
			gotoxy(30,3);printf("Tu tiempo fue de: %.2d:%.2d:%.2d\n", 4-min, 59-seg, 10-ds);
			min1=4-min;
			seg1=59-seg;
			ds1=10-ds;
			if(min>=0){
				min=min*100;
				ds=ds/10;
				suma=min+seg+ds;
				score=score+suma;
			}
			gotoxy(30,4);system("pause");
			x=0;
			y=1;
			opc=2;
			caso2();
		}
	}
	if(opc=2){
		xf=24;
		yf=11;
		if(xf==x && yf==y){
			gotoxy(30,3);printf("Tu tiempo record fue de: %.2d:%.2d:%.2d\n", 4-min, 59-seg, 10-ds);
			min2=4-min;
			seg2=59-seg;
			ds2=10-ds;
			if(min>=0){
				min=min*100;
				ds=ds/10;
				suma=min+seg+ds;
				score=score+suma;
			}
			gotoxy(30,4);system("pause");
			x=0;
			y=1;
			opc=3;
			caso3();
		}
	}
	if(opc=3){
		xf=0;
		yf=17;
		if(xf==x && yf==y){
			gotoxy(30,3);printf("Tu tiempo record fue de: %.2d:%.2d:%.2d\n", 4-min, 59-seg, 10-ds);
			min=4-min;
			seg=59-seg;
			ds=10-ds;
			if(min>=0){
				min=min*100;
				ds=ds/10;
				suma=min+seg+ds;
				score=score+suma;
			}
			gotoxy(30,4);system("pause");
			caso99();
			
		}
	}
}

/*Esta funcion hara que al terminar el ultimo mapa del juego mostrara el tiempo que tuvo en cada mapa y su puntaje final, como tambien un mensaje
	donde dira como estuvo su puntaje, al igual en esta funcion preguntara si desea continuar al menu o salir del programa.
*/
void mostrarRecord(int ds1,int seg1,int min1, int ds2,int seg2,int min2, int ds,int seg,int min, int score){
	char opcion;
	gotoxy(30,5);printf("RECORD EN EL MAPA 1: %.2d:%.2d:%.2d\n", min1, seg1, ds1);
	gotoxy(30,6);printf("RECORD EN EL MAPA 2: %.2d:%.2d:%.2d\n", min2, seg2, ds2);
	gotoxy(30,7);printf("RECORD EN EL MAPA 3: %.2d:%.2d:%.2d\n", min, seg, ds);
	gotoxy(30,8);printf("Tu score final es: %d", score);
	if(score<500){
		gotoxy(30,9);printf("Tu score es muy bajo...Debes mejorarlo!");
	}
	if(score<1000 && score>499){
		gotoxy(30,9);printf("Tu score esta bien...Sigue mejorando!");
	}
	if(score<1500 && score>999){
		gotoxy(30,9);printf("Tu score es excelente...Felicidades!");
	}
	
	gotoxy(30,11); printf("\nDeseas regresar al menu (s/n): ");
	fflush(stdin);
	scanf("%c",&opcion);
	if(opcion=='s' || opcion=='S'){
		system("cls");
		menu();
	}
	else{
		system("cls");
		opc=4;
	}
	
}
