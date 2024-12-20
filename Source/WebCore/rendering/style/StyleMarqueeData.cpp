/*
 * Copyright (C) 1999 Antti Koivisto (koivisto@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "config.h"
#include "StyleMarqueeData.h"

#include "RenderStyleConstants.h"
#include "RenderStyleDifference.h"
#include "RenderStyleInlines.h"

namespace WebCore {

StyleMarqueeData::StyleMarqueeData()
    : increment(RenderStyle::initialMarqueeIncrement())
    , speed(RenderStyle::initialMarqueeSpeed())
    , loops(RenderStyle::initialMarqueeLoopCount())
    , behavior(static_cast<unsigned>(RenderStyle::initialMarqueeBehavior()))
    , direction(static_cast<unsigned>(RenderStyle::initialMarqueeDirection()))
{
}

inline StyleMarqueeData::StyleMarqueeData(const StyleMarqueeData& o)
    : RefCounted<StyleMarqueeData>()
    , increment(o.increment)
    , speed(o.speed)
    , loops(o.loops)
    , behavior(o.behavior)
    , direction(o.direction) 
{
}

Ref<StyleMarqueeData> StyleMarqueeData::create()
{
    return adoptRef(*new StyleMarqueeData);
}

Ref<StyleMarqueeData> StyleMarqueeData::copy() const
{
    return adoptRef(*new StyleMarqueeData(*this));
}

bool StyleMarqueeData::operator==(const StyleMarqueeData& o) const
{
    return increment == o.increment && speed == o.speed && direction == o.direction &&
           behavior == o.behavior && loops == o.loops;
}

#if !LOG_DISABLED
void StyleMarqueeData::dumpDifferences(TextStream& ts, const StyleMarqueeData& other) const
{
    LOG_IF_DIFFERENT(increment);
    LOG_IF_DIFFERENT(speed);
    LOG_IF_DIFFERENT_WITH_CAST(MarqueeBehavior, behavior);
    LOG_IF_DIFFERENT_WITH_CAST(MarqueeDirection, direction);
}
#endif // !LOG_DISABLED

} // namespace WebCore
