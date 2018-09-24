/** 
 * Mise en oeuvre de Joueur.h
 *
 * @file Joueur.cxx
 */

#include <iostream>
#include <assert.h>
// A besoin de la declaration de la classe
#include "Joueur.h"

using namespace std;

Joueur::Joueur() 
{
    // rien
}

void
Joueur::init(bool white)
{
    m_white = white;
    if (white) {
        for (int i = 0; i < 8; i++) {
            m_pieces[i] = new Piece(i + 1, 1, true); 
        }
        for (int i = 0; i < 8; i++) {
            m_pieces[i + 8] = new Pion(i + 1, 2, true); 
        }
    } else {
        for (int i = 0; i < 8; i++) {
            m_pieces[i] = new Piece(i + 1, 8, false); 
        }
        for (int i = 0; i < 8; i++) {
            m_pieces[i + 8] = new Pion(i + 1, 7, false); 
        }
    }
}

Joueur::~Joueur()
{
    for (int i = 0; i < 16; i++) {
        if (m_pieces[i] != nullptr)
            delete m_pieces[i];
    }
}

void
Joueur::placer(Echiquier & e)
{
    for (int i = 0; i < 16; i++) {
        assert(e.placer(m_pieces[i]) == true);
        assert(e.getPiece(m_pieces[i]->x(), m_pieces[i]->y()) == m_pieces[i]);
        if (i >= 8 && i < 16) {
            if (m_white) {
                assert(m_pieces[i]->name() == 'P');
                assert(e.getPiece(m_pieces[i]->x(), m_pieces[i]->y())->name() == 'P');
            } else {
                assert(m_pieces[i]->name() == 'p');
                assert(e.getPiece(m_pieces[i]->x(), m_pieces[i]->y())->name() == 'p');
            }
        }
    }
}

void 
Joueur::affiche()
{
    cout << "Joueur " << (m_white? "blanc": "noir") << endl;
    for (int i = 0; i < 16; i++) {
        m_pieces[i]->affiche();
    }
    cout << "end Joueur" << endl;
}

JoueurBlanc::JoueurBlanc() 
{
    init(true);
}

JoueurNoir::JoueurNoir() 
{
    init(false);
}