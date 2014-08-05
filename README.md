BBWindow
========

How to Run: 

1. download the vlc from http://www.videolan.org/vlc/download-sources.html
   and vlc-qt from http://projects.tano.si/vlc-qt

2. change the *.pro file 

   add LIBS += -L/*your vlc-qt lib*/ -lvlc-qt -lvlc-qt-widgets
       INCLUDEPATH += /*your qt include folder*/
       CONFIG += release

3. build the project

4. Copy the vlc-qt-widgets.dll and vlc-qt.dll files from the directory of vlc-qt\bin into the build folder.
   Copy the libraries(all *.dll) and plugins directory from your vlc download into the build folder.

5. Run your project, good luck!
