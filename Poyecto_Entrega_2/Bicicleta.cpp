#include "Bicicleta.h"

void Bicicleta::setPreu(TipusBicicleta cost)
{
	switch (cost)
	{
	case TipusBicicleta::INFANTIL:
		m_preu = 100;
		break;
	case TipusBicicleta::MTB:
		m_preu = 200;
		break;
	case TipusBicicleta::CARRETERA:
		m_preu = 250;
		break;
	default:
		break;
	}
}

bool Bicicleta::operator<(const Bicicleta& b1) const
{

	return false;
}

Bicicleta::Bicicleta(const string& model, const string& descripcio, const int& temporada, Talla talla, Quadre quadre, Roda roda, Fre fre, TipusBicicleta tipus)
{
	m_model = model;
	m_descripcioModel = descripcio;
	m_temporada = temporada;
	m_talla = talla;
	m_quadre = quadre;
	m_roda = roda;
	m_fre = fre;
	m_tipus = tipus;
}
