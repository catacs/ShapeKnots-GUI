/***************************************************************
 *  @author: Catalin Stanciu
 *  @email: catacsdev@gmail.com
 *  Copyright (C) 2014
 * *************************************************************/

#ifndef DEFINES_H
#define DEFINES_H

#define DEFAULT_DATAPATH_ROUTE "./data_tables"

#ifdef WIN32
#define DEFAULT_SHAPEKNOTS_ROUTE "./ShapeKnots.exe"
#define DEFAULT_DRAW_ROUTE "./draw.exe"
#else
#define DEFAULT_SHAPEKNOTS_ROUTE "./ShapeKnots"
#define DEFAULT_DRAW_ROUTE "./draw"
#endif

#define DEFAULT_LANGUAGE "en"

#endif // DEFINES_H
