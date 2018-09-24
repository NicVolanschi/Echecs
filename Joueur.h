/** 
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"

/**
 * Declaration d'une classe mod�lisant un joueur de jeu d'echec.
 */
class Joueur 
{
    bool m_white;
    Piece *m_pieces[16];
protected:
    Joueur();
    ~Joueur();
    void init(bool white);
 public:
    void placer(Echiquier & e);
    void affiche();
    virtual int foo() = 0;
};

class JoueurBlanc : public Joueur
{
public: 
    JoueurBlanc();
    int foo() { return 1; }
};

class JoueurNoir : public Joueur
{
public: 
    JoueurNoir();
    int foo() { return 2; }    
};

#endif // !defined Joueur_h
