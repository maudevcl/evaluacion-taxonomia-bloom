#include "preguntamultipleopcion.h"
#include <iostream>

using namespace std;

PreguntaMultipleOpcion::PreguntaMultipleOpcion(int id, string enunciado, NivelTaxonomico nivel, int anio, int tiempo, vector<string> opciones, int respuestaCorrecta)
    : Pregunta(id, enunciado, nivel, anio, tiempo), opciones(opciones), respuestaCorrecta(respuestaCorrecta) {}

PreguntaMultipleOpcion::~PreguntaMultipleOpcion() {
    cout << "Destruyendo objeto PreguntaMultipleOpcion" << endl;
}

void PreguntaMultipleOpcion::mostrar() {
    cout << "Pregunta de opcion multiple: " << enunciado << endl;
    for (size_t i = 0; i < opciones.size(); i++) {
        cout << "  " << (i + 1) << ") " << opciones[i] << endl;
    }
    cout << "Nivel: " << nivelToString(nivelTaxonomico)
         << " | Anio: " << anio
         << " | Tiempo estimado: " << tiempoEstimado << " minutos" << endl;
}

string PreguntaMultipleOpcion::getTipo() {
    return "multiple";
}

vector<string> PreguntaMultipleOpcion::getOpciones() {
    return opciones;
}

int PreguntaMultipleOpcion::getRespuestaCorrecta() {
    return respuestaCorrecta;
}

void PreguntaMultipleOpcion::setOpciones(vector<string> nuevasOpciones) {
    opciones = nuevasOpciones;
}

void PreguntaMultipleOpcion::setRespuestaCorrecta(int nuevaRespuesta) {
    respuestaCorrecta = nuevaRespuesta;
}
