#ifndef TESTER_H
#define TESTER_H

#include "../lib.h"
#include "../Parser/parser.h"
#include "TestAlgorithm.h"
#include "TestGraph.h"
//#include "../GraphicUserInterface/WindowRender.h"

template<typename TV, typename TE>
void showGraph(UnDirectedGraph<TV, TE> &graph){
    graph.graphSize();
    char show;
    std::cout << "\nDo you want to see the graph? (Y/N): ";
    std::cin >> show;
    if(show == 'Y' || show == 'y'){
        graph.display();
        isConnectedMsg(graph.isConnected());
    }
}

namespace Menu{
    void Functions(UnDirectedGraph<char, int> &ugraph1, UnDirectedGraph<char, int> &ugraph2,
                   UnDirectedGraph<char, int> &ugraph3, DirectedGraph<char, int> &dgraph1,
                   DirectedGraph<char, int> &dgraph2, DirectedGraph<char, int> &dgraph3);
    void Algorithms(UnDirectedGraph<char, int> &ugraph1, UnDirectedGraph<char, int> &ugraph2,
                  UnDirectedGraph<char, int> &ugraph3, UnDirectedGraph<char, int> &ugraph4,
                  DirectedGraph<char, int> &dgraph1, DirectedGraph<char, int> &dgraph2,
                  DirectedGraph<char, int> &dgraph3);
    void parser(bool &cond, UnDirectedGraph<Airport, double> &graph, Parser &parser);
    template<typename TV, typename TE>
    void Creator(int &option, Graph<TV, TE>* &graph);
}

namespace Tester{
    void executeFunctionExamples(){
        UnDirectedGraph<char, int> ugraph1, ugraph2, ugraph3;
        DirectedGraph<char, int> dgraph1, dgraph2, dgraph3;
        graphFunctions(ugraph1, ugraph2, ugraph3, dgraph1, dgraph2, dgraph3);
        Menu::Functions(ugraph1, ugraph2, ugraph3, dgraph1, dgraph2, dgraph3);
    }

    void executeAlgorithmsExamples(){
        UnDirectedGraph<char, int> ugraph1, ugraph2, ugraph3, ugraph4;
        DirectedGraph<char, int> dgraph1, dgraph2, dgraph3;
        graphAlgorithms(ugraph1, ugraph2, ugraph3, ugraph4, dgraph1, dgraph2, dgraph3);
        Menu::Algorithms(ugraph1, ugraph2, ugraph3, ugraph4, dgraph1, dgraph2, dgraph3);
    }

    void executeParser(bool cond){
        std::string path;
        if(cond)  path = pathPe;
        else  path = pathAirports;
        
        std::cout << "Please wait while the graph is created ...\n";
        
        UnDirectedGraph<Airport, double> graph;
        Parser parser(path);
        parser.readJSON();
        parser.uGraphMake(graph);
        
        std::cout << "Graph created.\n";
        pause();
        
        Menu::parser(cond, graph, parser);
    }

    void executeGraphCreator(){
        Graph<std::string, int>* graph;
        int option;
        do{
            menu5();
            std::cout << "\t1. Undirected graph.\n";
            std::cout << "\t2. Directed graph.\n";
            std::cout << "\t3. Back.\n";
            std::cout << "\nSelect option: ";
            option = validInt();
            console_clear();
        }while(!check(option, 1, 3));
        
        if(option == 1) graph = new UnDirectedGraph<std::string, int>();
        else if(option == 2)    graph = new DirectedGraph<std::string, int>();
        else return;

        Menu::Creator(option, graph);
        delete graph;
    }
}

