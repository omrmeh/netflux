********
Read me
********

PSQL et instal de la base de donn�e : 

1. Afin de ne pas avoir de probl�me d'encodage sous Windows (accents, etc.)
	Il faut rajouter une variable d'environnement pour postgres SQL
	Pour cela, aller dans les propri�t�s du syst�me Windows puis "param�tres avanc�s" puis "variables d'environnement".
	Cliquer sur "	nouvelle" et entrer les infos suivantes :

		Nom de la variable : PGCLIENTENCODING
		Valeur de la variable : UTF-8

	Ou alors dans la fen�tre de commande : set PGCLIENTENCODING = UTF-8

2. Se conneter avec le user fourni par le service r�seau (ou postgres pour nous) : psql -U postgres -d postgres

3. Cr�ation de la bse de donn�es :
	Cr�er la base de donn�e en tant que superuser : CREATE DATABASE netflux;

4. Cr�ation d'un utilisateur cinemauser pour la base de donn�e :
	Lancer le fichier user_account.sql

5. Cr�er les tables de donn�es 
	Lancer le fichier netflux.sql	






