import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import Graphs 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
    LineGraph{

        color: "teal"
        refColor: "black"
        width: 400; height: 256
        points: client.points
        refPoints: client.refPoints
        size: 400
        anchors.centerIn: parent
    }
    Button {
        text: "Refresh"
        onClicked: {
            client.refresh();
        }
    }
}
