#include "bancopreguntas.h"
#include <iostream>

using namespace std;

BancoPreguntas::BancoPreguntas() {}

BancoPreguntas::~BancoPreguntas() {
    for (Pregunta* p : preguntas) {
        delete p;
    }
}

void BancoPreguntas::agregarPregunta(Pregunta* p) {
    preguntas.push_back(p);
}

void BancoPreguntas::mostrarTodas() {
    if (preguntas.empty()) {
        cout << "No hay preguntas registradas.\n";
        return;
    }

    for (Pregunta* p : preguntas) {
        p->mostrar();
        cout << "-----------------------------\n";
    }
}

void BancoPreguntas::eliminarPregunta(int id) {
    for (auto it = preguntas.begin(); it != preguntas.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            preguntas.erase(it);
            cout << "Pregunta eliminada correctamente.\n";
            return;
        }
    }
    cout << "No se encontro pregunta con ese ID.\n";
}

Pregunta* BancoPreguntas::buscarPorId(int id) {
    for (Pregunta* p : preguntas) {
        if (p->getId() == id)
            return p;
    }
    return nullptr;
}

vector<Pregunta*> BancoPreguntas::getPreguntas() {
    return preguntas;
}
