module TP where

-- Se importa una implementación básica para la función show para las funciones,
-- de modo que en la consola se muestren como "<function>" en vez de fallar
-- por un error de tipos.
import Text.Show.Functions

----------------------
-- Código inicial
----------------------

ordenarPor :: Ord a => (b -> a) -> [b] -> [b]
ordenarPor ponderacion =
  foldl (\ordenada elemento -> filter ((< ponderacion elemento).ponderacion) ordenada
                                  ++ [elemento] ++ filter ((>= ponderacion elemento).ponderacion) ordenada) []

data Demonio = Demonio {
    deudores :: [String],
    subordinados :: [Demonio]
} deriving (Show, Eq)

demonioDePrueba :: Demonio
demonioDePrueba = Demonio {deudores = ["Carlos"], subordinados = [demonioDePrueba2]}

demonioDePrueba2 :: Demonio
demonioDePrueba2 = Demonio {deudores = ["Pablo"], subordinados = []}

demonioDePrueba3 :: Demonio
demonioDePrueba3 = Demonio {deudores = ["Juan"], subordinados = []}

----------------------------------------------
-- Definí tus tipos de datos y funciones aquí
----------------------------------------------

{- 
1. Modelar a los humanos y deseos teniendo en cuenta que de los humanos nos interesa
   registrar su nombre, el nivel de reconocimiento y felicidad que tiene, y cuáles son sus
   deseos. Considerar que se deben poder desear (por lo menos) las siguientes cosas:
   - La paz mundial: al cumplirse, el humano se vuelve 20 veces más feliz.
   - Recibirse de una carrera: al cumplirse, la felicidad del humano aumenta en 250 y
     su reconocimiento aumenta en el triple de la longitud del nombre de la carrera de
     la que se recibió.
   - Ser famoso: al cumplirse, el reconocimiento del humano aumenta en 1000 y su
     felicidad pasa a ser 50 (independientemente de qué tan feliz fuera antes de cumplir
     el deseo).
   Declarar una constante de tipo Humano que sirva como ejemplo para probar los puntos
   siguientes que tenga felicidad = 100, reconocimiento = 50 y cuyos deseos sean la paz
   mundial, recibirse de "Ingeniería en Sistemas de Información", recibirse de "Medicina" y
   ser famoso (en ese orden).
-}

type Deseo = Humano -> Humano

data Humano = Humano {
  nombre :: String,
  felicidad :: Int,
  reconocimiento :: Int,
  deseos :: [Deseo]
} deriving (Show) -- Al definir deseos como una función, Humano empezó a dar error en "deriving (Show, Eq)"; tuve que sacar el Eq para que se vaya el error y modificar los tests para que no sea necesario mostrar un Humano (la profe me dijo que lo haga).

pazMundial :: Deseo
pazMundial humano = humano {felicidad = felicidad humano * 20}

recibirseEn :: String -> Deseo
recibirseEn nombreCarrera humano = humano {felicidad = felicidad humano + 250, reconocimiento = reconocimiento humano + 3 * length nombreCarrera}

serFamoso :: Deseo
serFamoso humano = humano {reconocimiento = reconocimiento humano + 1000, felicidad = 50}

humanoDePrueba :: Humano
humanoDePrueba = Humano {
  nombre = "Pablo",
  felicidad = 100,
  reconocimiento = 50,
  deseos = [pazMundial, recibirseEn "Ingeniería en Sistemas de Información", recibirseEn "Medicina", serFamoso]
}

cumplirDeseo :: Humano -> Deseo -> Humano
cumplirDeseo humano deseo = deseo humano

{-
2. Conocer la espiritualidad de un deseo para un humano, que se calcula como la diferencia
   entre lo que gana de felicidad luego de cumplir ese deseo y lo que gana de reconocimiento
   luego de cumplir ese deseo.
   Nota: No se espera validar que el humano tenga ese deseo para poder cumplirlo, ni
   se espera que deje de tener ese deseo luego de cumplirlo.
-}

espiritualidadDelDeseo :: Humano -> Deseo -> Int
espiritualidadDelDeseo humano deseo = felicidadGanada humano deseo - reconocimientoGanado humano deseo

felicidadGanada :: Humano -> Deseo -> Int
felicidadGanada humano deseo = felicidad (cumplirDeseo humano deseo) - felicidad humano

reconocimientoGanado :: Humano -> Deseo -> Int
reconocimientoGanado humano deseo = reconocimiento (cumplirDeseo humano deseo) - reconocimiento humano

{-
3. Saber si un humano sería más feliz si todos sus deseos se cumplieran.
   Para el humano de ejemplo, luego de cumplir todos sus deseos en el orden indicado en el
   punto 1 no sería más feliz, porque al volverse famoso quedaría con felicidad 50.
-}

cumplirTodosLosDeseos :: Humano -> Humano
cumplirTodosLosDeseos humano = foldl cumplirDeseo humano (deseos humano)

