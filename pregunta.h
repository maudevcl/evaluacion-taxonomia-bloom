#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <iostream>
#include <string>

using namespace std;


enum class NivelTaxonomico {
    RECORDAR,
    ENTENDER,
    APLICAR,
    ANALIZAR,
    EVALUAR,
    CREAR
};


string nivelToString(NivelTaxonomico nivel);
NivelTaxonomico stringToNivel(const string& str);


class Pregunta {
protected:
    int id;
    string enunciado;
    NivelTaxonomico nivelTaxonomico; 
    int anio;
    int tiempoEstimado;

public:
    Pregunta(int id, string enunciado, NivelTaxonomico nivel, int anio, int tiempo);
    virtual ~Pregunta();

    int getId();
    string getEnunciado();
    NivelTaxonomico getNivelTaxonomico();
    int getAnio();
    int getTiempoEstimado();

    void setEnunciado(string enunciado);
    void setNivelTaxonomico(NivelTaxonomico nivel);
    void setAnio(int anio);
    void setTiempoEstimado(int tiempo);

    virtual void mostrar() = 0;
    virtual string getTipo() = 0;
};

#endif
