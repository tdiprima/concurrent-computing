/*=========================================================================
*
*  Copyright Insight Software Consortium
*
*  Bradley Lowekamp
*  In SimpleITK I use this same header, I wrote a little wrapper which may be useful:
*
*  https://github.com/SimpleITK/SimpleITK/blob/next/Code/Common/include/nsstd/unordered_map.h
*
*=========================================================================*/
#ifndef sitk_nsstd_unordered_map_h
#define sitk_nsstd_unordered_map_h

#include "sitkConfigure.h"

#if !defined SITK_HAS_TR1_UNORDERED_MAP && !defined SITK_HAS_CXX11_UNORDERED_MAP
#error "No system (tr1/c++11) unordered_map header available!"
#endif


#if defined SITK_HAS_CXX11_UNORDERED_MAP && !defined SITK_HAS_TR1_SUB_INCLUDE
#include <unordered_map>
#elif
#include <tr1/unordered_map>
#endif

namespace itk
{
namespace simple
{
namespace nsstd
{
#if defined SITK_HAS_TR1_UNORDERED_MAP && !defined SITK_HAS_CXX11_UNORDERED_MAP
using std::tr1::unordered_map;
#else
using std::unordered_map;
#endif
}
}
}


#endif // sitk_nsstd_unordered_map_h