esMasFeliz :: Humano -> Bool
esMasFeliz humano = felicidad humano < (felicidad . cumplirTodosLosDeseos) humano

{-
4. Teniendo una función ordenarPor :: Ord a => (b -> a) -> [b] -> [b], que ordena 
   los elementos de la lista recibida de menor a mayor en base al criterio de ordenamiento 
   indicado, usarla para definir funciones que resuelvan lo siguiente:

a. Conocer los deseos más terrenales de un humano. Sólo los deseos con 
   espiritualidad menor a 150 se consideran terrenales, y se espera que se 
   encuentren ordenados por la espiritualidad que le aportan a ese humano.  
-}

esDeseoTerrenal :: Humano -> Deseo -> Bool
esDeseoTerrenal humano deseo = espiritualidadDelDeseo humano deseo < 150

deseosMasTerrenales :: Humano -> [Deseo]
deseosMasTerrenales humano = ordenarPor (espiritualidadDelDeseo humano) . filter (esDeseoTerrenal humano) $ deseos humano

{-
b. Conocer la mejor versión de un humano si se cumpliera uno de sus deseos, que es 
   como sería ese humano luego de cumplir el deseo para el cual la suma entre la 
   felicidad y reconocimiento se a mayor. 
-}

versionHumano :: Humano -> Int
versionHumano humano = felicidad humano + reconocimiento humano

mejorVersion :: Humano -> Humano
mejorVersion humano = last . ordenarPor versionHumano . map (cumplirDeseo humano) $ deseos humano

{-
5. Queremos incorporar a nuestro modelo a los demonios, que encontraron una forma de explotar la
   debilidad moral de los humanos para su propio beneficio. De cada demonio conocemos quiénes
   son sus deudores (que son los nombres de los humanos a los que ayudaron) y qué otros
   demonios tiene como subordinados.

a. Dado un demonio y un humano, saber si el demonio tiene poder sobre ese
   humano. Esto se cumple si el humano es deudor del demonio en cuestión o de
   alguno de sus subordinados. Para ser deudor alcanza con que el nombre del
   humano esté entre los deudores del demonio.
-}

-- Forma recursiva que abarca subordinados indirectos
esDeudor :: Humano -> Demonio -> Bool
esDeudor humano demonio = elem (nombre humano) (deudores demonio) || any (esDeudor humano) (subordinados demonio)

-- Forma no recursiva que solo abarca los subordinados directos
tienePoderSobre :: Humano -> Demonio -> Bool
tienePoderSobre humano demonio = esDeudor' humano demonio || any (esDeudor' humano) (subordinados demonio)

esDeudor' :: Humano -> Demonio -> Bool
esDeudor' humano demonio = nombre humano `elem` deudores demonio

{-
b. BONUS: Sabiendo que existe la función
   concatMap :: (a -> [b]) -> [a] -> [b] que hace una transformación sobre
   cada elemento y a su vez aplana el resultado, hacer una nueva versión de la
   función pedida en el punto anterior para que se considere a todos los
   subordinados, incluyendo también subordinados indirectos (que serían los
   subordinados de otro subordinado, ya sea directo o indirecto).
   Nota: no borrar la función del punto 5a, así podemos evaluarla de forma
   independiente.
-}

tienePoderSobreBONUS :: Humano -> Demonio -> Bool
tienePoderSobreBONUS humano demonio = esDeudor' humano demonio || any (esDeudor' humano) (todosLosSubordinados demonio)

todosLosSubordinados :: Demonio -> [Demonio]
todosLosSubordinados demonio = subordinados demonio ++ concatMap todosLosSubordinados (subordinados demonio)

{-
6. Definir la función:
   ayudarSiLeConviene :: Humano -> Demonio -> (Humano, Demonio)
   de modo que el demonio le cumpla el deseo más terrenal que tenga al humano, y además
   se agregue el nombre del humano a su lista de deudores, siempre y cuando el demonio no
   tenga poder sobre el humano y además ese humano tenga algún deseo terrenal. En caso
   de que esa condición no se cumpla, el demonio y el humano resultantes serían iguales
   que los recibidos.
   Para el humano de ejemplo, un demonio que no tiene poder sobre ese humano le
   cumpliría el deseo de ser famoso, y su nombre se incorporaría a los deudores del demonio.
-}

deseoMasTerrenal :: Humano -> Deseo
deseoMasTerrenal = head . deseosMasTerrenales

ayudarSiLeConviene :: Humano -> Demonio -> (Humano, Demonio)
ayudarSiLeConviene humano demonio
    | not (esDeudor humano demonio) && (not . null . deseosMasTerrenales $ humano) = (cumplirDeseo humano (deseoMasTerrenal humano), demonio {deudores = deudores demonio ++ [nombre humano]})
    | otherwise = (humano, demonio)