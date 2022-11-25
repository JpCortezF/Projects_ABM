/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* recibe la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return la funcion retorna -1 como ERROR si la lista es NULL o si no pudo abrir el archivo
 * y 0 si salio correctamente
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char* recibe la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return la funcion retorna -1 como ERROR si la lista es NULL o si no pudo abrir el archivo
 * y 0 si salio correctamente
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Alta de jugadores
 *
 * \param path char* recibe la ruta del archivo
 * \param pArrayListJugador LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador);

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 *
 * @param pArrayListSeleccion un lista de selecciones puntero a LinkedList
 * @param pArrayListJugador un lista de jugadores puntero a LinkedList
 * @return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 */
int controller_convocarJugadores(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);

/**
 *
 * @param pArrayListJugador un lista de jugadores puntero a LinkedList
 * @param pArrayListSeleccion un lista de selecciones puntero a LinkedList
 * @return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 */
int controller_listarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion un lista de selecciones puntero a LinkedList
 * \return la funcion retorna -1 como ERROR si la lista es NULL o si no pudo abrir el archivo
 * y 0 si salio correctamente
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList* lista de selecciones
 * @return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * @return retorna -1 si la lista que le llega es NULL y 0 para indicar que salio correctamente
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/**
 * recorre la lista y busca la coincidencia con el id recibido por parametro
 * @param pArrayListSeleccion puntero a la lista LinkedList
 * @param idSeleccion tipo int
 * @return retorna -1 como ERROR y para BIEN retorna el indice de coincidencia
 */
int searchSeleccionById(LinkedList* pArrayListSeleccion, int idSeleccion);
