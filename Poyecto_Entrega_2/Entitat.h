#pragma once
#include <string>

using namespace std;

class Entitat
{
public:
	virtual string getNom() const { return m_nom; }
	virtual string getCodi() const { return m_codi; }
	virtual void setNom(string nom) { m_nom = nom; }
	virtual void setCodi(string codi) { m_codi = codi; }
protected:
	Entitat() {}
	Entitat(string nom, string codiIdentificatiu){ m_nom = nom; m_codi = codiIdentificatiu; }
	string m_nom;
	string m_codi;
};

