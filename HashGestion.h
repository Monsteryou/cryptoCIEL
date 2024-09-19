#pragma once

#include <iostream>
#include <sha.h>
#include <hex.h>
#include <fstream>

/**
 * @brief Classe pour g�rer le calcul des hach�s SHA-256.
 *
 * Cette classe fournit des m�thodes pour calculer le hach� SHA-256 d'une cha�ne de caract�res
 * ou d'un fichier. Elle utilise la biblioth�que Crypto++ pour effectuer ces op�rations.
 */
class HashGestion
{
public:

    /**
     * @brief Constructeur par d�faut de la classe HashGestion.
     *
     * Initialise la classe HashGestion et affiche un message.
     */
    HashGestion();

    /**
     * Destructeur par d�faut de la classe HashGestion.
     *
     * 
     */
    ~HashGestion();

    /**
     *  Calcule le hach� SHA-256 d'une cha�ne de caract�res.
     *
     * 
     *
     * 
     */
    std::string CalculateSHA256(const std::string& input);

    /**
     * @brief Calcule le hach� SHA-256 d'un fichier.
     *
     *
     */
    std::string CalculateFileSHA256(const std::string& filename);
};
