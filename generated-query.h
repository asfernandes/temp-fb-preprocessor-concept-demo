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
	};

public:
	class Query : public BaseQuery<Fields>
	{
	public:
	};
};
