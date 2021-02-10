#include "Graf.h"

int Graf::getPes(Node* inici, Node* desti)
{
	int inicio = getIndex(inici), destino = getIndex(desti);
	return m_adyacencia[inicio][destino];
}

int Graf::getIndex(Node* vertex)
{
	for (int i = 0;i < m_vertexs.size();i++)
	{
		if (vertex == m_vertexs[i])
		{
			return i;
		}
	}
	return 0;
}

Node* Graf::distanciaMinima()
{
	int min = m_vertexs[0]->distanciaMinima, minIndex = -1;
	for (int posVei = 0;posVei < m_vertexs.size();posVei++)
	{
		if (!m_vertexs[posVei]->visitat && m_vertexs[posVei]->distanciaMinima <= min)
		{
			min = m_vertexs[posVei]->distanciaMinima;
			minIndex = posVei;
		}
	}
	return m_vertexs[minIndex];
}

int Graf::minDistance(vector<Node*>& dist, vector<bool>& visitat)
{
	int min = INT_MAX, minIndex = -1;
	for (int posVei = 0;posVei < m_vertexs.size();posVei++)
	{
		if (!visitat[posVei] && dist[posVei]->distanciaMinima <= min)
		{
			min = dist[posVei]->distanciaMinima;
			minIndex = posVei;
		}
	}
	return minIndex;
}

vector<Node*> Graf::dijkstra(Node* nodeInici)
{
	vector<Node*> dist(m_vertexs);
	for (int i = 0;i < dist.size();i++)
	{
		if (m_vertexs[i] == nodeInici)
			dist[i]->distanciaMinima = 0;
	}
	vector<bool> visitat;
	visitat.resize(m_vertexs.size(), false);
	for (int count = 0;count < dist.size() - 1;count++)
	{
		int posVeiAct = minDistance(dist, visitat);
		visitat[posVeiAct] = true;
		for(int posVei = 0;posVei < m_vertexs.size();posVei++)
		{
			if (!visitat[posVei])
				if (m_adyacencia[posVeiAct][posVei] != 0)
					if (dist[posVeiAct]->distanciaMinima + m_adyacencia[posVeiAct][posVei] < dist[posVei]->distanciaMinima)
						dist[posVei]->distanciaMinima = dist[posVeiAct]->distanciaMinima + m_adyacencia[posVeiAct][posVei];
		}
	}
	return dist;
}

Graf::Graf(vector<Botiga*> llistaVertexs, vector<Aresta> llistaArestes)
{
	for (int i = 0;i < llistaVertexs.size();i++)
	{
		Node* nodo;
		nodo->botiga = llistaVertexs[i];
		nodo->visitat = false;
		nodo->distanciaMinima = INT_MAX;
		m_vertexs.push_back(nodo);
	}
	for (int i = 0;i < llistaArestes.size();i++)
	{
		m_arestes.push_back(llistaArestes[i]);
	}
	
	m_adyacencia.resize(llistaVertexs.size());
	for (int i = 0;i < llistaVertexs.size();i++)
	{
		m_adyacencia[i].resize(llistaVertexs.size());
	}
	for (int i = 0;i < llistaArestes.size();i++)
	{
		for (int fila = 0;fila < llistaVertexs.size();fila++)
		{
			for (int col = 0;col < llistaVertexs.size();col++)
			{
				if (llistaArestes[i].inici == fila && llistaArestes[i].desti == col)
				{
					m_adyacencia[fila][col] = llistaArestes[i].pes;
					m_adyacencia[col][fila] = llistaArestes[i].pes;
				}
			}
		}
	}
}

vector<Botiga*> Graf::getBotiguesOrdenades(Node* nodeInici)
{
	vector<Node*> dist = dijkstra(nodeInici);
	vector<Botiga*> botigaOrdenadas;
	int min = INT_MAX;
	int posMin;
	int elementoFinal = m_vertexs.size();
	for (int i = 0;i < elementoFinal;i++)
	{
		if (dist[i] == nodeInici)
		{
			elementoFinal--;
			dist.erase(dist.begin() + i - 1);
			for (int j = 0;j < elementoFinal;j++)
			{
				if (dist[j]->distanciaMinima < min)
				{
					min = dist[j]->distanciaMinima;
					posMin = j;
				}
			}
			botigaOrdenadas.push_back(dist[posMin]->botiga);
			dist.erase(dist.begin() + posMin - 1);
			while (botigaOrdenadas.size() != m_vertexs.size() - 1)
			{
				for (int j = 0;j < elementoFinal;j++)
				{
					if (dist[j]->distanciaMinima < min)
					{
						min = dist[j]->distanciaMinima;
						posMin = j;
					}
				}
				botigaOrdenadas.push_back(dist[posMin]->botiga);
				dist.erase(dist.begin() + posMin - 1);
			}
		}
	}
	return botigaOrdenadas;
}

Graf& Graf::operator=(Graf g)
{
	// TODO: Insertar una instrucción "return" aquí
	Graf grafo;
	grafo.m_vertexs = g.m_vertexs;
	grafo.m_adyacencia = g.m_adyacencia;
	grafo.m_arestes = g.m_arestes;
	return grafo;
}
