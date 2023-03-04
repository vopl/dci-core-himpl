/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <cstddef>
#include <tuple>

namespace dci::himpl
{
    template <class TImpl>
    struct ImplMetaInfo;

//    {
//        static constexpr std::size_t _size  = 0;
//        static constexpr std::size_t _align = 1;

//        //static constexpr bool _isPolymorphic        = false;

//        static constexpr bool _hasDefaultCtor       = false;

//        static constexpr bool _hasCopyCtor          = false;
//        static constexpr bool _hasMoveCtor          = false;

//        static constexpr bool _hasCopyAssign        = false;
//        static constexpr bool _hasMoveAssign        = false;

//        //static constexpr bool _isAbstract           = false;

//        static constexpr bool _isFinal              = false;
//        static constexpr bool _hasDestructor        = false;
//        static constexpr bool _hasDestructorCaller  = false;

//        using BasesTuple = std::tuple<>;

//        template <class TBase>
//        static constexpr std::size_t baseOffset() {return ~size_t(0); }
//    };


}
