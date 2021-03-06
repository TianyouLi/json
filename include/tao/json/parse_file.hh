// Copyright (c) 2015-2016 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_PARSE_FILE_HH
#define TAOCPP_JSON_INCLUDE_PARSE_FILE_HH

#include <string>
#include <utility>

#include "sax/parse_file.hh"
#include "sax/to_value.hh"

namespace tao
{
   namespace json
   {
      template< template< typename ... > class Traits >
      basic_value< Traits > parse_file( const std::string & filename )
      {
         sax::to_basic_value< Traits > handler;
         sax::parse_file( filename, handler );
         return std::move( handler.value );
      }

      template< template< typename ... > class Traits >
      void parse_file( basic_value< Traits > & output, const std::string & filename )
      {
         output = parse_file< Traits >( filename );
      }

      inline value parse_file( const std::string & filename )
      {
         return parse_file< traits >( filename );
      }

   } // json

} // tao

#endif
