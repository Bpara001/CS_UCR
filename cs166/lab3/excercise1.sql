RESTRICT=No ACTION=defualt

CREATE TABLE Professor (ssn INTEGER NOT NULL,
						name text,
						age INTEGER,
						rank text,
						specialty text,
						PRIMARY KEY(ssn)
						ON DELETE NO ACTION
						));

CREATE TABLE Dept ( dno INTEGER NOT NULL,
					dname text,
					office text,
					ssn INTEGER,
					PRIMARY KEY(dno)
					FOREIGN KEY (ssn) REFERENCES Professor(ssn)
					ON DELETE NO ACTION
					));
					
					
CREATE TABLE Project (  pno INTEGER NOT NULL,
						sponser text,
						start_date DATE,
						end_date DATE,
						budget FLOAT,
						PRIMARY KEY(pno)
						ON DELETE NO ACTION
						));
						
CREATE TABLE Graduate(	ssn INTEGER NOT NULL,
						name text,
						age INTEGER,
						deg_pg text,
						PRIMARY KEY(snn)
						ON DELETE NO ACTION
						));



CREATE TABLE work_dept(	ssn INTEGER NOT NULL,
					duno INTEGER NOT NULL,
					time_pc FLOAT,
					PRIMARY KEY(ssn,dno),
					FOREIGN KEY (ssn) REFERENCES Professor(ssn),
					FOREIGN KEY (dno) REFERENCES Dept(dno)
					));
					
CREATE TABLE runs(	ssn INTEGER NOT NULL,
					duno INTEGER NOT NULL,
					PRIMARY KEY(ssn,dno),
					FOREIGN KEY (ssn) REFERENCES Professor(ssn),
					FOREIGN KEY (dno) REFERENCES Dept(dno)
					));
