#pragma once
#include <limits.h>
#include "Botiga.h"
#include <algorithm>

struct Node
{
	bool visitat;
	Botiga* botiga;
	int distanciaMinima;
	Node(Botiga* b) :visitat(false), botiga(b), distanciaMinima(INT_MAX) {}
};

struct Aresta
{
	int inici, desti, pes;
};
class Graf
{
private:
	const int ARESTA_NULA = -1;
	vector<Node*> m_vertexs;
	vector<Aresta> m_arestes;
	vector<vector<int>> m_adyacencia;
	int getPes(Node* inici, Node* desti);
	int getIndex(Node* vertex);
	Node* distanciaMinima();
	int minDistance(vector<Node*>& dist, vector<bool>& visitat);
	vector<Node*> dijkstra(Node* nodeInici);

public:
	Graf() {}
	Graf(vector<Botiga*> llistaVertexs, vector<Aresta> llistaArestes);
	vector<Node*> getVertexs() const { return m_vertexs; }
	vector<vector<int>> getArestes() const { return m_adyacencia; }
	vector<Botiga*> getBotiguesOrdenades(Node* nodeInici);
	Graf& operator=(Graf g);
};

