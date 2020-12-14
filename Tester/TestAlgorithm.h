#include "../lib.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/BFS.h"
#include "../Algorithms/DFS.h"
#include "../Algorithms/SCC.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/FloydWarshall.h"

template<typename TV, typename TE>
void TestKruskalPrim(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestDijkstra(Graph<TV, TE> &graph, int i, std::string id);
template<typename TV, typename TE>
void TestFloydWarshall(Graph<TV, TE> &graph, int i);
template<typename TV, typename TE>
void TestBFS(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestBFS(DirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestDFS(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestDFS(DirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestCSS(DirectedGraph<TV, TE> &graph, int i);

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


template<typename TV, typename TE>
void TestBFS(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete){
    std::cout << "\n----------------Graph " << i << "---------------\n";
    graph.display();

    std::cout << "\n-----------BFS Test " << i << "(\"" << id << "\")-----------\n";
    BFS<char, int> bfs(&graph);
    UnDirectedGraph<char, int> res0 = bfs.u_apply(id);
    res0.display();
    isConnectedMsg(res0.isConnected());

    if(complete){
        std::cout << "\n------------BFS Full " << i << "------------\n";
        UnDirectedGraph<char, int> res1 = bfs.u_apply();
        res1.display();
        isConnectedMsg(res1.isConnected());

        if(res0 == res1) std::cout << "\nBFS from " << id << " and full BFS give same trees\n\n";
        else  std::cout << "\nBFS from " << id << " and full BFS give different trees\n\n";
    }
}

template<typename TV, typename TE>
void TestBFS(DirectedGraph<TV, TE> &graph, int i, std::string id, bool complete){
    std::cout << "\n----------------Graph " << i << "---------------\n";
    graph.display();

    std::cout << "\n-----------BFS Test " << i << "(\"" << id << "\")-----------\n";
    BFS<char, int> bfs(&graph);
    DirectedGraph<char, int> res0 = bfs.d_apply(id);
    res0.display();
}

template<typename TV, typename TE>
void TestDFS(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete){
    std::cout << "\n----------------Graph " << i << "---------------\n";
    graph.display();

    std::cout << "\n-----------DFS Test " << i << "(\"" << id << "\")-----------\n";
    DFS<char, int> dfs(&graph);
    UnDirectedGraph<char, int> res0 = dfs.u_apply(id);
    res0.display();
    isConnectedMsg(res0.isConnected());

    if(complete){
        std::cout << "\n------------DFS Full " << i << "------------\n";
        UnDirectedGraph<char, int> res1 = dfs.u_apply();
        res1.display();
        isConnectedMsg(res1.isConnected());

        if(res0 == res1) std::cout << "\nDFS from " << id << " and full DFS give same trees\n\n";
        else  std::cout << "\nDFS from " << id << " and full DFS give different trees\n\n";
    }
}

template<typename TV, typename TE>
void TestDFS(DirectedGraph<TV, TE> &graph, int i, std::string id, bool complete){
    std::cout << "\n----------------Graph " << i << "---------------\n";
    graph.display();

    std::cout << "\n-----------DFS Test " << i << "(\"" << id << "\")-----------\n";
    DFS<char, int> dfs(&graph);
    DirectedGraph<char, int> res0 = dfs.d_apply(id);
    res0.display();
}

template<typename TV, typename TE>
void TestCSS(DirectedGraph<TV, TE> &graph, int i){
    std::cout << "\n----------------Graph " << i << "---------------\n";
    graph.display();

    std::cout << "\n------------CSS Test " << i << "------------\n";
    SCC<char, int> scc(&graph);
    std::list<DirectedGraph<TV, TE>*> res0 = scc.apply();
    char show;
    std::cout << "\nDo you want to see the graphs? (Y/N): ";
    std::cin >> show;
    if(show == 'Y' || show == 'y'){
        int i=0;
        for(auto &graph : res0){
            std::cout << "\nStrongly Connected Component " << i << ":\n";
            graph->display();
            ++i;
        }
    }
}

template<typename TV, typename TE>
void TestDijkstra(Graph<TV, TE> &graph, int i, std::string id){
    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph.display();

    std::cout << "\n---------Dijkstra Test " << i << "----------\n";
    Dijkstra<char, int> dijkstra(&graph);
    returnDijkstraType res0 = dijkstra.apply(id);
    parentUnorderedMapType parents = res0.first;
    distanceUnorderedMapType distances = res0.second;

    std::cout << "\nResultado Dijkstra:\n";
    for(auto p : parents){
        if(p.second)
            std::cout << "Vertex: " << p.first->data << " (Parent: " << p.second->data << "): " << distances[p.first] << "\n";
        else
            std::cout << "Vertex: " << p.first->data << " (Parent: NA): " << distances[p.first] << "\n";
    }
}

template<typename TV, typename TE>
void TestFloydWarshall(Graph<TV, TE> &graph, int i){
    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph.display();

    std::cout << "\n-------FloydWarshall Test " << i << "--------\n";
    FloydWarshall<char, int> floydwarshall(&graph);
    returnFloydWarshallType res0 = floydwarshall.apply();
    distanceMatrixType distances = res0.first;
    pathMatrixType paths = res0.second;
    int width = 12;

    std::cout << "Distances: \n";
    std::cout << std::setw(width) << " ";
    for(auto i : distances) std::cout << std::setw(width) << i.first;  std::cout << "\n";
    for(auto i : distances){
        std::cout << std::setw(width) << i.first;
        for(auto j : distances)
            std::cout << std::setw(width) << distances[i.first][j.first];
        std::cout << "\n";
    }
    std::cout << "\n\nPaths: \n";
    std::cout << std::setw(width) << " ";
    for(auto i : paths) std::cout << std::setw(width) << i.first;  std::cout << "\n";
    for(auto i : paths){
        std::cout << std::setw(width) << i.first;
        for(auto j : paths)
            std::cout << std::setw(width) << paths[i.first][j.first];
        std::cout << "\n";
    }std::cout << "\n\n";
}
