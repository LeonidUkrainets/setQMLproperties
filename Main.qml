import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Зміна властивостей")
    Rectangle
    {
        objectName: "rectangle"
        anchors.fill: parent
        color: "pink"
    }
    property bool someBool: false
    property int  someInt:  222
}
