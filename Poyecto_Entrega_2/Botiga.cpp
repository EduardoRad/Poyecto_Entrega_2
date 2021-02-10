#include "Botiga.h"

bool Botiga::solicitaComanda(Comanda& c, Magatzem& m)
{
	return false;
}

bool Botiga::solicitaComanda(Comanda& c)
{

	return false;
}

void Botiga::mostraCataleg()
{
}

int Botiga::calculaStockTotal()
{
	int stockTotal = 0;
	for (int i = 0;i < m_stockBotiga.size();i++)
	{
		
	}
	return stockTotal;
}

bool Botiga::solicitaBicicletaAMagatzem(const string& model, Bicicleta*& bicicleta)
{
	if (m_magatzem->getStock().count(model) > 0)
	{
		map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> stockMagatzem;
		stockMagatzem = m_magatzem->getStock();
		bicicleta = stockMagatzem[model].top();
		return true;
	}
	return false;
}

bool Botiga::procesa_venda(const string& model, Bicicleta*& bicicleta)
{
	if (comprobaBicicletaEnStock(model, bicicleta))
		return true;
	else
	{
		if (ComprobaStockEnVeines(model, bicicleta))
			return true;
		else
		{
			if (solicitaBicicletaAMagatzem(model, bicicleta))
				return true;
			else
				return false;
		}
	}
	return false;
}

bool Botiga::comprobaBicicletaEnStock(const string& model, Bicicleta*& bicicleta)
{
	if (m_stockBotiga.count(model) > 0)
	{
		bicicleta = m_stockBotiga[model].top();
		return true;
	}
	else
		return false;
}

bool Botiga::ComprobaStockEnVeines(const string& model, Bicicleta*& bicicleta)
{
	for (int i = 0;i < m_botigas.size();i++)
	{
		if(m_botigas[i]->comprobaBicicletaEnStock(model, bicicleta))
			return true;
	}
	return false;
}
