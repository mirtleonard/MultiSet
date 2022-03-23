#include "IteratorColectie.h"
#include "Colectie.h"

IteratorColectie::IteratorColectie(const Colectie& c): col(c) { // O(n) n - nr de elemente din vectorul de frecventa
    prim();
}

void IteratorColectie::prim() { // O(n) n - nr de elemente din vectorul de frecventa
    if (col.dim() == 0) {
        current = col.maxim - col.minim + 1;
        return;
    }
    current = -1;
    while (col.frecv[++current] == 0);
    times = col.frecv[current];
}

void IteratorColectie::urmator() { // O(n) n - nr de elemente din vectorul de frecventa
    if (times == 1) {
        while (col.frecv[++current] == 0 && current <= col.maxim - col.minim);
        times = col.frecv[current];
    } else {
        --times;
    }
}

bool IteratorColectie::valid() const { // teta(1)
    return current <= col.maxim - col.minim;
}

TElem IteratorColectie::element() const { // teta(1)
    return current + col.minim;
}
