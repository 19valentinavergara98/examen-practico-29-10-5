#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;


int main() {

// Obtener el método de la solicitud (GET o POST)
    const char* request_method = getenv("REQUEST_METHOD");
    char* query_string = nullptr;

    if (request_method != nullptr && strcmp(request_method, "GET") == 0) {
        // Si el método es GET, leer la cadena de consulta de la URL
        query_string = getenv("QUERY_STRING");
    } 
    else if (request_method != nullptr && strcmp(request_method, "POST") == 0) {
        // Si el método es POST, leer el contenido de la entrada estándar (stdin)
        const char* content_length_str = getenv("CONTENT_LENGTH");
        int content_length = 0;
        if (content_length_str != nullptr) {
            content_length = atoi(content_length_str); // Convertir a entero
        }
        query_string = new char[content_length + 1];  // Reservar espacio para el contenido POST
        cin.read(query_string, content_length);       // Leer desde stdin
        query_string[content_length] = '\0';          // Asegurarse de que sea una cadena terminada
    }


   
    char numero[50] = "";
    
    char orden[50] = "";

    if (query_string != nullptr) {
        // Parsear los parámetros
        char* param = strdup(query_string);  // Hacer una copia de la cadena de consulta
        char* token = strtok(param, "&");    // Separar los parámetros
        while (token != nullptr) {
            if (sscanf(token, "numero=%49s", numero) == 1) {  }
            if (sscanf(token, "orden=%49s", orden) == 1) {  }
            token = strtok(nullptr, "&");    // Continuar con el siguiente parámetro
        }
        free(param);  // Liberar la memoria
    }


    if( string(orden) == "resetear"){
        //crear fichero 
        ofstream archivo("configuracion.config");
        //rellenar fichero
        archivo << numero << "\n";
        //cerrar fichero
        archivo.close();
        cout << "Content-Type: text/plain\n\n";
        cout << "numero reseteado";
    }

    if( string(orden) == "añadir"){
       

        //abrir fichero
        ifstream archivo2("configuracion.config");
        //capturar contenido
        string n = "";
        string linea;
        getline(archivo2, linea);
        n = linea;
        //cerrar fichero
        archivo2.close();

        string respuesta = "{";
        respuesta += "\"numero\":\"";
        respuesta += n;
        respuesta += "\", \"mensaje\":\"";
        respuesta += "numero añadido";
        respuesta +="\"}";
        cout << "Content-Type: application/json\n\n";
        cout << respuesta;
       
    }
} 