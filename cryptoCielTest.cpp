#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"
#include <fstream>

int main()
{
    HashGestion LM;
    std::string File = "test_txt";
    std::cout << "SHA256 Hash: " << LM.CalculateSHA256(file) << std::endl;
    return(0);
    
   
}
