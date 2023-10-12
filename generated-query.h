#pragma once

#include "framework.h"


template <StringLiteral USER_SQL>
class ReadRdbRelations
{
private:
	static constexpr StringLiteral GENERATED_SQL = R"""(
		select rdb$relation_id, rdb$relation_name
			from rdb$relations
	)""";

private:
	template <typename T>
	using ThisFieldSelector = FieldSelector<USER_SQL, GENERATED_SQL, T>;

public:
	struct Fields
	{
		ThisFieldSelector<int16_t> RDB$RELATION_ID;
		ThisFieldSelector<std::string> RDB$RELATION_NAME;
		// Field added manually. Type does not matter (as GENERATED_SQL differs from USER_SQL)
		// and here was purposely used incorrectly.
		ThisFieldSelector<std::string> RDB$SYSTEM_FLAG;
	};

public:
	class Query : public BaseQuery<Fields>
	{
	public:
	};
};
