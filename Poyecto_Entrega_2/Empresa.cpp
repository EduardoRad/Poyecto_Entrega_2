#include "Empresa.h"

int Empresa::getSeguentCodiRus()
{

	return 0;
}

bool Empresa::realitzaComanda(Comanda& c, Proveidor& p)
{
	return p.procesaComanda(c, *m_magatzem);
}

string Empresa::generaCodiRus(const string& model)
{
	string codi_rus;
	/*char* intStr;
	snprintf(intStr, 10, "%d", getSeguentCodiRus());
	string str = string(intStr);
	codi_rus = model + str;*/
	return codi_rus;
}

bool Empresa::realitzaComanda(Comanda& c)
{
	return false;
}

bool Empresa::afegeixSeguiment(Bicicleta* bicicleta)
{
	DadesSeguiment seguiment;
	seguiment.m_bicicleta = bicicleta;
	if (m_taulaSeguiment.count(bicicleta->getCodiRus()) == 0)
	{
		m_taulaSeguiment.insert(make_pair(bicicleta->getCodiRus(), seguiment));
		return true;
	}
	return false;
}

bool Empresa::actualitzaEstat(const string& codiRus, EstatBicicleta nouEstat, Entitat* novaEntitat)
{
	if (m_taulaSeguiment.count(codiRus) > 0)
	{
		m_taulaSeguiment[codiRus].m_historic.push_back(make_pair(nouEstat, novaEntitat));
		return true;
	}
	return false;
}

bool Empresa::comprobaEstatCodi(string codiRus, EstatBicicleta objectiu)
{
	if(m_taulaSeguiment.count(codiRus) > 0)
	{
		bool flag = false;
		vector<pair<EstatBicicleta,Entitat*>> historial = m_taulaSeguiment[codiRus].m_historic;
		vector<pair<EstatBicicleta,Entitat*>>::iterator it = historial.begin();
		while(!flag && it != historial.end())
		{
			flag = (*it).first == objectiu;
			++it;
		}
		return flag;
	}
	return false;

}

Empresa::Empresa(string name, int numBotigues, Magatzem* magatzemPrincipal, Proveidor& p)
{
	m_name = name;
	m_nBotigues = numBotigues;
	m_magatzem = magatzemPrincipal;
	m_proveidor = p;
}

Empresa::Empresa(string name, vector<Botiga*> botigues, vector<Aresta> conexionsBotigues, Magatzem* magatzemPrincipal, Proveidor& p)
{
	m_name = name;
	m_nBotigues = botigues.size();
	m_magatzem = magatzemPrincipal;
	m_proveidor = p;
	Graf graf(botigues, conexionsBotigues);
	m_graf = graf;
	vector<Node*> vertex = m_graf.getVertexs();
	for (int i = 0;i < m_botigues.size();i++)
	{
		m_botigues[i]->setMatgatzem(m_magatzem);
		m_rutaOptima.push_back(m_graf.getBotiguesOrdenades(vertex[i]));
	}
}
