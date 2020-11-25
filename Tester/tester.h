#ifndef TESTER_H
#define TESTER_H

#include "../lib.h"
#include "../Algorithms/Kruskal.h"
#include "../Algorithms/Prim.h"
#include "../Parser/parser.h"

void KruskalPrimExample1();
void KruskalPrimExample2();
void KruskalPrimExample3();
void isConnectedMsg(bool cond);

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

        
    }

    void executeExamples(){
        KruskalPrimExample1();
        pause("ver otro ejemplo");
        menu2();
        KruskalPrimExample2();
        pause("ver otro ejemplo");
        menu2();
        KruskalPrimExample3();
    }

    void executeParser(){
        std::string path;
        if(cond)  path = "/home/runner/ProyectoGrafos/Parser/Data/pe.json";
        else  path = "/home/runner/ProyectoGrafos/Parser/Data/airports.json";

        std::cout << "Please wait while the graph is created ...\n";
        
        UnDirectedGraph<Airport, double> graph;
        Parser parser(path);
        parser.readJSON();
        parser.uGraphMake(graph);
        
        std::cout << "Graph created.\n";
        pause();
        
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
                std::cin >> option;
                console_clear();
            }while(!check(option, 1, 8));
            if(cond)  menu3();
            else  menu4();

            Kruskal<Airport, double> kruskal(&graph);
            Prim<Airport, double> prim(&graph);

            switch(option){
                case 1:{
                    graph.display();
                    isConnectedMsg(graph.isConnected());
                    pause();
                    break;
                }
                case 2:{
                    std::cout << "\n-------------Kruskal Test-------------\n";
                    UnDirectedGraph<Airport, double> resultKruskal = kruskal.apply();
                    resultKruskal.display(); 
                    isConnectedMsg(resultKruskal.isConnected());
                    pause();
                    break;
                }
                case 3:{
                    std::cout << "\n-------------Prim Test--------------\n";
                    std::string id;
                    std::cout << "Ingrese id (2789, 2786, 2802): ";
                    std::cin >> id;
                    UnDirectedGraph<Airport, double> resultPrim = prim.apply(id);
                    resultPrim.display();
                    isConnectedMsg(resultPrim.isConnected());
                    pause();
                    break;
                }
                case 4:{
                    std::cout << "\n-------------Kruskal Test-------------\n";
                    UnDirectedGraph<Airport, double> resultKruskal = kruskal.apply();
                    resultKruskal.display(); 
                    isConnectedMsg(resultKruskal.isConnected());
                    std::cout << "\n\n--------------Prim Test-------------\n";
                    UnDirectedGraph<Airport, double> resultPrim = prim.apply();
                    resultPrim.display();
                    isConnectedMsg(resultPrim.isConnected());
                    if(resultKruskal == resultPrim) std::cout << "Equal graphs\n";
                    else  std::cout << "Different graphs\n";
                    pause();
                    break;
                }
                case 5:{
                    
                    pause();
                    break;
                }
                case 6:{
                    
                    pause();
                    break;
                }
                case 7:{
                    
                    pause();
                    break;
                }
                default:
                    break;
            }
        }while(option != 8);
    }
}

void isConnectedMsg(bool cond){
    if(cond) std::cout << "\nIs Connected\n";
    else std::cout << "\nIs Disconnected\n";
}

void KruskalPrimExample1(){
    //TEST 1:
    UnDirectedGraph<char, int> graph;
    graph.insertVertex("0", '0');
    graph.insertVertex("1", '1');
    graph.insertVertex("2", '2');
    graph.insertVertex("3", '3');
    graph.insertVertex("4", '4');
    graph.createEdge("0", "1", 2);
    graph.createEdge("0", "3", 6);
    graph.createEdge("1", "2", 3);
    graph.createEdge("1", "3", 8);
    graph.createEdge("1", "4", 5);
    graph.createEdge("2", "4", 7);
    graph.createEdge("3", "4", 9);
    std::cout << "\n----------------Graph 1---------------\n";

    graph.display();
    
    std::cout << "\n------------Kruskal Test 1------------\n";
    Kruskal<char, int> kruskal(&graph);
    UnDirectedGraph<char, int> resultK = kruskal.apply();
    resultK.display(); 
    isConnectedMsg(resultK.isConnected());

    std::cout << "\n-----------Prim Test 1(\"0\")-----------\n";
    Prim<char, int> prim(&graph);
    UnDirectedGraph<char, int> res0 = prim.apply("0");
    res0.display();
    isConnectedMsg(res0.isConnected());
    
    std::cout << "\n-----------Prim Test 1(\"1\")-----------\n";
    UnDirectedGraph<char, int> res1 = prim.apply("1");
    res1.display();
    isConnectedMsg(res1.isConnected());

    std::cout << "\n-----------Prim Test 1(\"2\")-----------\n";
    UnDirectedGraph<char, int> res2 = prim.apply("2");
    res2.display();
    isConnectedMsg(res2.isConnected());

    std::cout << "\n-----------Prim Test 1(\"3\")-----------\n";
    UnDirectedGraph<char, int> res3 = prim.apply("3");
    res3.display();
    isConnectedMsg(res3.isConnected());

    std::cout << "\n-----------Prim Test 1(\"4\")-----------\n";
    UnDirectedGraph<char, int> res4 = prim.apply("4");
    res4.display();
    isConnectedMsg(res4.isConnected());
}

