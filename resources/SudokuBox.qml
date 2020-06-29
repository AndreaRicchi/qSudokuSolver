import QtQuick 2.0

Rectangle {
    id: box

    property variant values: []

    border {
        color: "black"
        width: 5
    }

    Grid {
        columns: 3
        rows: 3

        anchors {
            margins: 1
            fill: parent
        }

        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[0]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[1]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[2]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[3]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[4]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[5]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[6]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[7]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
        Rectangle {
            width: parent.width / 3
            height: parent.height / 3

            border {
                color: "grey"
                width: 1
            }

            Text {
                anchors.fill: parent
                text: values[8]
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: height / 2
            }
        }
    }
}
