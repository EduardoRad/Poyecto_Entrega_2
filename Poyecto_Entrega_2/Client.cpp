#include "Client.h"

Client::Client(string nom, string dni)
{
	m_nom = nom;
	m_codi = dni;
}

bool Client::comprarBicicleta(string model, Botiga& b)
{
	for (int i = 0;i < m_botigas.size();i++)
	{
		if (m_botigas[i]->getCodi() == b.getCodi())
		{
			Bicicleta* bici;
			return m_botigas[i]->comprobaBicicletaEnStock(model, bici);
		}
	}
	return false;
}

void Client::setBicicletes(vector<Bicicleta*> bicis)
{
	for (int i = 0;i < bicis.size();i++)
	{
		m_bicicletes.push_back(bicis[i]);
	}
}
