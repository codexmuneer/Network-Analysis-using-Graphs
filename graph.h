#include <iostream>
#include<iomanip>
#include <fstream>
#include"queue.h"
#include"stack.h"

using namespace std;


int nodes;
int edges;
int* my_array;

// Structure of Linked Lists
struct info {
	int data;
	int weight;
	info* next;
};

class DirectedGraph
{
    public:
	// Pointer To Pointer Array
	info** head;
	bool* visited;
	int countSource = 0;
	int countSink = 0;
    int countiso = 0;
	int countBFSVisited = 0;
	int countbridges = 0;
	int* inAry;
	int* outAry;
	int inCount = 0;
	int outCount = 0;
	int diameter = 0;
	// Array of pointers to info struct
	// of size
	
    
    DirectedGraph(int size){
        head = new info*[size];
	// Initialize pointer array to NULL
	    for (int i = 0; i < size; ++i) {
		    *(head + i) = NULL;
	    }
		visited = new bool[size];
		for(int i = 0; i < size; i++){
			visited[i] = false;
		}
    }

    void addEdge(int x,int y){
			info* n1 = new info;
			n1->data = y;
			// n1->weight = w;
			n1->next = NULL;
			// if(x == y){
			// 	cout<<"loop"<<endl;
			// }

			if(*(head + x)== NULL){
				*(head + x) = n1;
			}
			else{
				info* temp1 = *(head + x);
				while(temp1->next != NULL){
					temp1 = temp1->next;
				}
				temp1->next = n1;

			}
			

    }

	void bfs(int startVertex,int size){
		Queue q;
        int nodes = 0;
        int edges = 0;
		visited[startVertex] = true;
		q.enQueue(startVertex);

		while(!q.isEmpty()){
			int currVertex = q.showFront();
    		cout << "Visited " << currVertex << " ";
    		q.deQueue();
			info* temp = *(head + currVertex);
			while(temp != NULL){
				int adjVertex = temp->data ; 
      			if (!visited[adjVertex]) {
        			visited[adjVertex] = true;
        			q.enQueue(adjVertex);
                    
      			}
                
				temp = temp->next;
			}
		}
        cout<<endl;

	}


	void DFS(int startVertex) {


		visited[startVertex] = true;
		info* temp = *(head + startVertex);
		cout << startVertex << " ";


		while (temp != NULL) {
			int adjVertex = temp->data;
			if (!visited[adjVertex])
				DFS(adjVertex);
			temp = temp->next;
		}


	}

	 void findoutDegree()
	{
		int out[28980] {};
		int size = 0; 
		int j = 0;
		for (int i = 0; i != 28980; ++i) {
            
			info* temp = *(head + *(my_array + i * 2 + 0));
			while(temp != NULL){
				size+=1;
				temp = temp->next;
			}
			out[*(my_array + i * 2 + 0)] = size;
			size = 0;

    	}
	
		cout << "Vertex\t\tOut" << endl;
		for(int k = 0; k != 28980; k++)
		{
			cout << *(my_array + k * 2 + 0) << "\t\t"
				<< out[*(my_array + k * 2 + 0)] << endl;
		}
	}


	void findinDegree(){
		int in[edges] {};
		int j = 0;
		for(int i = 0; i != edges; ++i)
		{
			// Out degree for ith vertex will be the count
			// of direct paths from i to other vertices
			info* temp = *(head + *(my_array + i * 2 + 0));
			while(temp != NULL){
				while(j < edges){
					if(temp->data == *(my_array + j * 2 + 0)){
						in[*(my_array + j * 2 + 0)] += 1;
						
					}
					j++;

				}

				j = 0;
				temp = temp->next;

				
			}

	
		}
		cout << "Vertex\t\tin" << endl;
		for(int i = 0;i != 28980; i++){
			cout <<*(my_array + i * 2 + 0)<< "\t\t"<<in[*(my_array + i * 2 + 0)]<<endl;
		}
	}


	void findsourcenodes(){
		int in[28980] {};
		int source = 0;
		int j = 0;
		for(int i = 0; i != 28980; ++i)
		{
			// Out degree for ith vertex will be the count
			// of direct paths from i to other vertices
			info* temp = *(head + *(my_array + i * 2 + 0));
			while(temp != NULL){
				while(j < 28980){
					if(temp->data == *(my_array + j * 2 + 0)){
						in[*(my_array + i * 2 + 0)] += 1;
						
					}
					j++;

				}

				j = 0;
				temp = temp->next;

				
			}

	
		}
		for(int i = 0;i != 28980; i++){
			if(in[*(my_array + i * 2 + 0)] == 0){
				countSource+= 1;
			}
		}
		// cout<<"Source nodes are: "<<source<<endl;
	}