namespace Menu{
    void Functions(UnDirectedGraph<char, int> &ugraph1, UnDirectedGraph<char, int> &ugraph2,
                   UnDirectedGraph<char, int> &ugraph3, DirectedGraph<char, int> &dgraph1,
                   DirectedGraph<char, int> &dgraph2, DirectedGraph<char, int> &dgraph3){
        int option1;
        do{
            option1 = menu1();
            console_clear();
            
            open_image(imgAlgorithmsPaths[2*option1].c_str());
            open_image(imgAlgorithmsPaths[2*option1 + 1].c_str());

            switch(option1){
                case 1:
                    std::cout << "---------Density---------\n";
                    std::cout << "\nUnDirectedGraph 1\n";
                    ugraph1.display();
                    std::cout << "\nDensity: " << ugraph1.density() << "\n";
                    std::cout << "\nIsDense(0.5): ";
                    if(ugraph1.isDense()) std::cout << "YES\n";
                    else  std::cout << "NO\n";                  
                    
                    std::cout << "\nDirectedGraph 1\n";
                    dgraph1.display();
                    std::cout << "\nDensity: " << dgraph1.density() << "\n";
                    std::cout << "\nIsDense(0.4): ";
                    if(dgraph1.isDense(0.4)) std::cout << "YES\n";
                    else  std::cout << "NO\n";                  

                    pause();
                    break;
                case 2:
                    std::cout << "---------isConnected---------\n";
                    std::cout << "\nUnDirectedGraph 1\n";
                    ugraph1.display();
                    std::cout << "\nIsConnected: ";
                    if(ugraph1.isConnected()) std::cout << "YES\n";
                    else  std::cout << "NO\n";

                    std::cout << "\nUnDirectedGraph 2\n";
                    ugraph2.display();
                    std::cout << "\nIsConnected: ";
                    if(ugraph2.isConnected()) std::cout << "YES\n";
                    else  std::cout << "NO\n";

                    pause();
                    break;  
                case 3:
                    std::cout << "---------isStronglyConnected---------\n";
                    std::cout << "\nDirectedGraph 1\n";
                    dgraph1.display();
                    std::cout << "\nIsStronglyConnected: ";
                    if(dgraph1.isStronglyConnected()) std::cout << "YES\n";
                    else  std::cout << "NO\n";

                    std::cout << "\nDirectedGraph 2\n";
                    dgraph2.display();
                    std::cout << "\nIsStronglyConnected: ";
                    if(dgraph2.isStronglyConnected()) std::cout << "YES\n";
                    else  std::cout << "NO\n";

                    pause();
                    break;
                case 4:
                    std::cout << "---------isBipartite---------\n";
                    std::cout << "\nUnDirectedGraph 1\n";
                    ugraph1.display();
                    std::cout << "\nIsBipartite: ";
                    if(ugraph1.isBipartite()) std::cout << "YES\n";
                    else  std::cout << "NO\n";

                    std::cout << "\nUnDirectedGraph 3\n";
                    ugraph3.display();
                    std::cout << "\nIsBipartite: ";
                    if(ugraph3.isBipartite()) std::cout << "YES\n";
                    else  std::cout << "NO\n";

                    pause();
                    break;
                case 5:
                    std::cout << "---------isWeaklyConnected---------\n";
                    std::cout << "\nDirectedGraph 1\n";
                    dgraph1.display();
                    std::cout << "\nisWeaklyConnected: ";
                    if(dgraph1.isWeaklyConnected()) std::cout << "YES\n";
                    else  std::cout << "NO\n";

                    std::cout << "\nDirectedGraph 2\n";
                    dgraph3.display();
                    std::cout << "\nisWeaklyConnected: ";
                    if(dgraph3.isWeaklyConnected()) std::cout << "YES\n";
                    else  std::cout << "NO\n";

                    pause();
                    break;
                default:
                    break;
            }
        }while(option1 != 6);
    }
    void Algorithms(UnDirectedGraph<char, int> &ugraph1, UnDirectedGraph<char, int> &ugraph2,
                  UnDirectedGraph<char, int> &ugraph3, UnDirectedGraph<char, int> &ugraph4,
                  DirectedGraph<char, int> &dgraph1, DirectedGraph<char, int> &dgraph2,
                  DirectedGraph<char, int> &dgraph3){
        int option;
        do{
            do{
                menu2();
                std::cout << "\t1. Test Kruskal Prim 1 - small graph.\n";
                std::cout << "\t2. Test Kruskal Prim 2 - big graph.\n";
                std::cout << "\t3. Test Kruskal Prim 3 - disconnected graph.\n";
                std::cout << "\t4. Test BFS 1 - small graph.\n";
                std::cout << "\t5. Test BFS 2 - big graph.\n";
                std::cout << "\t6. Test BFS 3 - disconnected graph.\n";
                std::cout << "\t7. Test BFS 4 - directed graph.\n";
                std::cout << "\t8. Test DFS 1 - small graph.\n";
                std::cout << "\t9. Test DFS 2 - big graph.\n";
                std::cout << "\t10. Test DFS 3 - disconnected graph.\n";
                std::cout << "\t11. Test DFS 4 - directed graph.\n";
                std::cout << "\t12. Test CSS 1.\n";
                std::cout << "\t13. Test CSS 2.\n";
                std::cout << "\t14. Test Dijkstra 1.\n";
                std::cout << "\t15. Test Dijkstra 2.\n";
                std::cout << "\t16. Test AStar 1.\n";
                std::cout << "\t17. Test Floyd Warshall 1.\n";
                std::cout << "\t18. Test Floyd Warshall 2.\n";
                std::cout << "\t19. Test Bellman Ford 1.\n";
                std::cout << "\t20. Test Bellman Ford 2.\n";
                std::cout << "\t21. Back\n";
                std::cout << "\nSelect option: ";
                option = validInt();
                console_clear();
            }while(!check(option, 1, 21));
            menu2();
            
            open_image(imgAlgorithmsPaths[option].c_str());
            switch(option){
                case 1:{
                    TestKruskalPrim(&ugraph1, 1, "0", false);
                    pause();
                    break;
                }
                case 2:{
                    TestKruskalPrim(&ugraph2, 2, "H", false);
                    pause();
                    break;
                }
                case 3:{
                    TestKruskalPrim(&ugraph3, 3, "B", true);
                    pause();
                    break;
                }
                case 4:{
                    TestBFS(&ugraph1, 1, "4", false);
                    pause();
                    break;
                }
                case 5:{
                    TestBFS(&ugraph2, 2, "A", false);
                    pause();
                    break;
                }
                case 6:{
                    open_image(imgAlgorithmsPaths[66].c_str());
                    TestBFS(&ugraph3, 3, "G", true);
                    pause();
                    break;
                }
                case 7:{
                    TestBFS(&dgraph1, 4, "A", false);
                    pause();
                    break;
                }
                case 8:{
                    TestDFS(&ugraph1, 1, "4", false);
                    pause();
                    break;
                }
                case 9:{
                    TestDFS(&ugraph2, 2, "A", false);
                    pause();
                    break;
                }
                case 10:{
                    open_image(imgAlgorithmsPaths[1010].c_str());
                    TestDFS(&ugraph3, 3, "G", true);
                    pause();
                    break;
                }
                case 11:{
                    TestDFS(&dgraph1, 4, "A", false);
                    pause();
                    break;
                }
                case 12:{
                    TestCSS(&dgraph1, 1);
                    pause();
                    break;
                }
                case 13:{
                    TestCSS(&dgraph2, 2);
                    pause();
                    break;
                }
                case 14:{
                    TestDijkstra(&ugraph2, 1, "A");
                    pause();
                    break;
                }
                case 15:{
                    TestDijkstra(&dgraph1, 2, "D");
                    pause();
                    break;
                }
                case 16:{
                    std::unordered_map<std::string, int> hn;
                    hn["A"] = 36;
                    hn["B"] = 39;
                    hn["C"] = 31;
                    hn["D"] = 30;
                    hn["E"] = 34;
                    hn["F"] = 32;
                    hn["G"] = 21;
                    hn["H"] = 19;
                    hn["I"] = 0;
                    TestAStar(&ugraph4, 1, "A", "I", hn);
                    pause();
                    break;
                }
                case 17:{
                    TestFloydWarshall(&ugraph1, 1);
                    pause();
                    break;
                }
                case 18:{
                    TestFloydWarshall(&dgraph1, 2);
                    pause();
                    break;
                }
                case 19:{
                    TestBellmanFord(&ugraph2, 1, "A");
                    pause();
                    break;
                }
                case 20:{
                    TestBellmanFord(&dgraph3, 2, "A");
                    pause();
                    break;
                }
                default:
                    break;
            }
        }while(option != 21);
    }

