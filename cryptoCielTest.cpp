#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"
#include <fstream>

int main()
{
    HashGestion LM;
    std::string File = "test.txt";
    std::cout << "SHA256 Hash: " << LM.CalculateSHA256(File) << std::endl;
    return(0);
    
    AesGestion aes;
    aes.GenerateAESKey();
    aes.SaveAESKeyToFile("cle_aes.key");

}
