MODULES = pg_genotype
EXTENSION = pg_genotype
DATA = pg_genotype--1.0.sql
DOCS = README.pg_genotype

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
