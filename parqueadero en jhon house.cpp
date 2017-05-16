
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<time.h>
#include<string.h>
#include<stdio.h>


//estas son las clases:
class vehiculo
{
public:
	char placa[7];
	char marca[10];
	int modelo,s,r,totalh,totalm,total,tipo;


	struct h_enter{
	int hora;
	int minutos;
	}hent;

	struct h_exit{
	int hora;
	int minutos;
	}hexi;

	void ingresar(int car);
	int liquidar(char *s);
	void reporte();
};

//esta es la clase del parqueadero que es la que muestra el tiempo
class parking
{
public:
	//esta clase solo utliza un atributo "tempo"
	void tempo();
};

//esta es la clase que maneja el contador osea la cantidad de carros en el estacionamiento
class contador{
public:
	int i,ganan;
	int mostrar();
};

//declaracion del metodo

int contador::mostrar(){
	cout<<i<<endl;
	//return devuelve un valor del tipo de la funcion, si es una funcion de tipo void no devuelve un valor
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
int vehiculo::liquidar(char *s)
{
	int p;
	//strcmp es una funcion de la libreria srting.h que sirve para comparar dos cadenas devuelve un cero si las dos cadenas son iguales
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
		totalh= hexi.hora-hent.hora;
		totalm= hexi.minutos-hent.minutos;
		if(totalm<0){
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
	fstream autos;
	fstream con;
	
	contador *c;
	c=new contador();

	parking pk;
	
	vehiculo *q;
	for(int y=0;y<20;y++)
		q=new vehiculo[y];

	vehiculo z[20];

	int x=20,i,pp,vv,l,ganan,a;
	char plaka[7],decs;
	char  opc;
	
	con.open("a:\\i.save",ios::in|ios::binary);
	con.read((char*)c,sizeof(contador));
	c->mostrar();
	con.close();
	con.open("a:\\i.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	c->mostrar();
	con.close();
	con.open("a:\\i.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	i=c->i;
	ganan=c->ganan;
	con.close();
	int aux=i;

	for( a=0;a<(i+1);a++){
		
		if(a!=0)
			q++;
		autos.open("a:\\park.save",ios::in|ios::binary);
		q->reporte();
		q->total;
		autos.read((char*)q,sizeof(vehiculo));
		autos.close();
		aux=i-1;
		z[a]=*q;
		
	}
	
	

do{
	aux=i;
	system("CLS");
		pk.tempo();
		cout<<"\n\n\n\t\t\t\tParking Demon";
		cout<<"\n\n\n\t\t\t¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯"<<endl;
		cout<<"\t\t\t\1\t 1.ingresar\t    \1"<<endl;
		cout<<"\t\t\t\2\t 2.ganancias\t    \2"<<endl;
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
			aux=i;
		case '1':
			system("CLS");
			if(i>x){
				cout<<"no se permiten mas autos";
			}
			else{
				if(i>-2){
					i++;
					if(i!=0)
						q++;
					autos.open("a:\\park.save",ios::out|ios::binary);
					autos.write((char*)q,sizeof(vehiculo));
					q->ingresar(i);
					q->reporte();
					autos.close();
					z[i]=*q;

				}
			}
		
			break;

		case '2':
			system("CLS");
			cout<<"\n\n\n\t\t\tse han obtenido ingresos por un valor de:"<<ganan<<"$"<<endl;
			cout<<"\n\n\n\n\t\t\t"<<endl;
			system("PAUSE");
			system("CLS");
			break;

		case '3':
			system("CLS");		
			cout<<"digite la placa del auto"<<endl;
			cin>>plaka;
			for( vv=0;vv<(i+1);vv++){
				autos.open("a:\\park.save",ios::out|ios::binary);
				if(vv!=0)
				q--;
				aux--;
				autos.write((char *)q,sizeof(vehiculo));
				q->reporte();
				autos.close();
				pp= q->liquidar(plaka);

				if(pp==0&&i>-1){
					ganan= ganan+q->total;
					cout<<"el vehiculo ha salido del estacionamiento"<<endl;
					system("PAUSE");
					a=vv+1;
					i--;
					vv=i;
					
				}
				if(vv==i&&pp==0){
					for(a;a<(i+2);a++){
						q--;
						z[a]=*q;
					}
				}
				else
					z[vv]=*q;
			}
			if(pp!=0)
			{
				cout<<"el vehiculo digitado no ha ingresado."<<endl;
				system("PAUSE");
			}

			for(a=0;a<(i+1);a++){
				q=&z[a];
				if(a!=0)
				q++;
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
				if(l!=0)
				q--;
				autos.open("a\\park.save",ios::in|ios::binary);
				autos.read((char*)q,sizeof (vehiculo));	
				q->reporte();
				autos.close();
				cout<<"\t\t\t____________________________________"<<endl;
				system("PAUSE");
				system("CLS");
				aux=i-1;
			}
			for(a=0;a<(i+1);a++){
				q=&z[a];
				if(a!=i)
				q++;
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
	con.open("a:\\i.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	c->i=i;
	c->ganan=ganan;
	con.close();
	con.open("a:\\i.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	c->mostrar();
	con.close();
	con.open("a:\\i.save",ios::out|ios::binary);
	con.write((char*)c,sizeof(contador));
	c->i=i;
	c->ganan=ganan;
	con.close();

	
	for( a=0;a<(i+1);a++){
		
		if(a!=0)
			q--;
		autos.open("a:\\park.save",ios::out|ios::binary);
		q->reporte();
		q->total;
		autos.write((char*)q,sizeof(vehiculo));
		autos.close();
		aux=i-1;
	}

}
void main()
{

	menu();
}
