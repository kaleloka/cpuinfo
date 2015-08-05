/**
  * Coder: Kevin Ching
  * This module displays current CPU information to screen using a simple ListView
  * Use File->Display CPU Info to display on application screen.
  *
  * Item to improve:
  * - Auto display when program is launched
  * - Data binding between C++ class to ListView
  *
 */

import QtQuick 2.0
import QtQuick.Controls 1.3
import QtQuick.Window 2.2

import CpuInfo 1.0

ApplicationWindow {
    title: qsTr("CPU Info")
    width: 640
    height: 600
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Display CPU Info")
                onTriggered: fillListModel();
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    // This is the C++ object that reads CPU info
    // information is read as soon as the object is allocated
    Item
    {
        CCpuInfo
        {
            id: cpuItem
        }
    }

    MainForm
    {
        anchors.fill: parent

        // ListView that displays CPU info
        ListView
        {
            id: cpuInfo
            boundsBehavior: Flickable.StopAtBounds
            flickableDirection: Flickable.HorizontalAndVerticalFlick
            anchors.fill: parent
            model: cpuInfoModel
            delegate: listDelegate

        }
    }

    // list delegate
    // each row contain 2 columns of text
    // first column is name of property, second column is valud of property
    Component
    {
        id: listDelegate
        Rectangle
        {
            x: 5
            height: infoText.height // make sure row text don't overlap
            Text
            {
                x: 5
                text: name
                font.bold: true
            }

            Text
            {
                id: infoText
                x: 170
                width: 400
                wrapMode: Text.WordWrap // allow multi-line text
                text: info
            }
        }
    }

    // empty model to allow dynamic list
    ListModel
    {
        id: cpuInfoModel
    }

    // this function fills the list on screen with CPU information
    function fillListModel()
    {
        cpuInfoModel.clear();
        for ( var i = 0; i < cpuItem.size(); i++ )
        {
            cpuInfoModel.append({"name": cpuItem.key(i), "info": cpuItem.value(i)});
        }
    }
}
