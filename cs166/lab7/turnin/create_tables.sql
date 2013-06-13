drop table part_nyc;
create table part_nyc (part_number integer, 
                       supplier integer, 
                       color integer, 
                       on_hand integer, 
                       desct text); 
                       
drop table part_sfo;
create table part_sfo (part_number integer, 
                       supplier integer,
                       color integer, 
                       on_hand integer, 
                       desct text); 

drop table supplier; 
create table supplier (supplier_id integer,
                       supplier_name varchar(20));

insert into supplier values (0, 'Bob');
insert into supplier values (1, 'Ted');
insert into supplier values (2, 'Carol');
insert into supplier values (3, 'Alice');
insert into supplier values (4, 'Jerry');
insert into supplier values (5, 'Mickey');
insert into supplier values (6, 'Phil');
insert into supplier values (7, 'Vince');
insert into supplier values (8, 'Bill');
insert into supplier values (9, 'Donna');

                       
drop table color; 
create table color (color_id integer, 
                    color_name varchar(20));

insert into color values (0, 'Red'); 
insert into color values (1, 'Green');

--Copy the tables from the lab7.zip
COPY part_nyc (part_number,supplier,color,on_hand,desct)

FROM '/home/csmajs/wongc/Desktop/cs166/lab7/part_nyc.dat'

WITH DELIMITER ',';


COPY part_sfo (part_number,supplier,color,on_hand,desct)

FROM '/home/csmajs/wongc/Desktop/cs166/lab7/part_sfo.dat'

WITH DELIMITER ',';

--Create indexes
CREATE INDEX s1
ON supplier(supplier_id);

CREATE INDEX nyc1
ON part_nyc(color);

CREATE INDEX nyc2
ON part_nyc(on_hand);

CREATE UNIQUE INDEX nyc3
ON part_nyc(part_number);

CREATE INDEX sfo1
ON part_nyc(color);

CREATE INDEX sfo2
ON part_sfo(on_hand);

CREATE UNIQUE INDEX sfo3
ON part_sfo(part_number);


--Start my sql quries
--1. How many parts in NYC have more than 70 parts on_hand?
SELECT COUNT(N.part_number)
FROM part_nyc N
WHERE N.on_hand > 70;

--2.How many total parts on_hand, in both NYC and SFO, are Red?
SELECT (SELECT COUNT(N.on_hand) FROM part_nyc N WHERE N.color = 1) + 
(SELECT COUNT(S.on_hand) FROM part_sfo S WHERE S.color = 1);

--3.List all the suppliers that have more total on_hand parts in NYC than they do in SFO.
--4.List all suppliers that supply parts in NYC that aren't supplied by anyone in SFO.

--5.Update all of the NYC on_hand values to on_hand - 10.
UPDATE part_nyc
SET on_hand = 10;

--6.Delete all parts from NYC where there are less than 30 on_hand.
DELETE FROM part_nyc 
WHERE on_hand < 30;
