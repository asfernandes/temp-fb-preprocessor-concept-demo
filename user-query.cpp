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

		// Query was changed and not re-preprocessed, so can access
		// fields.RDB$RELATION_ID.asString() or fields.RDB$RELATION_NAME.asShort()
		// as well the new field
	});

	return 0;
}
