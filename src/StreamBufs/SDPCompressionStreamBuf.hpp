/*
Copyright 2014 Alex Frappier Lachapelle

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef SDPCOMPRESSIONSTREAMBUF_H
#define SDPCOMPRESSIONSTREAMBUF_H

#include <cstdio>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

#include "zlib.h"

#include "src/RawFileIO.hpp"
#include "src/StreamBufs/AlgorithmBase/SDPCompressionAlgorithmBase.hpp"
#include "src/StreamBufs/DefaultAlgorithms/SDPZlibCompressionAlgorithm.hpp"

//FIXME?: use of >> in a istream causes an error and to prematurely return eof.
//TODO: MAJOR Cleanup!
//TODO: implement xsgetn() xsputn()
//TODO: implement seeking
//TODO? (DONE) (UNTESTED): Make compression algorithms modular
//TODO?: make block size/block overuse user defined

class SDPCompressionStreamBuf : public std::streambuf{

public:

    //Vars

    struct SDPCompressionOptions{
        SDPCompressionAlgorithmBase *compressionAlgorithm;
        uint_least64_t blockSize;
        uint_least64_t blockSizeWithOverhead;
    };


    //Funcs
    SDPCompressionStreamBuf(std::istream *compressedIn);
    SDPCompressionStreamBuf(std::ostream *compressedOut);
    ~SDPCompressionStreamBuf();

    void SDPSetCompressionOptions(SDPCompressionOptions compressionOptions);


protected:

    virtual int_type overflow(int_type ch = traits_type::eof());

    virtual int_type underflow();
    virtual int_type uflow();
    virtual int_type pbackfail(int_type ch);

    virtual int sync();


private:

    //Vars
    //uint_least64_t blockSize = 1024*64;

    unsigned char nextChar;

    bool hasFirstBlockBeenRead;

    std::vector<unsigned char>::iterator bufferIterator;
    std::vector<unsigned char>           uncompressedBuffer;
    std::vector<unsigned char>           compressedBuffer;

    std::istream *inStream;
    std::ostream *outStream;

    SDPZlibCompressionAlgorithm defaultCompressionAlgorithm;

    SDPCompressionOptions compressionOptions;

    //Funcs

    int  getNextChar(bool doAdvance);
    int_type setNextChar(int_type ch);

};


#endif // SDPCOMPRESSIONSTREAMBUF_H














