:-module(hw5, [catomic_number/2, ion/2, molecule/2]).
:-[catoms].

listsum([], 0).
listsum([X|A], Res) :- listsum(A, Res2), Res is Res2+X.

catomic_number(NAME, CATOMIC_NUMBER) :- catom(NAME, _, _, ElectronList), listsum(ElectronList, CATOMIC_NUMBER).

ion(NAME, Q) :- catom(NAME, _, _, ElectronList), last(ElectronList, LastElectron), ((LastElectron>4 , Q is LastElectron - 8) ; (LastElectron =< 4, Q is LastElectron)).

% nameList, totalMass, totalCharge
mol([], 0, 0, _).
mol([NAME|Rest], TotalCN, TotalCharge, MinCN) :- TotalCN>0, catom(NAME, _, _, _), catomic_number(NAME, CN), CN >= MinCN, ion(NAME, Q), RestCN is TotalCN - CN, RestQ is TotalCharge - Q, mol(Rest, RestCN, RestQ, CN).

molecule(CATOM_LIST, TOTAL_CATOMIC_NUMBER) :- mol(CATOM_LIST, TOTAL_CATOMIC_NUMBER, 0, 0).

