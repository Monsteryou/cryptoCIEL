#pragma once

#include <iostream>
#include <sha.h>
#include <hex.h>
#include <fstream>

/**
 * @brief Classe pour gérer le calcul des hachés SHA-256.
 *
 * Cette classe fournit des méthodes pour calculer le haché SHA-256 d'une chaîne de caractères
 * ou d'un fichier. Elle utilise la bibliothèque Crypto++ pour effectuer ces opérations.
 */
class HashGestion
{
public:

    /**
     * @brief Constructeur par défaut de la classe HashGestion.
     *
     * Initialise la classe HashGestion et affiche un message.
     */
    HashGestion();

    /**
     * Destructeur par défaut de la classe HashGestion.
     *
     * 
     */
    ~HashGestion();

    /**
     *  Calcule le haché SHA-256 d'une chaîne de caractères.
     *
     * 
     *
     * 
     */
    std::string CalculateSHA256(const std::string& input);

    /**
     * @brief Calcule le haché SHA-256 d'un fichier.
     *
     *
     */
    std::string CalculateFileSHA256(const std::string& filename);
};
