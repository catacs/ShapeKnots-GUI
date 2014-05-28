/****************************************************************************
 *
 *   ShapeKnots-GUI - Qt GUI for ShapeKnots command-line tool
 *
 *           Copyright 2014 Catalin Stanciu
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *       http://www.apache.org/licenses/LICENSE-2.0
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 *****************************************************************************/

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