    void parser(bool &cond, UnDirectedGraph<Airport, double> &graph, Parser &parser){
        int option;
        do{
            do{
                if(cond)  menu3();
                else  menu4();
                std::cout << "\t1. Print graph.\n";
                std::cout << "\t2. Apply Kruskal algorithm.\n";
                std::cout << "\t3. Apply Prim algorithm from vertex.\n";
                std::cout << "\t4. MST from both algorithm.\n";
                std::cout << "\t5. Print one vertex by id.\n";
                std::cout << "\t6. Print vertexes by country.\n";
                std::cout << "\t7. Check for a path from 2 vertexes\n";
                std::cout << "\t8. Display Airport GUI\n";
                std::cout << "\t9. Back\n";
                std::cout << "\nSelect option: ";
                option = validInt();
                console_clear();
            }while(!check(option, 1, 9));
            if(cond)  menu3();
            else  menu4();

            Kruskal<Airport, double> kruskal(&graph);
            Prim<Airport, double> prim(&graph);

            switch(option){
                case 1:{
                    showGraph(graph);
                    pause();
                    break;
                }
                case 2:{
                    std::cout << "\n-------------Kruskal Test-------------\n";
                    UnDirectedGraph<Airport, double> resultKruskal = kruskal.apply();
                    showGraph(resultKruskal);
                    pause();
                    break;
                }
                case 3:{
                    std::cout << "\n-------------Prim Test--------------\n";
                    std::string id;
                    parser.showIDs();
                    std::cout << "\nInsert ID (2789, 2786, 2802): ";
                    std::cin >> id;
                    UnDirectedGraph<Airport, double> resultPrim = prim.apply(id);
                    showGraph(resultPrim);
                    pause();
                    break;
                }
                case 4:{
                    std::cout << "\n-------------Kruskal - Prim Test-------------\n";
                    UnDirectedGraph<Airport, double> resultKruskal = kruskal.apply();
                    UnDirectedGraph<Airport, double> resultPrim = prim.apply();
                    if(resultKruskal == resultPrim) std::cout << "\nPrim and Kruskal give EQUAL MST\n\n";
                    else  std::cout << "\nPrim and Kruskal give EQUAL MST\n\n";
                    std::cout << "Kruskal:\n\n";
                    showGraph(resultKruskal);
                    std::cout << "Prim:\n\n";
                    showGraph(resultPrim);
                    pause();
                    break;
                }
                case 5:{
                    std::cout << "\n-------------Display Vertex-------------\n";
                    std::string id;
                    parser.showIDs();
                    std::cout << "\nInsert id (2789, 2786, 2802): ";
                    std::cin >> id;
                    graph(id);
                    pause();
                    break;
                }
                case 6:{
                    std::cout << "\n--------Display Vertex by country--------\n";
                    std::string id;
                    parser.showCountries();
                    std::cout << "\nInsert country: ";
                    std::cin.ignore();
                    std::getline(std::cin, id);
                    std::vector<std::string> vectorIDs = parser.airportsCountry(id);
                    for(std::string e : vectorIDs)
                        graph(e);
                    pause();
                    break;
                }
                case 7:{
                    std::cout << "\n-------Two Airports Path-----------\n";
                    std::string id1, id2;
                    parser.showIDs();
                    std::cout << "\nInsert id1 and id2 (2789, 2786, 2802): ";
                    std::cin >> id1 >> id2;
                    graph(id1, id2);
                    pause();
                    break;
                }
                case 8:{
                    //GUI GraphicUserInterface;
                    //GraphicUserInterface.RenderAirportGraph(graph);
                    break;
                }
                default:
                    break;
            }
        }while(option != 9);
    }
    
