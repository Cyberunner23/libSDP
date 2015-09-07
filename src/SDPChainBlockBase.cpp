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

#include "SDPChainBlockBase.hpp"

using namespace libSDP;

SDPChainBlockBase::SDPChainBlockBase(std::shared_ptr<SDPChainBlockBase> childChainBlock)
    : childChainBlock(childChainBlock)
    , specReadWrite(nullptr){
    STUB_FUNC(__FILE__, __LINE__)
}

SDPChainBlockBase::SDPChainBlockBase(std::shared_ptr<SDPSpecBase> specReadWrite)
    : childChainBlock(nullptr)
    , specReadWrite(specReadWrite){
    STUB_FUNC(__FILE__, __LINE__)
}

SDPChainBlockBase::~SDPChainBlockBase(){
    STUB_FUNC(__FILE__, __LINE__)
}


bool SDPChainBlockBase::init(){
    INCOMPLETE_FUNC(__FILE__, __LINE__)
    //Assert if they BOTH point to nothing.
    assert(!(childChainBlock == nullptr && specReadWrite == nullptr));
    //Assert if they BOTH point to something.
    assert(!(childChainBlock != nullptr && specReadWrite != nullptr));
    onInit();
    if(childChainBlock != nullptr)
        childChainBlock.get()->init();
    if(specReadWrite != nullptr){
        //TODO: call appropriate func for specReadWrite.
    }
}

void SDPChainBlockBase::sync(){
    INCOMPLETE_FUNC(__FILE__, __LINE__)
    //Assert if they BOTH point to nothing.
    assert(!(childChainBlock == nullptr && specReadWrite == nullptr));
    //Assert if they BOTH point to something.
    assert(!(childChainBlock != nullptr && specReadWrite != nullptr));
    onSync();
    if(childChainBlock != nullptr)
        childChainBlock.get()->sync();
    if(specReadWrite != nullptr){
        //TODO: call appropriate func for specReadWrite.
    }
}

void SDPChainBlockBase::exit(){
    INCOMPLETE_FUNC(__FILE__, __LINE__)
    //Assert if they BOTH point to nothing.
    assert(!(childChainBlock == nullptr && specReadWrite == nullptr));
    //Assert if they BOTH point to something.
    assert(!(childChainBlock != nullptr && specReadWrite != nullptr));
    onExit();
    if(childChainBlock != nullptr)
        childChainBlock.get()->exit();
    if(specReadWrite != nullptr){
        //TODO: call appropriate func for specReadWrite.
    }
}



bool SDPChainBlockBase::read(std::vector<uchar> &data, uint64 size){
    STUB_FUNC(__FILE__, __LINE__)
}


bool SDPChainBlockBase::write(std::vector<uchar> &data, uint64 size){
    STUB_FUNC(__FILE__, __LINE__)
}


uint64 SDPChainBlockBase::getBottomBlockReadChunkNum(){

    INCOMPLETE_FUNC(__FILE__, __LINE__)
    //Assert if they BOTH point to nothing.
    assert(!(childChainBlock == nullptr && specReadWrite == nullptr));
    //Assert if they BOTH point to something.
    assert(!(childChainBlock != nullptr && specReadWrite != nullptr));

    if(childChainBlock != nullptr)
        childChainBlock.get()->getBottomBlockReadChunkNum();
    if(specReadWrite != nullptr){
        //TODO: call appropriate func for specReadWrite.
    }

}

uint64 SDPChainBlockBase::getBottomBlockWriteChunkNum(){

    INCOMPLETE_FUNC(__FILE__, __LINE__)
    //Assert if they BOTH point to nothing.
    assert(!(childChainBlock == nullptr && specReadWrite == nullptr));
    //Assert if they BOTH point to something.
    assert(!(childChainBlock != nullptr && specReadWrite != nullptr));

    if(childChainBlock != nullptr)
        childChainBlock.get()->getBottomBlockWriteChunkNum();
    if(specReadWrite != nullptr){
        //TODO: call appropriate func for specReadWrite.
    }

}