#ifndef LIB_H
#define LIB_H

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <list>
#include <limits>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#ifndef NOMINMAX
#define NOMINMAX
#endif

#define distanceMatrixType std::map<std::string, std::map<std::string, TE>>
#define pathMatrixType std::map<std::string, std::map<std::string, std::string>>
#define returnFloydWarshallType std::pair<distanceMatrixType, pathMatrixType>

#define distanceUnorderedMapType std::unordered_map<Vertex<TV, TE>*, TE>
#define distanceUnorderedMapAStarType std::unordered_map<Vertex<TV, TE>*, std::pair<TE, TE>>
#define parentUnorderedMapType std::unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*>

#define returnDijkstraType std::pair<parentUnorderedMapType, distanceUnorderedMapType>
#define returnAStarType std::pair<distanceUnorderedMapAStarType, parentUnorderedMapType>
#define returnBellmanFordType std::pair<parentUnorderedMapType, distanceUnorderedMapType>
#define returnSCCType std::list<DirectedGraph<TV, TE>*>

#ifdef _WIN32
    #include <windows.h>
#endif

void console_clear(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool check(int option, int inf, int sup){
    return option >= inf && option <= sup;
}

std::string pathPe, pathAirports, pathConflicts;
std::unordered_map<int, std::string> imgAlgorithmsPaths;
std::unordered_map<int, std::string> imgFunctionsPaths;

void config(){
    pathPe = "../Parser/Data/pe.json";
    pathAirports = "../Parser/Data/airports.json";
    pathConflicts = "../Parser/Data/conflicts.json";

#ifdef _WIN32
    imgFunctionsPaths[2] =  "..\\img\\\"Test Functions\"\\\"Graph density1 - isConnected1 - isBipartite1.PNG\"";
    imgFunctionsPaths[3] =  "..\\img\\\"Test Functions\"\\\"Graph density2 - isStronglyConnected1.PNG\"";
    imgFunctionsPaths[5] =  "..\\img\\\"Test Functions\"\\\"Graph isConnected2.PNG\"";
    imgFunctionsPaths[7] =  "..\\img\\\"Test Functions\"\\\"Graph isStronglyConnected2.PNG\"";
    imgFunctionsPaths[9] =  "..\\img\\\"Test Functions\"\\\"Graph isBipartite2.PNG\"";
    imgFunctionsPaths[11] = "..\\img\\\"Test Functions\"\\\"Graph isWeaklyConnected3.PNG\"";
    imgAlgorithmsPaths[1] = "..\\img\\\"Test Algorithm\"\\\"UGraph 1\"\\\"MST-Red.PNG\"";
    imgAlgorithmsPaths[2] = "..\\img\\\"Test Algorithm\"\\\"UGraph 2\"\\\"MST-Red.PNG\"";
    imgAlgorithmsPaths[3] = "..\\img\\\"Test Algorithm\"\\\"UGraph 3\"\\\"MST-Red.PNG\"";
    imgAlgorithmsPaths[4] = "..\\img\\\"Test Algorithm\"\\\"UGraph 1\"\\\"BFS(4)-Red.PNG\"";
    imgAlgorithmsPaths[5] = "..\\img\\\"Test Algorithm\"\\\"UGraph 2\"\\\"BFS(A)-Red.PNG\"";
    imgAlgorithmsPaths[6] = "..\\img\\\"Test Algorithm\"\\\"UGraph 3\"\\\"BFS(G)-Red.PNG\"";
    imgAlgorithmsPaths[66] ="..\\img\\\"Test Algorithm\"\\\"UGraph 3\"\\\"BFS(complete)-Red.PNG\"";
    imgAlgorithmsPaths[7] = "..\\img\\\"Test Algorithm\"\\\"DGraph 1\"\\\"BFS(A)-Red.PNG\"";
    imgAlgorithmsPaths[8] = "..\\img\\\"Test Algorithm\"\\\"UGraph 1\"\\\"DFS(4)-Red.PNG\"";
    imgAlgorithmsPaths[9] = "..\\img\\\"Test Algorithm\"\\\"UGraph 2\"\\\"DFS(A)-Red.PNG\"";
    imgAlgorithmsPaths[10] ="..\\img\\\"Test Algorithm\"\\\"UGraph 3\"\\\"DFS(G)-Red.PNG\"";
   imgAlgorithmsPaths[1010]="..\\img\\\"Test Algorithm\"\\\"UGraph 3\"\\\"DFS(complete)-Red.PNG\"";
    imgAlgorithmsPaths[11] ="..\\img\\\"Test Algorithm\"\\\"DGraph 1\"\\\"DFS(A)-Red.PNG\"";
    imgAlgorithmsPaths[12] ="..\\img\\\"Test Algorithm\"\\\"DGraph 1\"\\\"SCC-Red.PNG\"";
    imgAlgorithmsPaths[13] ="..\\img\\\"Test Algorithm\"\\\"DGraph 2\"\\\"SCC-Red.PNG\"";
    imgAlgorithmsPaths[14] ="..\\img\\\"Test Algorithm\"\\\"UGraph 2\"\\\"Djkstra(A)-Red.PNG\"";
    imgAlgorithmsPaths[15] ="..\\img\\\"Test Algorithm\"\\\"DGraph 1\"\\\"Dijkstra(D)-Red.PNG\"";
    imgAlgorithmsPaths[16] ="..\\img\\\"Test Algorithm\"\\\"UGraph 4\"\\\"Graph 4 - AStar result.PNG\"";
    imgAlgorithmsPaths[17] ="..\\img\\\"Test Algorithm\"\\\"UGraph 1\"\\\"FloydWarshall Result.PNG\"";
    imgAlgorithmsPaths[18] ="..\\img\\\"Test Algorithm\"\\\"DGraph 1\"\\\"FloydWarshall Result.PNG\"";
    imgAlgorithmsPaths[19] ="..\\img\\\"Test Algorithm\"\\\"UGraph 2\"\\\"Djkstra(A)-Red.PNG\"";
    imgAlgorithmsPaths[20] ="..\\img\\\"Test Algorithm\"\\\"DGraph 3\"\\\"Graph 6.PNG\"";
    imgFunctionsPaths[8] = imgFunctionsPaths[2];
    imgFunctionsPaths[4] = imgFunctionsPaths[2];
    imgFunctionsPaths[6] = imgFunctionsPaths[3];
    imgFunctionsPaths[10] = imgFunctionsPaths[3];
#else
    imgFunctionsPaths[2] = "../img/\"Test Functions\"/\"Graph density1 - isConnected1 - isBipartite1.PNG\"";
     imgFunctionsPaths[3] = "../img/\"Test Functions\"/\"Graph density2 - isStronglyConnected1.PNG\"";
     imgFunctionsPaths[5] = "../img/\"Test Functions\"/\"Graph isConnected2.PNG\"";
     imgFunctionsPaths[7] = "../img/\"Test Functions\"/\"Graph isStronglyConnected2.PNG\"";
     imgFunctionsPaths[9] = "../img/\"Test Functions\"/\"Graph isBipartite2.PNG\"";
    imgFunctionsPaths[11] = "../img/\"Test Functions\"/\"Graph isWeaklyConnected3.PNG\"";
    imgAlgorithmsPaths[1] = "../img/\"Test Algorithm\"/\"UGraph 1\"/\"MST-Red.PNG\"";
    imgAlgorithmsPaths[2] = "../img/\"Test Algorithm\"/\"UGraph 2\"/\"MST-Red.PNG\"";
    imgAlgorithmsPaths[3] = "../img/\"Test Algorithm\"/\"UGraph 3\"/\"MST-Red.PNG\"";
    imgAlgorithmsPaths[4] = "../img/\"Test Algorithm\"/\"UGraph 1\"/\"BFS(4)-Red.PNG\"";
    imgAlgorithmsPaths[5] = "../img/\"Test Algorithm\"/\"UGraph 2\"/\"BFS(A)-Red.PNG\"";
    imgAlgorithmsPaths[6] = "../img/\"Test Algorithm\"/\"UGraph 3\"/\"BFS(G)-Red.PNG\"";
    imgAlgorithmsPaths[66] ="../img/\"Test Algorithm\"/\"UGraph 3\"/\"BFS(complete)-Red.PNG\"";
    imgAlgorithmsPaths[7] = "../img/\"Test Algorithm\"/\"DGraph 1\"/\"BFS(A)-Red.PNG\"";
    imgAlgorithmsPaths[8] = "../img/\"Test Algorithm\"/\"UGraph 1\"/\"DFS(4)-Red.PNG\"";
    imgAlgorithmsPaths[9] = "../img/\"Test Algorithm\"/\"UGraph 2\"/\"DFS(A)-Red.PNG\"";
    imgAlgorithmsPaths[10] ="../img/\"Test Algorithm\"/\"UGraph 3\"/\"DFS(G)-Red.PNG\"";
   imgAlgorithmsPaths[1010]="../img/\"Test Algorithm\"/\"UGraph 3\"/\"DFS(complete)-Red.PNG\"";
    imgAlgorithmsPaths[11] ="../img/\"Test Algorithm\"/\"DGraph 1\"/\"DFS(A)-Red.PNG\"";
    imgAlgorithmsPaths[12] ="../img/\"Test Algorithm\"/\"DGraph 1\"/\"SCC-Red.PNG\"";
    imgAlgorithmsPaths[13] ="../img/\"Test Algorithm\"/\"DGraph 2\"/\"SCC-Red.PNG\"";
    imgAlgorithmsPaths[14] ="../img/\"Test Algorithm\"/\"UGraph 2\"/\"Djkstra(A)-Red.PNG\"";
    imgAlgorithmsPaths[15] ="../img/\"Test Algorithm\"/\"DGraph 1\"/\"Dijkstra(D)-Red.PNG\"";
    imgAlgorithmsPaths[16] ="../img/\"Test Algorithm\"/\"UGraph 4\"/\"Graph 4 - AStar result.PNG\"";
    imgAlgorithmsPaths[17] ="../img/\"Test Algorithm\"/\"UGraph 1\"/\"FloydWarshall Result.PNG\"";
    imgAlgorithmsPaths[18] ="../img/\"Test Algorithm\"/\"DGraph 1\"/\"FloydWarshall Result.PNG\"";
    imgAlgorithmsPaths[19] ="../img/\"Test Algorithm\"/\"UGraph 2\"/\"Djkstra(A)-Red.PNG\"";
    imgAlgorithmsPaths[20] ="../img/\"Test Algorithm\"/\"DGraph 3\"/\"Graph 6.PNG\"";
    imgFunctionsPaths[4] = imgFunctionsPaths[2];
    imgFunctionsPaths[6] = imgFunctionsPaths[3];
    imgFunctionsPaths[8] = imgFunctionsPaths[2];
    imgFunctionsPaths[10] = imgFunctionsPaths[3];
#endif
}

void open_image(const char img_path[]){
    #ifdef _WIN32
        std::string str1(img_path);
        std::string str2 = ".\\\\";
        str2 += str1;
        const char * command =  str2.c_str();
        system(command);
    #else
        std::string str1(img_path);
        std::string str2 = "xdg-open ";
        str2 += str1;
        auto command =  str2.c_str();
        system(command);
//        char var[] = "xdg-open ../img/graph.png";
        //system("xdg-open ../img/MST-Red.PNG");
//        system(&"xdg-open" [*img_path]);
//        system(var1);
    #endif
}

void isConnectedMsg(bool cond){
    if(cond) std::cout << "\nIs Connected\n";
    else std::cout << "\nIs Disconnected\n";
}

int validInt(){
    int option;
    while(!(std::cin >> option)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input.  Try again: ";
    }
    return option;
}

void pause(){
    std::cout << "\nInserte cualquier caracter para continuar...\n";
    std::string c; std::cin>>c;
    console_clear();
}

void pause(std::string msg){
    std::cout << "\nInserte cualquier caracter para " << msg << " ...\n";
    std::string c; std::cin>>c;
    console_clear();
}

int menuMain(){
    int option;
    do{
        std::cout << "================================================\n";
        std::cout << "MENU GRAPH TESTER\n";
        std::cout << "================================================\n";
        std::cout << "\t1. Test graph functions.\n";
        std::cout << "\t2. Test graph algorithms.\n";
        std::cout << "\t3. Test graph parser with pe.json.\n";
        std::cout << "\t4. Test graph parser with airports.json.\n";
        std::cout << "\t5. Create your graph\n";
        std::cout << "\t6. Exit\n";
        std::cout << "\nSelect option: ";
        option = validInt();
        console_clear();
    }while(!check(option, 1, 6));
    return option;
}

int menu1(){
    int option;
    do{
        std::cout << "================================================\n";
        std::cout << "MENU GRAPH FUNCTIONS TESTER\n";
        std::cout << "================================================\n";
        std::cout << "\t1. Test density.\n";
        std::cout << "\t2. Test isConnected in Undirected Graph.\n";
        std::cout << "\t3. Test isStronglyConnected in Directed Graph.\n";
        std::cout << "\t4. Test isBipartite.\n";
        std::cout << "\t5. Test isWeaklyConnected in Directed Graph.\n";
        std::cout << "\t6. Back\n";
        std::cout << "\nSelect option: ";
        option = validInt();
        console_clear();
    }while(!check(option, 1, 6));
    return option;
}

void menu2(){
    std::cout << "================================================\n";
    std::cout << "MENU GRAPH ALGORITHMS TESTER\n";
    std::cout << "================================================\n";
}

void menu3(){
    std::cout << "================================================\n";
    std::cout << "MENU GRAPH PARSER - PERU'S AIRPORTS\n";
    std::cout << "================================================\n";
}

void menu4(){
    std::cout << "================================================\n";
    std::cout << "MENU GRAPH PARSER - WORLD'S AIRPORTS\n";
    std::cout << "================================================\n";
}

void menu5(){
    std::cout << "================================================\n";
    std::cout << "MENU GRAPH CREATOR\n";
    std::cout << "================================================\n";
}
#endif