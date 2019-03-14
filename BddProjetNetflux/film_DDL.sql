--******************************************************************************************************************************************
--******************************************************************************************************************************************
--******************************************************************************************************************************************
--********************************************************** Projet NETFLUX ****************************************************************
--******************************************************************************************************************************************
--******************************************************************************************************************************************
--******************************************************************************************************************************************

--******************************************************************************************************************************************
-- Creation des tables
--******************************************************************************************************************************************

DROP TABLE if exists FILM;
DROP TABLE if exists GENRE;
DROP TABLE if exists PERSONNE;

Create Table GENRE (
ID_GENRE SERIAL CONSTRAINT PK_GENRE PRIMARY KEY,
G_NAME varchar (25) NOT NULL);

Create Table PERSONNE (
ID_PERSONNE SERIAL CONSTRAINT PK_PERSONNE PRIMARY KEY,
P_NAME varchar (100),
P_SURNAME varchar (100) NOT NULL,
P_BIRTH date,
P_COUNTRY varchar (150),
P_POSTER varchar(500));

Create Table FILM (
ID_FILM SERIAL CONSTRAINT PK_FILM PRIMARY KEY,
F_TITLE varchar (300) NOT NULL,
F_YEAR int CONSTRAINT CHK_FILM_YEAR CHECK (F_YEAR >= 1888),
ID_GENRE int CONSTRAINT FK_FILM_GENRE REFERENCES GENRE (ID_GENRE),
F_RATINGS int,
ID_REALISATEUR int CONSTRAINT FK_FILM_REAL REFERENCES PERSONNE (ID_PERSONNE),
F_POSTER varchar (500), 
F_SYNOPSIS text,
F_LENGTH int);

