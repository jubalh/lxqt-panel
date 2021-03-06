/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXDE-Qt - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2015 LXQt team
 * Authors:
 *   Dmitriy Zhukov <zjesclean@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <LXQt/Settings>
class QSettings;

enum class KeeperType
{
    Global,
    Window,
    Application
};

class Settings
{
public:
    Settings();
    static Settings & instance();

    void init(QSettings *settings);

public:
    bool showCapLock() const;
    bool showNumLock() const;
    bool showScrollLock() const;
    bool showLayout() const;
    KeeperType keeperType() const;
    void restore();
public:
    void setShowCapLock(bool show);
    void setShowNumLock(bool show);
    void setShowScrollLock(bool show);
    void setShowLayout(bool show);
    void setKeeperType(KeeperType type) const;
private:
    QSettings                           *m_settings = 0;
    QScopedPointer<LXQt::SettingsCache>  m_oldSettings;
};

#endif
