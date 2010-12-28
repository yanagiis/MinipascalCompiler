#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "minipascal_driver.h"

int main(int argc, char** argv)
{
        minipascal::Driver driver = minipascal::Driver();
        
        if(argc == 2)
        {
                std::fstream infile(argv[1]);
                if(!infile.good())
                {
                        std::cerr << "Could not open file: " << argv[1] << std::endl;
                        return 0;
                }
                else
                {
                        std::cout << "1. Start parsing and build AST....." << std::endl;
                        bool result = driver.parse_stream(infile, argv[1]);
                        if(result)
                        {
                                std::cout << "2. Start checking semantic....." << std::endl;
                                driver.declarationChecking();
                        }
                        else
                        {
                                std::cout << "Fail" << std::endl;
                        }
                        infile.close();
                }
        }
        return 0;
}