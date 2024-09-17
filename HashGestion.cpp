#include "HashGestion.h"

/**
 * @brief Constructeur par défaut de la classe HashGestion.
 * Affiche un message indiquant l'appel du constructeur.
 */
HashGestion::HashGestion()
{
    std::cout << "Constructeur par defaut du Hash" << std::endl;
}

/**
 * @brief Destructeur par défaut de la classe HashGestion.
 * Affiche un message indiquant l'appel du destructeur.
 */
HashGestion::~HashGestion()
{
    std::cout << "Destructeur par defaut du Hash" << std::endl;
}

/**
 * @brief Calcule le haché SHA-256 d'une chaîne de caractères.
 *
 * Cette méthode utilise la bibliothèque Crypto++ pour générer un haché SHA-256
 * sous forme hexadécimale à partir d'une chaîne d'entrée.
 *
 * @param input Chaîne de caractères en entrée dont le haché doit être calculé.
 * @return std::string Le haché SHA-256 de l'entrée sous forme de chaîne hexadécimale.
 */
std::string HashGestion::CalculateSHA256(const std::string& input)
{
    CryptoPP::SHA256 hash;
    std::string digest;

    CryptoPP::StringSource(input, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest))));

    return digest;
}

/**
 * @brief Calcule le haché SHA-256 d'un fichier.
 *
 * Cette méthode lit un fichier en mode binaire et génère son haché SHA-256 sous forme hexadécimale.
 * Utilise des blocs de lecture de 4096 octets pour traiter les grands fichiers.
 *
 * @param filename Nom du fichier dont le haché doit être calculé.
 * @return std::string Le haché SHA-256 du fichier sous forme de chaîne hexadécimale.
 *         Retourne une chaîne vide en cas d'erreur d'ouverture du fichier.
 */
std::string HashGestion::CalculateFileSHA256(const std::string& filename)
{
    CryptoPP::SHA256 hash;
    std::string hashFile;

    std::ifstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
        return "";
    }

    CryptoPP::HashFilter filter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hashFile)));

    const size_t bufferSize = 4096; // Taille du bloc de lecture
    CryptoPP::byte buffer[bufferSize]{};

    while (file.good())
    {
        file.read(reinterpret_cast<char*>(buffer), bufferSize);
        const std::streamsize bytesRead = file.gcount();

        if (bytesRead > 0)
        {
            filter.Put(buffer, bytesRead);
        }
    }

    filter.MessageEnd();
    return hashFile;
}
