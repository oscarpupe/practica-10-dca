#include <iostream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;

class Comentario {
public:
	string autor;
	string comentario;
	
	void MostrarComentario();
};

void Comentario::MostrarComentario() {
	cout << "	  -";
	cout << autor << ":" << endl;
	cout << "	   " << comentario << endl;
}

class Reporte {		
public:
	bool estado;
	string reporte;
	string autor;
	vector<Comentario> comentarios;

	void MostrarReporte();
	void MostrarReporteResumido();
};

void Reporte::MostrarReporte() {
	cout << "   " << autor << ":" << endl;
	cout << "   " << reporte << endl;
	
	for(int i=0;i<comentarios.size();i++) {
		comentarios[i].MostrarComentario();
	}
	
	cout << endl;
}

void Reporte::MostrarReporteResumido() {
	cout << " Autor: " << autor << endl;
	cout << " Tema: " << reporte << endl;	
	cout << endl;
}

vector <Reporte> reportes;

void RellenaReportes() {

	Comentario comentario;
	Reporte reporte;
	
	//Primer reporte
	reporte.reporte = "Al entrar en la web no puedo logearme";
	reporte.autor = "Pepe";
	
	comentario.autor = "Tomás";
	comentario.comentario = "Para poder logearte debes ir a login.";
	reporte.comentarios.push_back(comentario);
	comentario.autor = "Pepe";
	comentario.comentario = "He buscado esa opción pero no la encuentro.";
	reporte.comentarios.push_back(comentario);
	comentario.autor = "Tomás";
	comentario.comentario = "Mire en la esquina superior derecha, cicle en el icono que aparece.";
	reporte.comentarios.push_back(comentario);
	reporte.estado=false;
	
	reportes.push_back(reporte);
	reporte.comentarios.clear();
	
	//Segundo reporte
	reporte.reporte = "No puedo logearme con mi cuenta";
	reporte.autor = "Maria";
	
	comentario.autor = "Tomás";
	comentario.comentario = "¿Ha intentado con su correo y la contraseña proporcionada?";
	reporte.comentarios.push_back(comentario);
	comentario.autor = "Maria";
	comentario.comentario = "No sabía que tenía una contraseña dada, ¿dónde la puedo mirar?";
	reporte.comentarios.push_back(comentario);
	comentario.autor = "Tomás";
	comentario.comentario = "Busque en el correo del email que escribió al registrarse.";
	reporte.comentarios.push_back(comentario);
	reporte.estado=false;
	
	reportes.push_back(reporte);
	reporte.comentarios.clear();
	
	//Tercer reporte
	reporte.reporte = "Hola, no puedo editar los artículos que escribo ¿existe la opción?";
	reporte.autor = "Paco";
	
	comentario.autor = "Tomás";
	comentario.comentario = "Buenas, claro, ha de ir a la opción que dice MyZone del menú.";
	reporte.comentarios.push_back(comentario);
	comentario.autor = "Paco";
	comentario.comentario = "Vale, ya lo he conseguido";
	reporte.comentarios.push_back(comentario);
	comentario.autor = "Tomás";
	comentario.comentario = "Arreglado entonces";
	reporte.comentarios.push_back(comentario);
	reporte.estado=true;
	
	reportes.push_back(reporte);
	reporte.comentarios.clear();
	
	//Cuarto reporte
	reporte.reporte = "No puedo registrarme en la pagina, como lo hago?";
	reporte.autor = "Ana";
	
	comentario.autor = "Tomás";
	comentario.comentario = "Hola, más abajo hay un enlace que dice ¿No estas registrado?.";
	reporte.comentarios.push_back(comentario);
	comentario.autor = "Ana";
	comentario.comentario = "Vale, ya lo conseguí, ¡muchas gracias!";
	reporte.comentarios.push_back(comentario);
	comentario.autor = "Tomás";
	comentario.comentario = "Genial Ana, ¡saludos!";
	reporte.comentarios.push_back(comentario);
	reporte.estado=true;
	
	reportes.push_back(reporte);
	reporte.comentarios.clear();
}