	 void findsinknodes()
	{
		int out[edges] {};
		int size = 0; 
		int j = 0;
		int sink = 0;
		for (int i = 0; i != edges; ++i) {
            
			info* temp = *(head + *(my_array + i * 2 + 0));
			if(temp == NULL){
				// cout<<my_array[i][0]<<endl;
				countSink +=1;
			}

    	}

		// cout<<"Sink nodes are: "<<sink<<endl;
	}

	void findIsovertex(){
		int iso = 0;
		int in[edges] {};
		int j = 0;
		int out[edges] {};
		int size = 0; 
		int a = 0;
		for(int i = 0; i != edges; ++i)
		{
			// Out degree for ith vertex will be the count
			// of direct paths from i to other vertices
			info* temp = *(head + *(my_array + i * 2 + 0));
			while(temp != NULL){
				while(j < 28980){
					if(temp->data == *(my_array + j * 2 + 0)){
						in[*(my_array + j * 2 + 0)] += 1;
						
					}
					j++;

				}

				j = 0;
				temp = temp->next;

				
			}

		}

		for (int i = 0; i != 28980; ++i) {
            
			info* temp = *(head + *(my_array + i * 2 + 0));
			while(temp != NULL){
				size+=1;
				temp = temp->next;
			}
			out[*(my_array + i * 2 + 0)] = size;
			size = 0;

    	}
	
		for(int k = 0; k != 28980; k++)
		{
			if(out[*(my_array + k * 2 + 0)] == 0 && in[*(my_array + k * 2 + 0)] == 0 ){
				countiso += 1;
			}		
		}
		// cout<<"isolated nodes are: "<<iso<<endl;

	}


	void printAllPaths(int start, int end, int size)
	{

    int* path = new int[size];
    int path_index = 0; 
	int w;
    printAllPathsUtil(start, end,visited, path, path_index);
	}
 

	void printAllPathsUtil(int u, int d,bool visited[], int path[] ,int& path_index)
	{
		visited[u] = true;
		path[path_index] = u;
		int max = 0;
		path_index++;

		if (u == d) {
			for (int i = 0; i < path_index; i++){
				cout << path[i] << " ";
			}           
			cout << endl;

		}
		else 
		{
		
			info* temp = *(head + u);
			while(temp != NULL){
				int adjVertex = temp->data; 
				
				if (!visited[adjVertex]) {
					printAllPathsUtil(adjVertex, d, visited, path,path_index);
				}

				temp = temp->next;
			}

		}
	
		path_index--;
		visited[u] = false;
	}


    void showadjlist(int size){
	// Print the array of linked list
	for (int i = 0; i < size; ++i) {
		info* temp = *(head + *(my_array + i * 2 + 0));

		// Linked list number
		cout << *(my_array + i * 2 + 0) << "-->\t";

		// Print the Linked List
		while (temp != NULL) {
			cout << temp->data << " " ;
			temp = temp->next;
		}

		cout << '\n';
	}

    }






		void bridgeUtil(int u, bool visited[], int disc[],int low[], int parent[])
	{
		// A static variable is used for simplicity, we can
		// avoid use of static variable by passing a pointer.
		static int time = 0;
	
		// Mark the current node as visited
		visited[u] = true;
	
		// Initialize discovery time and low value
		disc[u] = low[u] = ++time;
	
		// Go through all vertices adjacent to this
		// list<int>::iterator i;
		info* temp = *(head + u);
		while(temp != NULL)
		{
			int v = temp->data;  // v is current adjacent of u
	
			// If v is not visited yet, then recur for it
			if (!visited[v])
			{
				parent[v] = u;
				bridgeUtil(v, visited, disc, low, parent);
	
				// Check if the subtree rooted with v has a
				// connection to one of the ancestors of u
				low[u]  = min(low[u], low[v]);
	
				// If the lowest vertex reachable from subtree
				// under v is  below u in DFS tree, then u-v
				// is a bridge
				if (low[v] > disc[u]){
					countbridges += 1;
				}
			}
	
			// Update low value of u for parent function calls.
			else if (v != parent[u])
				low[u]  = min(low[u], disc[v]);
		}
	}
	
	// DFS based function to find all bridges. It uses recursive
	// function bridgeUtil()
	void bridge()
	{
		int V = 28980;
		// Mark all the vertices as not visited
		bool *visited2 = new bool[V];
		int *disc = new int[V];
		int *low = new int[V];
		int *parent = new int[V];
	
		// Initialize parent and visited arrays
		for (int i = 0; i < V; i++)
		{
			parent[i] = NULL;
			visited2[i] = false;
		}
	
		// Call the recursive helper function to find Bridges
		// in DFS tree rooted with vertex 'i'
		for (int i = 0; i < V; i++)
			if (visited2[i] == false)
				bridgeUtil(i, visited, disc, low, parent);
	}


