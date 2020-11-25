#ifndef LIB_H
#define LIB_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <unordered_map>
#include <utility>
#include <vector>

bool check(int option, int inf, int sup){
    return option >= inf && option <= sup;
}

#ifdef _WIN32
  #include<windows.h>
#endif  

void console_clear(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
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
        std::cout << "\t5. Exit\n";
        std::cout << "\nSelect option: ";
        std::cin >> option;
        console_clear();
    }while(!check(option, 1, 5));
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
        std::cout << "\t5. Back\n";
        std::cout << "\nSelect option: ";
        std::cin >> option;
        console_clear();
    }while(!check(option, 1, 5));
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

#endif