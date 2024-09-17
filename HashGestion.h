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
     * @brief Destructeur par d�faut de la classe HashGestion.
     *
     * D�truit l'instance de la classe et affiche un message.
     */
    ~HashGestion();

    /**
     * @brief Calcule le hach� SHA-256 d'une cha�ne de caract�res.
     *
     * Cette m�thode prend une cha�ne de caract�res en entr�e et retourne son hach� SHA-256
     * sous forme hexad�cimale.
     *
     * @param input Cha�ne de caract�res dont le hach� doit �tre calcul�.
     * @return std::string Hach� SHA-256 de la cha�ne d'entr�e sous forme hexad�cimale.
     */
    std::string CalculateSHA256(const std::string& input);

    /**
     * @brief Calcule le hach� SHA-256 d'un fichier.
     *
     * Cette m�thode lit le contenu d'un fichier et calcule son hach� SHA-256.
     * Elle retourne le hach� sous forme hexad�cimale.
     *
     * @param filename Nom du fichier dont le hach� doit �tre calcul�.
     * @return std::string Hach� SHA-256 du fichier sous forme hexad�cimale.
     *         Retourne une cha�ne vide en cas d'erreur lors de l'ouverture du fichier.
     */
    std::string CalculateFileSHA256(const std::string& filename);
};
