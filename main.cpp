#include "lib.h"
#include "Tester/tester.h"
#include "Parser/parser.h"

int main(int argc, char *argv[]) {
    try{
        int option = 0, option1 = 0;
        do{
            console_clear();
            option = menuMain();
            switch(option){
                case 1:
                    Tester::executeFunctionExamples();
                    break;
                case 2:
                    Tester::executeExamples();
                    break;
                case 3:
                    menu3();
                    Tester::executeParser(true);
                    break;
                case 4:
                    menu4();
                    Tester::executeParser(false);
                    break;
                case 5:
                    Tester::executeGraphCreator();
                    break;
                default:
                    break;
            }
        }while(option != 6);
    }catch (const std::exception & ex){
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}