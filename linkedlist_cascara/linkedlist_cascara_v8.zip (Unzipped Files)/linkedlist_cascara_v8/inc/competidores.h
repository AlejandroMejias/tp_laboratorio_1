#ifndef COMPETIORES_H_INCLUDED
#define COMPETIORES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char paisOrigen[50];
    int medallasGanadas;
}Competidor;

Competidor* nuevo_competidor();
Competidor* competidor_nuevoParam(char* idStr, char* nombreStr, char* paisStr,char* medallasStr);
int imprimirCompetidor(Competidor* this);

// ID
int competidor_setId(Competidor* this, int id);
int competidor_getId(Competidor* this, int* id);
int idMaximo(LinkedList* this, int* id);

// NOMBRE

int competidor_setNombre(Competidor* this, char* nombre);
int competidor_getNombre(Competidor* this, char* nombre);

// PAIS ORIGEN
int competidor_setPaisOrigen(Competidor* this, char* paisOrigen);
int competidor_getPaisOrigen(Competidor* this, char* paisOrigen);

// MEDALLAS GANADAS
int competidor_setMedallasGanadas(Competidor* this, int medallas);
int competidor_getMedallasGanadas(Competidor* this, int* medallas);

// ORDENAMIENTOS
int competidor_sortId(void* e1, void* e2);
int competidor_sortNombre(void* e1, void* e2);
int competidor_sortPaisOrigen(void* e1, void* e2);
int competidor_sortMedallasGanadas(void* e1, void* e2);

#endif // COMPETIORES_H_INCLUDED