    template<typename TV, typename TE>
    void Creator(int &option, Graph<TV, TE>* &graph){
        int option1;
        do{
            do{
                menu5();
                std::cout << "\t1. Insert Vertex.\n";
                std::cout << "\t2. Insert Edge.\n";
                std::cout << "\t3. Delete Vertex.\n";
                std::cout << "\t4. Delete Edge.\n";
                std::cout << "\t5. Density.\n";
                if(option == 1) std::cout << "\t6. Is Connected.\n";
                else    std::cout << "\t6. Is Strongly Connected.\n";
                std::cout << "\t7. Display vertex.\n";
                std::cout << "\t8. Display vertices connection.\n";
                std::cout << "\t9. is Bipartite (UnDirectedGraph).\n";
                std::cout << "\t10. Apply Kruskal. \n";
                std::cout << "\t11. Apply Prim.\n";
                std::cout << "\t12. Apply Kruskal and Prim.\n";
                std::cout << "\t13. Apply BFS.\n";
                std::cout << "\t14. Apply BFS Full.\n";
                std::cout << "\t15. Apply DFS.\n";
                std::cout << "\t16. Apply DFS Full.\n";
                std::cout << "\t17. Apply Dijkstra.\n";
                std::cout << "\t18. Apply A*.\n";
                std::cout << "\t19. Apply Bellman-Ford.\n";
                std::cout << "\t20. Apply Floyd-Warshall.\n";
                std::cout << "\t21. Apply Strongly Connected Components.\n";
                std::cout << "\t22. Back.\n";
                std::cout << "\nSelect option: ";
                option1 = validInt();
                console_clear();
            }while(!check(option1, 1, 22));
            
            menu5();
            switch(option1){
                case 1:{
                    std::cout << "\n-------------Insert Vertex-------------\n\n";
                    graph->display();
                    std::string vertex;
                    std::cout << "\nInsert a vertex (char): ";
                    std::cin >> vertex;
                    graph->insertVertex(vertex, vertex);
                    std::cout << "\n";
                    graph->display();
                    pause();
                    break;
                }
                case 2:{
                    std::cout << "\n-------------Insert Edge-------------\n\n";
                    graph->display();
                    std::string id1;
                    std::string id2;
                    std::cout << "\nInsert first and second vertex (char): ";
                    std::cin >> id1 >> id2;

                    int w;
                    std::cout << "Insert weight (int): ";
                    w = validInt();

                    graph->createEdge(id1, id2, w);
                    std::cout << "\n";
                    graph->display();
                    pause();
                    break;
                }
                case 3:{
                    std::cout << "\n-------------Delete Vertex-------------\n\n";
                    graph->display();
                    std::string id;
                    std::cout << "\nInsert a vertex (char): ";
                    std::cin >> id;
                    graph->deleteVertex(id);
                    std::cout << "\n";
                    graph->display();
                    pause();
                    break;
                }
                case 4:{
                    std::cout << "\n-------------Delete Edge-------------\n\n";
                    graph->display();
                    std::string id1;
                    std::string id2;
                    std::cout << "\nInsert first and second vertex (char): ";
                    std::cin >> id1 >> id2;
                    graph->deleteEdge(id1, id2);
                    std::cout << "\n";
                    graph->display();
                    pause();
                    break;
                }
                case 5:{
                    std::cout << "\n-------------Density-------------\n\n";
                    graph->display();
                    std::cout << "Density: " << graph->density() << "\n";
                    pause();
                    break;
                }
                case 6:{
                    graph->display();
                    if(option == 1){
                        std::cout << "\n-------------Is Connected-------------\n\n";
                        if(graph->isConnected())    std::cout << "YES\n";
                        else    std::cout << "NO\n";
                    }else{
                        std::cout << "\n-------------Is Strongly Connected-------------\n\n";
                        if(graph->isStronglyConnected())    std::cout << "YES\n";
                        else    std::cout << "NO\n";
                    }
                    pause();
                    break;
                }
                case 7:{
                    std::cout << "\n-------------Display vertex-------------\n\n";
                    graph->display();
                    std::string id;
                    std::cout << "\nInsert a vertex (char): ";
                    std::cin >> id;
                    graph->operator()(id);
                    std::cout << "\n";
                    pause();
                    break;
                }
                case 8:{
                    std::cout << "\n-------------Display vertices connection-------------\n\n";
                    graph->display();
                    std::string id1;
                    std::string id2;
                    std::cout << "\nInsert first and second vertex (char): ";
                    std::cin >> id1 >> id2;
                    graph->operator()(id1, id2);
                    std::cout << "\n";
                    pause();
                    break;
                }
                case 9:{
                    std::cout << "\n-------------Is Bipartite-------------\n\n";
                    graph->display();
                    if(graph->isBipartite())    std::cout << "YES\n";
                    else std::cout << "NO\n";
                    pause();
                    break;
                }
                case 10:{
                    std::cout << "\n-------------Kruskal-------------\n\n";
                    if(option == 1){
                        graph->display();
                    
                        Kruskal<std::string, int> kruskal(graph);
                        UnDirectedGraph<std::string, int> resultKruskal = kruskal.apply();
                        std::cout << "\n-------------MST from Kruskal--------------\n";
                        resultKruskal.display(); 
                        isConnectedMsg(resultKruskal.isConnected());
                    }else{
                        std::cout << "Is DirectedGraph\n";
                    }
                    
                    pause();
                    break;
                }
                case 11:{
                    std::cout << "\n-------------Prim-------------\n\n";
                    if(option == 1){
                        graph->display();

                        Prim<std::string, int> prim(graph);
                        std::string id;
                        std::cout << "\nInsert a vertex (char): ";
                        std::cin >> id;
                        
                        UnDirectedGraph<std::string, int> resultPrim1 = prim.apply(id);
                        std::cout << "------Prim since a vertex: " << id << "------\n";
                        resultPrim1.display(); 
                        isConnectedMsg(resultPrim1.isConnected());
                    }else{
                        std::cout << "Is DirectedGraph\n";
                    }
                    pause();
                    break;
                }
                case 12:{
                    std::cout << "\n-----------Kruskal and Prim (total)-----------\n\n";
                    if(option == 1){
                        graph->display();

                        Kruskal<std::string, int> kruskal(graph);
                        UnDirectedGraph<std::string, int> resultKruskal = kruskal.apply();
                        std::cout << "\n-------------MST from Kruskal--------------\n";
                        resultKruskal.display(); 
                        isConnectedMsg(resultKruskal.isConnected());

                        Prim<std::string, int> prim(graph);
                        UnDirectedGraph<std::string, int> resultPrim2 = prim.apply();
                        std::cout << "\n-------------MST from Prim--------------\n";
                        resultPrim2.display(); 
                        isConnectedMsg(resultPrim2.isConnected());

                        if(resultKruskal == resultPrim2)    std::cout << "Prim and Kruskal give EQUAL MST\n";
                        else  std::cout << "Prim and Kruskal give DIFFERENT MST\n";
                    }else{
                        std::cout << "Is DirectedGraph\n";
                    }
                    pause();
                    break;
                }
                case 13:{
                    std::cout << "\n-----------BFS-----------\n\n";
                    graph->display();
                    std::string id;
                    std::cout << "\nInsert ID: ";
                    std::cin >> id;
                    TestBFS(graph, 0, id, false);
                    pause();
                    break;
                }
                case 14:{
                    std::cout << "\n-----------BFS complete-----------\n\n";
                    graph->display();
                    std::string id;
                    std::cout << "\nInsert ID: ";
                    std::cin >> id;
                    TestBFS(graph, 0, id, true);
                    pause();
                    break;
                }
                case 15:{
                    std::cout << "\n-----------DFS-----------\n\n";
                    graph->display();
                    std::string id;
                    std::cout << "\nInsert ID: ";
                    std::cin >> id;
                    TestDFS(graph, 0, id, false);
                    pause();
                    break;
                }
                case 16:{
                    std::cout << "\n-----------DFS complete-----------\n\n";
                    graph->display();
                    std::string id;
                    std::cout << "\nInsert ID: ";
                    std::cin >> id;
                    TestDFS(graph, 0, id, true);
                    pause();
                    break;
                }
                case 17:{
                    std::cout << "\n-----------Dijkstra-----------\n\n";
                    graph->display();
                    std::string id;
                    std::cout << "\nInsert ID: ";
                    std::cin >> id;
                    TestDijkstra(graph, 0, id);
                    pause();
                    break;
                }
                case 18:{
                    std::cout << "\n-----------A*-----------\n\n";
                    graph->display();
                    std::string idFrom, idTo;
                    std::cout << "\nInsert origin's ID and destiny's ID: ";
                    std::cin >> idFrom >> idTo;
                    
                    std::cout << "\nInsert heuristic for each ID: ";
                    std::unordered_map<std::string, int> heuristic;
                    int vertexes = graph->numberOfVertexes();
                    std::string id;
                    int distance;
                    for(int i=1; i <= vertexes; ++i){
                        std::cout << "\n\tInsert ID and distance (" << i << "): ";
                        std::cin >> id >> distance;
                        heuristic[id] = distance;
                    }
                    TestAStar(graph, 0, idFrom, idTo, heuristic);
                    pause();
                    break;
                }
                case 19:{
                    std::cout << "\n-----------Bellman Ford-----------\n\n";
                    graph->display();
                    std::string id;
                    std::cout << "\nInsert ID: ";
                    std::cin >> id;
                    TestBellmanFord(graph, 0, id);
                    pause();
                    break;
                }
                case 20:{
                    std::cout << "\n-----------Floyd Warshall-----------\n\n";
                    TestFloydWarshall(graph, 0);
                    pause();
                    break;
                }
                case 21:{
                    std::cout << "\n-----------Strongly Connected Components-----------\n\n";
                    if(option == 1){
                        std::cout << "This algorithm requires a directed grpah.\n";
                        break;
                    }
                    TestCSS(graph, 0);
                    pause();
                    break;
                }
                default:
                    break;
            }    
        }while(option1 != 22);
    }
}

#endif