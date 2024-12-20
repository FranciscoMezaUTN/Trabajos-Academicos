// Solucion
class Imperio {
	var property ciudades
	var pepines
	method pepines() = pepines
	
	method endeudado() = pepines < 0
	
	method puedePagarlo(monto) = monto <= pepines
	
	method pagar(monto){
		pepines -= monto
	}
	
	method recaudar(monto){
		pepines += monto
	}
	
	method evolucionar(){
		ciudades.forEach({ciudad => ciudad.evolucionar()})
	}
}

// Ciudades
class Ciudad {
	const imperio
	const property edificios = []
	var property habitantes
	var property tanques
	var sistemaImpositivo
	
	method esFeliz(){
		if( !imperio.endeudado() ){
			return edificios.sum({edificio => edificio.tranquilidad()}) > self.disconformidad()
		}
		return false
	}
	
	method disconformidad() = habitantes.div(10000) + 30.min(tanques)
	
	method costoDeConstruccion(edificio) = sistemaImpositivo.costoDeConstruccion(edificio, self)
	
	method construirEdificio(edificio){
		if( !imperio.puedePagarlo(self.costoDeConstruccion(edificio)) ){
			throw new DomainException(message = "El imperio donde se encuentra la ciudad no puede pagar la construccion del edificio")
		}
		imperio.pagar(self.costoDeConstruccion(edificio))
		edificios.add(edificio)
	}
	
	method evolucionar(){
		if( self.esFeliz() ){
			habitantes += habitantes*0.02
		}
		edificios.forEach({edificio => edificio.evolucionar(imperio, self)})
	}
	
	method cultura() = edificios.sum({edificio => edificio.cultura()})
}

class Capital inherits Ciudad{
	override method disconformidad() = super().div(2)
	
	override method costoDeConstruccion(edificio) = super(edificio)*1.1
	
	override method evolucionar(){
		super()
		if( !self.esFeliz() ){
			sistemaImpositivo = apaciguador
		}
		else{
			if( imperio.ciudades().sortedBy({ciudad1, ciudad2 => ciudad1.cultura() < ciudad2.cultura()}).take(3).contains(self) ){
				sistemaImpositivo = incentivoCultural
			}
			else{
				sistemaImpositivo = new Citadino(cantHabitantesIncremento = 25000)
			}
		}
	}
}

// Edificios
class Edificio {
	const property costoDeConstruccionBase
	
	method costoDeMantenimiento(ciudad) = ciudad.costoDeConstruccion(self)*0.01
	
	method evolucionar(imperio, ciudad){
		imperio.pagar(self.costoDeMantenimiento(ciudad))
	}
	
	method tranquilidad()
}

class EdificioEconomico inherits Edificio {
	const property cultura = 0
	const pepinesGenerados
	const esCapital
	
	override method tranquilidad() = 3
	
	override method evolucionar(imperio, ciudad){
		super(imperio, ciudad)
		if (esCapital==0)
			imperio.recaudar(pepinesGenerados)
		else
			imperio.recaudar(pepinesGenerados*3)
	}
}

class EdificioCultural inherits Edificio {
	const property cultura
	
	override method tranquilidad() = cultura * 3
}

class EdificioMilitar inherits Edificio {
	const property cultura = 0
	const tanquesGenerados
	
	override method tranquilidad() = 0
	
	override method evolucionar(imperio, ciudad){
		super(imperio, ciudad)
		ciudad.tanques(ciudad.tanques()+tanquesGenerados)
	}
}

// Sistemas impositivos
class SistemaImpositivo{
	method costoDeConstruccion(edificio, ciudad)
}

class Citadino inherits SistemaImpositivo {
	var cantHabitantesIncremento

	override method costoDeConstruccion(edificio, ciudad) = edificio.costoDeConstruccionBase() + ((edificio.costoDeConstruccionBase())*0.05) * ciudad.habitantes().div(cantHabitantesIncremento)
}

object incentivoCultural inherits SistemaImpositivo {
 	override method costoDeConstruccion(edificio, ciudad) = edificio.costoDeConstruccionBase() - edificio.cultura().div(3)
}

object apaciguador inherits SistemaImpositivo {
	override method costoDeConstruccion(edificio, ciudad) {
		if( ciudad.esFeliz() ){
			return edificio.costoDeConstruccionBase()
		}
		return edificio.costoDeConstruccionBase() - edificio.tranquilidad()
	}
}