// Copyright (c) 2015 Dr. Colin Hirsch
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#include "test.hh"

namespace tao
{
   namespace json
   {
      void test_array()
      {
         const auto v = from_string( "[ null, true, false, 42, 43.0, \"foo\", [ 1, 2, 3 ], { \"a\" : \"b\", \"c\" : \"d\" } ]" );

         TEST_ASSERT( v.type() == type::ARRAY );

         const auto & a = v.get_array();

         TEST_ASSERT( a.size() == 8 );
         TEST_ASSERT( a[ 0 ] == value( nullptr ) );
         TEST_ASSERT( a[ 1 ] == value( true ) );
         TEST_ASSERT( a[ 2 ] == value( false ) );
         TEST_ASSERT( a[ 3 ] == value( 42 ) );
         TEST_ASSERT( a[ 4 ] == value( 43.0 ) );
         TEST_ASSERT( a[ 5 ] == value( "foo" ) );
         TEST_ASSERT( a[ 6 ].type() == type::ARRAY );
         TEST_ASSERT( a[ 6 ].get_array().size() == 3 );
         TEST_ASSERT( a[ 6 ].get_array()[ 0 ] == value( 1 ) );
         TEST_ASSERT( a[ 6 ].get_array()[ 1 ] == value( 2 ) );
         TEST_ASSERT( a[ 6 ].get_array()[ 2 ] == value( 3 ) );
         TEST_ASSERT( a[ 7 ].type() == type::OBJECT );
         TEST_ASSERT( a[ 7 ].get_object().size() == 2 );
         TEST_ASSERT( a[ 7 ].get_object().at("a" ) == "b" );
         TEST_ASSERT( a[ 7 ].get_object().at( "c" ) == "d" );
      }

      void test_object()
      {
         const auto v = from_string( "{ \"a\" : null, \"b\" : true, \"c\" : false, \"d\" : 42, \"e\" : 43.0, \"f\" : \"foo\", \"g\" : [ 1, 2, 3 ], \"h\" : { \"a\" : \"b\", \"c\" : \"d\" } }" );

         TEST_ASSERT( v.type() == type::OBJECT );

         const auto & o = v.get_object();

         TEST_ASSERT( o.size() == 8 );
         TEST_ASSERT( o.at( "a" ) == value( nullptr ) );
         TEST_ASSERT( o.at( "b" ) == value( true ) );
         TEST_ASSERT( o.at( "c" ) == value( false ) );
         TEST_ASSERT( o.at( "d" ) == value( 42 ) );
         TEST_ASSERT( o.at( "e" ) == value( 43.0 ) );
         TEST_ASSERT( o.at( "f" ) == value( "foo" ) );
         TEST_ASSERT( o.at( "g" ).type() == type::ARRAY );
         TEST_ASSERT( o.at( "g" ).get_array().size() == 3 );
         TEST_ASSERT( o.at( "g" ).get_array()[ 0 ] == value( 1 ) );
         TEST_ASSERT( o.at( "g" ).get_array()[ 1 ] == value( 2 ) );
         TEST_ASSERT( o.at( "g" ).get_array()[ 2 ] == value( 3 ) );
         TEST_ASSERT( o.at( "h" ).type() == type::OBJECT );
         TEST_ASSERT( o.at( "h" ).get_object().size() == 2 );
         TEST_ASSERT( o.at( "h" ).get_object().at("a" ) == "b" );
         TEST_ASSERT( o.at( "h" ).get_object().at( "c" ) == "d" );
      }

      void unit_test()
      {
         TEST_ASSERT( from_string( "null" ) == value( nullptr ) );
         TEST_ASSERT( from_string( "42" ) == value( 42 ) );
         TEST_ASSERT( from_string( "42.0" ) == value( 42.0 ) );
         TEST_ASSERT( from_string( "true" ) == value( true ) );
         TEST_ASSERT( from_string( "false" ) == value( false ) );

         test_array();
         test_object();

         // More elaborate tests are performed by the "nativejson benchmarks".
      }

   } // json

} // tao

#include "main.hh"