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

Joueur::Joueur(bool white)
{
    m_white = white;
    if (white) {
        for (int i = 0; i < 8; i++) {
            m_pieces[i] = Piece(i + 1, 1, true); 
        }
        for (int i = 0; i < 8; i++) {
            m_pieces[i + 8] = Piece(i + 1, 2, true); 
        }
    } else {
        for (int i = 0; i < 8; i++) {
            m_pieces[i] = Piece(i + 1, 8, false); 
        }
        for (int i = 0; i < 8; i++) {
            m_pieces[i + 8] = Piece(i + 1, 7, false); 
        }
    }
}

void
Joueur::placer(Echiquier & e)
{
    for (int i = 0; i < 16; i++) {
        assert(e.placer(&m_pieces[i]) == true);
        assert(e.getPiece(m_pieces[i].x(), m_pieces[i].y()) == &m_pieces[i]);
    }
}

void 
Joueur::affiche()
{
    cout << "Joueur " << (m_white? "blanc": "noir") << endl;
    for (int i = 0; i < 16; i++) {
        m_pieces[i].affiche();
    }
    cout << "end Joueur" << endl;
}
