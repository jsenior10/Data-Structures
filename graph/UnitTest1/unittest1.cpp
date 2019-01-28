#include "stdafx.h"
#include "CppUnitTest.h"
#include "../graph/graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(insertEdge)
		{
			Graph* graph = new Graph();
			graph->newNode(0);
			graph->newNode(1);
			Assert::IsTrue(!graph->isPath(graph, graph->returnNode(0), graph->returnNode(1)));
			graph->newEdges(graph->returnNode(0), graph->returnNode(1), 3);
			Assert::IsTrue(graph->isPath(graph, graph->returnNode(0), graph->returnNode(1)));
		}

		TEST_METHOD(insertNode)
		{
			Graph* graph = new Graph();
			Assert::IsTrue(graph->returnNode(1) == nullptr); //test  the node doesnt already exist
			graph->newNode(1);
			Assert::IsTrue(graph->returnNode(1) != nullptr); // check it doesnt = 0 so it knows rthe node exists
		}

		TEST_METHOD(dijkstraTestConnectedNode)
		{
			int corAns;
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

			corAns = 3;
			Assert::IsTrue(graph->dijkstra(graph, graph->returnNode(0), graph->returnNode(1)) == corAns);
		}

		TEST_METHOD(dijkstraTestDisconnectedNode)
		{
			int corAns;
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

			corAns = 0;
			Assert::IsTrue(graph->dijkstra(graph, graph->returnNode(0), graph->returnNode(8)) == corAns);
		}

		TEST_METHOD(TestIsConnected)
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

			Assert::IsFalse(graph->isConnected(graph));

			graph->newEdges(graph->returnNode(6), graph->returnNode(8), 1); // add remaining connection

			Assert::IsTrue(graph->isConnected(graph));
		}

		TEST_METHOD(BFS)
		{
			std::vector<int> corAns = {0, 1, 2, 5, 7, 6, 3, 4};
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

			Assert::IsTrue(graph->BFS(graph, graph->returnNode(0)) == corAns);
		}

		TEST_METHOD(DFS)
		{
			std::vector<int> corAns = {2, 6, 3, 5, 0, 1, 7, 4};
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

			Assert::IsTrue(graph->DFS(graph, graph->returnNode(2)) == corAns);
		}

		TEST_METHOD(isPath)
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
			Assert::IsTrue(!graph->isPath(graph, graph->returnNode(0), graph->returnNode(8))); //test disconnected node
			Assert::IsTrue(graph->isPath(graph, graph->returnNode(0), graph->returnNode(0))); //test same node
			Assert::IsTrue(graph->isPath(graph, graph->returnNode(0), graph->returnNode(1))); //test  connected nodes
			Assert::IsTrue(graph->isPath(graph, graph->returnNode(0), graph->returnNode(7)));
			//test connected nodes with other nodes in between
		}
	};
}
