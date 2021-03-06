// Copyright (c) 2014-2015 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/ColinH/PEGTL/

#ifndef TAOCPP_JSON_EMBEDDED_PEGTL_MMAP_PARSER_HH
#define TAOCPP_JSON_EMBEDDED_PEGTL_MMAP_PARSER_HH

#include <string>

#include "parse.hh"
#include "input.hh"
#include "normal.hh"
#include "nothing.hh"

#include "internal/file_mapper.hh"

namespace tao_json_pegtl
{
   class mmap_parser
   {
   public:
      explicit
      mmap_parser( const std::string & filename )
            : m_file( filename ),
              m_source( filename ),
              m_input( 1, 0, m_file.begin(), m_file.end(), m_source.c_str() )
      { }

      mmap_parser( const std::string & filename, const tao_json_pegtl::input & from )
            : m_file( filename ),
              m_source( filename ),
              m_input( 1, 0, m_file.begin(), m_file.end(), m_source.c_str(), & from )
      { }

      const std::string & source() const
      {
         return m_source;
      }

      const tao_json_pegtl::input & input() const
      {
         return m_input;
      }

      template< typename Rule, template< typename ... > class Action = nothing, template< typename ... > class Control = normal, typename ... States >
      bool parse( States && ... st )
      {
         return parse_input< Rule, Action, Control >( m_input, st ... );
      }

   private:
      internal::file_mapper m_file;
      std::string m_source;
      tao_json_pegtl::input m_input;
   };

} // tao_json_pegtl

#endif
