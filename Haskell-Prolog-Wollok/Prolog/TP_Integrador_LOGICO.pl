%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Base de conocimientos inicial
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% objetivo(Proyecto, Objetivo, TareaARealizar)
objetivo(higiene, almejas, recolectarMaterial(playa)).
objetivo(higiene, algas, recolectarMaterial(mar)).
objetivo(higiene, grasa, recolectarMaterial(animales)).
objetivo(higiene, hidroxidoDeCalcio, quimica([hacerPolvo, diluirEnAgua])).
objetivo(higiene, hidroxidoDeSodio, quimica([mezclarIngredientes])).
objetivo(higiene, jabon, quimica([mezclarIngredientes, dejarSecar])).

%% Agregar objetivos para otros proyectos aquí...
objetivo(castillo, arena, recolectarMaterial(playa)).
objetivo(castillo, agua, recolectarMaterial(mar)).
objetivo(castillo, castilloDeArena, artesania(1)).

objetivo(carpinteria, madera, recolectarMaterial(bosque)).
objetivo(carpinteria, armario, artesania(4)).

objetivo(arte, cuero, recolectarMaterial(animales)).
objetivo(arte, madera, recolectarMaterial(bosque)).
objetivo(arte, escultura, artesania(7)).

%% También se espera que agreguen más información para los predicados
%% prerrequisito/2 y conseguido/1 para probar lo que necesiten

% prerrequisito(Prerrequisito, Producto)
prerrequisito(almejas, hidroxidoDeCalcio).
prerrequisito(hidroxidoDeCalcio, hidroxidoDeSodio).
prerrequisito(algas, hidroxidoDeSodio).
prerrequisito(hidroxidoDeSodio, jabon).
prerrequisito(grasa, jabon).

prerrequisito(arena, castilloDeArena).
prerrequisito(agua, castilloDeArena).

prerrequisito(madera, armario).

prerrequisito(cuero, escultura).
prerrequisito(madera, escultura).

% conseguido(Producto)
conseguido(almejas).
conseguido(algas).

conseguido(arena).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Implementar nuevos predicados aquí...

% 1.
habitanteDelReino(senku).
habitanteDelReino(chrome).
habitanteDelReino(kohaku).
habitanteDelReino(suika).

puedeCumplirTarea(senku, quimica(_)).
puedeCumplirTarea(senku, artesania(Dificultad)):-
  Dificultad =< 6.
puedeCumplirTarea(chrome, recolectarMaterial(Origen)):-
  Origen \= animales.
puedeCumplirTarea(chrome, quimica(Procesos)):-
  length(Procesos, CantProcesos),
  CantProcesos =< 3.
puedeCumplirTarea(kohaku, recolectarMaterial(animales)).
puedeCumplirTarea(suika, recolectarMaterial(playa)).
puedeCumplirTarea(suika, recolectarMaterial(bosque)).
puedeCumplirTarea(suika, quimica([mezclarIngredientes])).
puedeCumplirTarea(Habitante, artesania(Dificultad)):-
  habitanteDelReino(Habitante),
  Dificultad < 3.

% 2.
objetivoFinal(Proyecto, Objetivo):-
  objetivo(Proyecto, Objetivo,_),
  not((objetivo(Proyecto, OtroObjetivo,_),
  Objetivo \= OtroObjetivo,
  prerrequisito(Objetivo, OtroObjetivo))).

% 3.
esViable(Proyecto):-
  objetivo(Proyecto,_,_),
  forall(objetivo(Proyecto,_, Tarea), (habitanteDelReino(Habitante), puedeCumplirTarea(Habitante, Tarea))).

% 4.

esIndispensable(Habitante, Objetivo, Proyecto):-
  objetivo(Proyecto, Objetivo, Tarea),
  habitanteDelReino(Habitante),
  puedeCumplirTarea(Habitante, Tarea),
  forall((habitanteDelReino(OtroHabitante), OtroHabitante \= Habitante), not(puedeCumplirTarea(OtroHabitante, Tarea))).  


% 5.

puedeIniciarse(Objetivo, Proyecto):-
  objetivo(Proyecto, Objetivo,_),
  estaPendiente(Objetivo),
  forall(prerrequisito(PrerrequisitoObjetivo,Objetivo), not(estaPendiente(PrerrequisitoObjetivo))).

