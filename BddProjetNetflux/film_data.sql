--******************************************************************************************************************************************
--******************************************************************************************************************************************
--******************************************************************************************************************************************
--*************************************************************** DATA *********************************************************************
--******************************************************************************************************************************************
--******************************************************************************************************************************************
--******************************************************************************************************************************************

--******************************************************************************************************************************************
-- Remplissage des datas
--******************************************************************************************************************************************

--Table des genres
INSERT INTO GENRE (G_NAME) Values ('Société'); --1
INSERT INTO GENRE (G_NAME) Values ('Fantastique'); --2
INSERT INTO GENRE (G_NAME) Values ('Science fiction'); --3
INSERT INTO GENRE (G_NAME) Values ('Horreur'); --4
INSERT INTO GENRE (G_NAME) Values ('Romance'); --5
INSERT INTO GENRE (G_NAME) Values ('Animation'); --6
INSERT INTO GENRE (G_NAME) Values ('Comédie'); --7
INSERT INTO GENRE (G_NAME) Values ('Drame'); --8
INSERT INTO GENRE (G_NAME) Values ('Thriller'); --9
INSERT INTO GENRE (G_NAME) Values ('Conte'); --10
INSERT INTO GENRE (G_NAME) Values ('Anticipation'); --11
INSERT INTO GENRE (G_NAME) Values ('Arts martiaux'); --12
INSERT INTO GENRE (G_NAME) Values ('Documentaire'); --13
INSERT INTO GENRE (G_NAME) Values ('Road movie'); --14
INSERT INTO GENRE (G_NAME) Values ('Aventure'); --15
INSERT INTO GENRE (G_NAME) Values ('Action'); --16

--Table des réalisateurs
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY) Values ('Arnold', 'Newt', '22/02/1922', 'USA'); --1
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY) Values ('Maïwenn', 'Le Besco', '17/04/1976', 'France'); --2
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY) Values ('Peter', 'Jackson', '31/10/1961', 'Nouvelle Zelande'); --3
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY) Values ('James', 'Cameron', '16/08/1954', 'Canada'); --4
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY) Values ('William', 'Friedkin', '29/08/1935', 'USA'); --5
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY) Values ('Garry', 'Marshall', '13/11/1934', 'USA'); --6
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY) Values ('Tom', 'McGrath', '7/08/1964', 'USA'); --7 (mada 1)
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY) Values ('Eric', 'Darnell', '28/03/1961', 'USA'); --8 (mada 2)

