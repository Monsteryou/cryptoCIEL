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
     * @brief Destructeur par défaut de la classe HashGestion.
     *
     * Détruit l'instance de la classe et affiche un message.
     */
    ~HashGestion();

    /**
     * @brief Calcule le haché SHA-256 d'une chaîne de caractères.
     *
     * Cette méthode prend une chaîne de caractères en entrée et retourne son haché SHA-256
     * sous forme hexadécimale.
     *
     * @param input Chaîne de caractères dont le haché doit être calculé.
     * @return std::string Haché SHA-256 de la chaîne d'entrée sous forme hexadécimale.
     */
    std::string CalculateSHA256(const std::string& input);

    /**
     * @brief Calcule le haché SHA-256 d'un fichier.
     *
     * Cette méthode lit le contenu d'un fichier et calcule son haché SHA-256.
     * Elle retourne le haché sous forme hexadécimale.
     *
     * @param filename Nom du fichier dont le haché doit être calculé.
     * @return std::string Haché SHA-256 du fichier sous forme hexadécimale.
     *         Retourne une chaîne vide en cas d'erreur lors de l'ouverture du fichier.
     */
    std::string CalculateFileSHA256(const std::string& filename);
};
