
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

#ifndef SFML_RENDERWINDOW_H
#define SFML_RENDERWINDOW_H

// Headers

#include "Graphics/Color.h"

#include "Graphics/PrimitiveType.h"
#include "Graphics/Rect.h"
#include "Graphics/Types.h"
#include "Graphics/Vertex.h"
#include "System/Vector2.h"
#include "Window/VideoMode.h"
#include "Window/Window.h"
#include "Window/WindowHandle.h"
#include <stddef.h>

extern "C" sfRenderWindow *sfRenderWindow_createUnicode(sfVideoMode mode, const sfUint32 *title, sfUint32 style, const sfContextSettings *settings);

extern "C" sfRenderWindow *sfRenderWindow_createFromHandle(sfWindowHandle handle, const sfContextSettings *settings);

extern "C" void sfRenderWindow_destroy(sfRenderWindow *renderWindow);

extern "C" void sfRenderWindow_close(sfRenderWindow *renderWindow);

extern "C" sfBool sfRenderWindow_isOpen(const sfRenderWindow *renderWindow);

extern "C" sfContextSettings sfRenderWindow_getSettings(const sfRenderWindow *renderWindow);

extern "C" sfVector2i sfRenderWindow_getPosition(const sfRenderWindow *renderWindow);

extern "C" void sfRenderWindow_setPosition(sfRenderWindow *renderWindow, sfVector2i position);

extern "C" sfVector2u sfRenderWindow_getSize(const sfRenderWindow *renderWindow);

extern "C" void sfRenderWindow_setSize(sfRenderWindow *renderWindow, sfVector2u size);

extern "C" void sfRenderWindow_setUnicodeTitle(sfRenderWindow *renderWindow, const sfUint32 *title);

extern "C" void sfRenderWindow_setIcon(sfRenderWindow *renderWindow, unsigned int width, unsigned int height, const sfUint8 *pixels);

extern "C" void sfRenderWindow_setVisible(sfRenderWindow *renderWindow, sfBool visible);

extern "C" void sfRenderWindow_setVerticalSyncEnabled(sfRenderWindow *renderWindow, sfBool enabled);

extern "C" void sfRenderWindow_setMouseCursorVisible(sfRenderWindow *renderWindow, sfBool show);

extern "C" void sfRenderWindow_setMouseCursorGrabbed(sfRenderWindow *renderWindow, sfBool grabbed);

extern "C" void sfRenderWindow_setMouseCursor(sfRenderWindow *window, const sfCursor *cursor);

extern "C" void sfRenderWindow_setKeyRepeatEnabled(sfRenderWindow *renderWindow, sfBool enabled);

extern "C" void sfRenderWindow_setFramerateLimit(sfRenderWindow *renderWindow, unsigned int limit);

extern "C" void sfRenderWindow_setJoystickThreshold(sfRenderWindow *renderWindow, float threshold);

extern "C" sfBool sfRenderWindow_setActive(sfRenderWindow *renderWindow, sfBool active);

extern "C" void sfRenderWindow_requestFocus(sfRenderWindow *renderWindow);

extern "C" sfBool sfRenderWindow_hasFocus(const sfRenderWindow *renderWindow);

extern "C" void sfRenderWindow_display(sfRenderWindow *renderWindow);

extern "C" sfWindowHandle sfRenderWindow_getSystemHandle(const sfRenderWindow *renderWindow);

extern "C" void sfRenderWindow_clear(sfRenderWindow *renderWindow, sfColor color);

extern "C" void sfRenderWindow_setView(sfRenderWindow *renderWindow, const sfView *view);

extern "C" const sfView *sfRenderWindow_getView(const sfRenderWindow *renderWindow);

extern "C" const sfView *sfRenderWindow_getDefaultView(const sfRenderWindow *renderWindow);

extern "C" sfIntRect sfRenderWindow_getViewport(const sfRenderWindow *renderWindow, const sfView *view);

extern "C" sfVector2f sfRenderWindow_mapPixelToCoords(const sfRenderWindow *renderWindow, sfVector2i point, const sfView *view);

extern "C" sfVector2i sfRenderWindow_mapCoordsToPixel(const sfRenderWindow *renderWindow, sfVector2f point, const sfView *view);

extern "C" void sfRenderWindow_pushGLStates(sfRenderWindow *renderWindow);

extern "C" void sfRenderWindow_popGLStates(sfRenderWindow *renderWindow);

extern "C" void sfRenderWindow_resetGLStates(sfRenderWindow *renderWindow);

extern "C" sfVector2i sfMouse_getPositionRenderWindow(const sfRenderWindow *relativeTo);

extern "C" void sfMouse_setPositionRenderWindow(sfVector2i position, const sfRenderWindow *relativeTo);

extern "C" sfVector2i sfTouch_getPositionRenderWindow(unsigned int finger, const sfRenderWindow *relativeTo);

#endif // SFML_RENDERWINDOW_H
