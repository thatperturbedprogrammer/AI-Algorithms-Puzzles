male(sanjay).
female(naina).

male(siddhant).
female(siddhi).


male(ramdas).
female(dombiaaji).

male(sandip).
female(balika).
female(tanu).

parent(sanjay, naina, siddhant).
parent(sanjay, naina, siddhi).


parent(sandip, balika, tanu).

parent(ramdas, dombiaaji, naina).
parent(ramdas, dombiaaji, balika).


father(X, Y):-male(X), parent(X, Z, Y).
mother(Z, Y):-female(Z), parent(X, Z, Y).


son(X, Y, Z):-male(X), father(Y, X), mother(Z, X).
daughter(X, Y, Z):-female(X), father(Y, X), mother(Z, X).


wife(Y, X):-female(Y), parent(X, Y, Z).
husband(X, Y):-male(X), parent(X, Y, Z).


grandfather(X, Y):-male(X), father(X,Z), father(Z, Y).
grandmother(X, Y):-female(X), mother(X,Z), father(Z, Y).


brother(X, Y):-male(X), parent(Z, W, X), parent(Z, W, Y).
sister(X, Y):-female(X), parent(Z, W, X), parent(Z, W, Y).



uncle(X, Y):-male(X), brother(X, Z), father(Z, Y).


aunt(X, Y):-female(X), sister(X, Z), father(Z, Y).


aunty(X, Y):-female(X), wife(X, U), uncle(U, Y).

