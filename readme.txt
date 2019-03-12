********
Read me
********

0. Création de la bse de données : 
Se connecter en tant que super utilisateur postgres sur psql
Lancer le fichier user_account.sql (création d'un basicuser)
Créer la base de donnée : CREATE DATABASE netflux OWNER basicuser;


1. Afin de ne pas avoir de problème d'encodage sous Windows (accents, etc.)
Il faut rajouter une variable d'environnement pour postgres SQL
Pour cela, aller dans les propriétés du système Windows puis "paramètres avancés" puis "variables d'environnement".
Cliquer sur "	nouvelle" et entrer les infos suivantes :

Nom de la variable : PGCLIENTENCODING
Valeur de la variable : UTF-8

Checker dans l'invite de commande en indiquant le chemin de la base de donnée : 
set PGCLIENTENCODING
Sortie attendue : PGCLIENTENCODING=UTF-8