int main() {
	string respuesta, nombre, autor, comentario_nuevo, reporte_selec;
	int opcion, contador;
	Reporte reporte;
	cout << " Proyecto de Oscar Puerta Perez"<< endl;
	cout << " Practica de 2016"<< endl;
	
	RellenaReportes()
	
	while(opcion!=6) {
		opcion=0;
		while(opcion<1 || opcion>6) {
			cout <<endl;
			cout << "--------LBT DCA---------" <<endl;
			cout << "   ¿Qué desea hacer?" << endl;
			cout << "1.Informar de un reporte " << endl;
			cout << "2.Ver reportes cerrados" << endl;
			cout << "3.Ver reportes abiertos" << endl;
			cout << "4.Cerrar reporte" << endl;
			cout << "5.Buscar reporte" << endl;
			cout << "6.Salir" << endl;
			cout << "------------------------" <<endl;
			cout <<endl;
			
			cin >> opcion;
			if(opcion<1 || opcion>6){
				cout<<"->Solo los numeros indicados en el menu"<<endl;
			}
		}
		switch(opcion){
			case 1:
			
				cout << "->Escriba su nombre a continuación:" << endl;
				cin.ignore(256,'\n');
				getline(cin, nombre);
				reporte.autor = nombre;
			
				cout << "->Escriba su reporte a continuación:" << endl;
				getline(cin, respuesta);
				reporte.reporte = respuesta;
				reporte.estado = false;
		
				reportes.push_back(reporte);
				cout << "->Reporte enviado con éxito." << endl;
			break;
			case 2:
				if(reportes.size() == 0) {
					cout << "		" << "No hay temas cerrados en este momento." << endl;
				}
				else{
					contador=0;
					for(int i=0;i<reportes.size();i++) {
						if(reportes[i].estado==true){
							cout << " N-" << i+1 << ".";
							reportes[i].MostrarReporteResumido();
							contador++;
						}
					}
					if(contador==0){
						cout << "		" << "No hay temas cerrados en este momento." << endl;
					}
					else{
					cout << "->Si desea ver un reporte completo tecle su número correspondiente";
					cout << ", si no, tecle cualquier otro número." << endl;
					cin >> reporte_selec;
					cin.ignore(256,'\n');
					if(atoi(reporte_selec.c_str())>=1 &&  atoi(reporte_selec.c_str())<=reportes.size() && reportes[atoi(reporte_selec.c_str())-1].estado==true) {
						reportes[atoi(reporte_selec.c_str())-1].MostrarReporte();
					}
					else{
						cout << "->El numero introducido no es un reporte cerrado" << endl;
					}
					}	
				}
			break;
			case 3:
				if(reportes.size() == 0) {
					cout << "		" << "No hay temas abiertos en este momento." << endl;
				}
				else{
					contador=0;
					for(int i=0;i<reportes.size();i++) {
					if(reportes[i].estado==false){
						cout << " N-" << i+1 << ".";
						reportes[i].MostrarReporteResumido();
						contador++;
						}
					}
					if(contador==0){
						cout << "		" << "No hay temas abiertos en este momento." << endl;
					}
					else{
						cout << "->Si desea ver un reporte completo tecle su número correspondiente" << endl;
						cout << "->Si no, tecle cualquier otro número" << endl;
						cin >> reporte_selec;
			
						if(atoi(reporte_selec.c_str())>=1 &&  atoi(reporte_selec.c_str())<=reportes.size() && reportes[atoi(reporte_selec.c_str())-1].estado==false) {
							reportes[atoi(reporte_selec.c_str())-1].MostrarReporte();
							cout << "->¿Desea añadir un comentario? (S/n)" << endl;
							cin >> respuesta;
							if(respuesta=="s") {
								cout << "->Escriba su nombre a continuación:" << endl;
								cin.ignore(256,'\n');
								getline(cin, autor);	
								cout << "->Escriba su comentario a continuación:" << endl;
								getline(cin, comentario_nuevo);
								Comentario c;
								c.autor = autor;
								c.comentario = comentario_nuevo;
								reportes[atoi(reporte_selec.c_str())-1].comentarios.push_back(c);
								cout << endl << "->Comentario enviado con éxito." << endl;
							}
							cout << "->¿Desea dar el tema por cerrado? (s/n)" << endl;
							cin >> respuesta;
							cin.ignore(256,'\n');
							if(respuesta=="s") {
								reportes[atoi(reporte_selec.c_str())-1].estado=true;
								cout << "->El tema se ha cerrado con exito" << endl;
							}
						}
						else{
							cout << "->El numero introducido no es un reporte abierto" << endl;
						}
					}
				}
			break;
			case 4:
				if(reportes.size() == 0) {
					cout << "		" << "No hay temas abiertos en este momento." << endl;
				}
				else{
					contador=0;
					for(int i=0;i<reportes.size();i++) {
						if(reportes[i].estado==false){
							cout << " N-" << i+1 << ".";
							reportes[i].MostrarReporteResumido();
							contador++;
						}
					}
					if(contador==0){
						cout << "		" << "No hay temas abiertos en este momento." << endl;
					}
					else{
						cout << "->Si desea ver un reporte completo tecle su número correspondiente" << endl;
						cout << "->Si no, tecle cualquier otro número" << endl;
						cin >> reporte_selec;
			
						if(atoi(reporte_selec.c_str())>=1 &&  atoi(reporte_selec.c_str())<=reportes.size() && reportes[atoi(reporte_selec.c_str())-1].estado==false) {
							reportes[atoi(reporte_selec.c_str())-1].MostrarReporte();
							cout << "->¿Desea dar el tema por cerrado? (s/n)" << endl;
							cin >> respuesta;
							cin.ignore(256,'\n');
							if(respuesta=="s") {
								reportes[atoi(reporte_selec.c_str())-1].estado=true;
							}
						}
						else{
							cout << "->El numero introducido no es un reporte abierto" << endl;
						}
					}
				}
			break;
			case 5:
				if(reportes.size() == 0) {
					cout << "		" << "No hay reportes en este momento." << endl;
				}
				else{
					cout<<"->Se va a buscar por el inicio del reporte, pon la palabra" <<endl;
					cout<<"que quieras buscar"<<endl;
					cin.ignore(256,'\n');
					getline(cin, reporte_selec);
					contador=0;
					cout<<"REPORTES CERRADOS"<<endl;
					for(int i=0;i<reportes.size();i++) {
						if(reportes[i].reporte.find(reporte_selec)!=-1 && reportes[i].estado==true){
							cout << " N-" << i+1 << ".";
							reportes[i].MostrarReporteResumido();
							contador++;
						}
					}
					cout<<"REPORTES ABIERTOS"<<endl;
					for(int i=0;i<reportes.size();i++) {
						if(reportes[i].reporte.find(reporte_selec)!=-1 && reportes[i].estado==false){
							cout << " N-" << i+1 << ".";
							reportes[i].MostrarReporteResumido();
							contador++;
						}
					}
					if(contador==0){
						cout<<"->No hay reportes con esa palabra"<<endl;
					}
					else{
						cout << "->Si desea ver un reporte completo tecle su número correspondiente" << endl;
						cout << "->Si no, tecle cualquier otro número" << endl;
						cin >> reporte_selec;
				
						if(atoi(reporte_selec.c_str())>=1 &&  atoi(reporte_selec.c_str())<=reportes.size() && reportes[atoi(reporte_selec.c_str())-1].estado==false) {
							reportes[atoi(reporte_selec.c_str())-1].MostrarReporte();
							cout << "->¿Desea añadir un comentario? (S/n)" << endl;
							cin >> respuesta;
					
							if(respuesta=="s") {
								cout << "->Escriba su nombre a continuación:" << endl;
								cin.ignore(256,'\n');
								getline(cin, autor);
								cout << "->Escriba su comentario a continuación:" << endl;
								getline(cin, comentario_nuevo);
					
								Comentario c;
								c.autor = autor;
								c.comentario = comentario_nuevo;
					
								reportes[atoi(reporte_selec.c_str())-1].comentarios.push_back(c);
								cout << endl << "->Comentario enviado con éxito." << endl;
							}
				
							cout << "->¿Desea dar el tema por cerrado? (s/n)" << endl;
							cin >> respuesta;
							cin.ignore(256,'\n');
							if(respuesta=="s") {
								reportes[atoi(reporte_selec.c_str())-1].estado=true;
								cout << "->El tema se ha cerrado con exito" << endl;
							}
						}
						else if(atoi(reporte_selec.c_str())>=1 &&  atoi(reporte_selec.c_str())<=reportes.size() && reportes[atoi(reporte_selec.c_str())-1].estado==true) {
							reportes[atoi(reporte_selec.c_str())-1].MostrarReporte();
						}
						else{
							cout << "->El numero introducido no es un reporte" << endl;
						}
					}
				}
			break;
			case 6:
				cout<<"Gracias por utilizar nuestra aplicacion"<<endl;
			break;
		}
	}

	return 0;
}