		//This will select the size distribution of SCC
	void sizeDistributionSCC() {

		int* size = new int[edges];
		for (int i = 0; i < edges; i++)
			size[i] = 0;
		int temp_Size = 0;
		int* temp = new int[edges * 2];

		//This will store the size of each row of SCC
		for (int i = 0; i < edges; i++) {
			for (int j = 0; j < edges; j++) {
				if (temp[*(my_array + i * 2 + j)] != 0) {
					size[i]++;
				}
			}
		}
	
		
		for (int i = 0; i < edges; i++) {
			temp_Size = size[i];
			int count = 0;
			for (int j = 0; j < edges; j++) {
				if (temp_Size == size[j]) {
					count++;
				}
			}
		}

		for (int i = 0; i < edges; i++) {
			int count_size = 0;
			for (int j = 0; j < edges; j++) {
				if (temp[*(my_array + i * 2 + j)] != 0)
					temp_Size++;
			}

			for (int k = 0; k < edges; k++) {
				if (temp_Size == size[k]) {
					count_size++;
				}
			}

			cout << temp_Size << " " << count_size << endl;
			temp_Size = 0;
		}
	}




	





};


void printWelcome()
{
	cout << setw(75) << "________________________________________________________________________" << endl;
	cout << setw(75) << "========================================================================" << endl;
	cout<<"\t***********************************-GRAPH-********************************************\t"<<endl;
	cout << setw(75) << "========================================================================" << endl;
}

void printMenu()
{
	cout << "\t**************************************************"<< endl;
	cout<<"\tChoose from MENU \t"<<endl;
	cout << "\t**************************************************"<< endl;
	cout << "  _________________________________________________________________" << endl;
	cout << " |  ______________________________________________________________ |" << endl;
	cout << " | |PRESS: \t\t\t\t\t\t\t | |\n";
	cout << " | |"; cout << "1. for number of Nodes\t\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "2. for number of Edges\t\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "3. for number of Source Nodes\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "4. for number of Sink Nodes\t\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "5. for number of isolated Nodes\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "6. for number of   Bridge edges\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "7. for number of Articlated Nodes\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "8. for shortest path length distribution\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "9. for Diameter   \t\t\t\t\t\t"; cout << " | |" << endl;
	cout << " | |"; cout << "10. for in degree table       \t\t "; cout << "| |" << endl;
    cout << " | |"; cout << "11. for in out degree table\t\t "; cout << "| |" << endl;		
	cout << " | |"; cout << "12. for size of Largest SCC\t\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "13. size distribution of all SCCs\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "14. for size of Largest WCC\t\t\t\t\t "; cout << "| |" << endl;
	cout << " | |"; cout << "15. size distribution of all WCCs\t\t\t\t "; cout << "| |" << endl;
	cout << " | |_____________________________________________________________| |" << endl;
	cout << " |_________________________________________________________________|" << endl;
}




void fileread(string path)
{
	fstream file;
	string line, str_nodes, str_edges;
	string tokens[2];
	int count_space = 0;

	file.open(path);

	for (int i = 0; i < 2; i++) {
		getline(file, line);
		//cout << line << endl;
	}

	getline(file, line);
	//cout << line << endl;

	for (int i = 0; line[i] != '\0'; i++) {
        // cout<<line[i]<<endl;
		if (line[i] == 32)
			count_space++;
		if (count_space == 2)
			str_nodes += line[i + 1];
		if (count_space == 4)
			str_edges += line[i + 1];
	}

	nodes = stoi(str_nodes);
	// arr_node = new int[nodes];

	cout << nodes << endl;

	edges = stoi(str_edges);
    cout << edges << endl;
    file.close();

    int* arr = new int[edges * 2];

    int n;

    ifstream file2{"CA-GrQc1.txt"};
    if (!file2.is_open()){ cout<<"error"<<endl;}
        

    for (int i=0; i != edges ; ++i) {
        for (int j=0; j != 2; ++j) {
            file2 >> *(arr + i * 2 + j);
            // cout<<*(my_array + i * 2 + j)<<endl;
                            
        }
        
    }
    my_array = arr;


}


void dispy()
{
    for (int i=0; i != 28980; ++i) {
        for (int j=0; j != 2; ++j) {
            cout << *(my_array + i * 2 + j) << " ";
        }
        cout << endl;
    }

}



