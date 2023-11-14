//
// Created by michael.brunner on 14/11/2023.
//

#ifndef CPP_MODULES_GUI_API_H
#define CPP_MODULES_GUI_API_H

#include <QtCore/qglobal.h>

#if defined(GUI_LIBRARY)
# define GUI_API Q_DECL_EXPORT
#else
# define GUI_API Q_DECL_IMPORT
#endif

#endif //CPP_MODULES_GUI_API_H
