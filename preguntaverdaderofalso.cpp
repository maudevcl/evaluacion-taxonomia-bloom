#include "preguntaverdaderofalso.h"
#include <iostream>

using namespace std;

PreguntaVerdaderoFalso::PreguntaVerdaderoFalso(int id, string enunciado, NivelTaxonomico nivel, int anio, int tiempo, bool esVerdadero, string justificacion)
    : Pregunta(id, enunciado, nivel, anio, tiempo), esVerdadero(esVerdadero), justificacion(justificacion) {}

PreguntaVerdaderoFalso::~PreguntaVerdaderoFalso() {
    cout << "Destruyendo objeto PreguntaVerdaderoFalso" << endl;
}

void PreguntaVerdaderoFalso::mostrar() {
    cout << "Pregunta de verdadero o falso: " << enunciado << endl;
    cout << "Respuesta esperada: " << (esVerdadero ? "Verdadero" : "Falso") << endl;
    cout << "Justificacion: " << justificacion << endl;
    cout << "Nivel: " << nivelToString(nivelTaxonomico)
         << " | Anio: " << anio
         << " | Tiempo estimado: " << tiempoEstimado << " minutos" << endl;
}

string PreguntaVerdaderoFalso::getTipo() {
    return "verdadero_falso";
}

bool PreguntaVerdaderoFalso::getEsVerdadero() {
    return esVerdadero;
}

string PreguntaVerdaderoFalso::getJustificacion() {
    return justificacion;
}

void PreguntaVerdaderoFalso::setEsVerdadero(bool valor) {
    esVerdadero = valor;
}

void PreguntaVerdaderoFalso::setJustificacion(string nuevaJustificacion) {
    justificacion = nuevaJustificacion;
}