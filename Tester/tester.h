#ifndef TESTER_H
#define TESTER_H

#include "../lib.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Prim.h"
#include "../Algorithms/BFS.h"
#include "../Parser/parser.h"

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

namespace TestAlgorithm{
    template<typename TV, typename TE>
    void TestKruskalPrim(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
    template<typename TV, typename TE>
    void TestBFS(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
    template<typename TV, typename TE>
    void TestBFS(DirectedGraph<TV, TE> &graph, int i, std::string id, bool complete);
}

namespace Menu{
    void Functions(UnDirectedGraph<char, int> &ugraph1, UnDirectedGraph<char, int> &ugraph2,
                   UnDirectedGraph<char, int> &ugraph3, DirectedGraph<char, int> &dgraph1,
                   DirectedGraph<char, int> &dgraph2);
    void Examples(UnDirectedGraph<char, int> &ugraph1, UnDirectedGraph<char, int> &ugraph2,
                   UnDirectedGraph<char, int> &ugraph3, DirectedGraph<char, int> &dgraph1);
    void parser(bool &cond, UnDirectedGraph<Airport, double> &graph, Parser &parser);
    template<typename TV, typename TE>
    void Creator(int &option, Graph<TV, TE>* &graph);
}

namespace Tester{
    void executeFunctionExamples(){
        UnDirectedGraph<char, int>  ugraph1;
        ugraph1.insertVertex("1", '1');
        ugraph1.insertVertex("2", '2');
        ugraph1.insertVertex("3", '3');
        ugraph1.insertVertex("4", '4');
        ugraph1.createEdge("1", "2", 1);
        ugraph1.createEdge("1", "3", 1);
        ugraph1.createEdge("2", "3", 1);
        ugraph1.createEdge("2", "4", 1);

        UnDirectedGraph<char, int>  ugraph2;
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

        UnDirectedGraph<char, int>  ugraph3;
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

        DirectedGraph<char, int>  dgraph1;
        dgraph1.insertVertex("1", '1');
        dgraph1.insertVertex("2", '2');
        dgraph1.insertVertex("3", '3');
        dgraph1.insertVertex("4", '4');
        dgraph1.createEdge("1", "2", 1);
        dgraph1.createEdge("1", "3", 1);
        dgraph1.createEdge("2", "3", 1);
        dgraph1.createEdge("2", "4", 1);

        DirectedGraph<char, int>  dgraph2;
        dgraph2.insertVertex("1", '1');
        dgraph2.insertVertex("2", '2');
        dgraph2.insertVertex("3", '3');
        dgraph2.insertVertex("4", '4');
        dgraph2.createEdge("1", "2", 1);
        dgraph2.createEdge("1", "4", 1);
        dgraph2.createEdge("2", "3", 1);
        dgraph2.createEdge("3", "1", 1);
        dgraph2.createEdge("4", "3", 1);

        Menu::Functions(ugraph1, ugraph2, ugraph3, dgraph1, dgraph2);
    }

    void executeExamples(){
        UnDirectedGraph<char, int> ugraph1;
        ugraph1.insertVertex("0", '0');
        ugraph1.insertVertex("1", '1');
        ugraph1.insertVertex("2", '2');
        ugraph1.insertVertex("3", '3');
        ugraph1.insertVertex("4", '4');
        ugraph1.createEdge("0", "1", 2);
        ugraph1.createEdge("0", "3", 6);
        ugraph1.createEdge("1", "2", 3);
        ugraph1.createEdge("1", "3", 8);
        ugraph1.createEdge("1", "4", 5);
        ugraph1.createEdge("2", "4", 7);
        ugraph1.createEdge("3", "4", 9);
        
        UnDirectedGraph<char, int> ugraph2;
        ugraph2.insertVertex("A", 'A');
        ugraph2.insertVertex("B", 'B');
        ugraph2.insertVertex("C", 'C');
        ugraph2.insertVertex("D", 'D');
        ugraph2.insertVertex("E", 'E');
        ugraph2.insertVertex("F", 'F');
        ugraph2.insertVertex("G", 'G');
        ugraph2.insertVertex("H", 'H');
        ugraph2.insertVertex("I", 'I');
        ugraph2.insertVertex("J", 'J');
        ugraph2.createEdge("A", "D", 6);
        ugraph2.createEdge("A", "B", 3);
        ugraph2.createEdge("A", "E", 9);
        ugraph2.createEdge("B", "D", 4);
        ugraph2.createEdge("B", "C", 2);
        ugraph2.createEdge("B", "F", 9);
        ugraph2.createEdge("B", "E", 9);
        ugraph2.createEdge("C", "D", 2);
        ugraph2.createEdge("C", "G", 9);
        ugraph2.createEdge("C", "F", 8);
        ugraph2.createEdge("D", "G", 9);
        ugraph2.createEdge("E", "F", 8);
        ugraph2.createEdge("E", "J", 18);
        ugraph2.createEdge("F", "G", 7);
        ugraph2.createEdge("F", "I", 9);
        ugraph2.createEdge("F", "J", 10);
        ugraph2.createEdge("G", "H", 4);
        ugraph2.createEdge("G", "I", 5);
        ugraph2.createEdge("H", "I", 1);
        ugraph2.createEdge("H", "J", 4);
        ugraph2.createEdge("I", "J", 3);
    
        UnDirectedGraph<char, int> ugraph3;
        ugraph3.insertVertex("A", 'A');
        ugraph3.insertVertex("B", 'B');
        ugraph3.insertVertex("C", 'C');
        ugraph3.insertVertex("D", 'D');
        ugraph3.insertVertex("E", 'E');
        ugraph3.insertVertex("F", 'F');
        ugraph3.insertVertex("G", 'G');
        ugraph3.insertVertex("H", 'H');
        ugraph3.createEdge("A", "B", 1);
        ugraph3.createEdge("A", "C", 7);
        ugraph3.createEdge("A", "D", 10);
        ugraph3.createEdge("B", "C", 5);
        ugraph3.createEdge("B", "E", 8);
        ugraph3.createEdge("C", "E", 9);
        ugraph3.createEdge("C", "D", 11);
        ugraph3.createEdge("D", "E", 3);;
        ugraph3.createEdge("F", "G", 4);
        ugraph3.createEdge("F", "H", 2);
        ugraph3.createEdge("G", "H", 6);
        
        DirectedGraph<char, int> dgraph1;
        dgraph1.insertVertex("A", 'A');
        dgraph1.insertVertex("B", 'B');
        dgraph1.insertVertex("C", 'C');
        dgraph1.insertVertex("D", 'D');
        dgraph1.insertVertex("E", 'E');
        dgraph1.insertVertex("F", 'F');
        dgraph1.insertVertex("G", 'G');
        dgraph1.insertVertex("H", 'H');
        dgraph1.createEdge("A", "B", 10);
        dgraph1.createEdge("A", "C", 8);
        dgraph1.createEdge("B", "D", 4);
        dgraph1.createEdge("C", "B", 8);
        dgraph1.createEdge("C", "E", 5);
        dgraph1.createEdge("D", "F", 5);
        dgraph1.createEdge("E", "D", 5);
        dgraph1.createEdge("E", "F", 7);
        dgraph1.createEdge("F", "G", 12);
        dgraph1.createEdge("F", "H", 4);
        dgraph1.createEdge("G", "C", 7);
        dgraph1.createEdge("G", "E", 2);
        dgraph1.createEdge("G", "H", 5);

        Menu::Examples(ugraph1, ugraph2, ugraph3, dgraph1);
    }

    void executeParser(bool cond){
        std::string path;
        if(cond)  path = "Parser/Data/pe.json";
        else  path = "Parser/Data/airports.json";
        
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
                   DirectedGraph<char, int> &dgraph2){
        int option1;
        do{
            option1 = menu1();
            console_clear();
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
                default:
                    break;
            }
        }while(option1 != 5);
    }
    void Examples(UnDirectedGraph<char, int> &ugraph1, UnDirectedGraph<char, int> &ugraph2,
                   UnDirectedGraph<char, int> &ugraph3, DirectedGraph<char, int> &dgraph1){
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
                std::cout << "\t8. Back\n";
                std::cout << "\nSelect option: ";
                option = validInt();
                console_clear();
            }while(!check(option, 1, 8));
            menu2();
            
            switch(option){
                case 1:{
                    TestAlgorithm::TestKruskalPrim(ugraph1, 1, "0", false);
                    pause();
                    break;
                }
                case 2:{
                    TestAlgorithm::TestKruskalPrim(ugraph2, 2, "H", false);
                    pause();
                    break;
                }
                case 3:{
                    TestAlgorithm::TestKruskalPrim(ugraph3, 3, "B", true);
                    pause();
                    break;
                }
                case 4:{
                    TestAlgorithm::TestBFS(ugraph1, 1, "4", false);
                    pause();
                    break;
                }
                case 5:{
                    TestAlgorithm::TestBFS(ugraph2, 2, "A", false);
                    pause();
                    break;
                }
                case 6:{
                    TestAlgorithm::TestBFS(ugraph3, 3, "G", true);
                    pause();
                    break;
                }
                case 7:{
                    TestAlgorithm::TestBFS(dgraph1, 4, "A", false);
                    pause();
                    break;
                }
                default:
                    break;
            }
        }while(option != 7);
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
                std::cout << "\t8. Back\n";
                std::cout << "\nSelect option: ";
                option = validInt();
                console_clear();
            }while(!check(option, 1, 8));
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
                default:
                    break;
            }
        }while(option != 8);
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
                std::cout << "\t13. Back.\n";
                std::cout << "\nSelect option: ";
                option1 = validInt();
                console_clear();
            }while(!check(option1, 1, 13));
            
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
                default:
                    break;
            }    
        }while(option1 != 13);
    }
}

namespace TestAlgorithm{
    template<typename TV, typename TE>
    void TestKruskalPrim(UnDirectedGraph<TV, TE> &graph, int i, std::string id, bool complete){
        std::cout << "\n----------------Graph " << i << "---------------\n";
        graph.display();

        std::cout << "\n------------Kruskal Test " << i << "------------\n";
        Kruskal<char, int> kruskal(&graph);
        UnDirectedGraph<char, int> resultK = kruskal.apply();
        resultK.display(); 
        isConnectedMsg(resultK.isConnected());

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
}

#endif