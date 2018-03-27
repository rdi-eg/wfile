#include <iostream>
#include <string>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rdi_wfile.h"
#include "rdi_ar_letter_definitions.h"
#include "rdi_stl_utils.h"

using namespace std;
using namespace RDI;

string tests_path = get_current_directory() + "../../wfile_tests/";

wstring expected1(S_ALEF_NO_HAMZA + S_LAM + S_SEEN + S_LAM + S_ALEF_NO_HAMZA + S_MEEM + L" " +
                  S_AIN + S_LAM + S_YEH_WITH_DOTS + S_KAF + S_MEEM); //alsalam alaykom
vector<string> expected_directory_content =
{
    "test1",
    "test2",
    "test3"
};

map<string , string> expected2 =
{
    {"NNET3MODEL" , "final.mdl"},
    {"DICTIONARY" , "words.txt"},
    {"GRAPH" , "HCLG.fst"},
    {"WORD_INS_PENALTY" , "5.0"},
    {"ACOUSTIC_SCALE" , "0.1"},
    {"LATTICE_SCALE" , "6.0"},
    {"BEAM" , "15"},
    {"LATTICE_BEAM" , "8.0"},
    {"MAX_ACTIVE" , "7000"},
    {"USING_GPU" , "no"}

};

vector<vector<float>> expected3 =
{
    {1.5 , 5.2 , 6.56},
    {12.5 , 53.2 , 26.56},
    {1.2315 , 52.2 , 36.56}
};

vector<vector<float>> convert_str_to_float(vector<string>&& input){

    vector<float> temp;
    vector<vector<float>> res;

    for(const auto& item :input){
        vector<string> vs = split(item,' ');
        for(const auto& str : vs){
            temp.push_back(stof(str));
        }
        res.push_back(temp);
        temp.clear();
    }

    return res;
}

//TODO: write tests for the rest of the functions especially the appendLine files

TEST_CASE( "Read wstring from file" )
{
    CHECK( read_wfile_lines( tests_path + "test1")[0] == expected1 );
    CHECK_THROWS( read_wfile_lines( tests_path + "kotomoooto")[0] == expected1 );

}

TEST_CASE( "Create Directory" )
{
    CHECK( create_directory( tests_path + "testDirectory/") );
}

TEST_CASE( "Delete Directory" )
{
    CHECK( delete_directory( tests_path + "testDirectory" ) );
}

TEST_CASE( "Create File" )
{
    CHECK( write_file( tests_path + "testFile", "bleh") );
}

TEST_CASE( "Delete File" )
{
   CHECK(delete_file( tests_path + "testFile" ) );
   //CHECK_THROWS(delete_file( tests_path + "testFile" ) );
}

TEST_CASE( "Get Directory Content" )
{
    CHECK( get_directory_content(tests_path) == expected_directory_content );
}

TEST_CASE( "Path Config File")
{
   CHECK( parse_config_file(tests_path + "test2") == expected2);
   CHECK_THROWS( parse_config_file(tests_path + "bolaaa") == expected2);
}

TEST_CASE( "Get Absolute Path" )
{
	CHECK( get_absolute_path("../../wfile_tests/")[0] == '/' );
    CHECK( get_absolute_path("/var") == "/var" );
}

TEST_CASE( "Dump Matrix")
{
    REQUIRE( dump_matrix((tests_path + "test3"), expected3) == true);
    REQUIRE(convert_str_to_float( read_file_lines(tests_path + "test3") ) == expected3);
}

TEST_CASE( "Check If Given Path is a Directory" )
{
    CHECK( is_directory(tests_path) );
    CHECK_FALSE( is_directory(tests_path + "test1") );
    CHECK( is_directory("/usr/lib/") );
}

TEST_CASE( "Get File Name from Path" )
{
    CHECK		( extract_filename("/bin/bash") == "bash" );
    CHECK		( extract_filename("/lib64/ld-linux-x86-64.so.2") == "ld-linux-x86-64.so.2" );
    CHECK_THROWS( extract_filename("/usr/local/lib/") );
    CHECK_THROWS( extract_filename("/usr/local/lib") );
    CHECK		( extract_filename_without_extension("/bin/bash") == "bash" );
    CHECK		( extract_filename_without_extension("/lib64/ld-linux-x86-64.so.2") == "ld-linux-x86-64.so" );
    CHECK_THROWS( extract_filename_without_extension("/usr/local/lib") );
    CHECK_THROWS( extract_filename_without_extension("/usr/local/lib/") );
}

TEST_CASE("Get Path from File Name")
{
	CHECK( extract_path_from_filename("/bin/bash") == "/bin/" );
	CHECK( extract_path_from_filename("/lib64/ld-linux-x86-64.so.2") == "/lib64/" );
	CHECK( extract_path_from_filename("/usr/local/lib/") == "/usr/local/lib/" );
}


