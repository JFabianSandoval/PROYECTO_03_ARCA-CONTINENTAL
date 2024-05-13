#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>

using namespace std;

using namespace System;
// Clase Usuario para manejar la información del usuario
class Usuario {
private:
    string nombre;
    string apellido;
    string codigo;
    vector<bool> respuestas;

public:
    // Constructor para inicializar un usuario con nombre, apellido y código
    Usuario(const string& nombre, const string& apellido, const string& codigo)
        : nombre(nombre), apellido(apellido), codigo(codigo) {}

    // Método para registrar respuestas a las preguntas
    void responderPregunta(bool respuesta) {
        respuestas.push_back(respuesta);
    }

    // Método para determinar el rol del usuario basado en las respuestas
    string determinarRol() const {
        bool rolCEO = true; // Todas las respuestas son afirmativas
        for (bool respuesta : respuestas) {
            if (!respuesta) {
                rolCEO = false;
                break;
            }
        }
        if (rolCEO) return "Director de Finanzas";
        bool rolTesorero = respuestas[0] && respuestas[1] && respuestas[2] && respuestas[3] &&
            respuestas[4] && respuestas[5] && respuestas[7] && respuestas[9];
        if (rolTesorero) return "Tesorero";
        bool rolAFC = respuestas[0] && respuestas[1] && respuestas[2] && respuestas[3] &&
            respuestas[7] && respuestas[8] && respuestas[9] && respuestas[11];
        if (rolAFC) return "Analista Financiero Contable";
        bool rolDI = respuestas[0] && respuestas[1] && respuestas[5] && respuestas[9];
        if (rolDI) return "Departamento de Impuestos";
        bool rolGC = respuestas[0] && respuestas[2] && respuestas[3] && respuestas[4] && respuestas[6] &&
            respuestas[7] && respuestas[8] && respuestas[9] && respuestas[10] && respuestas[11];
        if (rolGC) return "Gerente Contable";
        bool rolCF = respuestas[0] && respuestas[6] && respuestas[7] && respuestas[9] && respuestas[10] && respuestas[11];
        if (rolCF) return "Controller Financiero";
        bool rolAIE = respuestas[0] && respuestas[6] && respuestas[8] && respuestas[11];
        if (rolAIE) return "Auditoria Interna Externa";




        return "Desconocido";
    }

    // Método para mostrar las respuestas
    void mostrarRespuestas() const {
        cout << "Respuestas del usuario " << nombre << " " << apellido << ":" << endl;
        for (size_t i = 0; i < respuestas.size(); ++i) {
            cout << "Pregunta " << i + 1 << ": " << (respuestas[i] ? "Sí" : "No") << endl;
        }
    }

    // Método para eliminar todas las respuestas
    void limpiarRespuestas() {
        respuestas.clear();
    }

    // Métodos para obtener información del usuario
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getCodigo() const { return codigo; }
};


void aparicion();
void crearBordes();
void logoUPC();
void barraCarga();
void  nombreArbolex();
void bordesInternos();
void mostrarCreditos();
void salir();
void integrantes();
void seleccion1();
void seleccion2();

