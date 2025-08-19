#pragma once

#include <RED4ext/RTTI/Property.hpp>

namespace RED4ext
{
using CProperty [[deprecated("Use rtti::Property")]] = rtti::Property; 
} // namespace RED4ext

