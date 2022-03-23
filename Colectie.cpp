#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>
using namespace std;

void Colectie::redim(int move, int oldSize) { // teta(n)
    TElem *newFrecv = new int[(maxim - minim + 1)];
    for (int i = 0; i < oldSize; ++i) {
        newFrecv[i + move] = frecv[i];
    }
    for (int i = oldSize + move; i < maxim - minim + 1; ++i) {
        newFrecv[i] = 0;
    }
    for (int i = 0; i < move; ++i) {
        newFrecv[i] = 0;
    }
    delete[] frecv;
    frecv = newFrecv;
}

Colectie::Colectie() { // teta(1)
    //constructor
    this->elements = 0;
    this->minim = 0;
    this->maxim = 0;
	frecv = new TElem[1];
    frecv[0] = 0;
}

void Colectie::adauga(TElem elem) { // O(n), caz favorabil teta(1), caz defavorabil teta(n), cazul mediu teta(n)
    if (elem < minim || elem > maxim) {
        int move = 0;
        int oldSize = maxim - minim + 1;
        if (elem < minim) {
            move = minim - elem;
            minim = elem;
        } else {
            maxim = elem;
        }
        redim(move, oldSize);
    }
    frecv[elem - minim] += 1;
    ++elements;
}

bool Colectie::sterge(TElem elem) { // teta(n)
    if (elem < minim || elem > maxim) {
        return false;
    }
    if (frecv[elem - minim] > 0) {
        frecv[elem - minim]--;
        --elements;
        return true;
    }
    /*if ((elem == minim || elem == maxim) && frecv[elem - minim]) {
        if (frecv[minim] == 0) {
            int move;
            while (frecv)

        }
    }
     */
	return false;
}

bool Colectie::cauta(TElem elem) const { // teta(1)
    if (elem < minim || elem > maxim) {
        return false;
    }
    return frecv[elem - minim] > 0;
}

int Colectie::nrAparitii(TElem elem) const { // teta(1)
    if (elem < minim || elem > maxim) {
        return 0;
    }
	return frecv[elem - minim];
}

int Colectie::dim() const { // teta(1)
	return elements;
}

bool Colectie::vida() const { // teta(1)
	return elements == 0;
}

IteratorColectie Colectie::iterator() const { // teta(1)
	return  IteratorColectie(*this);
}

Colectie::~Colectie() { // teta(1)
    delete[] frecv;
}
