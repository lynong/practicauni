#include <iostream>
#include <vector>
using namespace std;
typedef vector <double> fila;
typedef vector <fila> matriz;

matriz llenar(matriz butaca){
    for (int i=0;i<5;++i){
		for(int o=0;o<10;++o){
			butaca[i][o]=1;
		}
	}
	for (int i=0;i<5;++i){
		for(int o=0;o<10;++o){
			butaca[i][o];
		}
	}
	cout<<"Sala llenada exitosamente"<<endl<<endl;
	return butaca;	
}

matriz iniciar(matriz butaca){
    for (int i=0;i<5;++i){
		for(int o=0;o<10;++o){
			butaca[i][o]=0;
		}
	}
	for (int i=0;i<5;++i){
	//	cout<<endl;
		for(int o=0;o<10;++o){
			butaca[i][o];
		}
	}
	return butaca;
}

void graficar(matriz butaca){
	for (int i=0;i<5;++i){
		cout<<endl;
	for(int o=0;o<10;++o){
		cout<<butaca[i][o];
		}
	}
}

matriz asignar(matriz &butaca){
	bool seguir=true;
	bool seguir1=true;
	int f=0,col=0;
	while(seguir){
		cout<<"Ingrese la fila "<<endl;
		cin>>f;	
		if(f>0 and f<=5){
			seguir=false;
		}
		else{
			cout<<"Error: Esa fila no existe (filas existente van desde el 1 al 5)"<<endl;
		}
	}
	while(seguir1){
		cout<<"Ingrese el asiento a asignar en la fila "<<f<<"(1-10)"<<endl;
		cin>>col;
		if(col>0 and col<=10){
			seguir1=false;
		}
		else{
			cout<<"Error: cada fila tiene 10 asientos , el numero minimo es 1 y el maximo 10"<<endl;	
		}		
	}

	if(butaca[f-1][col-1]==1){
		cout<<"Error : El asiento ya esta asignado"<<endl;
		return butaca;
	}
	else{
		butaca[f-1][col-1]=1;
		return butaca;	
	}
//	butaca[f-1][col-1]=1;
//	graficar(butaca);	
//	return butaca;
}
matriz liberar(matriz &butaca){
	bool seguir=true;
	bool seguir1=true;
	int f=0,col=0;
	while(seguir1){
		cout<<"Ingrese la fila "<<endl;
		cin>>f;	
		if(f>0 and f<=5){
			seguir1=false;
		}
		else{
			cout<<"Error: Esa fila no existe (filas existente van desde el 1 al 5)"<<endl;
		}
	}

	while(seguir){
	
	cout<<"Ingrese el asiento a asignar en la fila "<<f<<"(1-10)"<<endl;
	cin>>col;
	if (col>0 and col<=10){
		butaca[f-1][col-1]=0;
		seguir=false;
	}
	else{
		cout<<"Error: cada fila tiene 10 asientos , el numero minimo es 1 y el maximo 10"<<endl;
	}
	}
//	graficar(butaca);	
	return butaca;
}
int main(){
	matriz sala1(5,fila(10));
    matriz sala2(5,fila(10));
    matriz sala3(5,fila(10));
//	cout<<"El estado actual de las 3 salas disponibles es (0=DISPONIBLE 1=OCUPADO) : "<<endl<<endl;
//	cout<<"Sala A "<<endl<<endl;
	sala1=iniciar(sala1);
//	cout<<endl<<endl;
//	cout<<"Sala B "<<endl<<endl;
	sala2=iniciar(sala2);
//	cout<<endl<<endl;
//	cout<<"Sala C "<<endl<<endl;
	sala3=iniciar(sala3);
//	cout<<endl<<endl;
	bool menuP=true;
	while(menuP){
		system("cls");
		string op;
		cout<<"###############################################################################"<<endl;
		cout<<"#                         SISTEMA DE BUTACAS  v0.31                           #"<<endl;
		cout<<"###############################################################################"<<endl<<endl;
		cout<<"DISPONIBLES LAS SIGUIENTES OPCIONES "<<endl<<endl;
		cout<<"1-VER EL ESTADO ACTUAL DE LAS SALAS"<<endl<<endl;
		cout<<"2-ASIGNAR UN ASIENTO"<<endl<<endl;
		cout<<"3-VACIAR UN ASIENTO"<<endl<<endl;
		cout<<"4-VACIAR TODOS LOS ASIENTOS"<<endl<<endl;
		cout<<"5-LLENAR TODOS LOS ASIENTOS"<<endl<<endl;
		cout<<"6-SALIR DEL PROGRAMA"<<endl<<endl;
		cin>>op;
		if(op=="1"){
			system("cls");
			string l;
			cout<<"El estado actual de las 3 salas disponibles es (0=DISPONIBLE 1=OCUPADO) : "<<endl<<endl;
			cout<<"Sala A "<<endl<<endl;
			graficar(sala1);
			cout<<endl<<endl;
			cout<<"Sala B "<<endl<<endl;
			graficar(sala2);
			cout<<endl<<endl;
			cout<<"Sala C "<<endl<<endl;
			graficar(sala3);
			cout<<endl<<endl;
			cout<<"Desea volver al menu anterior? (s/n)"<<endl;
			cin>>l;
			if(l=="n" or l=="N"){
				menuP=false;
			}
			else{
				menuP=true;
			}
		}
		if(op=="2"){
			bool m2=true;
			system("cls");
			while(m2){
			string mm="g";
			string n;
			cout<<"Actualmente se encuentran 3 salas disponibles "<<endl<<endl;
			cout<<"1-SALA A  2-SALA B  3-SALA C "<<endl;
			cin>>n;
			if(n=="1"){
				sala1=asignar(sala1);
				cout<<"Desea asignar otro asiento? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			if(n=="2"){
				sala2=asignar(sala2);
				cout<<"Desea asignar otro asiento? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			if(n=="3"){
				sala3=asignar(sala3);
				cout<<"Desea asignar otro asiento? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			}
		}
	    if(op=="3"){
	    	system("cls");
			bool m2=true;
			system("cls");
			while(m2){
			string mm="g";
			string n;
			cout<<"Actualmente se encuentran 3 salas disponibles "<<endl<<endl;
			cout<<"1-SALA A  2-SALA B  3-SALA C "<<endl;
			cin>>n;
			if(n=="1"){
				sala1=liberar(sala1);
				cout<<"Desea liberar otro asiento? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			if(n=="2"){
				sala2=liberar(sala2);
				cout<<"Desea liberar otro asiento? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			if(n=="3"){
				sala3=liberar(sala3);
				cout<<"Desea liberar otro asiento? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			}
		}
		if(op=="4"){
			bool m2=true;
			system("cls");
			while(m2){
			string mm="g";
			string n;
			cout<<"Actualmente se encuentran 3 salas disponibles "<<endl<<endl;
			cout<<"1-SALA A  2-SALA B  3-SALA C "<<endl;
			cin>>n;
			if(n=="1"){
				sala1=iniciar(sala1);
				cout<<"Desea vaciar otra sala? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			if(n=="2"){
				sala2=iniciar(sala2);
				cout<<"Desea vaciar otra sala? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal (s/n)?"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			if(n=="3"){
				sala3=iniciar(sala3);
				cout<<"Desea vaciar otra sala? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			}
		}
		if(op=="5"){
			bool m2=true;
			system("cls");
			while(m2){
			string mm="g";
			string n=0;
			cout<<"Actualmente se encuentran 3 salas disponibles "<<endl<<endl;
			cout<<"1-SALA A  2-SALA B  3-SALA C "<<endl;
			cin>>n;
			if(n=="1"){
				sala1=llenar(sala1);
				cout<<"Desea llenar otra sala? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			if(n=="2"){
				sala2=llenar(sala2);
				cout<<"Desea llenar otra sala? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			if(n=="3"){
				sala3=llenar(sala3);
				cout<<"Desea llenar otra sala? (s/n)"<<endl;
				cin>>mm;
				if(mm=="N" or mm=="n"){
					m2=false;
					cout<<"desea volver al menu principal? (s/n)"<<endl;
					cin>>mm;
					if(mm=="N" or mm=="n"){
						menuP=false;
					}
				}
			}
			}
		}
		if(op=="6"){
			exit(0);
		}
		if(op!="1" and op!="2" and op!="3" and op!="4" and op!="5" and op!="6" ){
			//system("cls");
			cout<<"Por favor asegure de introducir la opcion correcta (opciones disponibles 1 , 2 , 3 , 4 , 5)"<<endl;
		}
	//	else{
	//		system("cls");
	//		cout<<"Por favor asegure de introducir la opcion correcta (opciones disponibles 1 , 2 , 3 , 4 , 5)"<<endl;
	//	}	
	}
}
	
