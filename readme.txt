********
Read me
********

0. Cr�ation de la bse de donn�es : 
Se connecter en tant que super utilisateur postgres sur psql
Lancer le fichier user_account.sql (cr�ation d'un basicuser)
Cr�er la base de donn�e : CREATE DATABASE netflux OWNER basicuser;


1. Afin de ne pas avoir de probl�me d'encodage sous Windows (accents, etc.)
Il faut rajouter une variable d'environnement pour postgres SQL
Pour cela, aller dans les propri�t�s du syst�me Windows puis "param�tres avanc�s" puis "variables d'environnement".
Cliquer sur "	nouvelle" et entrer les infos suivantes :

Nom de la variable : PGCLIENTENCODING
Valeur de la variable : UTF-8

Checker dans l'invite de commande en indiquant le chemin de la base de donn�e : 
set PGCLIENTENCODING
Sortie attendue : PGCLIENTENCODING=UTF-8
