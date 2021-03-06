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
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY, P_POSTER, P_BIO) Values ('Arnold', 'Newt', '01/02/1922', 'USA', 'http://image.tmdb.org/t/p/w1280/rivHScdhT043n5jCSci7ToqLsoE.jpg', 'Newt Arnold était un réalisateur, producteur et scénariste américain. Arnold a dirigé Bloodsport, qui est sorti en 1988 et est depuis devenu un film culte et plusieurs autres films. Il a aussi été assistant réalisateur sur le Film The Godfather II réalisé par Francis Ford Coppola.'); --1
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY, P_POSTER, P_BIO) Values ('Maïwenn', 'Le Besco', '01/04/1976', 'France', 'http://image.tmdb.org/t/p/w1280/ipmcXbM2jDvvt0jwIF7KDbAHKPW.jpg', 'Maïwenn Le Besco, dite Maïwenn, née le 17 avril 1976 aux Lilas (Seine-Saint-Denis), est une actrice, scénariste et réalisatrice française. Elle commence sa carrière en tant qu’’enfant actrice en utilisant son nom de famille, mais est créditée sous son seul prénom depuis 1991. Elle est nommée au César du meilleur espoir féminin et du meilleur premier film pour Pardonnez-moi puis deux fois à celui de meilleure réalisatrice pour Polisse et Mon Roi.'); --2
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY, P_POSTER, P_BIO) Values ('Peter', 'Jackson', '01/10/1961', 'Nouvelle Zelande', 'http://image.tmdb.org/t/p/w1280/kSrfI3TbMdIMmPVOflLQ56OfscB.jpg', 'Peter Jackson est un réalisateur, scénariste et producteur néo-zélandais, né le 31 octobre 1961 à Wellington. Il est surtout connu pour avoir réalisé la trilogie du Seigneur des anneaux, d’’après l’’œuvre de J. R. R. Tolkien, et un remake de King Kong. Il réalise ensuite Le Hobbit, l’’adaptation cinématographique en trois volets du roman de Tolkien. Il est membre de l’’Ordre de Nouvelle-Zélande, chevalier de l’’Ordre du Mérite de Nouvelle-Zélande et Officier des Arts et des Lettres.'); --3
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY, P_POSTER, P_BIO) Values ('James', 'Cameron', '01/08/1954', 'Canada', 'http://image.tmdb.org/t/p/w1280/zy2foCd8PEtvCcsX48cROdQdDLB.jpg', 'James Francis Cameron, né le 16 août 1954 à Kapuskasing (Canada) est un réalisateur, scénariste, producteur et explorateur de fonds marins canadien qui habite aux Etats-Unis. Il a réalisé et écrit les films, Terminator (1984), Aliens, le retour (1986), Abyss (1989), Terminator 2 : Le Jugement dernier (1991), True Lies (1994), Titanic (1997) et Avatar (2009). En 1997, il bat un record avec Titanic, film consacré au naufrage de 1912. Le film est resté pendant onze ans le plus gros succès du box-office mondial et reçoit en 1998 l’’Oscar du meilleur film et Cameron remporte la même année l’’Oscar du meilleur réalisateur. Le film remporte également neuf autres Oscars. Le budget du film est de quelque 200 millions de dollars. Il bat un nouveau record en 2009. '); --4
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY, P_POSTER, P_BIO) Values ('William', 'Friedkin', '01/08/1935', 'USA', 'http://image.tmdb.org/t/p/w1280/1iBd92izRHpkSH4hOhcUBmF2cv7.jpg', 'William Friedkin, né le 29 août 1935 à Chicago (Illinois), est un réalisateur, scénariste et producteur de film américain. Plusieurs de ses films comme L’’Exorciste ou French Connection sont considérés comme des classiques du cinéma américain. Il a reçu notamment l’’Oscar du meilleur réalisateur pour French Connection.'); --5
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY, P_POSTER, P_BIO) Values ('Garry', 'Marshall', '01/11/1934', 'USA', 'http://image.tmdb.org/t/p/w1280/kx77E8p5rnEmKxIhFT0qWCEMEik.jpg', 'Garry Kent Masciarelli, né le 13 novembre 1934 à New York (État de New York), dans le Bronx et mort le 19 juillet 2016 à Burbank (Californie), est un acteur, réalisateur, scénariste et producteur américain. Il commence sa carrière comme acteur et auteur de sketches pour l’’émission télévisée The Tonight Show. Il révèle ensuite au monde entier Robin Williams avec la série de science-fiction Mork & Mindy. Son actrice préférée est Julia Roberts, à qui il offre son plus grand succès au début de sa carrière avec le film populaire Pretty Woman ; il tourne quatre productions cinématographiques avec elle, dont le dernier, Joyeuse Fête des mères, sorti deux mois et demi avant son décès. '); --6
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY, P_POSTER, P_BIO) Values ('Tom', 'McGrath', '01/08/1964', 'USA', 'http://image.tmdb.org/t/p/w1280/1qOQBwXSIAH0CKWP2RymCMdOi7a.jpg', 'Thomas « Tom » McGrath est un animateur, doubleur et réalisateur américain né le 7 août 1964 à Lynwood, dans l''État de Washington. Il est principalement connu pour avoir réalisé avec Eric Darnell le film d''animation sorti en 2005, Madagascar, ainsi que ses suites. Il a aussi prêté sa voix à d’’autres films de DreamWorks comme Souris City en 2006 et Shrek le troisième en 2007.'); --7 (mada 1)
INSERT INTO PERSONNE(P_NAME, P_SURNAME, P_BIRTH, P_COUNTRY, P_POSTER, P_BIO) Values ('Eric', 'Darnell', '01/03/1961', 'USA', 'http://image.tmdb.org/t/p/w1280/8aRWzSXl6fR0b2g3td44JJAU3es.jpg', 'Eric Darnell est un réalisateur, directeur des effets spéciaux, scénariste, et acteur spécialisé dans les films d''animation né en 1960 dans le Kansas.'); --8 (mada 2)

