#include "BicicletaMTB.h"

BicicletaMTB::BicicletaMTB(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, Categoria categoria, Modalitat modalitat, bool electrica)
{
	m_model = model;
	m_descripcioModel = descripcio;
	m_temporada = temporada;
	m_talla = talla;
	m_quadre = quadre;
	m_roda = roda;
	m_fre = fre;
	m_tipus = tipus;
	m_categoria = categoria;
	m_modalitat = modalitat;
	m_electrica = electrica;
}
