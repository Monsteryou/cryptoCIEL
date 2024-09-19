#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"
#include <fstream>

int main()
{
    HashGestion LM;
    std::string monMessageHash = "test_txt";
    std::cout << "SHA256 Hash: " << LM.CalculateSHA256(monMessageHash) << std::endl;
    return(0);
    
   
}
