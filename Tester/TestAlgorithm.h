#include "../lib.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/FloydWarshall.h"

template<typename TV, typename TE>
void TestKruskalPrim(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestDijkstra(Graph<TV, TE> &graph, int i, std::string id);
template<typename TV, typename TE>
void TestFloydWarshall(Graph<TV, TE> &graph, int i);

template<typename TV, typename TE>
void TestKruskalPrim(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete){
    std::cout << "\n----------------Graph " << i << "---------------\n";
    graph.display();

    std::cout << "\n------------Kruskal Test " << i << "------------\n";
    Kruskal<char, int> kruskal(&graph);
    UnDirectedGraph<char, int> resultK = kruskal.apply();
    resultK.display();
    isConnectedMsg(resultK.isConnected());

    //TODO: revisar implementacion
    std::cout << "\n-----------Prim Test " << i << "(\"" << id << "\")-----------\n";
    Prim<char, int> prim(&graph);
    UnDirectedGraph<char, int> resultP = prim.apply(id);
    resultP.display();
    isConnectedMsg(resultP.isConnected());

    if(resultK == resultP) std::cout << "\nPrim and Kruskal give EQUAL MST\n\n";
    else  std::cout << "\nPrim and Kruskal give DIFFERENT MST\n\n";

    if(complete){
        UnDirectedGraph<char, int> resultPcomplete = prim.apply();
        resultPcomplete.display();
        isConnectedMsg(resultPcomplete.isConnected());

        if(resultK == resultPcomplete) std::cout << "\nPrim and Kruskal give EQUAL MST\n\n";
        else  std::cout << "\nPrim and Kruskal give DIFFERENT MST\n\n";
    }
}
