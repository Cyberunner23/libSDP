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

#ifndef LIBSDP_SDPERROR_HPP
#define LIBSDP_SDPERROR_HPP

namespace libSDP{

    enum SDPErrEnum{
        NO_ERR,
        CANNOT_OPEN_FILE,
        INVALID_FILE_HEADER,
        INVALID_HEADER,
        EOS_REACHED
    };
}

#endif //LIBSDP_SDPERROR_HPP
