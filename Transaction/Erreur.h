#ifndef ERREUR_H_INCLUDED
#define ERREUR_H_INCLUDED
/***********************************************************************************
    @file Erreur.h
    @brief Erreur classe concrète pour les exceptions
    @version v1
    @date 8 juin 2020
    @bug aucun détecté
    @warning COMPILE
    @note
***********************************************************************************/



#include <iostream>
#include <string>
#include <stdexcept>
#include "timing.h"

using namespace std;

class Erreur : public exception {
    string info;
public:
    Erreur(const string& message) :info(message){}
    const char* what() const noexcept { return info.c_str(); }
    ~Erreur()throw(){}
};

class CompteManager;
class Compte;
class CompteReel;
class CompteVirtuel;
class CompteRacine;
class Transaction;
class Operation;
class TransactionManager;

#endif
