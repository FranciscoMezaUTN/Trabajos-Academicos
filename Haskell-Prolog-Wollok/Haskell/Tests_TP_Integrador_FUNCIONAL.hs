import Test.Hspec
import TP

main :: IO ()
main = hspec $ do
  describe "Punto 1" $ do
    it "Humano de prueba desea la paz mundial, entonces felicidad = 2000" $ do
      felicidad (cumplirDeseo humanoDePrueba pazMundial) `shouldBe` 2000
    it "Humano de prueba desea recibirse de Ingeniería en Sistemas de Información, entonces felicidad = 350" $ do
      felicidad (cumplirDeseo humanoDePrueba (recibirseEn "Ingeniería en Sistemas de Información")) `shouldBe` 350
    it "Humano de prueba desea recibirse de Ingeniería en Sistemas de Información, entonces reconocimiento = 161" $ do
      reconocimiento (cumplirDeseo humanoDePrueba (recibirseEn "Ingeniería en Sistemas de Información")) `shouldBe` 161
    it "Humano de prueba desea recibirse de la carrera Medicina, entonces felicidad = 350" $ do
      felicidad (cumplirDeseo humanoDePrueba (recibirseEn "Medicina")) `shouldBe` 350
    it "Humano de prueba desea recibirse de la carrera Medicina, entonces reconocimiento = 74" $ do
      reconocimiento (cumplirDeseo humanoDePrueba (recibirseEn "Medicina")) `shouldBe` 74
    it "Humano de prueba desea ser famoso, entonces felicidad = 50" $ do
      felicidad (cumplirDeseo humanoDePrueba serFamoso) `shouldBe` 50
    it "Humano de prueba desea ser famoso, entonces reconocimiento = 1050" $ do
      reconocimiento (cumplirDeseo humanoDePrueba serFamoso) `shouldBe` 1050
  describe "Punto 2" $ do
    it "Espiritualidad de la paz mundial para humano de prueba" $ do
      espiritualidadDelDeseo humanoDePrueba pazMundial `shouldBe` 1900
    it "Espiritualidad de Ser famoso para humano de prueba" $ do
      espiritualidadDelDeseo humanoDePrueba serFamoso `shouldBe` -1050
    it "Espiritualidad de recibirse de Ingeniería en Sistemas de Información para humano de prueba" $ do
      espiritualidadDelDeseo humanoDePrueba (recibirseEn "Ingeniería en Sistemas de Información") `shouldBe` 139
    it "Espiritualidad de recibirse de Medicina para humano de prueba" $ do
      espiritualidadDelDeseo humanoDePrueba (recibirseEn "Medicina") `shouldBe` 226
  describe "Punto 3" $ do
    it "Humano de prueba no es más feliz al cumplir todos sus deseos" $ do
      esMasFeliz humanoDePrueba `shouldBe` False
  describe "Punto 4" $ do
    it "Los deseos terrenales del humano de prueba ordenados son Ser famoso y recibirse de Ingeniería en Sistemas de Información" $ do
      felicidad (head (deseosMasTerrenales humanoDePrueba) humanoDePrueba) `shouldBe` 50
    it "Los deseos terrenales del humano de prueba ordenados son Ser famoso y recibirse de Ingeniería en Sistemas de Información" $ do
      felicidad (head (tail (deseosMasTerrenales humanoDePrueba)) humanoDePrueba) `shouldBe` 350
    it "La felicidad del humano de prueba en su mejor versión (luego de cumplir con la paz mndial) es 2000" $ do
      felicidad (mejorVersion humanoDePrueba) `shouldBe` 2000
  describe "Punto 5" $ do
    it "El demonio de prueba tiene poder sobre el humano de prueba" $ do
      esDeudor humanoDePrueba demonioDePrueba `shouldBe` True   
  describe "Punto 6" $ do
    it "Los deudores del demonio 3 serán Juan y humano de prueba (Pablo)" $ do
      deudores (snd (ayudarSiLeConviene humanoDePrueba demonioDePrueba3)) `shouldBe` ["Juan", "Pablo"] 
    it "Felicidad del humano de prueba cuando el demonio 3 le cumpla su deseo más terrenal será 350" $ do
      felicidad (fst (ayudarSiLeConviene humanoDePrueba demonioDePrueba3)) `shouldBe` 50   
    it "Reconocimiento del humano de prueba cuando el demonio 3 le cumpla su deseo más terrenal será 161" $ do
      reconocimiento (fst (ayudarSiLeConviene humanoDePrueba demonioDePrueba3)) `shouldBe` 1050
    it "Felicidad del humano de prueba cuando el demonio 1 no le cumpla su deseo más terrenal (porque ya es deudor) será 100" $ do
      felicidad (fst (ayudarSiLeConviene humanoDePrueba demonioDePrueba)) `shouldBe` 100
    it "Reconocimiento del humano de prueba cuando el demonio 1 no le cumpla su deseo más terrenal (porque ya es deudor) será 50" $ do
      reconocimiento (fst (ayudarSiLeConviene humanoDePrueba demonioDePrueba)) `shouldBe` 50      


  