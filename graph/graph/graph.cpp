#include "stdafx.h"
#include "graph.h"

int main()
{
	Graph* graph = new Graph();
	graph->newNode(0);
	graph->newNode(1);
	graph->newNode(2);
	graph->newNode(3);
	graph->newNode(4);
	graph->newNode(5);
	graph->newNode(6);
	graph->newNode(7);
	graph->newNode(8); //this node has no connections
	graph->displayGraph();
	graph->newEdges(graph->returnNode(0), graph->returnNode(1), 3);
	graph->newEdges(graph->returnNode(2), graph->returnNode(0), 2);
	graph->newEdges(graph->returnNode(2), graph->returnNode(1), 3);
	graph->newEdges(graph->returnNode(5), graph->returnNode(6), 1);
	graph->newEdges(graph->returnNode(2), graph->returnNode(6), 2);
	graph->newEdges(graph->returnNode(1), graph->returnNode(7), 3);
	graph->newEdges(graph->returnNode(0), graph->returnNode(5), 3);
	graph->newEdges(graph->returnNode(3), graph->returnNode(5), 4);
	graph->newEdges(graph->returnNode(4), graph->returnNode(7), 2);
	graph->newEdges(graph->returnNode(6), graph->returnNode(3), 1);

	//graph->newEdges(graph->returnNode(8), graph->returnNode(0), 1);
	//graph->newEdges(graph->returnNode(6), graph->returnNode(8), 1);
	//graph->displayGraph();
	graph->BFS(graph, graph->returnNode(2));
	std::cout << std::endl;
	//graph->BFSTest(graph, graph->returnNode(0));
	//graph->isPath(graph->returnNode(0), graph->returnNode(1));
	//graph->printGraph(graph->returnNode(4));
	//graph->resetVisited(graph);
	//graph->dfsWholeGraph(graph);
	//graph->bfstestWholeGraph(graph);
	std::cout << std::endl;
	//graph->dfstestWholeGraph(graph);
	//graph->isPath(graph, graph->returnNode(1), graph->returnNode(2));
	//graph->isConnected(graph);
	//graph->dijkstra(graph, graph->returnNode(0), graph->returnNode(3));
	//graph->findLowestWeight();
	/*	for (int i = 0; i < graph->vertices.size(); i++)
		{
			graph->BFS(graph, graph->vertices[i]);
		}*/
	graph->returnNode(12);
	system("pause");
	return 0;
}
