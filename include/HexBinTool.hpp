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

#ifndef HEXBINTOOL_H
#define HEXBINTOOL_H

#include <string>

#include "sodium.h"

class HexBinTool{

public:

	//Vars

	//Funcs

	//turns AABBCC to 0xAA 0xBB 0xCC
	int hexToBin(std::string hex, std::string &bin);
	//turns 0xAA 0xBB 0xCC to AABBCC
	char* binToHex(std::string bin, std::string &hex);


};

#endif //HEXBINTOOL_H