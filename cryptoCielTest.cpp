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
    aes.SaveAESKeyToFile("cle_aes.txt");
    aes.LoadAESKeyFromFile("cle_aes.txt");
    aes.EncryptFileAES256("cle_aes.txt" , "cle_aes_crypt.txt");
    aes.DecryptFileAES256("cle_aes_crypt.txt","cle_aes_decrypt.txt");

}
