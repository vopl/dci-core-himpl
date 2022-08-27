/* This file is part of the the dci project. Copyright (C) 2013-2022 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include <type_traits>
#include <cstddef>
#include <cstdint>

namespace dci::himpl::details
{
    template <class TFace, bool=std::is_polymorphic<TFace>::value, bool=std::is_polymorphic<typename TFace::Layout>::value>
    struct ImplOffsetEvaluator
    {
        static constexpr std::size_t _value = 0;
    };

    template <class TFace>
    struct ImplOffsetEvaluator<TFace, true, false>
    {
        struct VTableProbe
        {
            void* _vTablePtr;
            std::aligned_storage<sizeof(typename TFace::Layout), alignof(typename TFace::Layout)> x;
        };

        static constexpr std::size_t _value = offsetof(VTableProbe, x);
    };

    template <class TFace>
    struct ImplOffsetEvaluator<TFace, true, true>
    {
        static constexpr std::size_t _value = TFace::Layout::_implOffset;
    };
}
