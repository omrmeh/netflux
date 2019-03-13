********
Read me
********

PSQL et instal de la base de donnée : 

1. Afin de ne pas avoir de problème d'encodage sous Windows (accents, etc.)
	Il faut rajouter une variable d'environnement pour postgres SQL
	Pour cela, aller dans les propriétés du système Windows puis "paramètres avancés" puis "variables d'environnement".
	Cliquer sur "	nouvelle" et entrer les infos suivantes :

		Nom de la variable : PGCLIENTENCODING
		Valeur de la variable : UTF-8

	Ou alors dans la fenêtre de commande : set PGCLIENTENCODING = UTF-8

2. Se conneter avec le user fourni par le service réseau (ou postgres pour nous) : psql -U postgres -d postgres

3. Création de la bse de données :
	Créer la base de donnée en tant que superuser : CREATE DATABASE netflux;

4. Création d'un utilisateur cinemauser pour la base de donnée :
	Lancer le fichier user_account.sql

5. Créer les tables de données 
	Lancer le fichier netflux.sql	