--Table des films
INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR) 
Values (
'Bloodsport - Tous les coups sont permis', 1988, 16, 92, 3, 'http://image.tmdb.org/t/p/w1280/E4d48dFICxN1tcGywt1p5zBHYJ.jpg', 
'Un maître japonais, le dénommé Senso "Tiger" Tanaka dont le fils a péri dans un accident de voiture, va initier un certain Frank Dux, aux subtilités, à la beauté et à la noblesse du divin ninja. Quelques années plus tard, notre homme, devenu entraîneur aux sports de combat dans un camp américain qui forme les futurs agents secrets, décide, contre l''avis de ses supérieurs, de participer à Hong Kong, au célèbre "kumite", un championnat du monde des arts martiaux...', 
1);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR) 
Values (
'Polisse', 2011, 8, 127, 3, 'http://image.tmdb.org/t/p/w1280/cKs3XSFVbFeZcH3g9geAvr6ApOl.jpg', 
'Le quotidien des policiers de la BPM (Brigade de Protection des Mineurs) ce sont les gardes à vue de pédophiles, les arrestations de pickpockets mineurs mais aussi la pause déjeuner où l’’on se raconte ses problèmes de couple ; ce sont les auditions de parents maltraitants, les dépositions des enfants, les dérives de la sexualité chez les adolescents, mais aussi la solidarité entre collègues et les fous rires incontrôlables dans les moments les plus impensables ; c’est savoir que le pire existe, et tenter de faire avec… Comment ces policiers parviennent-ils à trouver l’’équilibre entre leurs vies privées et la réalité à laquelle ils sont confrontés, tous les jours ? Fred, l’’écorché du groupe, aura du mal à supporter le regard de Melissa, mandatée par le ministère de l’’intérieur pour réaliser un livre de photos sur cette brigade.', 
2);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR) 
Values (
'Le seigneur des anneaux: La communauté de l''anneau', 2011, 2, 178, 3, 'http://image.tmdb.org/t/p/w1280/56zTpe2xvaA4alU51sRWPoKPYZy.jpg', 
'Dans ce chapitre de la trilogie, le jeune et timide Hobbit, Frodon Sacquet, hérite d’’un anneau. Bien loin d’’être une simple babiole, il s’’agit de l’’Anneau Unique, un instrument de pouvoir absolu qui permettrait à Sauron, le Seigneur des ténèbres, de régner sur la Terre du Milieu et de réduire en esclavage ses peuples. À moins que Frodon, aidé d’’une Compagnie constituée de Hobbits, d’’Hommes, d’’un Magicien, d’’un Nain, et d’’un Elfe, ne parvienne à emporter l’’Anneau à travers la Terre du Milieu jusqu’’à la Crevasse du Destin, lieu où il a été forgé, et à le détruire pour toujours. Un tel périple signifie s’’aventurer très loin en Mordor, les terres du Seigneur des ténèbres, où est rassemblée son armée d’’Orques maléfiques...', 
3);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR)  
Values (
'Terminator', 1985, 3, 108, 3, 'http://image.tmdb.org/t/p/w1280/q8ffBuxQlYOHrvPniLgCbmKK4Lv.jpg', 
'A Los Angeles en 1984, un Terminator, cyborg surgi du futur, a pour mission d''exécuter Sarah Connor, une jeune femme dont l''enfant à naître doit sauver l''humanité. Kyle Reese, un résistant humain, débarque lui aussi pour combattre le robot, et aider la jeune femme...', 
4);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR)  
Values (
'L''Exorciste', 1974, 4, 122, 3, 'http://image.tmdb.org/t/p/w1280/4ucLGcXVVSVnsfkGtbLY4XAius8.jpg', 
'En Irak, le Père Merrin est profondément troublé par la découverte d’’une figurine du démon Pazuzu et les visions macabres qui s’’ensuivent.
Parallèlement, à Washington, la maison de l’’actrice Chris MacNeil est troublée par des phénomènes étranges : celle-ci est réveillée par des grattements mystérieux provenant du grenier, tandis que sa fille Regan se plaint que son lit bouge. Quelques jours plus tard, une réception organisée par Chris est troublée par l’’arrivée de Regan, qui profère des menaces de mort à l’’encontre du réalisateur Burke Dennings. Les crises se font de plus en plus fréquentes. En proie à des spasmes violents, l’’adolescente devient méconnaissable. Chris fait appel à un exorciste. L’’Eglise autorise le Père Damien Karras à officier en compagnie du Père Merrin. Une dramatique épreuve de force s’’engage alors pour libérer Regan.', 
5);

INSERT INTO FILM(F_TITLE, F_YEAR, ID_GENRE, F_LENGTH, F_RATINGS, F_POSTER, F_SYNOPSIS, ID_REALISATEUR) 
Values (
'Pretty Woman', 1990, 5, 119, 3, 'http://image.tmdb.org/t/p/w1280/fgmdaCMxXClZm2ePteLzCPySB1n.jpg', 
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
