//el proyecto esta descompuesto por ende usted debe organizarlo, como? pues, yo no se.

#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<time.h>
#include<string.h>
#include<stdio.h>

//esta es la clase seguida de los 4 metodos.

class vehiculo
{
public:
	char placa[7];
	char marca[10];
	int modelo,s,r,totalh,totalm,total,tipo;

//struct son tipos de variables que permiten almacenar mas de
//un tipo de variable dentro de si mismas estas se llaman estructuras.
	struct h_enter{
	int hora;
	int minutos;
	}hent;

	struct h_exit{
	int hora;
	int minutos;
	}hexi;

//los atributos hasta ahora dados (me imagino que los otros tocara hacerlos por iniciativa propia)
	void ingresar(int car);
	int liquidar(char *s);
	void reporte();
};
class parking
{
public:
	void tempo();
};

class contador{
public:
	int i;
	int mostrar();
};

int contador::mostrar(){
	cout<<i<<endl;
	return i;
}

//los metodos.
void vehiculo::ingresar(int car)
{
	car=20;
	cout<<"\n\n\n\t\t\tingrese la placa del vehiculo:"<<endl;
	cin>>placa;
	cout<<" \n\t\t\t¡gracias¡ \n\t\t\t ahora digite la marca del vehiculo:"<<endl;
	cin>>marca;
	do{
		system("CLS");
		cout<<"\t\t\tdigite el tipo de auto"<<endl;
		cout<<"\n\t\t\ttipo 1:\t para automoviles, camionetas y colectivos"<<endl;
		cout<<"\n\t\t\ttipo 2:\t para busetas buses y camiones"<<endl;
		cout<<"\n\t\t\ttipo 3:\t para motos"<<endl;
		cout<<"\n\t\t\ttipo 4:\t para tractomulas y/o vehiculos articulados"<<endl;
		cin>>tipo;
		for( r=1;r<5;r++){
			if(tipo==r)
				break;
		}
		if(r>4){
			cout<<"\t\tel tipo no es correcto por favor reingrese el tipo del auto"<<endl;
			r=7;
		}
	}
	while(r==7);
	cout<<"ingrese la hora de entrada (00-23): "<<endl;
	do{
		cin>>hent.hora;
		if(hent.hora>23||hent.hora<0)
			cout<<" \n la hora de entrada no es correcta \nreingrese la hora de entrada"<<endl;
	}
	while(hent.hora>23||hent.hora<0);

	cout<<"\ndigite los minutos (00-59):"<<endl;
	do{	
		cin>>hent.minutos;
	if(hent.minutos>59||hent.minutos<0)
		cout<<" \n los minutos no son correctos \nreingrese los minutos"<<endl;
	}
	while(hent.minutos>59||hent.minutos<0);
	system("CLS");
}
void vehiculo::reporte(){
	cout<<"\n\n\n\t\t placa \t"<<placa<<endl;
	cout<<"\t\t marca \t "<<marca<<endl;
	cout<<"\t\t tipo  \t "<<tipo<<endl;
	cout<<"\t\t hora de entrada:\n\t\t\t "<<hent.hora<<"-"<<hent.minutos<<endl;
}
/*void vehiculo::imprimir()
{
cout<<"\n\nplaca\ttipo\tmarca\th_entrada\th_salida\tmodelo"
este metodo esta en construccion */

int vehiculo::liquidar(char *s)
{
	int p;
	p= strcmp(placa,s);
	if(p==0)
	{
		do
		{
			cout<<"digite hora de salida (00-47)";
			cin>>hexi.hora;
		}
		while(hexi.hora<hent.hora);
		cout<<"digite minutos";
		cin>>hexi.minutos;
		system("CLS");
		system("CLS");
		totalh= hexi.hora-hent.hora;
		totalm= hexi.minutos-hent.minutos;
		if(totalm<1){
			totalh--;
			totalm=60+totalm;
		}
		total= (totalh*60) + totalm;
		total=total/60;
		if(tipo==1){
			if(total<6)
				total=total*1000;
			else
				if(total<12)
					total=3000;
				else
					total=total*250;
		}
		if(tipo==2){
			if(total<6)
				total=total*1500;
			else
				if(total<12)
					total=4000;
				else
					total=total*350;
		}
		if(tipo==3){
			if(total<6)
				total=total*7000;
			else
				if(total<12)
					total=2000;
				else
					total=total*250;
		}
		if(tipo==4){
			if(total<6)
				total=total*2500;
			else
				if(total<12)
					total=7000;
				else
					total=total*500;
		}
		cout<<"\t\t\tel automovil estuvo: "<<totalh<<"-"<<totalm<<"\nen el parqueadero, debe pagar:"<<total<<"$"<<endl;
		system("PAUSE");
	}
	return p;
}

