#include "../lib.h"
#include "../Graph/UndirectedGraph.h"
#include "../Graph/DirectedGraph.h"

void graphFunctions(UnDirectedGraph<char, int> &ugraph1, 
                    UnDirectedGraph<char, int> &ugraph2, 
                    UnDirectedGraph<char, int> &ugraph3, 
                    DirectedGraph<char, int> &dgraph1,
                    DirectedGraph<char, int> &dgraph2){
    ugraph1.insertVertex("1", '1');
    ugraph1.insertVertex("2", '2');
    ugraph1.insertVertex("3", '3');
    ugraph1.insertVertex("4", '4');
    ugraph1.createEdge("1", "2", 1);
    ugraph1.createEdge("1", "3", 1);
    ugraph1.createEdge("2", "3", 1);
    ugraph1.createEdge("2", "4", 1);
    
    ugraph2.insertVertex("1", '1');
    ugraph2.insertVertex("2", '2');
    ugraph2.insertVertex("3", '3');
    ugraph2.insertVertex("4", '4');
    ugraph2.insertVertex("5", '5');
    ugraph2.insertVertex("6", '6');
    ugraph2.createEdge("1", "2", 1);
    ugraph2.createEdge("1", "3", 1);
    ugraph2.createEdge("2", "3", 1);
    ugraph2.createEdge("2", "4", 1);
    ugraph2.createEdge("5", "6", 1);

    ugraph3.insertVertex("1", '1');
    ugraph3.insertVertex("2", '2');
    ugraph3.insertVertex("3", '3');
    ugraph3.insertVertex("4", '4');
    ugraph3.insertVertex("5", '5');
    ugraph3.insertVertex("6", '6');
    ugraph3.createEdge("1", "2", 1);
    ugraph3.createEdge("2", "3", 1);
    ugraph3.createEdge("3", "4", 1);
    ugraph3.createEdge("4", "5", 1);
    ugraph3.createEdge("5", "6", 1);
    ugraph3.createEdge("6", "1", 1);

    dgraph1.insertVertex("1", '1');
    dgraph1.insertVertex("2", '2');
    dgraph1.insertVertex("3", '3');
    dgraph1.insertVertex("4", '4');
    dgraph1.createEdge("1", "2", 1);
    dgraph1.createEdge("1", "3", 1);
    dgraph1.createEdge("2", "3", 1);
    dgraph1.createEdge("2", "4", 1);

    dgraph2.insertVertex("1", '1');
    dgraph2.insertVertex("2", '2');
    dgraph2.insertVertex("3", '3');
    dgraph2.insertVertex("4", '4');
    dgraph2.createEdge("1", "2", 1);
    dgraph2.createEdge("1", "4", 1);
    dgraph2.createEdge("2", "3", 1);
    dgraph2.createEdge("3", "1", 1);
    dgraph2.createEdge("4", "3", 1);
}

