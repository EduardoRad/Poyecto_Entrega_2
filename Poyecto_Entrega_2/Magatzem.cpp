#include "Magatzem.h"
Magatzem::Magatzem(string nom, string codi)
{
	m_nom = nom;
	m_codi = codi;
}

void Magatzem::enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada)
{
	for (int i = 0;i < paquet.size();i++)
	{
		paquet[i]->setDataEntrada(dataEntrada);
	}
	vector<string> models;
	models.push_back(paquet[0]->getModel());
	for (int i = 1;i < paquet.size(); i++)
	{
		for (int j = 0; j < models.size(); j++)
		{
			if (models[j] != paquet[i]->getModel())
				models.push_back(paquet[i]->getModel());
		}
	}
	for (int i = 0;i < models.size(); i++)
	{
		priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta> aux;
		for (int j = 0; j < paquet.size(); j++)
		{
			if (models[i] == paquet[j]->getModel())
				aux.push(paquet[j]);
		}
		m_stock.insert(pair<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>(models[i], aux));
	}
}

float Magatzem::procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual)
{
	if (c.getTotalBicicletes() == paquet.size())
	{
		if (dataActual.operator<=(c.getDataEntregaPrevista()))
			return c.getCostTotal();
		else
			return c.getCostTotal() - (c.getCostTotal() * 0.1);
	}
	else
		return c.getCostTotal() - (c.getCostTotal() * 0.1);
}

bool Magatzem::rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet)
{
	this->enmagatzemarComanda(paquet, dataRecepcioPaquet);
	vector<string> posiblesModels;
	m_data = dataRecepcioPaquet;
	for (int i = 0;i < c.getLlistaComanda().size();i++)
	{
		posiblesModels.push_back(c.getLlistaComanda()[i].m_model);
	}
	for (int i = 0;i < c.getLlistaComanda().size();i++)
	{
		m_relacioModelTipus.insert(pair<TipusBicicleta, vector<string>>(c.getLlistaComanda()[i].tipus, posiblesModels));
	}
	return false;
}

void Magatzem::generaFactura(bool paquetComplet, float costCorregit, Comanda& c)
{
	ofstream factura;
	factura.open("factura.txt");
	if (factura.is_open())
	{
		factura << "Resum comanda." << endl;
		factura << "Nom: " << m_nom << endl;
		factura << "Codi: " << m_codi << endl << endl;
		factura << "Articles: " << endl;
		for (map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it = m_stock.begin();it == m_stock.end(); it++)
		{
			factura << it->first << " * " << it->second.size() << endl;
		}
		factura << endl;
		factura << "Preu final: " << costCorregit << endl;
		if ((!paquetComplet))
			factura << "PAQUET INCOMPLET" << endl;
		factura.close();
	}
}

Bicicleta* Magatzem::agafaBicicletaAntiga(const string& model)
{
	return nullptr;
}

void Magatzem::mostraCataleg()
{
}
