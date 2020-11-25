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
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    break;
            }
        }while(option != 5);
    }catch (const std::exception & ex){
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}