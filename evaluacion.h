#ifndef EVALUACION_H
#define EVALUACION_H

#include <vector>
#include <string>
#include "pregunta.h"

class Evaluacion {
    private:
        string asignatura; 
        int anio; 
        double ponderacion; 
        vector<Pregunta*> preguntas; 

    public:
        Evaluacion(string asignatura, int anio, double ponderacion); 
        ~Evaluacion(); // Destructor
//metodos
        void agregarPregunta(Pregunta* p); 
        void mostrarEvaluacion(); 
        int calcularTiempoTotal(); 

        string getAsignatura(); 
        int getAnio(); 
        double getPonderacion(); 
        vector<Pregunta*> getPreguntas(); 
}; 

#endif