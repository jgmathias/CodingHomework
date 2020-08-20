//Lab 4: Mathias, James

//James Mathias
//May 12, 2019
//CS 832
//Lab #4: Graph

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "GraphType.h"

int main()
{
	const int size = 5;
	string VertexNames[size] = { "A", "B", "C", "D", "E" };
	GraphType<string> temp(size);
	
	for (int i = 0; i < size; i++)
	{
		temp.AddVertex(VertexNames[i]);
	}
	cout << "created graph with " << size << " nodes: ";
	for (int i = 0; i < size - 1; i++)
	{
		cout << VertexNames[i] << ", ";
	}
	cout << "and " << VertexNames[size - 1] << "\n" << endl;
	
	temp.AddEdge("A", "C", 13);
	cout << "added edge from A to C with weight 13" << endl;
	temp.AddEdge("C", "E", 35);
	cout << "added edge from C to E with weight 35" << endl;
	temp.AddEdge("E", "B", 52);
	cout << "added edge from E to B with weight 52" << endl;
	temp.AddEdge("B", "D", 24);
	cout << "added edge from B to D with weight 24" << endl;
	temp.AddEdge("D", "A", 41);
	cout << "added edge from D to A with weight 41" << "\n" << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "edge from " << VertexNames[i] << " to " << VertexNames[j] << ": " << boolalpha << setw(8) << left << temp.EdgeExists(VertexNames[i], VertexNames[j]) << "weight: " << setw(2) << right << temp.WeightIs(VertexNames[i], VertexNames[j]) << endl;
		}
	}
	cout << endl;

	temp.AddEdge("A", "B", 12);
	cout << "added edge from A to B with weight 12" << endl;
	temp.AddEdge("B", "C", 23);
	cout << "added edge from B to C with weight 23" << endl;
	temp.AddEdge("C", "D", 34);
	cout << "added edge from C to D with weight 34" << endl;
	temp.AddEdge("D", "E", 45);
	cout << "added edge from D to E with weight 45" << endl;
	temp.AddEdge("E", "A", 51);
	cout << "added edge from E to A with weight 51" << "\n" << endl;
	
	temp.DeleteEdge("A", "C");
	cout << "deleted edge from A to C" << endl;
	temp.DeleteEdge("C", "E");
	cout << "deleted edge from C to E" << endl;
	temp.DeleteEdge("E", "B");
	cout << "deleted edge from E to B" << endl;
	temp.DeleteEdge("B", "D");
	cout << "deleted edge from B to D" << endl;
	temp.DeleteEdge("D", "A");
	cout << "deleted edge from D to A" << "\n" << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "edge from " << VertexNames[i] << " to " << VertexNames[j] << ": " << boolalpha << setw(8) << left << temp.EdgeExists(VertexNames[i], VertexNames[j]) << "weight: " << setw(2) << right << temp.WeightIs(VertexNames[i], VertexNames[j]) << endl;
		}
	}
	cout << endl;

	system("PAUSE");
	return 0;
}