estaPendiente(Objetivo):-
  not(conseguido(Objetivo)).



% 6.

tiempoRestante(Proyecto, Tiempo):-
  esViable(Proyecto),
  findall(Duracion, (objetivo(Proyecto, Objetivo, Tarea), estaPendiente(Objetivo), duracionTarea(Tarea, Duracion)), Duraciones),
  sum_list(Duraciones, Tiempo).

duracionTarea(recolectarMaterial(mar), 8).
duracionTarea(recolectarMaterial(cuevas), 48).
duracionTarea(recolectarMaterial(Superficie), 3):-
  Superficie \= mar,
  Superficie \= cuevas.
duracionTarea(quimica(Procesos), Duracion):-
  length(Procesos, CantProcesos),
  Duracion is CantProcesos * 2.
duracionTarea(artesania(Dificultad), Dificultad).


% 7.

esCritico(Objetivo, Proyecto):-
  objetivo(Proyecto, Objetivo,_),
  objetivo(Proyecto, ObjetivoCostoso,_),
  esCostoso(ObjetivoCostoso, Proyecto),
  bloqueaAvance(Objetivo, ObjetivoCostoso),
  ObjetivoCostoso \= Objetivo.

esCostoso(Objetivo, Proyecto):-
  objetivo(Proyecto, Objetivo, Tarea),
  duracionTarea(Tarea, Duracion),
  Duracion > 5.

bloqueaAvance(ObjetivoBloqueador, ObjetivoBloqueado):-
  prerrequisito(ObjetivoBloqueador, ObjetivoBloqueado).
bloqueaAvance(ObjetivoBloqueador, ObjetivoBloqueado):-
  prerrequisito(ObjetivoBloqueador, ObjetivoIntermedio),
  prerrequisito(ObjetivoIntermedio, ObjetivoBloqueado).

/*
bloqueaAvance(ObjetivoBloqueador,Objetivo):-
  prerrequisito(ObjetivoBloqueador,Objetivo).
bloqueaAvance(ObjetivoBloqueador,Objetivo):-
  prerrequisito(ObjetivoBloqueador,OtroObjetivo),
  bloqueaAvance(OtroObjetivo,Objetivo).

*/

% 8.

leConvieneTrabajar(Habitante, Objetivo, Proyecto):-
  habitanteDelReino(Habitante),
  esViable(Proyecto),
  puedeIniciarse(Objetivo, Proyecto),
  objetivo(Proyecto, Objetivo, Tarea),
  puedeCumplirTarea(Habitante, Tarea),
  esValioso(Habitante, Objetivo, Proyecto).

esValioso(Habitante, Objetivo, Proyecto):-
  esIndispensable(Habitante, Objetivo, Proyecto).
esValioso(_, Objetivo, Proyecto):-
  objetivo(Proyecto, Objetivo, Tarea),
  duracionTarea(Tarea, Duracion),
  tiempoRestante(Proyecto, TiempoRestante),
  Duracion > TiempoRestante / 2.
esValioso(Habitante, Objetivo, Proyecto):-
  esCritico(Objetivo, Proyecto),
  forall((habitanteDelReino(OtroHabitante), objetivo(Proyecto, OtroObjetivo,_), OtroHabitante \= Habitante, OtroObjetivo \= Objetivo), puedeIniciarse(OtroObjetivo, Proyecto)).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Pruebas
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:- begin_tests(tp).

%% Tests de referencia
%% Testeo de consultas que esperan que sean ciertas
test(elHidroxidoDeCalcioEsPrerrequisitoDelJabon, nondet):-
  prerrequisito(hidroxidoDeSodio, jabon).

%% Testeo de consultas que esperan que sean falsas
test(elJabonNoEsPrerrequisitoDelHidroxidoDeCalcio, fail):-
  prerrequisito(jabon, hidroxidoDeSodio).

%% Testeo de consultas existenciales con múltiples respuestas => inversibilidad
test(prerrequisitosDelHidroxidoDeSodio, set(Producto == [hidroxidoDeCalcio, algas])):-
  prerrequisito(Producto, hidroxidoDeSodio).