int main() {
    Console::SetWindowSize(125, 40);
    Console::CursorVisible = false;
    int opcion;
    int op=1;
    char el;
    bool salirMenu=false;
    char eleccion;
    aparicion();
    

    do {
        // Mostrar el menú principal
        system("cls");
        crearBordes();
        bordesInternos();
        Console::ForegroundColor = ConsoleColor::Cyan;
        Console::SetCursorPosition(55, 20);
        cout << "1. USUARIOS";
        Console::ForegroundColor = ConsoleColor::Blue;
        Console::SetCursorPosition(55, 23);
        cout << "2. CREDITOS";
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(55, 26);
        cout << "3. SALIR"<<endl;
        Console::ForegroundColor = ConsoleColor::Black;
        Console::SetCursorPosition(5, 5);
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int opcionUsuarios;
            vector<Usuario> usuarios; // Lista para almacenar usuarios

            do {
                system("cls");
                crearBordes();
                bordesInternos();
                // Mostrar el submenú de Usuarios
                Console::ForegroundColor = ConsoleColor::Cyan;
                Console::SetCursorPosition(52, 20);
                cout << "1. REGISTRAR USUARIO";
                Console::ForegroundColor = ConsoleColor::Red;
                Console::SetCursorPosition(52, 23);
                cout << "2. ELIMINAR USUARIO";
                Console::ForegroundColor = ConsoleColor::Blue;
                Console::SetCursorPosition(52, 26);
                cout << "3. VER USUARIO";
                Console::ForegroundColor = ConsoleColor::DarkRed;
                Console::SetCursorPosition(52, 29);
                cout << "4. SALIR" << endl;
                Console::ForegroundColor = ConsoleColor::Black;
                Console::SetCursorPosition(5, 5);
                cin >> opcionUsuarios;

                switch (opcionUsuarios) {
                case 1: {
                    // Registrar un nuevo usuario
                    system("cls");
                    crearBordes();
                    bordesInternos();
                    
                    string nombre, apellido, codigo;
                    Console::ForegroundColor = ConsoleColor::Blue;
                    Console::SetCursorPosition(50, 20);
                    cout << "NOMBRE: ";
                    Console::SetCursorPosition(50, 24);
                    cout << "APELLIDO: ";
                    Console::SetCursorPosition(50, 28);
                    cout << "CODIGO: ";
                    Console::ForegroundColor = ConsoleColor::White;
                    Console::CursorVisible = true;
                    Console::SetCursorPosition(52, 22);
                    cin >> nombre;
                    Console::SetCursorPosition(52, 26);
                    cin >> apellido;
                    Console::SetCursorPosition(52, 30);
                    cin >> codigo;
                    Console::CursorVisible = false;
                    // Crear un nuevo objeto Usuario y agregarlo a la lista
                    Usuario nuevoUsuario(nombre, apellido, codigo);
                  
                    // Simular preguntas (en este ejemplo, simplemente se almacena un valor booleano)
                    for (int i = 0; i < 12; ++i) {
                        char respuesta;
                        system("cls");
                        crearBordes();
                        bordesInternos();
                        Console::SetCursorPosition(52, 24);
                        cout << "PREGUNTA " << i + 1 << " (y/n)? ";
                        Console::SetCursorPosition(52, 26);
                        cin >> respuesta;
                        nuevoUsuario.responderPregunta(tolower(respuesta) == 'y');
                    }

                    // Agregar el usuario a la lista de usuarios
                    usuarios.push_back(nuevoUsuario);
                    Console::SetCursorPosition(52, 26);
                    cout << "USUARIO REGISTRADO" << endl;
                    _sleep(1000);
                    system("cls");
                    break;
                }
                case 2: {
                    system("cls");
                    crearBordes();
                    bordesInternos();
                    // Eliminar usuario
                    int numeroUsuario;
                    Console::ForegroundColor = ConsoleColor::Red;
                    Console::SetCursorPosition(52, 24);
                    cout << "INGRESE USUARIO (1-" << usuarios.size() << "): ";
                    Console::SetCursorPosition(52, 26);
                    cin >> numeroUsuario;

                    if (numeroUsuario >= 1 && numeroUsuario <= usuarios.size()) {
                        // Eliminar usuario de la lista
                        usuarios.erase(usuarios.begin() + numeroUsuario - 1);
                        system("cls");
                        crearBordes();
                        bordesInternos();
                        Console::SetCursorPosition(52, 24);
                        cout << "USUARIO ELIMINADO." << endl;
                    }
                    else {
                        system("cls");
                        crearBordes();
                        bordesInternos();
                        Console::SetCursorPosition(52, 24);
                        cout << "NÚMERO DE USUARIO INVÁLIDO." << endl;
                    }
                    break;
                }
                case 3: {
                    // Ver usuarios
                    system("cls");
                    crearBordes();
                    int ye=7;
                    int xe = 7;
                    Console::ForegroundColor = ConsoleColor::Green;
                    Console::SetCursorPosition(5, 5);
                    cout << "LISTA DE USUARIOS" << endl;
                    for (size_t i = 0; i < usuarios.size(); ++i) {
                    Console::SetCursorPosition(xe, ye);
                        cout << i + 1 << ".Nombre: " << usuarios[i].getNombre() << " Apellido: " << usuarios[i].getApellido() << " Codigo: " << usuarios[i].getCodigo();
                        Console::SetCursorPosition(7, ye + 1);
                        cout<< " Rol: " << usuarios[i].determinarRol();
                        ye=ye+3;
                        if (ye == 45) {
                            xe = 47;
                        }
                    }
                    _getch();
                    break;
                }
                case 4:
                    // Salir del submenú de Usuarios
                    break;
                default:
                    cout << "Opcion invalida. Intente de nuevo." << endl;
                    break;
                }
            } while (opcionUsuarios != 4);

            break;
        }
        case 2:
            // Mostrar Creditos

            mostrarCreditos();
            _getch();
            break;
        case 3:
            // Salir del programa
            system("cls");
            exit(0);
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion <4);

    return 0;
}

