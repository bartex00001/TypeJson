#pragma once

#include <BetterJson/Prim.hpp>
#include <BetterJson/Allocator.hpp>
#include <BetterJson/File.hpp>
#include <BetterJson/JsonTypes/Json.hpp>    


namespace json
{

template< Allocator TAllocator = DEFAULT_ALLOCATOR>
class Parser
{
	std::reference_wrapper< TAllocator > alloc;
	std::reference_wrapper< File > file;
    bool used{};

	void skipWhitespace();

	void parseString(char*& str);
	void parseObjectValue(ObjKeyValuePair& objKeyVal);
	void parseNumber(PrimVariant& primVariant);

	void parseAnyPrim(PrimVariant& primVariant);

	void parseObject(PrimObject& obj);
	void parseArray(PrimArray& arr);
	void parseString(PrimString& str);
	void parseInt(PrimInt& i, char buffor[], const char* end);
	void parseFloat(PrimFloat& f, char buffor[], const char* end);
	void parseBool(PrimBool& b);
	void parseNull(PrimNull& null);

public:
	Parser(TAllocator& alloc, File& file);
    PrimObject& operator()();
};

}

#include <BetterJson/Implementations/Parser.tpp>