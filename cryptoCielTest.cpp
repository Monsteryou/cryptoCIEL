#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"
#include <fstream>

int main()
{

    /*
            * SHA256 - (4) Question 2,3,4,5

    HashGestion LM;
    std::string monMessageHash = "Crypto.txt";
    std::cout << LM.CalculateSHA256(monMessageHash) << std::endl;



            * AES - (5) Question 6,7,8,9

    AesGestion AES;
    AES.GenerateAESKey();
    AES.SaveAESKeyToFile("ClefAES.txt");
    AES.EncryptFileAES256("cle_aes.txt", "cle_aes_crypt.txt");
    AES.DecryptFileAES256("cle_aes_crypt.txt","cle_aes_decrypt.txt");

            * RSA - (6.1) 1er Programme
    */

    RsaGestion RSA;
    RSA.generationClef("YouennRSAPublic.pem", "YouennRSAPrive.pem", 2048);

    /*
    std::string MessageEncrypt = "Chien ";
    std::string MessageCrypt = RSA.chiffrementRsa(MessageEncrypt);
    std::cout << MessageCrypt << std::endl;
    std::string MessageDecrypt = RSA.dechiffrementRsa(MessageCrypt);
    std::cout << MessageDecrypt << std::endl;

            * RSA - (6.2) 2eme Programmes
    RSA.chargementClefs("YouennRSAPublic.pem", "YouennRSAPrive.pem")
    RSA.chiffreDansFichier("YouennRSADonnee.txt", "YouennRSAChiffre.txt");
    RSA.dechiffrementFichier("YouennRSADonnee.txt", "YouennRSADechiffre.txt", 2048);
    */
   
    RSA.chargementClefs("YouennRSAPublic.pem", "YouennRSAPrive.pem");
    RSA.chiffrementFichier("YouennRSADonnee.txt", "YouennRSAChiffre.txt", 2048); 
    RSA.dechiffrementFichier("YouennRSAChiffre.txt", "YouennRSADechiffre.txt", 2048);
    
}