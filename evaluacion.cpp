#include "evaluacion.h"
#include <iostream>

using namespace std;

Evaluacion::Evaluacion(string asignatura, int anio, double ponderacion) : asignatura(asignatura), anio(anio), ponderacion(ponderacion) {
}

Evaluacion::~Evaluacion() {
    cout << "Destruyendo evaluacion" << endl;
}

void Evaluacion::agregarPregunta(Pregunta* p) {
    preguntas.push_back(p); // agregar una nueva pregunta a la evaluacion
}

void Evaluacion::mostrarEvaluacion() {
    cout << "Evaluacion de " << asignatura << " del anio " << anio << " con ponderacion " << ponderacion << "%" << endl;
    cout << "Preguntas:" << endl;
    for (Pregunta* p : preguntas) {
        cout << "-----------------------------" << endl;
        p->mostrar(); // mostrar cada pregunta en la evaluacion
    }
    cout << "Tiempo total estimado: " << calcularTiempoTotal() << " minutos" << endl;
}

int Evaluacion::calcularTiempoTotal() {
    int total = 0;
    for (Pregunta* p : preguntas) {
        total += p->getTiempoEstimado(); // suma tiempo estimado
    }
    return total; 
}
string Evaluacion::getAsignatura() {
    return asignatura; // asignatura evaluacion
}
int Evaluacion::getAnio() {
    return anio; 
}
double Evaluacion::getPonderacion() {
    return ponderacion; 
}
vector<Pregunta*> Evaluacion::getPreguntas() {
    return preguntas; // preguntas evaluacion
}