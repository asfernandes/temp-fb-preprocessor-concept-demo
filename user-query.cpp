#include "generated-query.h"
#include <iostream>


int main()
{
	SQL_QUERY(ReadRdbRelations, R"""(
		select rdb$relation_id, rdb$relation_name, rdb$system_flag
			from rdb$relations
	)""") query;

	query.forEach([](auto&& fields) {
		std::cout << fields.RDB$RELATION_ID.asShort() << ", " << fields.RDB$RELATION_NAME.asString() << ", " <<
			fields.RDB$SYSTEM_FLAG.asShort() << std::endl;

		// Query was re-preprocessed, so can not access fields with wrong type
		// std::cout << fields.RDB$RELATION_ID.asString() << std::endl;
	});

	return 0;
}
