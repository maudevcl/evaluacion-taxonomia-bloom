#ifndef PREGUNTAMULTIPLEOPCION_H
#define PREGUNTAMULTIPLEOPCION_H

#include "pregunta.h"
#include <vector>

class PreguntaMultipleOpcion : public Pregunta {
    private:
        vector<string> opciones; 
        int respuestaCorrecta; 

    public:
        PreguntaMultipleOpcion(int id, string enunciado, NivelTaxonomico nivel, int anio, int tiempo, vector<string> opciones, int respuestaCorrecta);
        ~PreguntaMultipleOpcion(); 

        void mostrar() override; 
        string getTipo() override; 

        vector<string> getOpciones(); 
        int getRespuestaCorrecta(); 

        void setOpciones(vector<string> nuevasOpciones); 
        void setRespuestaCorrecta(int nuevaRespuesta); 
};

#endif 