--Table des films
INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR) 
Values (
'Bloodsport - Tous les coups sont permis', 1988, 16, 92, 5, 'http://image.tmdb.org/t/p/w1280/E4d48dFICxN1tcGywt1p5zBHYJ.jpg', 
'Un maître japonais, le dénommé Senso "Tiger" Tanaka dont le fils a péri dans un accident de voiture, va initier un certain Frank Dux, aux subtilités, à la beauté et à la noblesse du divin ninja. Quelques années plus tard, notre homme, devenu entraîneur aux sports de combat dans un camp américain qui forme les futurs agents secrets, décide, contre l''avis de ses supérieurs, de participer à Hong Kong, au célèbre "kumite", un championnat du monde des arts martiaux...', 
1);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR) 
Values (
'Polisse', 2011, 8, 127, 4, 'http://image.tmdb.org/t/p/w1280/cKs3XSFVbFeZcH3g9geAvr6ApOl.jpg', 
'Le quotidien des policiers de la BPM (Brigade de Protection des Mineurs) ce sont les gardes à vue de pédophiles, les arrestations de pickpockets mineurs mais aussi la pause déjeuner où l’’on se raconte ses problèmes de couple ; ce sont les auditions de parents maltraitants, les dépositions des enfants, les dérives de la sexualité chez les adolescents, mais aussi la solidarité entre collègues et les fous rires incontrôlables dans les moments les plus impensables ; c’est savoir que le pire existe, et tenter de faire avec… Comment ces policiers parviennent-ils à trouver l’’équilibre entre leurs vies privées et la réalité à laquelle ils sont confrontés, tous les jours ? Fred, l’’écorché du groupe, aura du mal à supporter le regard de Melissa, mandatée par le ministère de l’’intérieur pour réaliser un livre de photos sur cette brigade.', 
2);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR) 
Values (
'Le seigneur des anneaux: La communauté de l''anneau', 2011, 2, 178, 5, 'http://image.tmdb.org/t/p/w1280/56zTpe2xvaA4alU51sRWPoKPYZy.jpg', 
'Dans ce chapitre de la trilogie, le jeune et timide Hobbit, Frodon Sacquet, hérite d’’un anneau. Bien loin d’’être une simple babiole, il s’’agit de l’’Anneau Unique, un instrument de pouvoir absolu qui permettrait à Sauron, le Seigneur des ténèbres, de régner sur la Terre du Milieu et de réduire en esclavage ses peuples. À moins que Frodon, aidé d’’une Compagnie constituée de Hobbits, d’’Hommes, d’’un Magicien, d’’un Nain, et d’’un Elfe, ne parvienne à emporter l’’Anneau à travers la Terre du Milieu jusqu’’à la Crevasse du Destin, lieu où il a été forgé, et à le détruire pour toujours. Un tel périple signifie s’’aventurer très loin en Mordor, les terres du Seigneur des ténèbres, où est rassemblée son armée d’’Orques maléfiques... La Compagnie doit non seulement combattre les forces extérieures du mal mais aussi les dissensions internes et l’’influence corruptrice qu’’exerce l’’Anneau lui-même. L’’issue de l’’histoire à venir est intimement liée au sort de la Compagnie.', 
3);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR)  
Values (
'Terminator', 1985, 3, 108, 4, 'http://image.tmdb.org/t/p/w1280/q8ffBuxQlYOHrvPniLgCbmKK4Lv.jpg', 
'A Los Angeles en 1984, un Terminator, cyborg surgi du futur, a pour mission d''exécuter Sarah Connor, une jeune femme dont l''enfant à naître doit sauver l''humanité. Kyle Reese, un résistant humain, débarque lui aussi pour combattre le robot, et aider la jeune femme...', 
4);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR)  
Values (
'L''Exorciste', 1974, 4, 122, 1, 'http://image.tmdb.org/t/p/w1280/4ucLGcXVVSVnsfkGtbLY4XAius8.jpg', 
'En Irak, le Père Merrin est profondément troublé par la découverte d’’une figurine du démon Pazuzu et les visions macabres qui s’’ensuivent.
Parallèlement, à Washington, la maison de l’’actrice Chris MacNeil est troublée par des phénomènes étranges : celle-ci est réveillée par des grattements mystérieux provenant du grenier, tandis que sa fille Regan se plaint que son lit bouge. Quelques jours plus tard, une réception organisée par Chris est troublée par l’’arrivée de Regan, qui profère des menaces de mort à l’’encontre du réalisateur Burke Dennings. Les crises se font de plus en plus fréquentes. En proie à des spasmes violents, l’’adolescente devient méconnaissable. Chris fait appel à un exorciste. L’’Eglise autorise le Père Damien Karras à officier en compagnie du Père Merrin. Une dramatique épreuve de force s’’engage alors pour libérer Regan.', 
5);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR) 
Values (
'Pretty Woman', 1990, 5, 119, 2, 'http://image.tmdb.org/t/p/w1280/fgmdaCMxXClZm2ePteLzCPySB1n.jpg', 
'Edward Lewis, homme d''affaires performant, rencontre par hasard Vivian Ward, beaute fatale qui arpente chaque nuit les trottoirs d''Hollywood Boulevard. La jeune femme ne fera qu''une bouchee du brillant PDG.', 
6);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR)  
Values (
'Madagascar', 2005, 6, 119, 3, 'http://image.tmdb.org/t/p/w1280/2YiESGB68BGQSAFvfJxBi774sc4.jpg', 
'Lorsqu’’un lion, un zèbre, une girafe, un hippopotame et une poignée de pingouins psychotiques fuient leur zoo new-yorkais pour secourir l’’un des leurs, l’’aventure s’’écrit avec un grand A. Et lorsque le destin les réunit sur l’’île de Madagascar, ils doivent apprendre en formation accélérée les rudiments de la vie à l’’air libre.', 
7);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR)  
Values (
'Madagascar', 2007, 6, 119, 3, 'https://www.imdb.com/title/tt0351283/mediaviewer/rm2831549952', 
'Lorsqu’’un lion, un zèbre, une girafe, un hippopotame et une poignée de pingouins psychotiques fuient leur zoo new-yorkais pour secourir l’’un des leurs, l’’aventure s’’écrit avec un grand A. Et lorsque le destin les réunit sur l’’île de Madagascar, ils doivent apprendre en formation accélérée les rudiments de la vie à l’’air libre.', 
7);
