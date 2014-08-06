/**
 * \file CoreHeaderVerifier.cpp
 * \brief Verify component header file 'compilation' correctness.
 *
 */

/*
 * This file is part of OndALear  collection of open source components.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Copyright (C) 2008 Amnon Janiv <amnon.janiv@ondalear.com>
 *
 * Initial version: 2011-11-11
 * Author: Amnon Janiv <amnon.janiv@ondalear.com>
 */

/*
 * $Id:  $
 */
#include "CoreConfig.hpp"
#include "BaseException.hpp"
#include "CoreImplIncludes.hpp"
#include "CoreTypes.hpp"
#include "CoreMacros.hpp"
#include "MemUtil.hpp"
#include "CoreIncludes.hpp"
#include "StringUtil.hpp"
#include "Enum.hpp"
#include "EnumWrapper.hpp"
#include "CoreContainerTypes.hpp"
#include "CoreStream.hpp"
#include "CoreUtil.hpp"
#include "CoreConstants.hpp"
#include "InvalidObjectStateException.hpp"
