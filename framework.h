#pragma once

#include <algorithm>
#include <functional>
#include <string>
#include <cstdint>


#define SQL_QUERY(name, sql) name<sql>::Query


template <size_t N>
struct StringLiteral
{
	constexpr StringLiteral(const char (&str)[N])
	{
		std::copy_n(str, N, value);
	}

	char value[N];
};


struct GenericFieldTag {};


template <typename T>
class Field
{};

template <>
class Field<int16_t>
{
public:
	int16_t asShort()
	{
		return 0;
	}
};

template <>
class Field<std::string>
{
public:
	std::string asString()
	{
		return {};
	}
};

template <>
class Field<GenericFieldTag>
{
public:
	int16_t asShort()
	{
		return 0;
	}

	std::string asString()
	{
		return {};
	}
};


template <StringLiteral USER_SQL, StringLiteral GENERATED_SQL, typename T>
using FieldSelector =
	Field<
		std::conditional_t<
			std::equal(
				std::begin(USER_SQL.value), std::end(USER_SQL.value),
				std::begin(GENERATED_SQL.value), std::end(GENERATED_SQL.value)
			),
			T,
			GenericFieldTag
		>
	>;


template <typename Fields>
class BaseQuery
{
public:
	void forEach(std::function<void (Fields&)> callback)
	{
		callback(fields);
	}

private:
	Fields fields;
};
