#include "generated-query.h"
#include <iostream>


int main()
{
	SQL_QUERY(ReadRdbRelations, R"""(
		select rdb$relation_id, rdb$relation_name
			from rdb$relations
	)""") query;

	query.forEach([](auto&& fields) {
		std::cout << fields.RDB$RELATION_ID.asShort() << ", " << fields.RDB$RELATION_NAME.asString() << std::endl;

		// Query above matches the generated one, so cannot access fields with wrong types
		// std::cout << fields.RDB$RELATION_ID.asString() << std::endl;
	});

	return 0;
}