void aparicion() {
    crearBordes();
    logoUPC();
    barraCarga();
    system("cls");
}
void crearBordes() {
    system("cls");
    Console::ForegroundColor = ConsoleColor::White;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 125; j++) {
            if (j < 2 || j >= 123 || i == 0 || i == 49) {
                cout << char(219);
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    Console::SetCursorPosition(0, 0);
}
void logoUPC() {

    Console::ForegroundColor = ConsoleColor::Red;
    Console::SetCursorPosition(61, 7); cout << "###"; _sleep(1);
    Console::SetCursorPosition(60, 8); cout << "####"; _sleep(1);
    Console::SetCursorPosition(58, 9); cout << "#####"; _sleep(1);
    Console::SetCursorPosition(56, 10); cout << "########";
    Console::SetCursorPosition(37, 11); cout << "###              #########                          .#"; _sleep(1);
    Console::SetCursorPosition(36, 12); cout << "###               ##########                            ###"; _sleep(1);
    Console::SetCursorPosition(34, 13); cout << "###                ############                             ###"; _sleep(1);
    Console::SetCursorPosition(32, 14); cout << "####                ###############                           .####"; _sleep(1);
    Console::SetCursorPosition(30, 15); cout << "#####,                #################                          .####"; _sleep(1);
    Console::SetCursorPosition(29, 16); cout << "######                 ###################                        ######"; _sleep(1);
    Console::SetCursorPosition(28, 17); cout << "######                  #####################                       ######"; _sleep(1);
    Console::SetCursorPosition(27, 18); cout << "#######                   #######################                     #######"; _sleep(1);
    Console::SetCursorPosition(26, 19); cout << "########                   ########################                    #######"; _sleep(1);
    Console::SetCursorPosition(26, 20); cout << "########                    ,#######################                   ########"; _sleep(1);
    Console::SetCursorPosition(25, 21); cout << ",#########                     #######################                 #########"; _sleep(1);
    Console::SetCursorPosition(25, 22); cout << "##########                       #####################                 ##########"; _sleep(1);
    Console::SetCursorPosition(25, 23); cout << "###########                        ###################                ###########"; _sleep(1);
    Console::SetCursorPosition(25, 24); cout << "############                          ################               ############"; _sleep(1);
    Console::SetCursorPosition(25, 25); cout << " ############                           ##############              .############"; _sleep(1);
    Console::SetCursorPosition(25, 26); cout << " ##############                          ##############             #############"; _sleep(1);
    Console::SetCursorPosition(25, 27); cout << " ,###############                         ############            ##############"; _sleep(1);
    Console::SetCursorPosition(25, 28); cout << "  #################                       ###########           ,##############"; _sleep(1);
    Console::SetCursorPosition(25, 29); cout << "   ###################                    #########         ,#################"; _sleep(1);
    Console::SetCursorPosition(25, 30); cout << "    #######################               #######       #####################"; _sleep(1);
    Console::SetCursorPosition(25, 31); cout << "     .############################       ##   ##############################"; _sleep(1);
    Console::SetCursorPosition(25, 32); cout << "       ###################################################################"; _sleep(1);
    Console::SetCursorPosition(25, 33); cout << "         ###############################################################"; _sleep(1);
    Console::SetCursorPosition(25, 34); cout << "           ###########################################################"; _sleep(1);
    Console::SetCursorPosition(25, 35); cout << "              #####################################################"; _sleep(1);
    Console::SetCursorPosition(25, 36); cout << "                 ###############################################"; _sleep(1);
    Console::SetCursorPosition(25, 37); cout << "                    #########################################"; _sleep(1);
    Console::SetCursorPosition(25, 38); cout << "                         #############################"; _sleep(1);
    _sleep(1);//EDIT
}
void barraCarga() {

    Console::ForegroundColor = ConsoleColor::White; Console::SetCursorPosition(57, 45); cout << "L O A D I N G ...";
    for (int i = 0; i < 31; i++)
    {
        Console::ForegroundColor = ConsoleColor::DarkGray;
        Console::SetCursorPosition(49 + i, 43);
        cout << char(219);
    }
    _sleep(400);
    for (int i = 0; i < 31; i++)
    {
        Console::ForegroundColor = ConsoleColor::Red;
        Console::SetCursorPosition(49 + i, 43);
        cout << char(219);
        _sleep(30);
    }
    _sleep(300);

}
void nombreArbolex() {
    Console::ForegroundColor = ConsoleColor::Green;
    Console::SetCursorPosition(0, 0);
    Console::SetCursorPosition(28, 7);   cout << "       _       _______     ______      ___   _____     ________  ____  ____ ";
    Console::SetCursorPosition(28, 8);   cout << "      / \\     |_   __ \\   |_   _ \\   .'   `.|_   _|   |_   __  ||_  _||_  _|";
    Console::SetCursorPosition(28, 9);   cout << "     / _ \\      | |__) |    | |_) | /  .-.  \\ | |       | |_ \\_|  \\ \\  / /  ";
    Console::SetCursorPosition(28, 10); cout << "    / ___ \\     |  __ /     |  __'. | |   | | | |   _   |  _| _    > `' <   ";
    Console::SetCursorPosition(28, 11); cout << "  _/ /   \\ \\_  _| |  \\ \\_  _| |__) |\\  `-'  /_| |__/ | _| |__/ | _/ /'`\\ \\_ ";
    Console::SetCursorPosition(28, 12); cout << " |____| |____||____| |___||_______/  `.___.'|________||________||____||____|";

}
void bordesInternos() {
    Console::ForegroundColor = ConsoleColor::DarkBlue;
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 29; j++) {
            Console::SetCursorPosition(47 + j, 18 + i);
            if (j < 1 || j >= 28 || i == 0 || i == 16) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void mostrarCreditos() {
    system("cls");
    crearBordes();
    integrantes();
   
}
void salir() {
    system("cls");
    Console::ForegroundColor = ConsoleColor::Black;
    exit(0);
}
void integrantes() {
    Console::SetCursorPosition(0, 0);
    Console::SetCursorPosition(35, 5); cout << "-*-*-*-*-*-*-*-*-*-* Creditos: *-*-*-*-*-*-*-*-*-*-*-";
    Console::SetCursorPosition(20, 15); cout << " * Fabian Jesus Sandoval Cueto -u20221a132";
    Console::SetCursorPosition(20, 20); cout << " * Axel Rodrigo Sandoval Ramos - u202319003";
    Console::SetCursorPosition(20, 25); cout << " * Nicolas Fredy Torrejon Gonzales - u20231e961";
    Console::SetCursorPosition(20, 30); cout << " * Alberto Fernando Rodriguez Barreto -u202418094";
    Console::SetCursorPosition(20, 43); cout << "Presione Enter para volver al menu";
}
void seleccion1() {
    Console::ForegroundColor = ConsoleColor::Cyan;
    Console::SetCursorPosition(55, 20);
    cout << "> DIAGRAMA";
    Console::SetCursorPosition(55, 23);
    Console::ForegroundColor = ConsoleColor::White;
    cout << "CREDITOS     ";
    Console::SetCursorPosition(55, 26);
    cout << "SALIR      ";
}
void seleccion2() {
    Console::ForegroundColor = ConsoleColor::Blue;
    Console::SetCursorPosition(55, 23);
    cout << "> CREDITOS      ";
    Console::ForegroundColor = ConsoleColor::White;
    Console::SetCursorPosition(55, 20);
    cout << "DIAGRAMA  ";
    Console::SetCursorPosition(55, 26);
    cout << "SALIR     ";
}
