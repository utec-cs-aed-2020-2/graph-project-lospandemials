#include "lib.h"
#include "Tester/tester.h"
#include "Parser/parser.h"

using namespace std;

int main(int argc, char *argv[]) {
    try{
        std::cout << "================================================" << std::endl;
        std::cout << "MENU GRAPH TESTER" << std::endl;
        std::cout << "================================================" << std::endl;
        
        Tester::executeExamples();
        //Tester::executeParser();
        
    }catch (invalid_argument& e){
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}