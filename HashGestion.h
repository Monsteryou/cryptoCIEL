#pragma once

#include <iostream>
#include <sha.h>
#include <hex.h>
#include <fstream>

/**
 * Classe pour gérer le calcul des hachés SHA-256.
 *
 *
 */
class HashGestion
{
public:

    /**
     *  Constructeur par défaut de la classe HashGestion.
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
     *  Calcule le haché SHA-256 d'un fichier.
     *
     *
     */
    std::string CalculateFileSHA256(const std::string& filename);
};
