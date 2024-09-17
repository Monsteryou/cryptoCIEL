#include "HashGestion.h"

/**
 * @brief Constructeur par d�faut de la classe HashGestion.
 * Affiche un message indiquant l'appel du constructeur.
 */
HashGestion::HashGestion()
{
    std::cout << "Constructeur par defaut du Hash" << std::endl;
}

/**
 * @brief Destructeur par d�faut de la classe HashGestion.
 * Affiche un message indiquant l'appel du destructeur.
 */
HashGestion::~HashGestion()
{
    std::cout << "Destructeur par defaut du Hash" << std::endl;
}

/**
 * @brief Calcule le hach� SHA-256 d'une cha�ne de caract�res.
 *
 * Cette m�thode utilise la biblioth�que Crypto++ pour g�n�rer un hach� SHA-256
 * sous forme hexad�cimale � partir d'une cha�ne d'entr�e.
 *
 * @param input Cha�ne de caract�res en entr�e dont le hach� doit �tre calcul�.
 * @return std::string Le hach� SHA-256 de l'entr�e sous forme de cha�ne hexad�cimale.
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
 * @brief Calcule le hach� SHA-256 d'un fichier.
 *
 * Cette m�thode lit un fichier en mode binaire et g�n�re son hach� SHA-256 sous forme hexad�cimale.
 * Utilise des blocs de lecture de 4096 octets pour traiter les grands fichiers.
 *
 * @param filename Nom du fichier dont le hach� doit �tre calcul�.
 * @return std::string Le hach� SHA-256 du fichier sous forme de cha�ne hexad�cimale.
 *         Retourne une cha�ne vide en cas d'erreur d'ouverture du fichier.
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
