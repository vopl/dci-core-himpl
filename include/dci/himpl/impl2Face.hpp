/* This file is part of the the dci project. Copyright (C) 2013-2023 vopl, shtoba.
   This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public
   License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
   This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
   You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. */

#pragma once

#include "details/implOffsetEvaluator.hpp"
#include <bit>
#include <cstdint>

namespace dci::himpl
{
    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class TFace, class TImpl>
    constexpr TFace* impl2Face(TImpl* p) noexcept
    {
        constexpr std::size_t implOffset = details::ImplOffsetEvaluator<TFace>::_value;

        if constexpr(implOffset)
        {
            if(p)
            {
                return std::bit_cast<TFace*>(std::bit_cast<std::uintptr_t>(p)-implOffset);
            }

            return nullptr;
        }

        return std::bit_cast<TFace*>(std::bit_cast<std::uintptr_t>(p)-implOffset);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class TFace, class TImpl>
    constexpr const TFace* impl2Face(const TImpl* cp) noexcept
    {
        constexpr std::size_t implOffset = details::ImplOffsetEvaluator<TFace>::_value;

        if constexpr(implOffset)
        {
            if(cp)
            {
                return std::bit_cast<const TFace*>(std::bit_cast<std::uintptr_t>(cp)-implOffset);
            }

            return nullptr;
        }

        return std::bit_cast<const TFace*>(std::bit_cast<std::uintptr_t>(cp)-implOffset);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class TFace, class TImpl>
    constexpr TFace& impl2Face(TImpl& r) noexcept
    {
        return *impl2Face<TFace, TImpl>(&r);
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class TFace, class TImpl>
    constexpr TFace&& impl2Face(TImpl&& rr) noexcept
    {
        return static_cast<TFace&&>(*impl2Face<TFace, TImpl>(&rr));
    }

    /////////0/////////1/////////2/////////3/////////4/////////5/////////6/////////7
    template <class TFace, class TImpl>
    constexpr const TFace& impl2Face(const TImpl& cr) noexcept
    {
        return *impl2Face<TFace, TImpl>(&cr);
    }
}