void KruskalPrimExample2(){
    //TEST 2:
    UnDirectedGraph<char, int> graph;
    graph.insertVertex("A", 'A');
    graph.insertVertex("B", 'B');
    graph.insertVertex("C", 'C');
    graph.insertVertex("D", 'D');
    graph.insertVertex("E", 'E');
    graph.insertVertex("F", 'F');
    graph.insertVertex("G", 'G');
    graph.insertVertex("H", 'H');
    graph.insertVertex("I", 'I');
    graph.insertVertex("J", 'J');
    graph.createEdge("A", "D", 6);
    graph.createEdge("A", "B", 3);
    graph.createEdge("A", "E", 9);
    graph.createEdge("B", "D", 4);
    graph.createEdge("B", "C", 2);
    graph.createEdge("B", "F", 9);
    graph.createEdge("B", "E", 9);
    graph.createEdge("C", "D", 2);
    graph.createEdge("C", "G", 9);
    graph.createEdge("C", "F", 8);
    graph.createEdge("D", "G", 9);
    graph.createEdge("E", "F", 8);
    graph.createEdge("E", "J", 18);
    graph.createEdge("F", "G", 7);
    graph.createEdge("F", "I", 9);
    graph.createEdge("F", "J", 10);
    graph.createEdge("G", "H", 4);
    graph.createEdge("G", "I", 5);
    graph.createEdge("H", "I", 1);
    graph.createEdge("H", "J", 4);
    graph.createEdge("I", "J", 3);
  
    std::cout << "\n----------------Graph 2---------------\n";
    graph.display();
    
    std::cout << "\n------------Kruskal Test 2------------\n";
    Kruskal<char, int> kruskal(&graph);
    UnDirectedGraph<char, int> resultK = kruskal.apply();
    resultK.display(); 
    isConnectedMsg(resultK.isConnected());

    std::cout << "\n-----------Prim Test 2(\"H\")-----------\n";
    Prim<char, int> prim(&graph);
    UnDirectedGraph<char, int> resultP = prim.apply("H");
    resultP.display();
    isConnectedMsg(resultP.isConnected());
}

void KruskalPrimExample3(){
    //TEST 3:
    UnDirectedGraph<char, int> graph;
    graph.insertVertex("A", 'A');
    graph.insertVertex("B", 'B');
    graph.insertVertex("C", 'C');
    graph.insertVertex("D", 'D');
    graph.insertVertex("E", 'E');
    graph.insertVertex("F", 'F');
    graph.insertVertex("G", 'G');
    graph.insertVertex("H", 'H');
    graph.createEdge("A", "B", 1);
    graph.createEdge("A", "C", 7);
    graph.createEdge("A", "D", 10);
    graph.createEdge("B", "C", 5);
    graph.createEdge("B", "E", 8);
    graph.createEdge("C", "E", 9);
    graph.createEdge("C", "D", 11);
    graph.createEdge("D", "E", 3);;
    graph.createEdge("F", "G", 4);
    graph.createEdge("F", "H", 2);
    graph.createEdge("G", "H", 6);

    std::cout << "\n----------------Graph 3---------------\n";
    graph.display();

    std::cout << "\n------------Kruskal Test 3------------\n";
    Kruskal<char, int> kruskal(&graph);
    UnDirectedGraph<char, int> result = kruskal.apply();
    result.display(); 
    isConnectedMsg(result.isConnected());

    std::cout << "\n-----------Prim Test 3(\"B\")-----------\n";
    Prim<char, int> prim(&graph);
    UnDirectedGraph<char, int> resultP = prim.apply("B");
    resultP.display();
    isConnectedMsg(resultP.isConnected());

    if(result == resultP) std::cout << "Prim and Kruskal give DIFFERENT MST\n\n";
    else  std::cout << "Prim and Kruskal give EQUAL MST\n\n";

    UnDirectedGraph<char, int> resultPcomplete = prim.apply();
    resultPcomplete.display();
    isConnectedMsg(resultPcomplete.isConnected());
    
    if(result == resultPcomplete) std::cout << "Prim and Kruskal give DIFFERENT MST\n\n";
    else  std::cout << "Prim and Kruskal give EQUAL MST\n\n";
}

#endif
