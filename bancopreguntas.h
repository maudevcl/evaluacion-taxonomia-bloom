#ifndef BANCOPREGUNTAS_H
#define BANCOPREGUNTAS_H

#include <vector>
#include "pregunta.h"

class BancoPreguntas {
    private:
        vector<Pregunta*> preguntas; // almacenar pregutnas

    public:
        BancoPreguntas(); 
        ~BancoPreguntas(); 
// metodos
        void agregarPregunta(Pregunta* pregunta);
        void mostrarTodas(); 
        void eliminarPregunta(int id); 
        void buscarPorNivel(string nivel); 
        Pregunta* buscarPorId(int id); 
        vector<Pregunta*> getPreguntas(); 
};

#endif