# filler

Projet filler 42

(Résumé: Créez votre programme joueur pour affronter d’autres étudiants sur le célèbre (ou pas) plateau du Filler. Le principe est simple : deux joueurs s’affrontent sur un plateau, et doivent placer, tour à tour, la pièce que le maître du jeu (fourni sous la forme d’un exécutable Ruby) leur donne, gagnant ainsi des points. La partie s’arrête dès qu’une pièce ne peut plus être placée. Petit projet ludique !)

Pour lancer le programme :

make
./ressources/filler_vm -p1 [ressources/.filler | ./filler] -p2 [ressources/.filler | ./filler] -f [maps/*.map]
Pour lancer le programme avec le visualisateur :

./ressources/filler_vm -p1 [ressources/.filler | ./filler] -p2 [ressources/.filler | ./filler] -f [maps/*.map] | ./visu/visu