%% Tests de nuevos requerimientos, implementar aquí...
% Punto 1
test(senkuPuedeHacerMuchosProcesosDeQuimica, nondet):-
  puedeCumplirTarea(senku, quimica([mezclarIngredientes, hacerPolvo, diluirEnAgua, dejarSecar])).
test(senkuPuedeHacerArtesaniaDeDificultad5, nondet):-
  puedeCumplirTarea(senku, artesania(5)).
test(chromeNoPuedeRecolectarMaterialProvenienteDeAnimales, fail):-
  puedeCumplirTarea(chrome, animales).
test(chromePuedeHacerDosProcesosQuimicos, nondet):-
  puedeCumplirTarea(chrome, quimica([mezclarIngredientes, hacerPolvo])).
test(kohakuPuedeRecolectarMaterialProvenienteDeAnimales, nondet):-
  puedeCumplirTarea(kohaku, recolectarMaterial(animales)).
test(habitantesQuePuedenHacerArtesaniasDeDificultadDos, set(Habitante == [senku, chrome, kohaku, suika])):-
  puedeCumplirTarea(Habitante, artesania(2)).

% Punto 2
test(objetivoFinalDeHigiene, set(Objetivo == [jabon])):-
  objetivoFinal(higiene, Objetivo).

% Punto 3
test(elProyectoHigieneEsViable, nondet):-
  esViable(higiene).
test(proyectosViables, set(Proyecto == [higiene, castillo, carpinteria])):-
  esViable(Proyecto).
test(elProyectoArteNoEsViable, fail):-
  esViable(arte).

% Punto 4
test(nadieEsIndispensableParaElObjetivoJabonDelProyectoHigiene, set(Habitante == [])):-
  esIndispensable(Habitante, jabon, higiene).
test(senkuEsIndispensableParaElObjetivoArmarioDelProyectoCarpinteria, nondet):-
  esIndispensable(senku, armario, carpinteria).

% Punto 5
test(puedeIniciarseElHidroxidoDeCalcio, nondet):-
  puedeIniciarse(hidroxidoDeCalcio, higiene).
test(objetivosQuePuedenIniciarseDelProyectoHigiene, set(Objetivo == [hidroxidoDeCalcio, grasa])):-
  puedeIniciarse(Objetivo, higiene).

% Punto 6
test(tiempoRestanteDelProyectoHigiene, set(Tiempo == [13])):-
  tiempoRestante(higiene, Tiempo).

% Punto 7
test(laEsculturaEsUnObjetivoCostoso, nondet):-
  esCostoso(escultura, arte).
test(objetivosCostososDelProyectoHigiene, set(Objetivo == [algas])):-
  esCostoso(Objetivo, higiene).

test(elJabonNoBloqueaLaGrasa, fail):-
  bloqueaAvance(jabon, grasa).
test(lasAlgasBloqueanElJabon, nondet):-
  bloqueaAvance(algas, jabon).

test(laMaderaEsUnObjetivoCriticoDelProyectoArte, nondet):-
  esCritico(madera, arte).
test(objetivosCriticosDelProyectoHigiene, set(Objetivo == [])):-
  esCritico(Objetivo, higiene).

% Punto 8
test(senkuEsValiosoParaElObjetivoArmarioDelProyectoCarpinteria, nondet):- % Por indispensable
  esValioso(senku, armario, carpinteria).
test(esValiosoRealizarElObjetivoAguaDelProyectoCastillo, nondet):- % Por tiempo e indispensable
  esValioso(_, agua, castillo).
test(algasEsUnObjetivoValiosoParaHigiene, set(Objetivo == [algas])):- % Por tiempo (solo por tiempo porque suika no es indispensable)
  esValioso(suika, Objetivo, higiene).
test(objetivoValiososParaHigiene, set(Objetivo == [algas, grasa])):- % Por tiempo (e indispensable) (algas) y por indispensable (grasa)
  esValioso(_, Objetivo, higiene).
test(maderaEsUnObjetivoValioso, nondet):- % Por critico
  esValioso(_, madera, arte).

test(aChromeLeConvieneTrabajarEnElAguaDelProyectoCastillo, nondet):-
  leConvieneTrabajar(chrome, agua, castillo).

:- end_tests(tp).
