// Copyright (c) 2014-2016 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef TAOCPP_JSON_EMBEDDED_PEGTL_INTERNAL_EOLF_HH
#define TAOCPP_JSON_EMBEDDED_PEGTL_INTERNAL_EOLF_HH

#include "skip_control.hh"

#include "../analysis/generic.hh"

#include "eol.hh"

namespace tao_json_pegtl
{
   namespace internal
   {
      struct eolf
      {
         using analyze_t = analysis::generic< analysis::rule_type::OPT >;

         template< typename Input >
         static bool match( Input & in )
         {
            if ( const auto s = in.size() ) {
               return eol::match_impl( in, s );
            }
            return true;
         }
      };

      template<>
      struct skip_control< eolf > : std::true_type {};

   } // internal

} // tao_json_pegtl

#endif
