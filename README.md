# Projet 2 - Analyse d’adresses IP

Ce projet est un programme en C permettant de gérer des adresses IP. Il permet de vérifier la validité des adresses IP,
de déterminer leur classe et leur type (publique, privée, localhost, broadcast ou multicast), et de calculer l'adresse
réseau et l'adresse hôte.

## Structure du projet

Le projet est divisé en plusieurs fichiers :

- `main.c` : Contient la fonction principale du programme permettant d'afficher les différents résultats dans la
  console.
- `Fonctions.c` : Contient les implémentations des fonctions utilisées dans le programme.
- `Fonctions.h` : Contient les déclarations des fonctions utilisées dans le programme.
- `CMakeLists.txt` : Fichier de configuration pour CMake.

## Fonctionnalités

Le programme propose les fonctionnalités suivantes :

- Vérification de la validité d'une adresse IP.
- Extraction des parties d'une adresse IP et de son masque.
- Détermination de la classe d'une adresse IP.
- Détermination du type d'une adresse IP (publique, privée, localhost, broadcast ou multicast).
- Calcul de l'adresse réseau à partir d'une adresse IP et de son masque.
- Calcul de l'adresse hôte à partir d'une adresse IP et de son masque.

## Prérequis

- CMake (version 3.27 ou supérieure)
- Un compilateur C compatible avec le standard C11

## Compilation

Pour compiler le projet, utilisez les commandes suivantes :

```sh
mkdir build
cd build
cmake ..
make
```


## Manuel d'emploi
Pour utiliser le programme, suivez les étapes ci-dessous :
  - Compilez le programme en suivant les instructions de la section "Compilation".
  - Exécutez le programme généré. Par défaut, le programme se nommera Code et sera situé dans le répertoire build.
  - Lorsque le programme s'exécute, il vous demande de saisir une adresse IP. Saisissez l'adresse IP au format x.x.x.x ou x.x.x.x/n (avec n étant le masque de sous-réseau en CIDR).
  - Le programme affichera l'adresse IP saisie et vérifiera sa validité. Si l'adresse est valide, il affichera :
  - La classe de l'adresse réseau.
  - Le type de l'adresse IP (publique, privée, localhost, broadcast ou multicast).
  - L'adresse réseau calculée.
  - L'adresse hôte calculée.

Si l'adresse IP est invalide, le programme affichera un message d'erreur.
 

## Auteurs

Lien du projet : [@Mini Projet](https://github.com/MyttocS82/Projet-C-Analyse-d-adresses-IP)

- [@Michelon Scott](https://github.com/MyttocS82)
- [@Vigneau Adam](https://gitlab.info.iut-tlse3.fr/vgd4689a)
