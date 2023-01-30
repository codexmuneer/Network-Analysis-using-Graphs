#include <iostream>
#include <fstream>
#include<iomanip>
#include"graph.h"

using namespace std;




int main(){
    fileread("CA-GrQc.txt");
	DirectedGraph dg(edges+1);

	for(int i = 0; i < edges; i++){
        dg.addEdge( *(my_array + i * 2 + 0) , *(my_array + i * 2 + 1) );

    }
	// dg.findinDegree();
	int option;
	printWelcome();
	system("PAUSE");

	do {
		system("CLS");
		printMenu();
		cout << "Enter Option: ";
		cin >> option;

		switch (option) {
		case 1:
			system("CLS");
			cout << "Number of Nodes: "<< nodes << endl;
			break;
		case 2:
			system("CLS");
			cout << "Number of Edges: " << edges << endl;
			break;
		case 3:
			system("CLS");
			dg.findsourcenodes();
			cout << "Number of source nodes are: " << dg.countSource << endl;
			break;
		case 4:
			system("CLS");
			dg.findsinknodes();
			cout << "Number of source nodes are: " << dg.countSink << endl;
			break;
		case 5:
			system("CLS");
			dg.findIsovertex();
			cout << "Number of ISO nodes are: " << dg.countiso << endl;
			break;
		case 6:
			system("CLS");
			dg.bridge();
			cout << "Number of Bridges: "<< dg.countbridges << endl;
			break;
		case 7:
			system("CLS");
			cout << "Number of Articulation Nodes: "<< dg.countBFSVisited << endl;
			break;
		case 8:
			system("CLS");
			cout << "Display the shortest path length distribution: "<< dg.countBFSVisited << endl;
			break;
		case 9:
			system("CLS");
			cout << "Display the diameter of the graph: "<< dg.diameter << endl;
			break;
		case 10:
			system("CLS");
			dg.findinDegree();
			break;
		case 11:
			system("CLS");
			dg.findoutDegree();
			break;
		case 12:
			system("CLS");
			cout << "Size of Largest SCC: " << dg.countBFSVisited << endl;
			break;
		case 13:
			system("CLS");
			dg.sizeDistributionSCC();
			break;
		case 14:
			system("CLS");
			cout << dg.countBFSVisited ;
			break;
		}

		cout << "\nPress 0 to exit OR Press 1 to Choose another option: \n";
		cin >> option;
	} while (option != 0);
	



    return 0;
}
