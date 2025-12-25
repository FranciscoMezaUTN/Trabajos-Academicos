package ar.utn.ba.dds.front_tp.dto.input;

import ar.utn.ba.dds.front_tp.dto.TipoAlgoritmoConsenso;
import com.fasterxml.jackson.annotation.JsonIgnoreProperties;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import java.util.ArrayList;
import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class ColeccionFormInputDTO {
  private Long id;
  private String titulo;
  private String descripcion;
  private List<CriterioDePertenenciaInputDTO> criteriosDePertenencias = new ArrayList<>();
  private List<String> fuentes = new ArrayList<>();
  private TipoAlgoritmoConsenso algoritmoConsenso;
}
