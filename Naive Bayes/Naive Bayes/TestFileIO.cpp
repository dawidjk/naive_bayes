//
//  TestFileIO.cpp
//  Naive Bayes
//
//  Created by David Kluszczynski on 3/26/19.
//  Copyright © 2019 David Kluszczynski. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "Catch2.hpp"
#include "FileIO.hpp"
#include <string>

TEST_CASE( "Open Read File Successfully", "[FileIO]" ) {
    FileIO file_io;
    REQUIRE( file_io.OpenFileRead("/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/trainingimages") );
}

TEST_CASE( "Open Read File Fail", "[FileIO]" ) {
    FileIO file_io;
    REQUIRE( !file_io.OpenFileRead("/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/doesnotexist") );
}

TEST_CASE( "File Is Open", "[FileIO]" ) {
    FileIO file_io;
    file_io.OpenFileWrite ("/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/training_fake");
    REQUIRE( file_io.GetWriteFile().is_open() );
}

TEST_CASE( "Open Write File Successfully", "[FileIO]" ) {
    std::string file = "/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/fake_file";
     std::remove("/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/fake_file");
    
    FileIO file_io;
    REQUIRE( file_io.OpenFileWrite(file) );
    REQUIRE( file_io.OpenFileRead(file) );
}

TEST_CASE( "Read First Line Correctly", "[FileIO]" ) {
    FileIO file_io;
    file_io.OpenFileRead("/Users/dave07747/Documents/CS126/naivebayes-dawidjk/digitdata/traininglabels");
    REQUIRE( file_io.ReadLine() == "5");
}
