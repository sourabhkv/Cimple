CREATE TABLE PUBLISHER
(NAME VARCHAR (20),
PHONE varchar(10),
ADDRESS VARCHAR (20),
CONSTRAINT PKP PRIMARY KEY(NAME));

CREATE TABLE BOOK
(BOOK_ID VARCHAR(8),
TITLE VARCHAR (20),
PUBLISHER_NAME VARCHAR(20),
PUB_YEAR INTEGER,
CONSTRAINT PKB PRIMARY KEY(BOOK_ID),
CONSTRAINT FKB FOREIGN KEY(PUBLISHER_NAME) REFERENCES PUBLISHER(NAME));

CREATE TABLE BOOK_AUTHORS
(BOOK_ID VARCHAR(8),
AUTHOR_NAME VARCHAR (20),
CONSTRAINT PKBA PRIMARY KEY (BOOK_ID,AUTHOR_NAME),
CONSTRAINT FKBA FOREIGN KEY(BOOK_ID) REFERENCES BOOK(BOOK_ID)ON DELETE CASCADE);

CREATE TABLE LIBRARY_PROGRAMME
(PROGRAMME_ID VARCHAR(6),
PROGRAMME_NAME VARCHAR (20),
ADDRESS VARCHAR (20),
CONSTRAINT PKLB PRIMARY KEY(PROGRAMME_ID));

CREATE TABLE BOOK_COPIES
(BOOK_ID VARCHAR(8),
PROGRAMME_ID VARCHAR(6),
NO_OF_COPIES INTEGER,
CONSTRAINT PKBC PRIMARY KEY(BOOK_ID, PROGRAMME_ID),
CONSTRAINT FKBC FOREIGN KEY(BOOK_ID) REFERENCES BOOK(BOOK_ID) ON DELETE CASCADE,
CONSTRAINT FKBB FOREIGN KEY(PROGRAMME_ID) REFERENCES LIBRARY_PROGRAMME (PROGRAMME_ID));

CREATE TABLE BOOK_LENDING
(BOOK_ID VARCHAR(8),
PROGRAMME_ID VARCHAR(6),
CARD_NO INTEGER,
DATE_OUT DATE,
DUE_DATE DATE,
CONSTRAINT PKBL PRIMARY KEY(BOOK_ID, PROGRAMME_ID,CARD_NO),
CONSTRAINT FKBL FOREIGN KEY(BOOK_ID) REFERENCES BOOK(BOOK_ID)ON DELETE CASCADE);



INSERT INTO PUBLISHER VALUES ('MCGRAW HILL', 9989076587, 'BANGALORE');
INSERT INTO PUBLISHER VALUES ('PEARSON', 9889076565, 'NEWDELHI');
INSERT INTO PUBLISHER VALUES ('RANDOM HOUSE', 7455679345, 'HYDRABAD');
INSERT INTO PUBLISHER VALUES ('HACHETTE LIVRE', 8970862340, 'CHENAI');
INSERT INTO PUBLISHER VALUES ('GRUPO PLANETA', 7756120238, 'BANGALORE');

SELECT * FROM PUBLISHER;


INSERT INTO BOOK VALUES ('1','DBMS', 'MCGRAW HILL',2017);
INSERT INTO BOOK VALUES ('2','ADBMS', 'MCGRAW HILL',2016);
INSERT INTO BOOK VALUES ('3','CN', 'PEARSON',2016);
INSERT INTO BOOK VALUES ('4','CG', 'GRUPO PLANETA',2015);
INSERT INTO BOOK VALUES ('5','OS', 'PEARSON',2016);
SELECT * FROM BOOK;

INSERT INTO BOOK_AUTHORS VALUES ('1','NAVATHE');
INSERT INTO BOOK_AUTHORS VALUES ('2','NAVATHE');
INSERT INTO BOOK_AUTHORS VALUES ('3','TANENBAUM');
INSERT INTO BOOK_AUTHORS VALUES ('4','EDWARD ANGEL');
INSERT INTO BOOK_AUTHORS VALUES ('5','GALVIN');

SELECT * FROM BOOK_AUTHORS ;

INSERT INTO LIBRARY_PROGRAMME VALUES ('10','VV PURAM','BANGALORE');
INSERT INTO LIBRARY_PROGRAMME VALUES ('11','BIT','BANGALORE');
INSERT INTO LIBRARY_PROGRAMME VALUES ('12','RAJAJI NAGAR', 'BANGALORE');
INSERT INTO LIBRARY_PROGRAMME VALUES ('13','JP NAGAR','BANGALORE');
INSERT INTO LIBRARY_PROGRAMME VALUES ('14','JAYANAGAR','BANGALORE');

INSERT INTO BOOK_COPIES VALUES ( '1','10', 10);
INSERT INTO BOOK_COPIES VALUES ( '1','11', 5);
INSERT INTO BOOK_COPIES VALUES ( '2','12', 2);
INSERT INTO BOOK_COPIES VALUES ( '2','13', 5);
INSERT INTO BOOK_COPIES VALUES ( '3','14', 7);
INSERT INTO BOOK_COPIES VALUES ( '5','10', 1);
INSERT INTO BOOK_COPIES VALUES ( '4','11', 3);

SELECT * FROM BOOK_COPIES;

INSERT INTO BOOK_LENDING VALUES ('1', '10', 101, '01-01-17', '01-06-17');
INSERT INTO BOOK_LENDING VALUES ('3', '14', 101, '11-01-17', '11-03-17');
INSERT INTO BOOK_LENDING VALUES ('2', '13', 101, '21-02-17', '21-04-17');
INSERT INTO BOOK_LENDING VALUES ('4', '11', 101, '15-03-17', '15-07-17');
INSERT INTO BOOK_LENDING VALUES ('1', '11', 104, '12-04-17', '12-05-17');



SELECT * FROM BOOK_LENDING;


SELECT B.BOOK_ID, B.TITLE, B.PUBLISHER_NAME, A.AUTHOR_NAME,
C.NO_OF_COPIES, L.PROGRAMME_ID
FROM BOOK B, BOOK_AUTHORS A, BOOK_COPIES C, LIBRARY_PROGRAMME L
WHERE B.BOOK_ID=A.BOOK_ID
AND B.BOOK_ID=C.BOOK_ID
AND L.PROGRAMME_ID=C.PROGRAMME_ID;


SELECT B.CARD_NO
FROM BOOK_LENDING B
WHERE DATE_OUT BETWEEN '01-01-2017' AND '01-06-2018'
GROUP BY CARD_NO
HAVING COUNT(*)>3;

CREATE TABLE BOOKPART
PARTITION BY RANGE(PUB_YEAR)
(PARTITION P1 VALUES LESS THAN (2016),
PARTITION P2 VALUES LESS THAN (MAXVALUE))
AS
SELECT * FROM BOOK;

SELECT * FROM BOOKPART partition (P2);