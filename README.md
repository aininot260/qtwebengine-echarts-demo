# qtwebengine_echarts_demo
 This is the demo for showing the usage of integrating echarts in QT project. This demo can use the rich drawing characteristics of echarts to draw 3D scattered point and 3D polyline diagram.

## Usage

Make sure you have qtwebengine installed.

If you are in arm64 device, you can install the qt support with the following command:

```
sudo apt install qt5-default qtcreator -y
sudo apt install qtwebengine5*
sudo apt install qtwebengine5-dev
sudo apt install qtwebchannel5*
``` 

Open the .pro file in QtCreator and build the project.

You may need to modify the path in mainwindows.cpp in line 17 in arm64 version qt:

```
qWebEngineView->load(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+ "/../qtwebengine_echarts_demo/html/echarts_webchannel_demo.html"));
``` 

You can also reference the API docs in https://echarts.apache.org/en/api.html to modify the html file in ./html/echarts_webchannel_demo.html
