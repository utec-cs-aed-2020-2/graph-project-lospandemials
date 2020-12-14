#include "../lib.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/BFS.h"
#include "../Algorithms/DFS.h"
#include "../Algorithms/SCC.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/AStar.h"
#include "../Algorithms/FloydWarshall.h"
#include "../Algorithms/BellmanFord.h"

template<typename TV, typename TE>
void TestKruskalPrim(Graph<TV, TE> *graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestBFS(Graph<TV, TE> *graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestDFS(Graph<TV, TE> *graph, int i, std::string id, bool complete);
template<typename TV, typename TE>
void TestCSS(Graph<TV, TE> *graph, int i);
template<typename TV, typename TE>
void TestDijkstra(Graph<TV, TE> &graph, int i, std::string id);
template<typename TV, typename TE>
void TestAStar(Graph<TV, TE> &graph, int i, std::string idFrom, std::string idTo, std::unordered_map<std::string, TE> hn);
template<typename TV, typename TE>
void TestFloydWarshall(Graph<TV, TE> &graph, int i);
template<typename TV, typename TE>
void TestBellmanFord(Graph<TV, TE> &graph, int i, std::string id);

template<typename TV, typename TE>
void TestKruskalPrim(Graph<TV, TE> *graph, int i, std::string id, bool complete){
    DirectedGraph<TV, TE>* dgraph = dynamic_cast<DirectedGraph<TV, TE>*>(graph);
    if(dgraph)  return;
    UnDirectedGraph<TV, TE>* ugraph = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);

    std::cout << "\n----------------Graph " << i << "---------------\n";
    ugraph->display();

    std::cout << "\n------------Kruskal Test " << i << "------------\n";
    Kruskal<TV, TE> kruskal(ugraph);
    UnDirectedGraph<TV, TE> resultK = kruskal.apply();
    resultK.display(); 
    isConnectedMsg(resultK.isConnected());

    std::cout << "\n-----------Prim Test " << i << "(\"" << id << "\")-----------\n";
    Prim<TV, TE> prim(ugraph);
    UnDirectedGraph<TV, TE> resultP = prim.apply(id);
    resultP.display();
    isConnectedMsg(resultP.isConnected());

    if(resultK == resultP) std::cout << "\nPrim and Kruskal give EQUAL MST\n\n";
    else  std::cout << "\nPrim and Kruskal give DIFFERENT MST\n\n";

    if(complete){
        UnDirectedGraph<TV, TE> resultPcomplete = prim.apply();
        resultPcomplete.display();
        isConnectedMsg(resultPcomplete.isConnected());
        
        if(resultK == resultPcomplete) std::cout << "\nPrim and Kruskal give EQUAL MST\n\n";
        else  std::cout << "\nPrim and Kruskal give DIFFERENT MST\n\n";
    }
}

template<typename TV, typename TE>
void TestBFS(Graph<TV, TE> *graph, int i, std::string id, bool complete){
    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph->display();
    
    int option = 0;
    UnDirectedGraph<TV, TE>* ugraph = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);
    if(ugraph)  option = 1;    

    std::cout << "\n-----------BFS Test " << i << "(\"" << id << "\")-----------\n";
    BFS<TV, TE> bfs(graph);
    
    if(option == 1){
        UnDirectedGraph<TV, TE> res0 = bfs.u_apply(id);
        res0.display();
        isConnectedMsg(res0.isConnected());
        if(complete){
            std::cout << "\n------------BFS Full " << i << "------------\n";
            UnDirectedGraph<TV, TE> res1 = bfs.u_apply();
            res1.display();
            isConnectedMsg(res1.isConnected());
            if(res0 == res1) std::cout << "\nBFS from " << id << " and full BFS give same trees.\n\n";
            else  std::cout << "\nBFS from " << id << " and full BFS give different trees.\n\n";
        }
    }else{
        DirectedGraph<TV, TE> res0 = bfs.d_apply(id);
        res0.display();
        isConnectedMsg(res0.isConnected());
        if(complete){
            std::cout << "\n------------BFS Full " << i << "------------\n";
            DirectedGraph<TV, TE> res1 = bfs.d_apply();
            res1.display();
            isConnectedMsg(res1.isConnected());
            if(res0 == res1) std::cout << "\nBFS from " << id << " and full BFS give same trees.\n\n";
            else  std::cout << "\nBFS from " << id << " and full BFS give different trees.\n\n";
        }
    }
}

