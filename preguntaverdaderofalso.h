#ifndef PREGUNTAVERDADEROFALSO_H
#define PREGUNTAVERDADEROFALSO_H

#include "pregunta.h"

class PreguntaVerdaderoFalso : public Pregunta{
    private:
        bool esVerdadero; 
        string justificacion; 
    
    public:
        PreguntaVerdaderoFalso(int id, string enunciado, NivelTaxonomico nivel, int anio, int tiempo, bool esVerdadero, string justificacion);
        ~PreguntaVerdaderoFalso(); 

        void mostrar() override; 
        string getTipo() override; 

        bool getEsVerdadero(); 
        string getJustificacion(); 

        void setEsVerdadero(bool valor); 
        void setJustificacion(string justificacion); 
};

#endif