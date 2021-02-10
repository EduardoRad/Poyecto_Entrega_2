#include "Comanda.h"

Comanda::Comanda(const Data& entregaPrevista, vector<lineaComanda>& comanda)
{
	m_totalBicicletes = comanda.size();
	m_entregaPrevista = entregaPrevista;
	m_llista_comanda = comanda;
}