void parking::tempo(){
	struct tm *punt1;
	time_t ti;
	ti=time(NULL);
	punt1=localtime(&ti);
	cout<<"\n\t\t\t\t\t\t\t"<<asctime(punt1);
}
void menu() 
{	
	fstream autos;//leer el archivo de los objetos
	fstream con;//leer el archivo del contador
	
	contador *c;
	c=new contador();

	parking pk;
	
	vehiculo *q;
	for(int y=0;y<20;y++)
		q=new vehiculo[y];

	int x=20,i,pp,vv,l,ganan,a;
	char plaka[7],decs;
	char  opc;
	
	con.open("a:\\i2.save",ios::in|ios::binary);
	con.read((char*)c,sizeof(contador));
	c->mostrar();
	con.close();
	con.open("a:\\i2.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	c->mostrar();
	con.close();
	con.open("a:\\i2.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	i=c->i;
	con.close();		
do{
	
		system("CLS");
		pk.tempo();
		cout<<"\n\n\n\t\t\t\tParking Demon";
		cout<<"\n\n\n\t\t\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl;
		cout<<"\t\t\t\1\t 1.ingresar\t    \1"<<endl;
		cout<<"\t\t\t\2\t 2.ganacias\t    \2"<<endl;
		cout<<"\t\t\t\1\t 3.liquidar\t    \1"<<endl;
		cout<<"\t\t\t\2\t 4.reporte \t    \2"<<endl;
		cout<<"\t\t\t\1\t 5.salir   \t    \1"<<endl;
		cout<<"\t\t\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl;
		cout<<"\t\t\t\2\t digite su opcion   \2"<<endl;
		cout<<"\t\t\t";

		if(i<0)
		{
			i=-1;
			cout<<"no hay automoviles en el estacionamiento"<<endl;
		}
		else {
			if(i==0){
				q=0;
				cout<<"solo hay un auto en el parqueadero"<<endl;
			}
			else {
				cout<<"en el momento hay "<<i+1<<"carros en el estacionamiento"<<endl;
			}
		}
		cout<<"\t\t\t\t";
		cin>>opc;
		system("CLS");
		switch(opc)
		{
		case '1':
			system("CLS");
			if(i>x){
				cout<<"no se permiten mas autos";
			}
			else{
				if(i>-2){
					i++;
					autos.open("a:\\park2.save",ios::out|ios::binary);
					q->ingresar(i);
					q->reporte();
					autos.write((char*)q,sizeof(vehiculo));
					autos.close();
					q++;
				}
			}
		
			break;

		case '2':
			system("CLS");
			cout<<"\n\n\n\t\t\tse han obtenido ingresos por un valor de:"<<ganan<<"$";
			break;

		case '3':
			system("CLS");		
			cout<<"digite la placa del auto"<<endl;
			cin>>plaka;
			for(vv=0;vv<(i+1);vv++){
				if(vv!=0)
					q=q-vv;
				autos.open("a:\\park2.save",ios::out|ios::binary);
				autos.write((char *)q,sizeof(vehiculo));
				q->reporte();
				autos.close();
				pp= q->liquidar(plaka);
				if(pp==0&&i>-1){
					ganan= ganan+q->total;
					cout<<"el vehiculo ha salido del estacionamiento"<<endl;
					system("PAUSE");
					i--;
					vv=i;
					q--;
				}
			}
			if(pp!=0)
			{
				cout<<"el vehiculo digitado no ha ingresado."<<endl;
				system("PAUSE");
			}
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\n\t\t\tEste es el reporte de los vehiculos ingresados"<<endl;
			if(i==-1){
				cout<<"\n\t\t\ten el momento no hay automoviles en el estacionamiento"<<endl;
				system("PAUSE");
			}
			for(l=0;l<(i+1);l++)
			{
				q=q-l;
				autos.open("a\\park2.save",ios::in|ios::binary);
				autos.read((char*)q,sizeof (vehiculo));
				q->reporte();
				autos.close();
				cout<<"\t\t\t____________________________________"<<endl;
				system("PAUSE");
				system("CLS");
			}
		
			break;
		case '5':
			cout<<"\n\n\n\n\n\n\t\t\t\ten realidad quiere salir?";
			cin>>decs;
			if(decs!='s'){
				opc=6;
			}
			break;
		default: cout<<"su opcion no es valida"<<endl;
			system("PAUSE");
			break;
		}

	
	}

	while (opc!='5');
	con.open("a:\\i2.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	c->i=i;
	con.close();
	con.open("a:\\i2.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	c->mostrar();
	con.close();
	con.open("a:\\i2.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	c->i=i;
	con.close();
	
	for( a=0;a<(i+1);a++){
		q=q-a;
		autos.open("a:\\park22.save",ios::in|ios::binary);
		autos.read((char*)q,sizeof(vehiculo));
		q->reporte();
		q->total;
		autos.close();
		
	}
	for( a=0;a<(i+1);a++){
		q=q-a;
		autos.open("a:\\park2.save",ios::out|ios::binary);
		q->reporte();
		q->total;
		autos.write((char*)q,sizeof(vehiculo));
		autos.close();
		
	}
	
}
void main()
{

	menu();
}