template<typename TV, typename TE>
void TestDFS(Graph<TV, TE> *graph, int i, std::string id, bool complete){
    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph->display();
    
    int option = 0;
    UnDirectedGraph<TV, TE>* ugraph = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);
    if(ugraph)  option = 1;    

    std::cout << "\n-----------DFS Test " << i << "(\"" << id << "\")-----------\n";
    DFS<TV, TE> dfs(graph);
    
    if(option == 1){
        UnDirectedGraph<TV, TE> res0 = dfs.u_apply(id);
        res0.display();
        isConnectedMsg(res0.isConnected());
        if(complete){
            std::cout << "\n------------DFS Full " << i << "------------\n";
            UnDirectedGraph<TV, TE> res1 = dfs.u_apply();
            res1.display();
            isConnectedMsg(res1.isConnected());
            if(res0 == res1) std::cout << "\nDFS from " << id << " and full DFS give same trees.\n\n";
            else  std::cout << "\nDFS from " << id << " and full DFS give different trees.\n\n";
        }
    }else{
        DirectedGraph<TV, TE> res0 = dfs.d_apply(id);
        res0.display();
        isConnectedMsg(res0.isConnected());
        if(complete){
            std::cout << "\n------------DFS Full " << i << "------------\n";
            DirectedGraph<TV, TE> res1 = dfs.d_apply();
            res1.display();
            isConnectedMsg(res1.isConnected());
            if(res0 == res1) std::cout << "\nDFS from " << id << " and full DFS give same trees.\n\n";
            else  std::cout << "\nDFS from " << id << " and full DFS give different trees.\n\n";
        }
    }
}

template<typename TV, typename TE>
void TestCSS(Graph<TV, TE> *graph, int i){
    UnDirectedGraph<TV, TE>* ugraph = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);
    if(ugraph)  return;

    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph->display();
    
    std::cout << "\n------------CSS Test " << i << "------------\n";
    SCC<TV, TE> scc(graph);
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
void TestDijkstra(Graph<TV, TE> *graph, int i, std::string id){
    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph->display();
    
    std::cout << "\n---------Dijkstra Test " << i << "----------\n";
    Dijkstra<TV, TE> dijkstra(graph);
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
void TestAStar(Graph<TV, TE> *graph, int i, std::string idFrom, std::string idTo, std::unordered_map<std::string, TE> hn){
    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph->display();
    
    std::cout << "\n-----------A* Test " << i << "------------\n";
    AStar<TV, TE> astar(graph);
    returnAStarType res0 = astar.apply(idFrom, idTo, hn);
    distanceUnorderedMapAStarType distances = res0.first;
    parentUnorderedMapType parents = res0.second;
    
    std::cout << "\nResultado A*:\n";
    for(auto p : distances)
        std::cout << p.first->data << " -> G(n): " << p.second.first << " | F(n): " << p.second.second << " Parent: " << parents[p.first]->data << "\n";
}

template<typename TV, typename TE>
void TestFloydWarshall(Graph<TV, TE> *graph, int i){
    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph->display();
    
    std::cout << "\n-------FloydWarshall Test " << i << "--------\n";
    FloydWarshall<TV, TE> floydwarshall(graph);
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

template<typename TV, typename TE>
void TestBellmanFord(Graph<TV, TE> *graph, int i, std::string id){
    if(i) std::cout << "\n----------------Graph " << i << "---------------\n";
    else  std::cout << "\n----------------Graph Creator---------------\n";
    graph->display();
    
    std::cout << "\n---------BellmanFord Test " << i << "----------\n";
    BellmanFord<TV, TE> bellmanford(graph);
    returnBellmanFordType res0 = bellmanford.apply(id);
    parentUnorderedMapType parents = res0.first;
    distanceUnorderedMapType distances = res0.second;

    std::cout << "\nResultado BellmanFord:\n";
    for(auto p : parents){
        if(p.second)
            std::cout << "Vertex: " << p.first->data << " (Parent: " << p.second->data << "): " << distances[p.first] << "\n";
        else
            std::cout << "Vertex: " << p.first->data << " (Parent: NA): " << distances[p.first] << "\n";
    }
}