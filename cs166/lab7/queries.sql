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
