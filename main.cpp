#include "graph.h"
#include "random.h"
#include "tree.h"
#include "graphMat.h"
#include "satellite.h"
#include <iostream>
#include <ctime>
#define TIMES 10000
using namespace std;

/*
Test case 1: 
		Build a random graph which essentially have lesser degree nodes.
Parameters:
		Takes references for Tree(Arrayed Tree) , graph(adjacency lists) , graphMat(Addjacency Matrix)
		to populate the graph
*/

void build_random_graph(graph& g,Tree& t,graphMat& gm){

	int vertices  =  randomNumber(99,1);

	int edges  =  randomNumber(min(400,vertices*(vertices-1)/2),100);
	
	for(int i = 0;i<vertices;i++){

		int v = t.AddNode();
		int runtype = randomNumber(6,1);
		g.add_vertex(v,runtype);
		gm.add_vertex(v,runtype);

	}
	for(int i = 0;i<edges;i++){

		int a = randomNumber(vertices-1,0);
		int b = randomNumber(vertices-1,0);
		g.add_edge(a,b);
		t.AddEdge (a,b);
		gm.add_edge(a,b);

	}

}

/*
Test case 2: 
		Build a random graph which essentially have higher degree nodes.
Parameters:
		Takes references for Tree(Arrayed Tree) , graph(adjacency lists) , graphMat(Addjacency Matrix)
		to populate the graphs
*/

void build_over_degree_random_graph(graph& g,Tree& t,graphMat& gm){

	int vertices  =  randomNumber(99,1);

	int edges  =  randomNumber(min(400,vertices*(vertices-1)/2),100);
	
	for(int i = 0;i<vertices;i++){

		int v = t.AddNode();
		int runtype  =  randomNumber(6,1);
		g.add_vertex(v,runtype);
		gm.add_vertex(v,runtype);

	}

	for(int i = 0;i<vertices;i++){

		int deg  =  randomNumber(vertices-1,1);
		for(int j = 0;j<deg;j++){
			int v  =  randomNumber(vertices-1,1);
			g.add_edge(i,v);
			t.AddEdge(i,v);
			gm.add_edge(i,v);
		}

	}
}

/*
Time comparison method which essentially which runs DFS for TIMES(1000) number of times.
*/
void Time_Comparison(graph& g,Tree& t,graphMat& gm){

	std::clock_t start;
    double duration;


    /*

    Time Evaluation for adjacency lists implemenatation.

    */
    start  =  std::clock();    
    for(int i = 0;i<TIMES;i++)
    	g.dfs(0);
    duration  =  ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"Normal Graph (Adjacency lists) :\t"<< duration  <<" seconds\n";



    /*

    Time Evaluation for adjacency Matrix implemenatation.

    */
    start  =  std::clock();    
    for(int i = 0;i<TIMES;i++)
    	gm.dfs(0);
    duration  =  ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"Normal Graph (Adjacency Matrix):\t"<< duration <<" seconds\n";

    /*

    Time Evaluation for Arrayed tree implemenatation.

    */
    start  =  std::clock();    
    t.DFSOptimizer (0);
    for(int i = 0;i<TIMES;i++)
    	t.DFS (0);
    duration  =  ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"Arrayed Tree Implementation of Graph :\t"<< duration  <<" seconds\n";

}

int main()
{
	int sizes[]  =  { sizeof(A), sizeof(B) };

	/*
	Test case 1:

	*/
	cout<<"Perfomances : \n\n";

	cout<< "\nTest case 1: With nodes having lesser degrees\n"; 
	graph g(true);
	graphMat gm(true);
	Tree t(2, sizes, 2, true);
	build_random_graph(g,t,gm);
	// t.Print();
	Time_Comparison(g,t,gm);


	/*
	Test case 2:
	*/
	cout<< "\n\nTest case 2: With nodes having higher degrees\n"; 
	graph g1(true);
	Tree t1(2, sizes, 2, true);
	graphMat gm1(true);
	build_over_degree_random_graph(g1,t1,gm1);
	// t1.Print();
	Time_Comparison(g1,t1,gm1);

	int sizes2[]  =  { sizeof(A), sizeof(F) };
	cout<< "\nTest case 3: With nodes having lesser degrees(With bulk number of variable in each class)\n"; 
	graph g2(true);
	graphMat gm2(true);
	Tree t2(2, sizes2, 2, true);
	build_random_graph(g2,t2,gm2);
	// t.Print();
	Time_Comparison(g2,t2,gm2);


	/*
	Test case 2:
	*/
	cout<< "\n\nTest case 4: With nodes having higher degrees(with bulk number of variables in each class)\n"; 
	graph g3(true);
	Tree t3(2, sizes2, 2, true);
	graphMat gm3(true);
	build_over_degree_random_graph(g3,t3,gm3);
	// t1.Print();
	Time_Comparison(g3,t3,gm3);


	
	return 0;
}
