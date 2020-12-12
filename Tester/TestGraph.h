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

void graphAlgorithms(UnDirectedGraph<char, int> &ugraph1,
                     UnDirectedGraph<char, int> &ugraph2,
                     UnDirectedGraph<char, int> &ugraph3,
                     UnDirectedGraph<char, int> &ugraph4,
                     DirectedGraph<char, int> &dgraph1,
                     DirectedGraph<char, int> &dgraph2,
                     DirectedGraph<char, int> &dgraph3){

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
    ugraph2.createEdge("A", "B", 3);
    ugraph2.createEdge("A", "D", 6);
    ugraph2.createEdge("A", "E", 9);
    ugraph2.createEdge("B", "C", 2);
    ugraph2.createEdge("B", "D", 4);
    ugraph2.createEdge("B", "E", 9);
    ugraph2.createEdge("B", "F", 9);
    ugraph2.createEdge("C", "D", 2);
    ugraph2.createEdge("C", "F", 8);
    ugraph2.createEdge("C", "G", 9);
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
    ugraph3.createEdge("C", "D", 11);
    ugraph3.createEdge("C", "E", 9);
    ugraph3.createEdge("D", "E", 3);;
    ugraph3.createEdge("F", "G", 4);
    ugraph3.createEdge("F", "H", 2);
    ugraph3.createEdge("G", "H", 6);

    ugraph4.insertVertex("A", 'A');
    ugraph4.insertVertex("B", 'B');
    ugraph4.insertVertex("C", 'C');
    ugraph4.insertVertex("D", 'D');
    ugraph4.insertVertex("E", 'E');
    ugraph4.insertVertex("F", 'F');
    ugraph4.insertVertex("G", 'G');
    ugraph4.insertVertex("H", 'H');
    ugraph4.insertVertex("I", 'I');
    ugraph4.createEdge("A", "B", 22);
    ugraph4.createEdge("A", "C", 9);
    ugraph4.createEdge("A", "D", 12);
    ugraph4.createEdge("B", "C", 35);
    ugraph4.createEdge("B", "F", 36);
    ugraph4.createEdge("B", "H", 34);
    ugraph4.createEdge("C", "D", 4);
    ugraph4.createEdge("C", "E", 65);
    ugraph4.createEdge("C", "F", 42);
    ugraph4.createEdge("D", "E", 33);
    ugraph4.createEdge("D", "I", 30);
    ugraph4.createEdge("E", "F", 18);
    ugraph4.createEdge("E", "G", 23);
    ugraph4.createEdge("F", "G", 39);
    ugraph4.createEdge("F", "H", 24);
    ugraph4.createEdge("G", "H", 25);
    ugraph4.createEdge("G", "I", 21);
    ugraph4.createEdge("H", "I", 19);

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

    dgraph2.insertVertex("A", 'A');
    dgraph2.insertVertex("B", 'B');
    dgraph2.insertVertex("C", 'C');
    dgraph2.insertVertex("D", 'D');
    dgraph2.insertVertex("E", 'E');
    dgraph2.insertVertex("F", 'F');
    dgraph2.insertVertex("G", 'G');
    dgraph2.insertVertex("H", 'H');
    dgraph2.createEdge("A", "B", 1);
    dgraph2.createEdge("B", "C", 1);
    dgraph2.createEdge("B", "E", 1);
    dgraph2.createEdge("B", "F", 1);
    dgraph2.createEdge("C", "D", 1);
    dgraph2.createEdge("C", "G", 1);
    dgraph2.createEdge("D", "C", 1);
    dgraph2.createEdge("D", "H", 1);
    dgraph2.createEdge("E", "A", 1);
    dgraph2.createEdge("E", "F", 1);
    dgraph2.createEdge("F", "G", 1);
    dgraph2.createEdge("G", "F", 1);
    dgraph2.createEdge("H", "D", 1);
    dgraph2.createEdge("H", "G", 1);

    dgraph3.insertVertex("A", 'A');
    dgraph3.insertVertex("B", 'B');
    dgraph3.insertVertex("C", 'C');
    dgraph3.insertVertex("D", 'D');
    dgraph3.createEdge("A", "B", 1);
    dgraph3.createEdge("B", "C", 3);
    dgraph3.createEdge("C", "D", 2);
    dgraph3.createEdge("D", "B", -6);

}