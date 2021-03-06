/*
Copyright 2015 Alex Frappier Lachapelle

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

#include "Utils/RawFileIO.hpp"

using namespace libSDP;
using namespace libSDP::Utils;

RawFileIO::RawFileIO() : isSysBigEndian(endian.isSysBigEndian()){}
RawFileIO::~RawFileIO(){}


//no need to swap bytes, there's only one.
size_t RawFileIO::read(uint8 &val, std::shared_ptr<std::istream> inStream){

    uint8 tmpUint8;
    inStream.get()->read(reinterpret_cast<char*> (&tmpUint8), 1);

    val = tmpUint8;

    return (size_t)inStream.get()->gcount();
}

size_t RawFileIO::read(uint16 &val, std::shared_ptr<std::istream> inStream, Endian fileEndian){

    uint16 tmpUint16;
    inStream.get()->read(reinterpret_cast<char*> (&tmpUint16), 2);

    if(isFileAndSysEndianSame(fileEndian)){
        val = tmpUint16;
    }else{
        val = endian.byteSwap(tmpUint16);
    }

    return (size_t)inStream.get()->gcount();
}

size_t RawFileIO::read(uint32 &val, std::shared_ptr<std::istream> inStream, Endian fileEndian){

    uint32 tmpUint32;
    inStream.get()->read(reinterpret_cast<char*> (&tmpUint32), 4);

    if(isFileAndSysEndianSame(fileEndian)){
        val = tmpUint32;
    }else{
        val = endian.byteSwap(tmpUint32);
    }

    return (size_t)inStream.get()->gcount();
}

size_t RawFileIO::read(uint64 &val, std::shared_ptr<std::istream> inStream, Endian fileEndian){

    uint64 tmpUint64;
    inStream.get()->read(reinterpret_cast<char*> (&tmpUint64), 8);

    if(isFileAndSysEndianSame(fileEndian)){
        val = tmpUint64;
    }else{
        val = endian.byteSwap(tmpUint64);
    }

    return (size_t)inStream.get()->gcount();
}


size_t RawFileIO::read(uint8  &val, std::shared_ptr<SDPSourceSinkBase> sourceSink){

    uint8 tmpUint8;
    sourceSink.get()->read(reinterpret_cast<uchar*> (&tmpUint8), 1);

    val = tmpUint8;

    return (size_t)sourceSink.get()->getReadCount();
}

size_t RawFileIO::read(uint16 &val, std::shared_ptr<SDPSourceSinkBase> sourceSink, Endian fileEndian){

    uint16 tmpUint16;
    sourceSink.get()->read(reinterpret_cast<uchar*> (&tmpUint16), 2);

    if(isFileAndSysEndianSame(fileEndian)){
        val = tmpUint16;
    }else{
        val = endian.byteSwap(tmpUint16);
    }

    return (size_t)sourceSink.get()->getReadCount();
}

size_t RawFileIO::read(uint32 &val, std::shared_ptr<SDPSourceSinkBase> sourceSink, Endian fileEndian){

    uint32 tmpUint32;
    sourceSink.get()->read(reinterpret_cast<uchar*> (&tmpUint32), 4);

    if(isFileAndSysEndianSame(fileEndian)){
        val = tmpUint32;
    }else{
        val = endian.byteSwap(tmpUint32);
    }

    return (size_t)sourceSink.get()->getReadCount();
}

size_t RawFileIO::read(uint64 &val, std::shared_ptr<SDPSourceSinkBase> sourceSink, Endian fileEndian){

    uint64 tmpUint64;
    sourceSink.get()->read(reinterpret_cast<uchar*> (&tmpUint64), 8);

    if(isFileAndSysEndianSame(fileEndian)){
        val = tmpUint64;
    }else{
        val = endian.byteSwap(tmpUint64);
    }

    return (size_t)sourceSink.get()->getReadCount();
}



void RawFileIO::write(uint8 &val, std::shared_ptr<std::ostream> outStream){
    outStream.get()->write(reinterpret_cast<const char*> (&val), 1);
}

void RawFileIO::write(uint16 &val, std::shared_ptr<std::ostream> outStream, Endian fileEndian){

    if(isFileAndSysEndianSame(fileEndian)){
        outStream.get()->write(reinterpret_cast<const char*> (&val), sizeof val);
    }else{
        uint16 tmp = endian.byteSwap(val);
        outStream.get()->write(reinterpret_cast<const char*> (&tmp), sizeof val);
    }
}

void RawFileIO::write(uint32 &val, std::shared_ptr<std::ostream> outStream, Endian fileEndian){

    if(isFileAndSysEndianSame(fileEndian)){
        outStream.get()->write(reinterpret_cast<const char*> (&val), 4);
    }else{
        uint32 tmp = endian.byteSwap(val);
        outStream.get()->write(reinterpret_cast<const char*> (&tmp), sizeof val);
    }
}

void RawFileIO::write(uint64 &val, std::shared_ptr<std::ostream> outStream, Endian fileEndian){

    if(isFileAndSysEndianSame(fileEndian)){
        outStream.get()->write(reinterpret_cast<const char*> (&val), 8);
    }else{
        uint64 tmp = endian.byteSwap(val);
        outStream.get()->write(reinterpret_cast<const char*> (&tmp), 8);
    }
}



void RawFileIO::write(uint8  &val, std::shared_ptr<SDPSourceSinkBase> sourceSink){
    sourceSink.get()->write(reinterpret_cast<const uchar*> (&val), 1);
}

void RawFileIO::write(uint16 &val, std::shared_ptr<SDPSourceSinkBase> sourceSink, Endian fileEndian){

    if(isFileAndSysEndianSame(fileEndian)){
        sourceSink.get()->write(reinterpret_cast<const uchar*> (&val), sizeof val);
    }else{
        uint16 tmp = endian.byteSwap(val);
        sourceSink.get()->write(reinterpret_cast<const uchar*> (&tmp), sizeof val);
    }
}

void RawFileIO::write(uint32 &val, std::shared_ptr<SDPSourceSinkBase> sourceSink, Endian fileEndian){

    if(isFileAndSysEndianSame(fileEndian)){
        sourceSink.get()->write(reinterpret_cast<const uchar*> (&val), 4);
    }else{
        uint32 tmp = endian.byteSwap(val);
        sourceSink.get()->write(reinterpret_cast<const uchar*> (&tmp), sizeof val);
    }
}

void RawFileIO::write(uint64 &val, std::shared_ptr<SDPSourceSinkBase> sourceSink, Endian fileEndian){

    if(isFileAndSysEndianSame(fileEndian)){
        sourceSink.get()->write(reinterpret_cast<const uchar*> (&val), 8);
    }else{
        uint64 tmp = endian.byteSwap(val);
        sourceSink.get()->write(reinterpret_cast<const uchar*> (&tmp), 8);
    }
}



bool RawFileIO::isFileAndSysEndianSame(Endian fileEndian){
    if((isSysBigEndian && fileEndian == BIG__ENDIAN) || (!isSysBigEndian && fileEndian == LITTLE__ENDIAN))
        return true;
    return false;
}
