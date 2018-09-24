/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include <assert.h>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"


// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool
memeEndroit(Piece & p1, Piece & p2)
{
  return p1.x() == p2.x() && p1.y() == p2.y();
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );
  
  // On l'affiche
  // cout << "Piece: x=" << p1.x() << " y=" << p1.y() << " "
  //      << ( p1.isWhite() ? "blanche" : "noire" ) << endl;
  p1.affiche();

  Piece p2(1, 4, false);

  // cout << "Piece: x=" << p2.x() << " y=" << p2.y() << " "
  //      << ( p2.isWhite() ? "blanche" : "noire" ) << endl;
  p2.affiche();

    // erreur d'acces:
    //p2.m_white = true;

  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1

  bool b = p2.isBlack();
  cout << "b= " << b << endl;

  assert(p2.isBlack() == true);

  //Piece tbl[4];
  //Joueur blanc(true);
  //Joueur noir(false);
  //Joueur mj;
  JoueurBlanc blanc;
  JoueurNoir noir;
  //blanc.affiche();
  noir.affiche();

  assert(memeEndroit(p1, p2) == 0);
  assert(memeEndroit(p1, p1) == 1);
  Piece p3(1,3,true);
  assert(memeEndroit(p3, p1) == 0);
  //assert(memeEndroit(Piece(3,3,true), p1) == 1);

  p3.plusForte(p2).affiche();
  p3.plusForte(Piece(2,4, true)).affiche();

  Echiquier e;
  e.affiche();

  // assert(e.placer(&p1) == true);x
  // assert(e.placer(&p1) == false);
  // assert(e.getPiece(3, 3) == &p1);
  // Piece perr = Piece(10, 20, true);
  // assert(e.placer(nullptr) == false);
  // assert(e.placer(&perr) == false);

  blanc.placer(e);
  noir.placer(e);
  e.affiche();

  Pion p(2,2, true);
  assert(p.name() == 'P');

  Piece *tourB = e.getPiece(1, 1);
  assert(tourB->mouvementValide(e, 1, 4) == false);
  assert(tourB->mouvementValide(e, 1, 7) == false);
  assert(tourB->mouvementValide(e, 1, 2) == false);
  assert(tourB->mouvementValide(e, 1, 1) == false);

  string line;
  while(true) {
    cout << "> ";
    cin >> line;
    if (line == "exit") break;
    cout << "move=" << line << endl;
    if (line.size() != 4 || 
      line[0] < 'a' || line[0] > 'h' || line[2] < 'a' || line[2] > 'h' ||
      line[1] < '1' || line[1] > '8' || line[3] < '1' || line[3] > '8') {
      cout << "mouvement incompris" << endl;
      continue;
    }
    int x1 = line[0] - 'a' + 1;
    int y1 = line[1] - '0';
    int x2 = line[2] - 'a' + 1;
    int y2 = line[3] - '0';
    Piece *p = e.getPiece(x1, y1);
    if (p != nullptr) {
      p->affiche();
      cout << endl;
    }
    cout << "e.deplacer(" << x2 << "," << y2 << ")" << endl;
  }
}
