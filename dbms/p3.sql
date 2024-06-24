CREATE TABLE ACTOR (ACT_ID NUMBER (3), ACT_NAME VARCHAR (20), ACT_GENDER CHAR (1), CONSTRAINT PKAC PRIMARY KEY(ACT_ID));
CREATE TABLE DIRECTOR(
DIR_ID NUMBER (3), DIR_NAME VARCHAR (20), DIR_PHONE NUMBER (10), CONSTRAINT PKDI PRIMARY KEY(DIR_ID));
CREATE TABLE MOVIES (
MOV_ID NUMBER (4),
MOV_TITLE VARCHAR (25), MOV_YEAR NUMBER (4), MOV_LANG VARCHAR (12), DIR_ID NUMBER (3), CONSTRAINT PKMV PRIMARY KEY(MOV_ID), CONSTRAINT FKMV FOREIGN KEY(DIR_ID) REFERENCES DIRECTOR(DIR_ID))

CREATE TABLE MOVIE_CAST (
ACT_ID NUMBER (3), MOV_ID NUMBER (4), ROLE VARCHAR (10), CONSTRAINT PKMC PRIMARY KEY(ACT_ID, MOV_ID), CONSTRAINT FKMC FOREIGN KEY(ACT_ID) REFERENCES ACTOR(ACT_ID), CONSTRAINT FKMCC FOREIGN KEY(MOV_ID) REFERENCES MOVIES(MOV_ID));
CREATE TABLE RATING (
MOV_ID NUMBER (4), REV_STARS INTEGER, CONSTRAINT FKRA FOREIGN KEY(MOV_ID) REFERENCES MOVIES(MOV_ID));
INSERT INTO ACTOR VALUES (301,'ANUSHKA','F');
INSERT INTO ACTOR VALUES (302,'PRABHAS','M');
INSERT INTO ACTOR VALUES (303,'ARAVIND','M');
INSERT INTO ACTOR VALUES (304,'JERMY','M');
INSERT INTO ACTOR VALUES (305,'KIM NEWMEN','M');
SELECT * FROM ACTOR;

INSERT INTO DIRECTOR VALUES (60,'RAJAMOULI', 8751611001);
INSERT INTO DIRECTOR VALUES (61,'HITCHCOCK', 7766138911);
INSERT INTO DIRECTOR VALUES (62,'FARAN', 9986776531);
INSERT INTO DIRECTOR VALUES (63,'STEVEN SPIELBERG', 8989776530);
INSERT INTO DIRECTOR VALUES (64,'MAHESH', 8989776539);
SELECT * FROM DIRECTOR;

INSERT INTO MOVIES VALUES (1001,'BAHUBALI-2', 2017, 'TELAGU', 60);
INSERT INTO MOVIES VALUES (1002,'BAHUBALI-1', 2015, 'TELAGU', 60);
INSERT INTO MOVIES VALUES (1003,'PSYCHO', 2008, 'ENGLISH', 61);
INSERT INTO MOVIES VALUES (1004,'WAR HORSE', 2011, 'ENGLISH', 63);
INSERT INTO MOVIES VALUES (1005,'LAST BUS', 2016, 'KANNADA', 64);
INSERT INTO MOVIES VALUES (1006,'THE BIRDS', 2011, 'ENGLISH', 61);
INSERT INTO MOVIES VALUES (1007,'TITANIC', 2012, 'ENGLISH', 63);
SELECT * FROM MOV;

INSERT INTO MOVIE_CAST VALUES (301, 1002, 'HEROINE');
INSERT INTO MOVIE_CAST VALUES (301, 1001, 'HEROINE');
INSERT INTO MOVIE_CAST VALUES (303, 1005, 'HERO');
INSERT INTO MOVIE_CAST VALUES (302, 1002, 'HERO');
INSERT INTO MOVIE_CAST VALUES (302, 1001, 'HERO');
INSERT INTO MOVIE_CAST VALUES (304, 1004, 'HERO');
INSERT INTO MOVIE_CAST VALUES (305, 1005, 'HERO');
INSERT INTO MOVIE_CAST VALUES (305, 1007, 'HERO');
SELECT * FROM MOVIE_CAST;

INSERT INTO RATING VALUES (1001, 4);
INSERT INTO RATING VALUES (1002, 2);
INSERT INTO RATING VALUES (1003, 5);
INSERT INTO RATING VALUES (1004, 4);
INSERT INTO RATING VALUES (1005, 3);
INSERT INTO RATING VALUES (1006, 8);
INSERT INTO RATING VALUES (1007, 0);
INSERT INTO RATING VALUES (1001, 2);
INSERT INTO RATING VALUES (1002, 5);

SELECT * FROM RATING;

#1
SELECT M.MOV_TITLE
FROM MOVIES M,DIRECTOR D
WHERE M.DIR_ID=D.DIR_ID AND D.DIR_NAME = 'HITCHCOCk';


#2
SELECT MOV_TITLE
FROM MOVIES M, MOVIE_CAST MV
WHERE M.MOV_ID=MV.MOV_ID AND ACT_ID IN (SELECT ACT_ID
FROM MOVIE_CAST GROUP BY ACT_ID
HAVING COUNT (ACT_ID)>=1)
GROUP BY MOV_TITLE
HAVING COUNT (*)>1;

#3
SELECT A.ACT_NAME
FROM ACTOR A
JOIN MOVIE_CAST C
ON A.ACT_ID=C.ACT_ID
JOIN MOVIES M
ON C.MOV_ID=M.MOV_ID
WHERE M.MOV_YEAR NOT BETWEEN 2000 AND 2015;

#4
SELECT MOV_TITLE, MAX(REV_STARS)
FROM MOVIES
INNER JOIN RATING USING (MOV_ID)
GROUP BY MOV_TITLE
HAVING MAX (REV_STARS)>0
ORDER BY MOV_TITLE;

#5
UPDATE RATING
SET REV_STARS=5
WHERE MOV_ID IN (SELECT M.MOV_ID FROM MOVIES M,DIRECTOR D
WHERE M.DIR_ID=D.DIR_ID AND
D.DIR_NAME = 'STEVEN SPIELBERG');

#before
SELECT * FROM RATING;

#after
SELECT * FROM RATING;