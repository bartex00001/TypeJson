#pragma once

#include <BetterJson/Parser.hpp>
#include <BetterJson/JsonTypes/Json.hpp>
#include <BetterJson/JsonTypes/Object.hpp>
#include <BetterJson/JsonTypes/Array.hpp>
#include <BetterJson/MemoryPool.hpp>


namespace json
{

template< typename T >
T& Json::as()
{
    return *dynamic_cast< T* >(this);
}

Json& Json::operator[](const std::string& key)
{
    return as< Object >()[key];
}


// template< typename T >
// Json::operator T&()
// {
//     return as< T >();
// }

}
