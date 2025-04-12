#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include "pregunta.h"
#include "preguntamultipleopcion.h"
#include "preguntaverdaderofalso.h"
#include "bancopreguntas.h"
#include "evaluacion.h"

using namespace std;

void mostrarMenu() {
    cout << "\n--- MENU PRINCIPAL ---\n";
    cout << "1. Crear pregunta (seleccion multiple o verdadero/falso)\n";
    cout << "2. Mostrar todas las preguntas\n";
    cout << "3. Eliminar pregunta por ID\n";
    cout << "4. Buscar preguntas por nivel taxonomico\n";
    cout << "5. Generar evaluacion\n";
    cout << "6. Actualizar pregunta por ID\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    srand(time(nullptr));
    BancoPreguntas banco;
    Evaluacion evaluacion("Paradigmas de Programacion", 2025, 25.0);
    int opcion = 0;

    do {
        mostrarMenu();
        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Debe ingresar un numero entre 1 y 7.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1: {
                int tipo;
                cout << "\nSeleccione tipo de pregunta:\n1. Opcion multiple\n2. Verdadero/Falso\n";
                cin >> tipo;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (tipo != 1 && tipo != 2) {
                    cout << "Opcion invalida.\n";
                    break;
                }

                int id, anio, tiempo;
                string enunciado, nivelStr;
                NivelTaxonomico nivel;

                cout << "ID: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (banco.buscarPorId(id)) {
                    cout << "Error: ya existe una pregunta con ese ID.\n";
                    break;
                }

                cout << "Enunciado: ";
                getline(cin, enunciado);

                cout << "Nivel taxonomico (recordar, entender, aplicar, analizar, evaluar, crear): ";
                getline(cin, nivelStr);

                try {
                    nivel = stringToNivel(nivelStr);
                } catch (const invalid_argument& e) {
                    cout << "ERROR: " << e.what() << endl;
                    break;
                }

                cout << "Anio: ";
                cin >> anio;
                cout << "Tiempo estimado (en minutos): ";
                cin >> tiempo;

                if (tipo == 1) {
                    vector<string> opciones;
                    string op;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Ingrese 4 opciones:\n";
                    for (int i = 0; i < 4; ++i) {
                        cout << "Opcion " << i + 1 << ": ";
                        getline(cin, op);
                        opciones.push_back(op);
                    }
                    int respuesta;
                    cout << "Indice de la respuesta correcta (1-4): ";
                    cin >> respuesta;
                    if (respuesta < 1 || respuesta > 4) {
                        cout << "Respuesta fuera de rango.\n";
                        break;
                    }
                    Pregunta* pregunta = new PreguntaMultipleOpcion(id, enunciado, nivel, anio, tiempo, opciones, respuesta - 1);
                    banco.agregarPregunta(pregunta);
                    cout << "Pregunta de opcion multiple agregada correctamente.\n";
                } else {
                    string boolStr, justificacion;
                    bool esVerdadero;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "¿La afirmacion es verdadera? (si/no): ";
                    getline(cin, boolStr);
                    esVerdadero = (boolStr == "si" || boolStr == "SI");
                    cout << "Justificacion esperada: ";
                    getline(cin, justificacion);
                    Pregunta* nueva = new PreguntaVerdaderoFalso(id, enunciado, nivel, anio, tiempo, esVerdadero, justificacion);
                    banco.agregarPregunta(nueva);
                    cout << "Pregunta de verdadero/falso agregada correctamente.\n";
                }
                break;
            }

            case 2:
                banco.mostrarTodas();
                break;

            case 3: {
                int id;
                cout << "Ingrese el ID de la pregunta a eliminar: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                banco.eliminarPregunta(id);
                break;
            }

            case 4: {
                string nivelStr;
                NivelTaxonomico nivel;
                cout << "Ingrese el nivel taxonomico a buscar: ";
                getline(cin, nivelStr);
                try {
                    nivel = stringToNivel(nivelStr);
                } catch (const invalid_argument& e) {
                    cout << "ERROR: " << e.what() << endl;
                    break;
                }
                for (Pregunta* p : banco.getPreguntas()) {
                    if (p->getNivelTaxonomico() == nivel) {
                        p->mostrar();
                    }
                }
                break;
            }

            case 5: {
                int cantidad;
                string nivelStr;
                NivelTaxonomico nivel;
            
                cout << "Cuantas preguntas desea agregar a la evaluacion? ";
                cin >> cantidad;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                cout << "De que nivel taxonomico? (recordar, entender, aplicar, analizar, evaluar, crear): ";
                getline(cin, nivelStr);
            
                try {
                    nivel = stringToNivel(nivelStr);
                } catch (const invalid_argument& e) {
                    cout << "ERROR: " << e.what() << endl;
                    break;
                }
            
                vector<Pregunta*> disponibles = banco.getPreguntas();
            
                random_device rd;
                mt19937 g(rd());
                shuffle(disponibles.begin(), disponibles.end(), g);
            
                int agregadas = 0;
            
                for (Pregunta* p : disponibles) {
                    bool mismoNivel = (p->getNivelTaxonomico() == nivel);
                    bool esConsecutivo = abs(p->getAnio() - evaluacion.getAnio()) == 1;
            
                    // Verificar si ya fue agregada a la evaluacion
                    bool yaAgregada = false;
                    for (Pregunta* ya : evaluacion.getPreguntas()) {
                        if (ya->getId() == p->getId()) {
                            yaAgregada = true;
                            break;
                        }
                    }
            
                    if (mismoNivel && !esConsecutivo && !yaAgregada && agregadas < cantidad) {
                        evaluacion.agregarPregunta(p);
                        agregadas++;
                    }
                }
            
                if (agregadas == 0) {
                    cout << "No se encontraron preguntas disponibles para ese nivel." << endl;
                } else {
                    cout << "Preguntas agregadas: " << agregadas << endl;
                    if (agregadas < cantidad) {
                        cout << "Nota: No se alcanzo la cantidad solicitada.\n";
                    }
                    evaluacion.mostrarEvaluacion();
                }
            
                break;
            }
            

            case 6: {
                int id;
                cout << "ingrese el ID de la pregunta a actualizar: ";
                cin >> id;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Pregunta* p = banco.buscarPorId(id);
                if (!p) {
                    cout << "No se encontro pregunta con ese ID." << endl;
                    break;
                }

                cout << "\nPregunta actual:\n";
                p->mostrar();

                string nuevoEnunciado, nuevoNivelStr;
                int nuevoAnio, nuevoTiempo;
                NivelTaxonomico nuevoNivel;

                cout << "\n--- ACTUALIZAR DATOS ---\n";
                cout << "Nuevo enunciado: ";
                getline(cin, nuevoEnunciado);
                cout << "Nuevo nivel taxonomico (recordar, entender, aplicar, analizar, evaluar, crear): ";
                getline(cin, nuevoNivelStr);
                try {
                    nuevoNivel = stringToNivel(nuevoNivelStr);
                } catch (const invalid_argument& e) {
                    cout << "ERROR: " << e.what() << endl;
                    break;
                }
                cout << "Nuevo anio: ";
                cin >> nuevoAnio;
                cout << "Nuevo tiempo estimado (minutos): ";
                cin >> nuevoTiempo;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                p->setEnunciado(nuevoEnunciado);
                p->setNivelTaxonomico(nuevoNivel);
                p->setAnio(nuevoAnio);
                p->setTiempoEstimado(nuevoTiempo);

                if (p->getTipo() == "multiple") {
                    auto* m = dynamic_cast<PreguntaMultipleOpcion*>(p);
                    vector<string> nuevasOpciones;
                    string op;
                    cout << "Ingrese nuevas 4 opciones:\n";
                    for (int i = 0; i < 4; ++i) {
                        cout << "Opcion " << i + 1 << ": ";
                        getline(cin, op);
                        nuevasOpciones.push_back(op);
                    }
                    int nuevaCorrecta;
                    cout << "Indice de la respuesta correcta (1-4): ";
                    cin >> nuevaCorrecta;
                    if (nuevaCorrecta < 1 || nuevaCorrecta > 4) {
                        cout << "Respuesta fuera de rango." << endl;
                        break;
                    }
                    m->setOpciones(nuevasOpciones);
                    m->setRespuestaCorrecta(nuevaCorrecta - 1);
                } else if (p->getTipo() == "verdadero_falso") {
                    auto* vf = dynamic_cast<PreguntaVerdaderoFalso*>(p);
                    string boolStr, justificacion;
                    cout << "¿La afirmacion es verdadera? (si/no): ";
                    cin >> boolStr;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    bool nuevaVerdad = (boolStr == "si" || boolStr == "SI");
                    cout << "Nueva justificacion esperada: ";
                    getline(cin, justificacion);
                    vf->setEsVerdadero(nuevaVerdad);
                    vf->setJustificacion(justificacion);
                }

                cout << "Pregunta actualizada correctamente." << endl;
                break;
            }

            case 7:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
        }

    } while (opcion != 7);

    return 0;
}
