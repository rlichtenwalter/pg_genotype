#include <postgres.h>
#include <fmgr.h>
#include <stdint.h>
#include <stdio.h>

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1( genotype_in );
Datum genotype_in( PG_FUNCTION_ARGS ) {
	char* str;
	char allele1;
	char allele2;
	char genotype;
	str = PG_GETARG_CSTRING( 0 );
	if( sscanf( str, "%c%c", &allele1, &allele2 ) != 2 ) {
		ereport( ERROR, (errcode(ERRCODE_INVALID_TEXT_REPRESENTATION),errmsg("invalid input syntax for genotype: \"%s\"", str)) );
	}
	if(
			(allele1 != 'A' && allele1 != 'C' && allele1 != 'G' && allele1 != 'T' && allele1 != 'I' && allele1 != 'D') ||
			(allele2 != 'A' && allele2 != 'C' && allele2 != 'G' && allele2 != 'T' && allele2 != 'I' && allele2 != 'D') ) {
		ereport( ERROR, (errcode(ERRCODE_INVALID_TEXT_REPRESENTATION),errmsg("invalid input syntax for genotype: \"%s\"", str)) );
	}
	if( allele1 == 'T' ) {
		allele1 = 'O';
	}
	if( allele2 == 'T' ) {
		allele2 = 'O';
	}
	genotype = (allele1 << 4) | (allele2 & 0x0f);
	PG_RETURN_CHAR( genotype );
}

PG_FUNCTION_INFO_V1( genotype_out );
Datum genotype_out( PG_FUNCTION_ARGS ) {
	char genotype;
	char allele1;
	char allele2;
	char* result;
	genotype = PG_GETARG_CHAR( 0 );
	allele1 = ((uint8_t)genotype >> 4) | 0x40;
	allele2 = (genotype & 0x0f) | 0x40;
	if( allele1 == 'O' ) {
		allele1 = 'T';
	}
	if( allele2 == 'O' ) {
		allele2 = 'T';
	}
	result = psprintf( "%c%c", allele1, allele2);
	PG_RETURN_CSTRING( result );
}
