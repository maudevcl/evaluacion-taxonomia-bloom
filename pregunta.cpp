#include "pregunta.h"
#include <iostream>
#include <algorithm> 

using namespace std;


Pregunta::Pregunta(int id, string enunciado, NivelTaxonomico nivel, int anio, int tiempo)
    : id(id), enunciado(enunciado), nivelTaxonomico(nivel), anio(anio), tiempoEstimado(tiempo) {}

Pregunta::~Pregunta() {
    cout << "Destruyendo objeto Pregunta base" << endl;
}

int Pregunta::getId() {
    return id;
}

string Pregunta::getEnunciado() {
    return enunciado;
}

NivelTaxonomico Pregunta::getNivelTaxonomico() {
    return nivelTaxonomico;
}

int Pregunta::getAnio() {
    return anio;
}

int Pregunta::getTiempoEstimado() {
    return tiempoEstimado;
}

void Pregunta::setEnunciado(string e) {
    enunciado = e;
}

void Pregunta::setNivelTaxonomico(NivelTaxonomico nivel) {
    nivelTaxonomico = nivel;
}

void Pregunta::setAnio(int a) {
    anio = a;
}

void Pregunta::setTiempoEstimado(int t) {
    tiempoEstimado = t;
}



string nivelToString(NivelTaxonomico nivel) {
    switch (nivel) {
        case NivelTaxonomico::RECORDAR: return "Recordar";
        case NivelTaxonomico::ENTENDER: return "Entender";
        case NivelTaxonomico::APLICAR:  return "Aplicar";
        case NivelTaxonomico::ANALIZAR: return "Analizar";
        case NivelTaxonomico::EVALUAR:  return "Evaluar";
        case NivelTaxonomico::CREAR:    return "Crear";
        default: return "Desconocido";
    }
}

NivelTaxonomico stringToNivel(const string& str) {
    string s = str;
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    if (s == "recordar") return NivelTaxonomico::RECORDAR;
    if (s == "entender") return NivelTaxonomico::ENTENDER;
    if (s == "aplicar")  return NivelTaxonomico::APLICAR;
    if (s == "analizar") return NivelTaxonomico::ANALIZAR;
    if (s == "evaluar")  return NivelTaxonomico::EVALUAR;
    if (s == "crear")    return NivelTaxonomico::CREAR;

    throw invalid_argument("Nivel taxonomico invalido: " + str);
}
