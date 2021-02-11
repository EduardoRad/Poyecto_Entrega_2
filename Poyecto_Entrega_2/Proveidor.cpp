#include "Proveidor.h"

Data Proveidor::generaDataEnviament(Data dataprevista, int diesmaxim)
{
	Data data;
	int min = -diesmaxim;
	int aumento = min + rand() % + (diesmaxim - min);
	data = dataprevista + aumento;
	return data;
}

bool Proveidor::procesaComanda(Comanda c, Magatzem& m)
{
	Data dataEntrega;
	dataEntrega = generaDataEnviament(c.getDataEntregaPrevista(), 10);
	vector<Bicicleta*>paquet;
	return m.rebreComanda(c, paquet, dataEntrega);
}
