#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controlador_cargarDesdeTexto(char* path , LinkedList* pListadoCompetidores);
int controlador_addCompetidor(LinkedList* pListadoCompetidores);
int controlador_editCompetidor(LinkedList* pArrayListEmployee);
int controlador_eliminarCompetidor(LinkedList* pListadoCompetidores);
int controlador_listarCompetidores(LinkedList* pListadoCompetidores);
int controlador_sortCompetidores(LinkedList* pListadoCompetidores);
int controlador_generarSublista(LinkedList* pListadoCompetidores);
int controlador_moverCompetidor(LinkedList* pListadoCompetidores);
int controlador_listadoGanadores(char* path , LinkedList* pListadoCompetidores);
int controlador_copiaSeguridad(char* path , LinkedList* pListadoCompetidores);
int controlador_guardarDesdeTexto(char* path, LinkedList* pListadoCompetidores);


#endif // CONTROLLER_H_INCLUDED
